#ifndef ENEMY_H
#define ENEMY_H

#include <QPixmap>
#include <QRect>
#include "gameheaders/gameobj.h"
#include "gameheaders/bullet.h"
#include "gameheaders/hero.h"

class Enemy:public GameObj
{
public:
    Enemy();
    void init(qreal maxhp);
    void setPos(qreal x=0,qreal y=0,qreal facex=0,qreal facey=-1);
    void setHp(qreal value);
    bool isColliding(Bullet *target);//判断是否与target相撞，两者距离较近时再调用以优化
    bool isColliding(Hero *target);
    qreal maxhp=0;
    qreal hp=0;
    int smallscorecount=0;
    int bigscorecount=0;
    int smallpowercount=0;
    int bigpowercount=0;
};

class Boss:public Enemy{//boss
public:
    Boss();
    void Init(qreal maxhp,int maxstage,QString size,QString armor,QString species,QString name,qreal x,qreal y,qreal facex=0,qreal facey=-1);
    void extraInit(int maxstage,QString size,QString armor,QString species,QString name);
    virtual void Draw(QPainter* painter);
    int stage;
    int maxstage;
    qreal stagelefttime;
    QString name;
};

class Zako:public Enemy{//杂鱼
public:
    Zako();
    void Init(qreal maxhp,QString size,QString armor,QString species,qreal x,qreal y,qreal facex=0,qreal facey=-1);
    void extraInit(QString size,QString armor,QString species);
};

#endif // ENEMY_H
