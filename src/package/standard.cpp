#include "standard.h"
#include "serverplayer.h"
#include "room.h"
#include "skill.h"
#include "maneuvering.h"
#include "clientplayer.h"
#include "engine.h"
#include "client.h"
#include "exppattern.h"

QString BasicCard::getType() const{
    return "basic";
}

Card::CardType BasicCard::getTypeId() const{
    return Basic;
}

TrickCard::TrickCard(Suit suit, int number, bool aggressive)
    :Card(suit, number), aggressive(aggressive),
    cancelable(true)
{
}

bool TrickCard::isAggressive() const{
    return aggressive;
}

void TrickCard::setCancelable(bool cancelable){
    this->cancelable = cancelable;
}

QString TrickCard::getType() const{
    return "trick";
}

Card::CardType TrickCard::getTypeId() const{
    return Trick;
}

bool TrickCard::isCancelable(const CardEffectStruct &effect) const{
    return cancelable;
}

TriggerSkill *EquipCard::getSkill() const{
    return skill;
}

QString EquipCard::getType() const{
    return "equip";
}

Card::CardType EquipCard::getTypeId() const{
    return Equip;
}

void EquipCard::onUse(Room *room, const CardUseStruct &card_use) const{
    ServerPlayer *player = card_use.from;

    QVariant data = QVariant::fromValue(card_use);
    RoomThread *thread = room->getThread();
    thread->trigger(CardUsed, room, player, data);

    thread->trigger(CardFinished, room, player, data);
}

void EquipCard::use(Room *room, ServerPlayer *source, QList<ServerPlayer *> &targets) const{
    WrappedCard *equipped = NULL;
    ServerPlayer *target = targets.value(0, source);
    if (room->getCardOwner(getId()) != source) return;
    switch(location()){
    case WeaponLocation: equipped = target->getWeapon(); break;
    case ArmorLocation: equipped = target->getArmor(); break;
    case DefensiveHorseLocation: equipped = target->getDefensiveHorse(); break;
    case OffensiveHorseLocation: equipped = target->getOffensiveHorse(); break;
    }

    if (room->getCardPlace(getId()) == Player::PlaceHand)
        {
            QList<CardsMoveStruct> exchangeMove;
            CardsMoveStruct move1;
            move1.card_ids << getId();
            move1.to = target;
            move1.to_place = Player::PlaceEquip;
            move1.reason = CardMoveReason(CardMoveReason::S_REASON_USE, target->objectName());
            exchangeMove.push_back(move1);
            if(equipped)
            {
                CardsMoveStruct move2;
                move2.card_ids << equipped->getId();
                move2.to = NULL;
                move2.to_place = Player::DiscardPile;
                move2.reason = CardMoveReason(CardMoveReason::S_REASON_CHANGE_EQUIP, target->objectName());
                exchangeMove.push_back(move2);
            }
            LogMessage log;
            log.from = target;
            log.type = "$Install";
            log.card_str = QString::number(getEffectiveId());
            room->sendLog(log);

            room->moveCardsAtomic(exchangeMove, true);
        }

}

void EquipCard::onInstall(ServerPlayer *player) const{
    Room *room = player->getRoom();

    if(skill)
        room->getThread()->addTriggerSkill(skill);
    if (Sanguosha->getSkill(this) && Sanguosha->getSkill(this)->inherits("ViewAsSkill"))
        room->attachSkillToPlayer(player, this->objectName());
}

void EquipCard::onUninstall(ServerPlayer *player) const{
    Room *room = player->getRoom();
    if (Sanguosha->getSkill(this) && Sanguosha->getSkill(this)->inherits("ViewAsSkill"))
        room->detachSkillFromPlayer(player, this->objectName(), true);
}

QString GlobalEffect::getSubtype() const{
    return "global_effect";
}

void GlobalEffect::onUse(Room *room, const CardUseStruct &card_use) const{
    ServerPlayer *source = card_use.from;
    QList<ServerPlayer *> targets, all_players = room->getAllPlayers();
    foreach(ServerPlayer *player, all_players){
        const ProhibitSkill *skill = room->isProhibited(source, player, this);
        if(skill){
            LogMessage log;
            log.type = "#SkillAvoid";
            log.from = player;
            log.arg = skill->objectName();
            log.arg2 = objectName();
            room->sendLog(log);

            room->broadcastSkillInvoke(skill->objectName());
        }else
            targets << player;
    }

    CardUseStruct use = card_use;
    use.to = targets;
    TrickCard::onUse(room, use);
}

