#include "gamerule.h"
#include "serverplayer.h"
#include "room.h"
#include "standard.h"
#include "engine.h"
#include "settings.h"

#include <QTime>

GameRule::GameRule(QObject *)
    :TriggerSkill("game_rule")
{
    //@todo: this setParent is illegitimate in QT and is equivalent to calling
    // setParent(NULL). So taking it off at the moment until we figure out
    // a way to do it.
    //setParent(parent);

    events << GameStart << TurnStart << EventPhaseStart << CardUsed
           << CardEffected << CardFinished
           << HpRecover << HpLost << PostHpReduced
           << EventLoseSkill << EventAcquireSkill
           << AskForPeaches << AskForPeachesDone << Dying << Death << GameOverJudge
           << SlashHit << SlashMissed << SlashEffected << SlashProceed
           << ConfirmDamage << PreHpReduced << DamageDone << DamageComplete
           << StartJudge << FinishRetrial << FinishJudge
           << Pindian;
}

bool GameRule::triggerable(const ServerPlayer *target) const{
    return true;
}

int GameRule::getPriority() const{
    return 0;
}

void GameRule::onPhaseChange(ServerPlayer *player) const{
    Room *room = player->getRoom();
    switch(player->getPhase()){
    case Player::PhaseNone: {
        Q_ASSERT(false);
        }
    case Player::RoundStart:{
            break;
        }
    case Player::Start: {
            player->setMark("SlashCount", 0);
            break;
        }
    case Player::Judge: {
            QList<const Card *> tricks = player->getJudgingArea();
            while(!tricks.isEmpty() && player->isAlive()){
                const Card *trick = tricks.takeLast();
                bool on_effect = room->cardEffect(trick, NULL, player);
                if(!on_effect)
                    trick->onNullified(player);
            }
            break;
        }
    case Player::Draw: {
            QVariant num = 2;
            if(room->getTag("FirstRound").toBool()){
                room->setTag("FirstRound", false);
                if(room->getMode() == "02_1v1")
                    num = 1;
            }

            room->getThread()->trigger(DrawNCards, room, player, num);
            int n = num.toInt();
            if(n > 0)
                player->drawCards(n, false);
            break;
        }

    case Player::Play: {
            player->clearHistory();

            while(player->isAlive()){
                CardUseStruct card_use;
                room->activate(player, card_use);
                if (card_use.card != NULL) {
                    room->useCard(card_use);
                }
                else break;
            }
            break;
        }

    case Player::Discard:{
            int discard_num, keep_num;
            QSet<const Card *> jilei_cards;
            QList<const Card *> handcards;
            do
            {
                handcards = player->getHandcards();
                foreach(const Card *card, handcards){
                    if(player->isJilei(card))
                        jilei_cards << card;
                }
                keep_num = qMax(player->getMaxCards(), jilei_cards.size());
                discard_num = player->getHandcardNum() - keep_num;
                jilei_cards.clear();
                if (discard_num > 0)
                    room->askForDiscard(player, "gamerule", discard_num, 1);
            }while (discard_num > 0);
            if (player->getHandcardNum() > player->getMaxCards())
                room->showAllCards(player);
            break;
        }
    case Player::Finish: {
            break;
        }

    case Player::NotActive:{
            if(player->hasFlag("drank")){
                LogMessage log;
                log.type = "#UnsetDrankEndOfTurn";
                log.from = player;
                room->sendLog(log);

                room->setPlayerFlag(player, "-drank");
            }

            player->clearFlags();
            player->clearHistory();

            return;
        }
    }
}

