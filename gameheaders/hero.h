#ifndef HERO_H
#define HERO_H

#include <QPixmap>
#include <QRect>
#include <QSoundEffect>
#include "gameheaders/gameobj.h"
#include "movevector.h"

class Hero:public GameObj
{
public:
    Hero();
    void init(int herochoice);
    void Revive(int leftplayers,qreal leftpower);//复活
    virtual void setPos(qreal x,qreal y,qreal facex=0,qreal facey=-1);
    virtual void Draw(QPainter *painter);
    void changePattern(int pattern);//高低速贴图切换
    int heronum;//自机组号0123
    qreal highspeed;
    qreal lowspeed;
    qreal power;//火力
    int players;//残机数
    int spells;//强力技数
    int spellcount;//强力技有效时刻数
    int ghostcount;//非强力技无敌有效时刻数
    bool isShooting;
    bool isTryingActivateSpell;
    bool canActivateSpell;
    bool isAbsorbingProps;
    MoveVector vector;

    QSoundEffect shootEffect;
};
#endif // HERO_H
