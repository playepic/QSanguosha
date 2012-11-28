#ifndef SPPACKAGE_H
#define SPPACKAGE_H

#include "package.h"
#include "card.h"
#include "standard.h"

class SPPackage: public Package{
    Q_OBJECT

public:
    SPPackage();
};

class WeidiCard: public SkillCard{
    Q_OBJECT

public:
    Q_INVOKABLE WeidiCard();

    virtual void onUse(Room *room, const CardUseStruct &card_use) const;
};

class YuanhuCard: public SkillCard {
    Q_OBJECT

public:
    Q_INVOKABLE YuanhuCard();

    virtual bool targetFilter(const QList<const Player *> &targets, const Player *to_select, const Player *Self) const;
    virtual void onUse(Room *room, const CardUseStruct &card_use) const;
    virtual void onEffect(const CardEffectStruct &effect) const;
};

class SPCardPackage: public Package{
    Q_OBJECT

public:
    SPCardPackage();
};

class SPMoonSpear:public Weapon{
    Q_OBJECT

public:
    Q_INVOKABLE SPMoonSpear(Card::Suit suit = Diamond, int number = 12);
};

#endif // SPPACKAGE_H