bool GameRule::trigger(TriggerEvent triggerEvent, Room* room, ServerPlayer *player, QVariant &data) const{
    if(room->getTag("SkipGameRule").toBool()){
        room->removeTag("SkipGameRule");
        return false;
    }

    // Handle global events
    if (player == NULL)
    {      
        if (triggerEvent == GameStart) {
            foreach (ServerPlayer* player, room->getPlayers())
            {
                if(player->getGeneral()->getKingdom() == "god" && player->getGeneralName() != "anjiang"){
                    QString new_kingdom = room->askForKingdom(player);
                    room->setPlayerProperty(player, "kingdom", new_kingdom);

                    LogMessage log;
                    log.type = "#ChooseKingdom";
                    log.from = player;
                    log.arg = new_kingdom;
                    room->sendLog(log);
                }                
            }
            room->setTag("FirstRound", true);
            room->drawCards(room->getPlayers(), 4, NULL);
        }
        return false;
    }

    switch(triggerEvent){
    case TurnStart:{
            player = room->getCurrent();
            if (player->hasFlag("drank")) {
                room->setPlayerFlag(player, "-drank");
            }
            if (!player->faceUp())
                player->turnOver();
            else if(player->isAlive())
                player->play();

            break;
        }

    case EventPhaseStart: onPhaseChange(player); break;
    case CardUsed: {
            if(data.canConvert<CardUseStruct>()){
                CardUseStruct card_use = data.value<CardUseStruct>();
                const Card *card = card_use.card;
                RoomThread *thread = room->getThread();

                card_use.from->broadcastSkillInvoke(card);

                if(card_use.card->hasPreAction())
                    card_use.card->doPreAction(room, card_use);

                ServerPlayer *target;
                QList<ServerPlayer *> targets = card_use.to;

                if(card_use.from && !card_use.to.empty()){
                    foreach(ServerPlayer *to, card_use.to){
                        target = to;
                        while(thread->trigger(TargetConfirming, room, target, data)){
                            CardUseStruct new_use = data.value<CardUseStruct>();
                            target = new_use.to.at(targets.indexOf(target));
                            targets = new_use.to;
                        }
                    }
                }

                card_use = data.value<CardUseStruct>();
                if(card_use.from && !card_use.to.isEmpty())
                {
                    foreach(ServerPlayer *p, room->getAllPlayers())
                        thread->trigger(TargetConfirmed, room, p, data);
                }
                card->use(room, card_use.from, card_use.to);
            }

            break;
        }
    case CardFinished: {
            CardUseStruct use = data.value<CardUseStruct>();
            foreach(ServerPlayer *p, use.to)
                if(p->getMark("qinggang") > 0)
                    p->setMark("qinggang", 0);
            room->clearCardFlag(use.card);

            break;
    }

    case EventAcquireSkill:
    case EventLoseSkill:{
        QString skill_name = data.toString();
        const Skill *skill = Sanguosha->getSkill(skill_name);
        bool refilter = skill->inherits("FilterSkill");

        if (refilter)
            room->filterCards(player, player->getCards("he"), triggerEvent == EventLoseSkill);

        break;
    }

    case HpRecover:{
            RecoverStruct recover_struct = data.value<RecoverStruct>();
            int recover = recover_struct.recover;
            int new_hp = qMin(player->getHp() + recover, player->getMaxHp());
            room->setPlayerProperty(player, "hp", new_hp);
            room->broadcastInvoke("hpChange", QString("%1:%2").arg(player->objectName()).arg(recover));

            break;
        }

    case HpLost:{
            int lose = data.toInt();

            LogMessage log;
            log.type = "#LoseHp";
            log.from = player;
            log.arg = QString::number(lose);
            room->sendLog(log);

            room->setPlayerProperty(player, "hp", player->getHp() - lose);
            QString str = QString("%1:%2L").arg(player->objectName()).arg(-lose);
            room->broadcastInvoke("hpChange", str);

            QVariant data2 = QVariant::fromValue(lose);
            room->getThread()->trigger(PostHpReduced, room, player, data2);

            break;
    }

    case PostHpReduced:{
            if (player->getHp() > 0)
                break;

            if (data.canConvert<DamageStruct>()) {
                DamageStruct damage = data.value<DamageStruct>();
                room->enterDying(player, &damage);
            } else
                room->enterDying(player, NULL);

            break;
    }

    case Dying:{
            if(player->getHp() > 0){
                player->setFlags("-dying");
                break;
            }

            LogMessage log;
            log.type = "#AskForPeaches";
            log.from = player;
            log.to = room->getAllPlayers();
            log.arg = QString::number(1 - player->getHp());
            room->sendLog(log);

            RoomThread *thread = room->getThread();
            foreach(ServerPlayer *saver, room->getAllPlayers()){
                if(player->getHp() > 0)
                    break;

                thread->trigger(AskForPeaches, room, saver, data);
            }

            player->setFlags("-dying");
            thread->trigger(AskForPeachesDone, room, player, data);

            break;
        }

    case AskForPeaches:{
            DyingStruct dying = data.value<DyingStruct>();
            ServerPlayer *current = room->getCurrent();
            ServerPlayer *jiaxu = NULL;
            const Card *peach = NULL;
            if(current->hasSkill("wansha"))
                jiaxu = current;

            while(dying.who->getHp() <= 0){
                if(!current->hasSkill("wansha") || current->isDead() || dying.who->objectName() == player->objectName()
                        || player->hasFlag("dying") || player == jiaxu)
                    if(dying.who->isAlive())
                        peach = room->askForSinglePeach(player, dying.who);
                if(peach == NULL)
                    break;

                CardUseStruct use;
                use.card = peach;
                use.from = player;
                if(player != dying.who)
                    use.to << dying.who;

                room->useCard(use, false);
            }

            break;
        }

    case AskForPeachesDone:{
            if(player->getHp() <= 0 && player->isAlive()){
                DyingStruct dying = data.value<DyingStruct>();
                room->killPlayer(player, dying.damage);
            }

            break;
        }

    case ConfirmDamage:{
            DamageStruct damage = data.value<DamageStruct>();

            if(damage.card && damage.card->hasFlag("drank")){
                LogMessage log;
                log.type = "#AnalepticBuff";
                log.from = damage.from;
                log.to << damage.to;
                log.arg = "analeptic";
                room->sendLog(log);

                damage.damage++;
                data = QVariant::fromValue(damage);
            }

            break;
        }

    case PreHpReduced:{
            DamageStruct damage = data.value<DamageStruct>();

            bool chained = player->isChained();
            if(!chained)
                break;

            if(chained && damage.nature != DamageStruct::Normal){
                room->setPlayerProperty(player, "chained", false);
                damage.trigger_chain = true;

                LogMessage log;
                log.type = "#IronChainDamage";
                log.from = player;
                room->sendLog(log);

                data = QVariant::fromValue(damage);
            }

            break;
        }

    case DamageDone:{
            DamageStruct damage = data.value<DamageStruct>();
            room->sendDamageLog(damage);

            room->applyDamage(player, damage);
            room->getThread()->trigger(PostHpReduced, room, player, data);
            break;
        }
    case DamageComplete:{
            DamageStruct damage = data.value<DamageStruct>();
            if(room->getMode() == "02_1v1" && player->isDead()){
                QString new_general = player->tag["1v1ChangeGeneral"].toString();
                if(!new_general.isEmpty())
                    changeGeneral1v1(player);
            }
            if(damage.trigger_chain){
                // iron chain effect
                if(!damage.chain){
                    QList<ServerPlayer *> chained_players;
                    if(room->getCurrent()->isDead())
                        chained_players = room->getOtherPlayers(room->getCurrent());
                    else
                        chained_players = room->getAllPlayers();
                    foreach(ServerPlayer *chained_player, chained_players){
                        if(chained_player->isChained() && chained_player->isAlive()){

                            DamageStruct chain_damage = damage;
                            chain_damage.to = chained_player;
                            chain_damage.chain = true;

                            room->damage(chain_damage);
                        }
                    }
                }
            }
            break;
        }

    case CardEffected:{
            if(data.canConvert<CardEffectStruct>()){
                CardEffectStruct effect = data.value<CardEffectStruct>();
                if(room->isCanceled(effect))
                    return true;

                effect.card->onEffect(effect);
            }

            break;
        }

    case SlashEffected:{
            SlashEffectStruct effect = data.value<SlashEffectStruct>();

            QVariant data = QVariant::fromValue(effect);
            room->getThread()->trigger(SlashProceed, room, effect.from, data);

            break;
        }

    case SlashProceed:{
            SlashEffectStruct effect = data.value<SlashEffectStruct>();

            QString slasher = effect.from->objectName();
            const Card *jink = room->askForCard(effect.to, "jink", "slash-jink:" + slasher, data, CardUsed, effect.from);
            room->slashResult(effect, jink);

            break;
        }

    case SlashHit:{
            SlashEffectStruct effect = data.value<SlashEffectStruct>();

            DamageStruct damage;
            damage.card = effect.slash;

            damage.damage = 1;

            damage.from = effect.from;
            damage.to = effect.to;
            damage.nature = effect.nature;
            room->damage(damage);

            break;
        }

    case SlashMissed:{
            SlashEffectStruct effect = data.value<SlashEffectStruct>();
            if(effect.to->getMark("qinggang") > 0)
                effect.to->setMark("qinggang", 0);
            break;
        }

    case GameOverJudge:{            
            if(room->getMode() == "02_1v1"){
                QStringList list = player->tag["1v1Arrange"].toStringList();

                if(!list.isEmpty())
                    return false;
            }

            QString winner = getWinner(player);
            if(!winner.isNull()){
                room->gameOver(winner);
                player->bury();
                return true;
            }

            break;
        }

    case Death:{
            player->bury();

            if(room->getTag("SkipNormalDeathProcess").toBool())
                return false;

            DamageStar damage = data.value<DamageStar>();
            ServerPlayer *killer = damage ? damage->from : NULL;
            if(killer){
                rewardAndPunish(killer, player);
            }

            if(room->getMode() == "02_1v1"){
                QStringList list = player->tag["1v1Arrange"].toStringList();

                if(!list.isEmpty()){
                    player->tag["1v1ChangeGeneral"] = list.takeFirst();
                    player->tag["1v1Arrange"] = list;

                    DamageStar damage = data.value<DamageStar>();

                    if(damage == NULL){
                        changeGeneral1v1(player);
                        return false;
                    }
                }
            }

            break;
        }

    case StartJudge:{
            int card_id = room->drawCard();
            room->getThread()->delay(Config.S_JUDGE_SHORT_DELAY);
            JudgeStar judge = data.value<JudgeStar>();
            judge->card = Sanguosha->getCard(card_id);

            LogMessage log;
            log.type = "$InitialJudge";
            log.from = player;
            log.card_str = judge->card->getEffectIdString();
            room->sendLog(log);

            room->moveCardTo(judge->card, NULL, judge->who, Player::PlaceJudge,
                             CardMoveReason(CardMoveReason::S_REASON_JUDGE,
                             judge->who->objectName(),
                             QString(), QString(), judge->reason), true);
            judge->updateResult();
            room->getThread()->delay(Config.S_JUDGE_SHORT_DELAY);
            break;
        }

    case FinishRetrial:{
            JudgeStar judge = data.value<JudgeStar>();
            if(judge->play_animation)
                room->sendJudgeResult(judge);

            LogMessage log;
            log.type = "$JudgeResult";
            log.from = player;
            log.card_str = judge->card->getEffectIdString();
            room->sendLog(log);

            room->removeTag("retrial");            
            break;
        }

    case FinishJudge:{
            JudgeStar judge = data.value<JudgeStar>();
            room->getThread()->delay(Config.S_JUDGE_LONG_DELAY);
            if(room->getCardPlace(judge->card->getEffectiveId()) == Player::PlaceJudge){
                CardMoveReason reason(CardMoveReason::S_REASON_JUDGEDONE, judge->who->objectName(), QString(), judge->reason);
                room->moveCardTo(judge->card, judge->who, NULL, Player::DiscardPile, reason, true);
            }            
            break;
        }

    case Pindian:{
            PindianStar pindian = data.value<PindianStar>();
            // modify this
            CardMoveReason reason1(CardMoveReason::S_REASON_PINDIAN, pindian->from->objectName(), pindian->to->objectName(),
                pindian->reason, QString());
            room->moveCardTo(pindian->from_card, pindian->from, NULL, Player::DiscardPile, reason1, true);


            CardMoveReason reason2(CardMoveReason::S_REASON_PINDIAN, pindian->to->objectName());
            room->moveCardTo(pindian->to_card, pindian->to, NULL, Player::DiscardPile, reason2, true);
            LogMessage log;

            log.type = "$PindianResult";
            log.from = pindian->from;
            log.card_str = pindian->from_card->getEffectIdString();
            room->sendLog(log);

            log.type = "$PindianResult";
            log.from = pindian->to;
            log.card_str = pindian->to_card->getEffectIdString();
            room->sendLog(log);

            break;
        }

    default:
        ;
    }

    return false;
}