bool GlobalEffect::isAvailable(const Player *player) const{
    bool canUse = false;
    QList<const Player *> players = player->getSiblings();
    players << player;
    foreach(const Player *p, players){
        if(p->isDead())
            continue;

        if(player->isProhibited(p, this))
            continue;

        canUse = true;
        break;
    }

    return canUse && TrickCard::isAvailable(player);
}

QString AOE::getSubtype() const{
    return "aoe";
}

bool AOE::isAvailable(const Player *player) const{
    bool canUse = false;
    QList<const Player *> players = player->getSiblings();
    foreach(const Player *p, players){
        if(p->isDead())
            continue;

        if(player->isProhibited(p, this))
            continue;

        canUse = true;
        break;
    }

    return canUse && TrickCard::isAvailable(player);
}

void AOE::onUse(Room *room, const CardUseStruct &card_use) const{
    ServerPlayer *source = card_use.from;
    QList<ServerPlayer *> targets, other_players = room->getOtherPlayers(source);
    foreach(ServerPlayer *player, other_players){
        const ProhibitSkill *skill = room->isProhibited(source, player, this);
        if(skill){
            LogMessage log;
            log.type = "#SkillAvoid";
            log.from = player;
            log.arg = skill->objectName();
            log.arg2 = objectName();
            room->sendLog(log);

            room->broadcastSkillInvoke(skill->objectName());
        }else
            targets << player;
    }

    CardUseStruct use = card_use;
    use.to = targets;
    TrickCard::onUse(room, use);
}

QString SingleTargetTrick::getSubtype() const{
    return "single_target_trick";
}

bool SingleTargetTrick::targetFilter(const QList<const Player *> &targets, const Player *to_select, const Player *Self) const{
    return true;
}

DelayedTrick::DelayedTrick(Suit suit, int number, bool movable)
    :TrickCard(suit, number, true), movable(movable)
{
    judge.negative = true;
    judge.play_animation = true;
}

void DelayedTrick::onUse(Room *room, const CardUseStruct &card_use) const{
    LogMessage log;
    log.from = card_use.from;
    log.to = card_use.to;
    log.type = "#UseCard";
    log.card_str = toString();
    room->sendLog(log);
    QVariant data = QVariant::fromValue(card_use);
    RoomThread *thread = room->getThread();
    thread->trigger(CardUsed, room, card_use.from, data);

    thread->trigger(CardFinished, room, card_use.from, data);
}

void DelayedTrick::use(Room *room, ServerPlayer *source, QList<ServerPlayer *> &targets) const{
    ServerPlayer *target = targets.value(0, source);
    CardMoveReason reason(CardMoveReason::S_REASON_USE, source->objectName(), target->objectName(), this->getSkillName(), QString());
    room->moveCardTo(this, source, target, Player::PlaceDelayedTrick, reason, true);
}

QString DelayedTrick::getSubtype() const{
    return "delayed_trick";
}

void DelayedTrick::onEffect(const CardEffectStruct &effect) const{
    Room *room = effect.to->getRoom();

    CardMoveReason reason(CardMoveReason::S_REASON_USE, effect.to->objectName(), getSkillName(), QString());
    room->moveCardTo(this, NULL, Player::PlaceTable, reason, true);

    LogMessage log;
    log.from = effect.to;
    log.type = "#DelayedTrick";
    log.arg = effect.card->objectName();
    room->sendLog(log);

    JudgeStruct judge_struct = judge;
    judge_struct.who = effect.to;
    room->judge(judge_struct);

    if(judge_struct.isBad()){
        takeEffect(effect.to);
        if(room->getCardOwner(getEffectiveId()) == NULL)
        {
            CardMoveReason reason(CardMoveReason::S_REASON_NATURAL_ENTER, QString());
            room->throwCard(this, reason, NULL);
        }
    }else if(movable){
        onNullified(effect.to);
    }
    if (!movable)
    {
        CardMoveReason reason(CardMoveReason::S_REASON_NATURAL_ENTER, QString());
        room->throwCard(this, reason, NULL);
    }
}

