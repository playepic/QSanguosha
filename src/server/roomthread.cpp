#include "roomthread.h"
#include "room.h"
#include "engine.h"
#include "gamerule.h"
#include "scenerule.h"
#include "scenario.h"
#include "ai.h"
#include "jsonutils.h"
#include "settings.h"
#include "standard.h"

#include <QTime>
#include <json/json.h>

#ifdef QSAN_UI_LIBRARY_AVAILABLE
#pragma message WARN("UI elements detected in server side!!!")
#endif

using namespace QSanProtocol::Utils;

LogMessage::LogMessage()
    :from(NULL)
{
}

QString LogMessage::toString() const{
    QStringList tos;
    foreach(ServerPlayer *player, to)
        if (player != NULL) tos << player->objectName();

    return QString("%1:%2->%3:%4:%5:%6")
            .arg(type)
            .arg(from ? from->objectName() : "")
            .arg(tos.join("+"))
            .arg(card_str).arg(arg).arg(arg2);
}

DamageStruct::DamageStruct()
    :from(NULL), to(NULL), card(NULL), damage(1), nature(Normal), chain(false), transfer(false), trigger_chain(false)
{
}

CardEffectStruct::CardEffectStruct()
    :card(NULL), from(NULL), to(NULL), multiple(false)
{
}

SlashEffectStruct::SlashEffectStruct()
    :slash(NULL), jink(NULL), from(NULL), to(NULL), drank(false), nature(DamageStruct::Normal)
{
}

DyingStruct::DyingStruct()
    :who(NULL), damage(NULL)
{
}

RecoverStruct::RecoverStruct()
    :recover(1), who(NULL), card(NULL)
{

}

PindianStruct::PindianStruct()
    :from(NULL), to(NULL), from_card(NULL), to_card(NULL)
{

}

bool PindianStruct::isSuccess() const{
    return from_card->getNumber() > to_card->getNumber();
}

JudgeStructPattern::JudgeStructPattern(){
}

bool JudgeStructPattern::match(const Player *player, const Card *card) const{
    if(pattern.isEmpty())
        return false;

    if(isRegex){
        QString class_name = card->getClassName();
        Card::Suit suit = card->getSuit();

        QString number = card->getNumberString();
        QString card_str = QString("%1:%2:%3").arg(class_name).arg(Card::Suit2String(suit)).arg(number);

        return QRegExp(pattern).exactMatch(card_str);
    }else{
        const CardPattern *card_pattern = Sanguosha->getPattern(pattern);
        return card_pattern && card_pattern->match(player, card);
    }
}

JudgeStructPattern &JudgeStructPattern::operator =(const QRegExp &rx){
    pattern = rx.pattern();
    isRegex = true;

    return *this;
}

JudgeStructPattern &JudgeStructPattern::operator =(const QString &str){
    pattern = str;
    isRegex = false;

    return *this;
}

// members should be initilized the same order as defined
JudgeStruct::JudgeStruct()
    : negative(false), play_animation(false), who(NULL), card(NULL),
    good(true), time_consuming(false), _m_result(TRIAL_RESULT_UNKNOWN)
{

}

bool JudgeStruct::isEffected(){
    if(!negative)
        return isGood();
    else
        return isBad();
}

void JudgeStruct::updateResult()
{
    bool effected = (good == pattern.match(who, card));
    if (effected) _m_result = TRIAL_RESULT_GOOD;
    else _m_result = TRIAL_RESULT_BAD;
}

bool JudgeStruct::isGood() const
{
    Q_ASSERT(_m_result != TRIAL_RESULT_UNKNOWN);
    return _m_result == TRIAL_RESULT_GOOD;
}

bool JudgeStruct::isGood(const Card *card) const
{
    Q_ASSERT(card);
    return good == pattern.match(who, card);
}

bool JudgeStruct::isBad() const
{
    return ! isGood();
}

PhaseChangeStruct::PhaseChangeStruct()
    :from(Player::NotActive), to(Player::NotActive)
{}

CardUseStruct::CardUseStruct()
    :card(NULL), from(NULL)
{
}

bool CardUseStruct::isValid(const QString &pattern) const{
    return card != NULL;
    /*if (card == NULL) return false;
    if (!card->getSkillName().isEmpty())
    {
        bool validSkill = false;
        QString skillName = card->getSkillName();
        QSet<const Skill *> skills = from->getVisibleSkills();
        for (int i = 0; i < 4; i++)
        {
            const EquipCard* equip = from->getEquip(i);
            if (equip == NULL) continue;
            const Skill* skill = Sanguosha->getSkill(equip);
            if (skill)
            {
                skills.insert(skill);
            }
        }
        foreach (const Skill *skill, skills)
        {
            if (skill->objectName() != skillName) continue;
            const ViewAsSkill *vsSkill = ViewAsSkill::parseViewAsSkill(skill);
            if (vsSkill)
            {
                if (!vsSkill->isAvailable(from, m_reason, pattern)) return false;
                else 
                {
                    validSkill = true;
                    break;
                }                
            }
            else if (skill->getFrequency() == Skill::Wake)
            {
                bool valid = (from->getMark(skill->objectName()) > 0);
                if (!valid) return false;
                else validSkill = true;
            }
            else return false;
        }
        if (!validSkill) return false;
    }
    if (card->targetFixed()) return true;
    else {
        QList<const Player *> targets;
        foreach (const ServerPlayer* player, to)
            targets.push_back(player);
        return card->targetsFeasible(targets, from);
    }*/
}

