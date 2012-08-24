#include "lingpackage.h"
#include "general.h"
#include "skill.h"
#include "standard.h"
#include "client.h"
#include "carditem.h"
#include "engine.h"


LuoyiCard::LuoyiCard(){
    once = true;
    target_fixed = true;
}

void LuoyiCard::use(Room *, ServerPlayer *source, QList<ServerPlayer *> &) const{
    source->setFlags("luoyi");
}

class NeoLuoyi: public OneCardViewAsSkill{
public:
    NeoLuoyi():OneCardViewAsSkill("neoluoyi"){

    }

    virtual bool isEnabledAtPlay(const Player *player) const{
        return !player->hasUsed("LuoyiCard") && !player->isNude();
    }

    virtual bool viewFilter(const Card *card) const{
        return card->isKindOf("EquipCard");
    }

    virtual const Card *viewAs(const Card *originalCard) const{
        LuoyiCard *card = new LuoyiCard;
        card->addSubcard(originalCard);
        return card;
    }
};

NeoFanjianCard::NeoFanjianCard(){
    once = true;
}

void NeoFanjianCard::onEffect(const CardEffectStruct &effect) const{
    ServerPlayer *zhouyu = effect.from;
    ServerPlayer *target = effect.to;
    Room *room = zhouyu->getRoom();

    int card_id = room->askForCardChosen(zhouyu, zhouyu, "h", "neofanjian");
    room->broadcastSkillInvoke("fanjian");
    const Card *card = Sanguosha->getCard(card_id);
    Card::Suit suit = room->askForSuit(target, "neofanjian");

    LogMessage log;
    log.type = "#ChooseSuit";
    log.from = target;
    log.arg = Card::Suit2String(suit);
    room->sendLog(log);

    room->getThread()->delay();
    target->obtainCard(card);
    room->showCard(target, card_id);

    if(card->getSuit() != suit){
        DamageStruct damage;
        damage.card = NULL;
        damage.from = zhouyu;
        damage.to = target;

        room->damage(damage);
    }
}

class NeoFanjian:public ZeroCardViewAsSkill{
public:
    NeoFanjian():ZeroCardViewAsSkill("neofanjian"){

    }

    virtual bool isEnabledAtPlay(const Player *player) const{
        return !player->isKongcheng() && ! player->hasUsed("NeoFanjianCard");
    }

    virtual const Card *viewAs() const{
        return new NeoFanjianCard;
    }
};

class Yishi: public TriggerSkill{
public:
    Yishi():TriggerSkill("yishi"){
        events << DamageCaused;
    }

    virtual bool trigger(TriggerEvent, Room* room, ServerPlayer *player, QVariant &data) const{
        DamageStruct damage = data.value<DamageStruct>();

        if(damage.card && damage.card->isKindOf("Slash") && damage.card->getSuit() == Card::Heart &&
           !damage.chain && !damage.transfer && player->askForSkillInvoke(objectName(), data)){
		   
            room->broadcastSkillInvoke("yishi", 1);
            LogMessage log;
            log.type = "#Yishi";
            log.from = player;
            log.arg = objectName();
            log.to << damage.to;
            room->sendLog(log);
			if(!damage.to->isAllNude()){
                int card_id = room->askForCardChosen(player, damage.to, "hej", objectName());
			    if(room->getCardPlace(card_id) == Player::PlaceDelayedTrick)
                    room->broadcastSkillInvoke("yishi", 2);
                else if(room->getCardPlace(card_id) == Player::PlaceEquip)
                    room->broadcastSkillInvoke("yishi", 3);
                else
                    room->broadcastSkillInvoke("yishi", 4);
                CardMoveReason reason(CardMoveReason::S_REASON_EXTRACTION, player->objectName());
                room->obtainCard(player, Sanguosha->getCard(card_id), reason, room->getCardPlace(card_id) != Player::PlaceHand);
			}
            return true;
        }
        return false;
    }
};

class Zhulou:public PhaseChangeSkill{
public:
    Zhulou():PhaseChangeSkill("zhulou"){
    }