void GameRule::changeGeneral1v1(ServerPlayer *player) const{
    Room *room = player->getRoom();
    QString new_general = player->tag["1v1ChangeGeneral"].toString();
    player->tag.remove("1v1ChangeGeneral");
    room->changeHero(player, new_general, true, true);
    room->revivePlayer(player);

    if(player->getKingdom() != player->getGeneral()->getKingdom())
        room->setPlayerProperty(player, "kingdom", player->getGeneral()->getKingdom());

    room->broadcastInvoke("revealGeneral",
                          QString("%1:%2").arg(player->objectName()).arg(new_general),
                          player);

    if(!player->faceUp())
        player->turnOver();

    if(player->isChained())
        room->setPlayerProperty(player, "chained", false);

    player->drawCards(4);
}

void GameRule::rewardAndPunish(ServerPlayer *killer, ServerPlayer *victim) const{
    if(killer->isDead())
        return;

    if(killer->getRoom()->getMode() == "06_3v3"){
        if(Config.value("3v3/UsingNewMode", false).toBool())
            killer->drawCards(2);
        else
            killer->drawCards(3);
    }
    else{
        if(victim->getRole() == "rebel" && killer != victim){
            killer->drawCards(3);
        }else if(victim->getRole() == "loyalist" && killer->getRole() == "lord"){
            killer->throwAllHandCardsAndEquips();
        }
    }
}

