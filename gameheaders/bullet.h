#ifndef BULLET_H
#define BULLET_H
#include "gameheaders/gameobj.h"

class Bullet : public GameObj
{
public:
    Bullet(GameObj* p);
    void init(GameObj* p);
    void setPos(qreal x,qreal y,qreal facex=0,qreal facey=-1);
    //bool isColliding(GameObj* target);//判断是否与target相撞，两者距离较近时再调用以优化
    //根据弹幕游戏设计原则的“判定写在复杂形状里”的原则，不统一写成总类的函数
    GameObj* parent;
    QString party;//阵营
    bool istracking;//是否为诱导追踪弹
    qreal ap;//攻击力
};

class HeroBullet:public Bullet
{
public:
    HeroBullet(GameObj* p,int hnum,bool islow,qreal x,qreal y,qreal facex=0,qreal facey=-1);
    void extraInitForHero(int hnum,bool islow);//传入自机组号及高低速以初始化贴图及碰撞箱等
};

class EnemyBullet:public Bullet
{
public:
    EnemyBullet(GameObj* p,QString color,QString shape,qreal x,qreal y,qreal facex=0,qreal facey=-1,qreal speed=10.0,qreal dspeed=0.0);
    void extraInitForEnemy(QString color,QString shape,qreal speed,qreal dspeed);
    bool isColliding(GameObj* target);//判断是否与target相撞，两者距离较近时再调用以优化
};
#endif // BULLET_H