    virtual bool onPhaseChange(ServerPlayer *gongsun) const{
        Room *room = gongsun->getRoom();
        if(gongsun->getPhase() == Player::Finish && gongsun->askForSkillInvoke(objectName())){
            gongsun->drawCards(2);
            room->broadcastSkillInvoke("zhulou", qrand() % 2 + 1);
            if(!room->askForCard(gongsun, ".Weapon", "@zhulou-discard", QVariant(), CardDiscarded))
                room->loseHp(gongsun);
        }
        return false;
    }
};

class Tannang: public DistanceSkill{
public:
    Tannang():DistanceSkill("tannang")
    {
    }

    virtual int getCorrect(const Player *from, const Player *to) const{
        if(from->hasSkill(objectName()))
            return -from->getLostHp();
        else
            return 0;
    }
};

class NeoJushou: public PhaseChangeSkill{
public:
    NeoJushou():PhaseChangeSkill("neojushou"){

    }

    virtual bool onPhaseChange(ServerPlayer *target) const{
        if(target->getPhase() == Player::Finish){
            Room *room = target->getRoom();
            if(room->askForSkillInvoke(target, objectName())){
                target->drawCards(2+target->getLostHp());
                target->turnOver();

                room->broadcastSkillInvoke("jushou");
            }
        }

        return false;
    }
};

class NeoGanglie:public MasochismSkill{
public:
    NeoGanglie():MasochismSkill("neoganglie"){

    }

    virtual void onDamaged(ServerPlayer *xiahou, const DamageStruct &damage) const{
        ServerPlayer *from = damage.from;
        Room *room = xiahou->getRoom();
        QVariant source = QVariant::fromValue(from);

        if(from && from->isAlive() && room->askForSkillInvoke(xiahou, "neoganglie", source)){
            room->broadcastSkillInvoke("ganglie");

            JudgeStruct judge;
            judge.pattern = QRegExp("(.*):(heart):(.*)");
            judge.good = false;
            judge.reason = objectName();
            judge.who = xiahou;

            room->judge(judge);
            if(judge.isGood()){
                QStringList choicelist;
                choicelist << "damage";
                if (from->getHandcardNum() > 1)
                    choicelist << "throw";
                QString choice;
                if (choicelist.length() == 1)
                    choice = choicelist.first();
                else
                    choice = room->askForChoice(xiahou, "neoganglie", choicelist.join("+"));
                if(choice == "damage"){
                    DamageStruct damage;
                    damage.from = xiahou;
                    damage.to = from;

                    room->setEmotion(xiahou, "good");
                    room->damage(damage);
                }
                else
                     room->askForDiscard(from, objectName(), 2, 2);
            }else
                room->setEmotion(xiahou, "bad");
        }
    }
};

LingPackage::LingPackage()
    :Package("ling")
{

    General * neo_xuchu = new General(this, "neo_xuchu", "wei");
    neo_xuchu->addSkill(new NeoLuoyi);
    neo_xuchu->addSkill("#luoyi");

    General * neo_zhouyu = new General(this, "neo_zhouyu", "wu", 3);
    neo_zhouyu->addSkill("yingzi");
    neo_zhouyu->addSkill(new NeoFanjian);


    General * neo_guanyu = new General(this, "neo_guanyu", "shu");
    neo_guanyu->addSkill("wusheng");
    neo_guanyu->addSkill(new Yishi);

    General * neo_gongsunzan = new General(this, "neo_gongsunzan", "qun");
    neo_gongsunzan->addSkill("yicong");
    neo_gongsunzan->addSkill("#yicong_effect");
    neo_gongsunzan->addSkill(new Zhulou);


    General * neo_zhangfei = new General(this, "neo_zhangfei", "shu");
    neo_zhangfei->addSkill("paoxiao");
    neo_zhangfei->addSkill(new Tannang);

    General * neo_zhaoyun = new General(this, "neo_zhaoyun", "shu");
    neo_zhaoyun->addSkill("longdan");
    neo_zhaoyun->addSkill("yicong");
    neo_zhaoyun->addSkill("#yicong_effect");

    General * neo_caoren = new General(this, "neo_caoren", "wei");
    neo_caoren->addSkill(new NeoJushou);

    General * neo_xiahoudun = new General(this, "neo_xiahoudun", "wei");
    neo_xiahoudun->addSkill(new NeoGanglie);

    addMetaObject<LuoyiCard>();
    addMetaObject<NeoFanjianCard>();
}

ADD_PACKAGE(Ling)