QString GameRule::getWinner(ServerPlayer *victim) const{
    Room *room = victim->getRoom();
    QString winner;

    if(room->getMode() == "06_3v3"){
        switch(victim->getRoleEnum()){
        case Player::Lord: winner = "renegade+rebel"; break;
        case Player::Renegade: winner = "lord+loyalist"; break;
        default:
            break;
        }
    }else if(Config.EnableHegemony){
        bool has_anjiang = false, has_diff_kingdoms = false;
        QString init_kingdom;
        foreach(ServerPlayer *p, room->getAlivePlayers()){
            if(room->getTag(p->objectName()).toStringList().size()){
                has_anjiang = true;
            }

            if(init_kingdom.isEmpty()){
                init_kingdom = p->getKingdom();
            }
            else if(init_kingdom != p->getKingdom()){
                has_diff_kingdoms = true;
            }
        }

        if(!has_anjiang && !has_diff_kingdoms){
            QStringList winners;
            QString aliveKingdom = room->getAlivePlayers().first()->getKingdom();
            foreach(ServerPlayer *p, room->getPlayers()){
                if(p->isAlive())winners << p->objectName();
                if(p->getKingdom() == aliveKingdom)
                {
                    QStringList generals = room->getTag(p->objectName()).toStringList();
                    if(generals.size()&&!Config.Enable2ndGeneral)continue;
                    if(generals.size()>1)continue;

                    //if someone showed his kingdom before death,
                    //he should be considered victorious as well if his kingdom survives
                    winners << p->objectName();
                }
            }

            winner = winners.join("+");
        }
    }else{
        QStringList alive_roles = room->aliveRoles(victim);
        switch(victim->getRoleEnum()){
        case Player::Lord:{
                if(alive_roles.length() == 1 && alive_roles.first() == "renegade")
                    winner = room->getAlivePlayers().first()->objectName();
                else
                    winner = "rebel";
                break;
            }

        case Player::Rebel:
        case Player::Renegade:
            {
                if(!alive_roles.contains("rebel") && !alive_roles.contains("renegade")){
                    winner = "lord+loyalist";
                    if(victim->getRole() == "renegade" && !alive_roles.contains("loyalist"))
                        room->setTag("RenegadeInFinalPK", true);
                }
                break;
            }

        default:
            break;
        }
    }

    return winner;
}