bool CardUseStruct::tryParse(const Json::Value &usage, Room *room){
    if (usage.size() < 2 || !usage[0].isString() || !usage[1].isArray())
        return false;

    card = Card::Parse(toQString(usage[0]));

    const Json::Value &targets = usage[1];

    for (unsigned int i = 0; i < targets.size(); i++)
    {
        if (!targets[i].isString()) return false;
        this->to << room->findChild<ServerPlayer *>(toQString(targets[i]));
    }
    return true;
}

void CardUseStruct::parse(const QString &str, Room *room){
    QStringList words = str.split("->", QString::KeepEmptyParts);
    
    Q_ASSERT(words.length() == 1 || words.length() == 2);

    QString card_str = words.at(0);
    QString target_str = ".";
    
    //@todo: it's observed that when split on "a->."
    // only returns one QString, which is "a". Suspect
    // it's a bug with QT regular expression. Figure out
    // the cause of the issue.
    if (words.length() == 2 && !words.at(1).isEmpty()) 
        target_str = words.at(1);    

    card = Card::Parse(card_str);

    if(target_str != "."){
        QStringList target_names = target_str.split("+");
        foreach(QString target_name, target_names)
            to << room->findChild<ServerPlayer *>(target_name);
    }
}

QString EventTriplet::toString() const{
    return QString("event = %1, room = %2, target = %3[%4], data = %5[%6]")
            .arg(_m_event)
            .arg(_m_room->getId())
            .arg(_m_target->objectName()).arg(_m_target->getGeneralName())
            .arg(_m_data->toString()).arg(_m_data->typeName());
}

//@todo: setParent here is illegitimate in QT and is equivalent to calling
// setParent(NULL). Find another way to do it if we really need a parent.
RoomThread::RoomThread(Room *room)
    :room(room)
{
    room->getRoomState()->reset();
}

void RoomThread::addPlayerSkills(ServerPlayer *player, bool invoke_game_start){
    QVariant void_data;
    bool invoke_verify = false;

    foreach(const TriggerSkill *skill, player->getTriggerSkills()){
        addTriggerSkill(skill);

        if(invoke_game_start && skill->getTriggerEvents().contains(GameStart))
            invoke_verify = true;
    }

    //We should make someone trigger a whole GameStart event instead of trigger a skill only.
    if(invoke_verify)
        trigger(GameStart, room, player, void_data);
}

void RoomThread::constructTriggerTable(){
    foreach(ServerPlayer *player, room->getPlayers()){
        addPlayerSkills(player, true);
    }    
}

void RoomThread::run3v3(){
    QList<ServerPlayer *> warm, cool;
    foreach(ServerPlayer *player, room->m_players){
        switch(player->getRoleEnum()){
        case Player::Lord: warm.prepend(player); break;
        case Player::Loyalist: warm.append(player); break;
        case Player::Renegade: cool.prepend(player); break;
        case Player::Rebel: cool.append(player); break;
        }
    }

    QString order = room->askForOrder(cool.first());
    QList<ServerPlayer *> *first, *second;

    if(order == "warm"){
        first = &warm;
        second = &cool;
    }else{
        first = &cool;
        second = &warm;
    }

    action3v3(first->first());

    forever{
        qSwap(first, second);

        QList<ServerPlayer *> targets;
        foreach(ServerPlayer *player, *first){
            if(!player->hasFlag("actioned") && player->isAlive())
                targets << player;
        }

        ServerPlayer *to_action = room->askForPlayerChosen(first->first(), targets, "3v3-action");
        if(to_action){
            action3v3(to_action);

            if(to_action != first->first()){
                ServerPlayer *another;
                if(to_action == first->last())
                    another = first->at(1);
                else
                    another = first->last();

                if(!another->hasFlag("actioned") && another->isAlive())
                    action3v3(another);
            }
        }
    }
}

void RoomThread::action3v3(ServerPlayer *player){
    room->setCurrent(player);
    trigger(TurnStart, room, room->getCurrent());
    room->setPlayerFlag(player, "actioned");

    bool all_actioned = true;
    foreach(ServerPlayer *player, room->m_alivePlayers){
        if(!player->hasFlag("actioned")){
            all_actioned = false;
            break;
        }
    }

    if(all_actioned){
        foreach(ServerPlayer *player, room->m_alivePlayers){
            room->setPlayerFlag(player, "-actioned");
        }
    }
}

