#ifndef DASHBOARD_H
#define DASHBOARD_H

#include "QSanSelectableItem.h"
#include "qsanbutton.h"
#include "carditem.h"
#include "player.h"
#include "skill.h"
#include "sprite.h"
#include "protocol.h"
#include "TimedProgressBar.h"
#include "GenericCardContainerUI.h"
#include "pixmapanimation.h"

#include <QPushButton>
#include <QComboBox>
#include <QGraphicsLinearLayout>
#include <QLineEdit>
#include <QProgressBar>
#include <QMutex>
#include <QPropertyAnimation>


class Dashboard : public PlayerCardContainer
{
    Q_OBJECT
public:
    Dashboard(QGraphicsItem *button_widget);
    virtual QRectF boundingRect() const;
    void setWidth(int width);
    int getMiddleWidth();
    inline QRectF getAvatarArea()
    {
        QRectF rect;
        rect.setSize(_dlayout->m_avatarArea.size());
        QPointF topLeft = mapFromItem(_getAvatarParent(), _dlayout->m_avatarArea.topLeft());
        rect.moveTopLeft(topLeft);
        return rect;
    }
    
    void hideControlButtons();
    void showControlButtons();

    QSanSkillButton *removeSkillButton(const QString &skillName);
    QSanSkillButton *addSkillButton(const QString &skillName);
    bool isAvatarUnderMouse();
    
    void highlightEquip(QString skillName, bool hightlight);

    void setTrust(bool trust);    
    void selectCard(const QString &pattern, bool forward = true, bool multiple = false);
    void selectEquip(int position);
    void useSelected();
    const Card *getSelected() const;
    void unselectAll();
    void hideAvatar();

    void disableAllCards();
    void enableCards();
    void enableAllCards();

    void adjustCards(bool playAnimation = true);
    
    virtual QGraphicsItem* getMouseClickReceiver();

    QList<CardItem*> removeCardItems(const QList<int> &card_ids, Player::Place place);
    virtual QList<CardItem*> cloneCardItems(QList<int> card_ids);

    // pending operations
    void startPending(const ViewAsSkill *skill);
    void stopPending();
    void updatePending();
    const ViewAsSkill *currentSkill() const;
    const Card *pendingCard() const;

    void selectCard(CardItem* item, bool isSelected);

    int getButtonWidgetWidth() const;
    int getTextureWidth() const;

    int width();
    int height();

    static const int S_PENDING_OFFSET_Y = -25;
public slots:
    void sortCards(bool doAnmiation = true);
    void reverseSelection();
    void skillButtonActivated();
    void skillButtonDeactivated();
    void selectAll();

protected:
    void _createExtraButtons();
    virtual void _adjustComponentZValues();
    virtual void addHandCards(QList<CardItem*> &cards);
    virtual QList<CardItem*> removeHandCards(const QList<int> &cardIds);

    // initialization of _m_layout is compulsory for children classes.
    inline virtual QGraphicsItem* _getEquipParent() { return _m_leftFrame; }
    inline virtual QGraphicsItem* _getDelayedTrickParent() { return _m_leftFrame; }
    inline virtual QGraphicsItem* _getAvatarParent() { return _m_rightFrame; }
    inline virtual QGraphicsItem* _getMarkParent() { return _m_floatingArea; }
    inline virtual QGraphicsItem* _getPhaseParent() { return _m_floatingArea; }
    inline virtual QGraphicsItem* _getRoleComboBoxParent() { return _m_rightFrame; }
    inline virtual QGraphicsItem* _getPileParent() { return _m_rightFrame; }
    inline virtual QGraphicsItem* _getProgressBarParent() { return _m_floatingArea; }
    inline virtual QGraphicsItem* _getFocusFrameParent() { return _m_rightFrame; }
    inline virtual QGraphicsItem* _getDeathIconParent() { return _m_middleFrame;}
    inline virtual QString getResourceKeyName() { return QSanRoomSkin::S_SKIN_KEY_DASHBOARD; }
    
    bool _addCardItems(QList<CardItem*> &card_items, const CardsMoveStruct &moveInfo);
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent);
    void _addHandCard(CardItem* card_item);    
    void _adjustCards();
    void _adjustCards(const QList<CardItem *> &list, int y);

    int _m_width;
    // sync objects
    QMutex m_mutex;
    QMutex m_mutexEnableCards;
    
    QSanButton *m_btnReverseSelection;
    QSanButton *m_btnSortHandcard;
    QGraphicsPixmapItem *_m_leftFrame, *_m_middleFrame, *_m_rightFrame;    
    // we can not draw bg directly _m_rightFrame because then it will always be
    // under avatar (since it's avatar's parent).
    QGraphicsPixmapItem *_m_rightFrameBg;
    QGraphicsItem *button_widget;
        
    CardItem *selected;
    QList<CardItem*> m_handCards;

    QGraphicsRectItem *trusting_item;
    QGraphicsSimpleTextItem *trusting_text;

    QSanInvokeSkillDock* _m_skillDock;
    const QSanRoomSkin::DashboardLayout* _dlayout;

    //for animated effects
    EffectAnimation *animations;

    // for parts creation
    void _createLeft();
    void _createRight();
    void _createMiddle();
    void _updateFrames();

    // for pendings
    QList<CardItem *> pendings;
    const Card *pending_card;
    const ViewAsSkill *view_as_skill;
    const FilterSkill *filter;
    
    // for equip skill/selections
    PixmapAnimation* _m_equipBorders[4];
    QSanSkillButton* _m_equipSkillBtns[4];
    bool _m_isEquipsAnimOn[4];
    QList<QSanSkillButton*> _m_button_recycle;

    void _createEquipBorderAnimations();
    void _setEquipBorderAnimation(int index, bool turnOn);

    void drawEquip(QPainter *painter, const CardItem *equip, int order);
    void setSelectedItem(CardItem *card_item);

protected slots:
    virtual void _onEquipSelectChanged();
    
private slots:
    void onCardItemClicked();
    void onCardItemThrown();
    void onCardItemHover();
    void onCardItemLeaveHover();
    void onMarkChanged();

signals:
    void card_selected(const Card *card);
    void card_to_use();
    void progressBarTimedOut();
};

#endif // DASHBOARD_H