HulaoPassMode::HulaoPassMode(QObject *parent)
    :GameRule(parent)
{
    setObjectName("hulaopass_mode");

    events << HpChanged << StageChange;
    default_choice = "recover";
}

bool HulaoPassMode::trigger(TriggerEvent triggerEvent, Room* room, ServerPlayer *player, QVariant &data) const{
    switch(triggerEvent) {
    case StageChange: {
        ServerPlayer* lord = room->getLord();
        room->changeHero(lord, "shenlvbu2", true, true);
        room->setPlayerMark(lord, "secondMode", 1);

        QList<const Card *> tricks = lord->getJudgingArea();
        foreach(const Card *trick, tricks)
        {
            CardMoveReason reason(CardMoveReason::S_REASON_NATURAL_ENTER, QString());
            room->throwCard(trick, reason, NULL);
        }
        break;
                      }
    case GameStart: {
        // Handle global events
        if (player == NULL)
        {            
            ServerPlayer* lord = room->getLord();
            lord->drawCards(8, false);
            foreach (ServerPlayer* player, room->getPlayers())
            {
                if(player->isLord())
                    continue;
                else
                    player->drawCards(player->getSeat() + 1, false);
            }
            return false;
        }
        break;
                    }
    case CardUsed:{
        CardUseStruct use = data.value<CardUseStruct>();
        if(use.card->isKindOf("Weapon") && player->askForSkillInvoke("weapon_recast", data)){
            player->broadcastSkillInvoke("@recast");
            CardMoveReason reason(CardMoveReason::S_REASON_RECAST, player->objectName());
            room->throwCard(use.card, reason, NULL);
            player->drawCards(1);
            return false;
        }

            break;
        }

    case HpChanged:{
        if(player->isLord() && player->getHp() <= 4 && player->getMark("secondMode") == 0){
                throw StageChange;
            }

            return false;
        }

    case Death:{
            if(player->isLord()){
                room->gameOver("rebel");
            }else{
                if(room->aliveRoles(player).length() == 1)
                    room->gameOver("lord");

                LogMessage log;
                log.type = "#Reforming";
                log.from = player;
                room->sendLog(log);

                player->bury();
                room->setPlayerProperty(player, "hp", 0);

                foreach(ServerPlayer *player, room->getOtherPlayers(room->getLord())){
                    if(player->askForSkillInvoke("draw_1v3"))
                        player->drawCards(1, false);
                }
            }

            return false;
        }

    case TurnStart:{
            if(player->isLord()){
                if(!player->faceUp())
                    player->turnOver();
                else
                    player->play();
            }else{
                if(player->isDead()){
                    if(player->getHp() + player->getHandcardNum() == 6){
                        LogMessage log;
                        log.type = "#ReformingRevive";
                        log.from = player;
                        room->sendLog(log);

                        room->revivePlayer(player);
                    }else if(player->isWounded()){
                        if(player->getHp() > 0 && (room->askForChoice(player, "Hulaopass", "recover+draw") == "draw")){
                            LogMessage log;
                            log.type = "#ReformingDraw";
                            log.from = player;
                            room->sendLog(log);
                            player->drawCards(1, false);
                            return false;
                        }

                        LogMessage log;
                        log.type = "#ReformingRecover";
                        log.from = player;
                        room->sendLog(log);

                        room->setPlayerProperty(player, "hp", player->getHp() + 1);
                    }else
                        player->drawCards(1, false);
                }else if(!player->faceUp())
                    player->turnOver();
                else
                    player->play();
            }

            return false;
        }

    default:
        break;
    }

    return GameRule::trigger(triggerEvent, room, player, data);
}