void RoomThread::run(){
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    Sanguosha->registerRoom(room);
    GameRule *game_rule;
    if(room->getMode() == "04_1v3")
        game_rule = new HulaoPassMode(this);
    else if(Config.EnableScene)    //changjing
        game_rule = new SceneRule(this);    //changjing
    else
        game_rule = new GameRule(this);

    addTriggerSkill(game_rule);
    if (Config.EnableBasara) addTriggerSkill(new BasaraMode(this));

    if(room->getScenario() != NULL){
        const ScenarioRule *rule = room->getScenario()->getRule();
        if(rule)
            addTriggerSkill(rule);
    }

    // start game, draw initial 4 cards
    try {        
        trigger(GameStart, (Room*)room, NULL);
        constructTriggerTable();

        if(room->mode == "06_3v3"){
            run3v3();
        }else if(room->getMode() == "04_1v3"){
            ServerPlayer *shenlvbu = room->getLord();
            try {            
                QList<ServerPlayer *> league = room->getPlayers();
                league.removeOne(shenlvbu);

                forever{
                    foreach(ServerPlayer *player, league){
                        if(player->hasFlag("actioned"))
                            room->setPlayerFlag(player, "-actioned");
                    }

                    foreach(ServerPlayer *player, league){
                        room->setCurrent(player);
                        trigger(TurnStart, room, room->getCurrent());

                        if(!player->hasFlag("actioned"))
                            room->setPlayerFlag(player, "actioned");                                       

                        if(player->isAlive()){
                            room->setCurrent(shenlvbu);
                            trigger(TurnStart, room, room->getCurrent());
                        }
                    }
                }
            }
            catch (TriggerEvent triggerEvent)
            {
                trigger(triggerEvent, (Room*)room, NULL);
                foreach(ServerPlayer *player, room->getPlayers()){
                    if(player != shenlvbu){
                        if(player->hasFlag("actioned"))
                            room->setPlayerFlag(player, "-actioned");

                        if(player->getPhase() != Player::NotActive){

                            trigger(EventPhaseEnd, room, player);

                            player->changePhase(player->getPhase(), Player::NotActive);
                        }
                    }
                }

                room->setCurrent(shenlvbu);

                forever{
                    trigger(TurnStart, room, room->getCurrent());
                    room->setCurrent(room->getCurrent()->getNext());
                }
            }
        }else{
            if(room->getMode() == "02_1v1")
                room->setCurrent(room->getPlayers().at(1));

            forever {
                trigger(TurnStart, room, room->getCurrent());
                if (room->isFinished()) break;
                room->setCurrent(room->getCurrent()->getNextAlive());
            }
        }
    } catch (TriggerEvent triggerEvent) {
        if (triggerEvent == GameFinished){
            Sanguosha->unregisterRoom();
            return;
        }
        else Q_ASSERT(false);
    }
}

static bool CompareByPriority(const TriggerSkill *a, const TriggerSkill *b){
    if(a->getPriority() == b->getPriority())
        return b->inherits("WeaponSkill") || b->inherits("ArmorSkill");
    return a->getPriority() > b->getPriority();
}

bool RoomThread::trigger(TriggerEvent triggerEvent, Room* room, ServerPlayer *target, QVariant &data){
    // Q_ASSERT(QThread::currentThread() == this);

    // push it to event stack
    EventTriplet triplet(triggerEvent, room, target, &data);
    event_stack.push_back(triplet);

    bool broken = false;
    QList<const TriggerSkill*> triggered;
    const QList<const TriggerSkill*> &skills = skill_table[triggerEvent];
    for (int i = 0; i < skills.size(); i++)
    {
        const TriggerSkill *skill = skills[i];
        if (skill->triggerable(target) && !triggered.contains(skill)) {
            triggered.append(skill);
            broken = skill->trigger(triggerEvent, room, target, data);
            if(broken)
                break;
        }
    }

    if(target){
        foreach(AI *ai, room->ais){
            ai->filterEvent(triggerEvent, target, data);
        }
    }

    // pop event stack
    event_stack.pop_back();

    return broken;
}

const QList<EventTriplet> *RoomThread::getEventStack() const{
    return &event_stack;
}

bool RoomThread::trigger(TriggerEvent triggerEvent, Room* room, ServerPlayer *target){
    QVariant data;
    return trigger(triggerEvent, room, target, data);
}

void RoomThread::addTriggerSkill(const TriggerSkill *skill){
    if(skill == NULL || skillSet.contains(skill->objectName()))
        return;

    skillSet << skill->objectName();

    QList<TriggerEvent> events = skill->getTriggerEvents();
    foreach(TriggerEvent triggerEvent, events){
        QList<const TriggerSkill *> &table = skill_table[triggerEvent];

        table << skill;
        qStableSort(table.begin(), table.end(), CompareByPriority);
    }

    if(skill->isVisible()){
        foreach(const Skill *skill, Sanguosha->getRelatedSkills(skill->objectName())){
            const TriggerSkill *trigger_skill = qobject_cast<const TriggerSkill *>(skill);
            if (trigger_skill)
                addTriggerSkill(trigger_skill);
        }
    }
}

void RoomThread::delay(unsigned long secs){
    if(room->property("to_test").toString().isEmpty()&& Config.AIDelay>0)
        msleep(secs);
}