void DelayedTrick::onNullified(ServerPlayer *target) const{
    Room *room = target->getRoom();
    if(movable){
        QList<ServerPlayer *> players = room->getOtherPlayers(target);
        players << target;

        foreach(ServerPlayer *player, players){
            if(player->containsTrick(objectName()))
                continue;

            const ProhibitSkill *skill = room->isProhibited(target, player, this);
            if(skill){
                LogMessage log;
                log.type = "#SkillAvoid";
                log.from = player;
                log.arg = skill->objectName();
                log.arg2 = objectName();
                room->sendLog(log);

                room->broadcastSkillInvoke(skill->objectName());
                continue;
            }

            CardMoveReason reason(CardMoveReason::S_REASON_TRANSFER, target->objectName(), QString(), this->getSkillName(), QString());
            room->moveCardTo(this, target, player, Player::PlaceDelayedTrick, reason, true);
            break;
        }
    }
    else{
        CardMoveReason reason(CardMoveReason::S_REASON_NATURAL_ENTER, target->objectName());
        room->throwCard(this, reason, NULL);
    }
}

Weapon::Weapon(Suit suit, int number, int range)
    :EquipCard(suit, number), range(range)
{
}

int Weapon::getRange() const{
    return range;
}

QString Weapon::getSubtype() const{
    return "weapon";
}

EquipCard::Location Weapon::location() const{
    return WeaponLocation;
}

QString Weapon::label() const{
    return QString("%1(%2)").arg(getName()).arg(range);
}

QString Weapon::getCommonEffectName() const{
    return "weapon";
}

QString Armor::getSubtype() const{
    return "armor";
}

EquipCard::Location Armor::location() const{
    return ArmorLocation;
}

QString Armor::label() const{
    return getName();
}

QString Armor::getCommonEffectName() const{
    return "armor";
}

Horse::Horse(Suit suit, int number, int correct)
    :EquipCard(suit, number), correct(correct)
{
}

int Horse::getCorrect() const{
    return correct;
}

void Horse::onInstall(ServerPlayer *) const{

}

void Horse::onUninstall(ServerPlayer *) const{

}

QString Horse::label() const{
    QString format;

    if(correct > 0)
        format = "%1(+%2)";
    else
        format = "%1(%2)";

    return format.arg(getName()).arg(correct);
}

QString Horse::getCommonEffectName() const{
    return "horse";
}

OffensiveHorse::OffensiveHorse(Card::Suit suit, int number, int correct)
    :Horse(suit, number, correct)
{

}

QString OffensiveHorse::getSubtype() const{
    return "offensive_horse";
}

DefensiveHorse::DefensiveHorse(Card::Suit suit, int number, int correct)
    :Horse(suit, number, correct)
{

}

QString DefensiveHorse::getSubtype() const{
    return "defensive_horse";
}

EquipCard::Location Horse::location() const{
    if(correct > 0)
        return DefensiveHorseLocation;
    else
        return OffensiveHorseLocation;
}


StandardPackage::StandardPackage()
    :Package("standard")
{
    addGenerals();

    patterns["."] = new ExpPattern(".|.|.|hand");
    patterns[".S"] = new ExpPattern(".|spade|.|hand");
    patterns[".C"] = new ExpPattern(".|club|.|hand");
    patterns[".H"] = new ExpPattern(".|heart|.|hand");
    patterns[".D"] = new ExpPattern(".|diamond|.|hand");

    patterns[".black"] = new ExpPattern(".|.|.|hand|black");
    patterns[".red"] = new ExpPattern(".|.|.|hand|red");

    patterns[".."] = new ExpPattern(".");
    patterns["..S"] = new ExpPattern(".|spade");
    patterns["..C"] = new ExpPattern(".|club");
    patterns["..H"] = new ExpPattern(".|heart");
    patterns["..D"] = new ExpPattern(".|diamond");

    patterns[".Basic"] = new ExpPattern("BasicCard");
    patterns[".Trick"] = new ExpPattern("TrickCard");
    patterns[".Equip"] = new ExpPattern("EquipCard");

    patterns[".Weapon"] = new ExpPattern("Weapon");
    patterns["slash"] = new ExpPattern("Slash");
    patterns["jink"] = new ExpPattern("Jink");
    patterns["peach"] = new  ExpPattern("Peach");
    patterns["nullification"] = new ExpPattern("Nullification");
    patterns["peach+analeptic"] = new ExpPattern("Peach,Analeptic");
}

ADD_PACKAGE(Standard)