BasaraMode::BasaraMode(QObject *parent)
    :GameRule(parent)
{
    setObjectName("basara_mode");

    events << CardsMoveOneTime << DamageInflicted;

    skill_mark["niepan"] = "@nirvana";
    skill_mark["smallyeyan"] = "@flame";
    skill_mark["luanwu"] = "@chaos";
    skill_mark["fuli"] = "@laoji";
    skill_mark["zuixiang"] = "@sleep";
}

QString BasaraMode::getMappedRole(const QString &role){
    static QMap<QString, QString> roles;
    if(roles.isEmpty()){
        roles["wei"] = "lord";
        roles["shu"] = "loyalist";
        roles["wu"] = "rebel";
        roles["qun"] = "renegade";
    }
    return roles[role];
}

int BasaraMode::getPriority() const{
    return 5;
}

void BasaraMode::playerShowed(ServerPlayer *player) const{
    Room *room = player->getRoom();
    QStringList names = room->getTag(player->objectName()).toStringList();
    if(names.isEmpty())
        return;

    if(Config.EnableHegemony){
        QMap<QString, int> kingdom_roles;
        foreach(ServerPlayer *p, room->getOtherPlayers(player)){
            kingdom_roles[p->getKingdom()]++;
        }

        if(kingdom_roles[Sanguosha->getGeneral(names.first())->getKingdom()] >= 2
                && player->getGeneralName() == "anjiang")
            return;
    }

    QString answer = room->askForChoice(player, "RevealGeneral", "yes+no");
    if(answer == "yes"){

        QString general_name = room->askForGeneral(player,names);

        generalShowed(player,general_name);
        if (Config.EnableHegemony) room->getThread()->trigger(GameOverJudge, room, player);
        playerShowed(player);
    }
}

void BasaraMode::generalShowed(ServerPlayer *player, QString general_name) const
{
    Room * room = player->getRoom();
    QStringList names = room->getTag(player->objectName()).toStringList();
    if(names.isEmpty())return;

    if(player->getGeneralName() == "anjiang")
    {
        room->changeHero(player, general_name, false, false, false, false);
        foreach(QString skill_name, skill_mark.keys()){
            if(player->hasSkill(skill_name))
                room->setPlayerMark(player, skill_mark[skill_name], 1);
        }
    }
    else
        room->changeHero(player, general_name, false, false, true, false);

    room->getThread()->addPlayerSkills(player);
    room->setPlayerProperty(player, "kingdom", player->getGeneral()->getKingdom());
    if(Config.EnableHegemony)room->setPlayerProperty(player, "role", getMappedRole(player->getGeneral()->getKingdom()));

    names.removeOne(general_name);
    room->setTag(player->objectName(),QVariant::fromValue(names));

    LogMessage log;
    log.type = "#BasaraReveal";
    log.from = player;
    log.arg  = player->getGeneralName();
    log.arg2 = player->getGeneral2Name();

    room->sendLog(log);
    room->broadcastInvoke("playSystemAudioEffect", "choose-item");
}

bool BasaraMode::trigger(TriggerEvent triggerEvent, Room* room, ServerPlayer *player, QVariant &data) const{
    // Handle global events
    if (player == NULL)
    {
        if (triggerEvent == GameStart)
        {
            if(Config.EnableHegemony)
                room->setTag("SkipNormalDeathProcess", true);
            foreach(ServerPlayer* sp, room->getAlivePlayers())
            {
                room->setPlayerProperty(sp, "general", "anjiang");
                sp->setGender(General::SexLess);
                room->setPlayerProperty(sp,"kingdom","god");

                LogMessage log;
                log.type = "#BasaraGeneralChosen";
                log.arg = room->getTag(sp->objectName()).toStringList().at(0);

                if(Config.Enable2ndGeneral)
                {
                    room->setPlayerProperty(sp, "general2", "anjiang");
                    log.arg2 = room->getTag(sp->objectName()).toStringList().at(1);
                }

                sp->invoke("log",log.toString());
                sp->tag["roles"] = room->getTag(sp->objectName()).toStringList().join("+");
            }
            return false;
        }
    }


    player->tag["event"] = triggerEvent;
    player->tag["event_data"] = data;

    switch(triggerEvent){    
    case CardEffected:{
        if(player->getPhase() == Player::NotActive){
            CardEffectStruct ces = data.value<CardEffectStruct>();
            if(ces.card)
                if(ces.card->isKindOf("TrickCard") ||
                        ces.card->isKindOf("Slash"))
                playerShowed(player);

            const ProhibitSkill* prohibit = room->isProhibited(ces.from,ces.to,ces.card);
            if(prohibit)
            {
                LogMessage log;
                log.type = "#SkillAvoid";
                log.from = ces.to;
                log.arg  = prohibit->objectName();
                log.arg2 = ces.card->objectName();

                room->sendLog(log);

                return true;
            }
        }
        break;
    }

    case EventPhaseStart:{
        if(player->getPhase() == Player::Start)
            playerShowed(player);

        break;
    }
    case DamageInflicted:{
        playerShowed(player);
        break;
    }
    case GameOverJudge:{
        if(Config.EnableHegemony){
            if(player->getGeneralName() == "anjiang"){
                QStringList generals = room->getTag(player->objectName()).toStringList();
                room->changePlayerGeneral(player, generals.at(0));
                if(Config.Enable2ndGeneral)room->changePlayerGeneral2(player, generals.at(1));
                room->setPlayerProperty(player, "kingdom", player->getGeneral()->getKingdom());
                room->setPlayerProperty(player, "role", getMappedRole(player->getKingdom()));
            }
        }
        break;
    }

    case Death:{
        if(Config.EnableHegemony){
            DamageStar damage = data.value<DamageStar>();
            ServerPlayer *killer = damage ? damage->from : NULL;
            if(killer && killer->getKingdom() == damage->to->getKingdom()){
                killer->throwAllHandCardsAndEquips();
            }
            else if(killer && killer->isAlive()){
                killer->drawCards(3);
            }
        }

        break;
    }

    default:
        break;
    }

    return false;
}
