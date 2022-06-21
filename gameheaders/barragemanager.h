#ifndef BARRAGEMANAGER_H
#define BARRAGEMANAGER_H
#include <QObject>
#include <QtMath>
#include "gameheaders/bulletmanager.h"
#include "gameheaders/enemymanager.h"

class BarrageManager : public QObject
{
    Q_OBJECT
public:
    explicit BarrageManager(QObject *parent = nullptr);
    BulletManager* bulletmanager;
    EnemyManager* enemymanager;
    void Init(BulletManager* bm,EnemyManager* em);
    void AddOneCircle(GameObj *parent,qreal center_x,qreal center_y,int num_in_circle,QString color,QString shape,qreal speed=10.0,qreal dspeed=0.0,qreal biasangle=0);//环状弹幕
    void AddOneAim(GameObj *parent,GameObj *target,qreal init_x,qreal init_y,int num_of_line,qreal angle,QString color,QString shape,qreal speed=10.0,qreal dspeed=0.0,qreal biasangle=0);//自机狙
    void AddOneRandomCircle(GameObj *parent,qreal center_x,qreal center_y,int num_in_circle,QString color,QString shape,qreal maxspeed=10.0,qreal minspeed=1.0,qreal maxdspeed=0.0,qreal mindspeed=0.0);//随机环状弹幕
    void AddOneRandomRain(GameObj *parent,QString x_or_y,qreal init_x_or_y,int num,qreal angle,QString color,QString shape,qreal maxspeed=10.0,qreal minspeed=1.0,qreal maxdspeed=0.0,qreal mindspeed=0.0);//随机降雨
    void AddOneRing(GameObj *parent,qreal center_x,qreal center_y,qreal angle,qreal radius,int num_in_ring,QString color,QString shape,qreal speed=10.0,qreal dspeed=0.0,qreal init_angle=0,qreal biasangle=0);//直线运动的环
    void AddOneLine(GameObj *parent,qreal init_x,qreal init_y,qreal angle,QString color,QString shape,qreal spacing=5.0,int num_in_line=5,qreal speed=10.0,qreal dspeed=0.0,qreal biasangle=0);//线段
    void AddOneLaser(GameObj *parent,qreal init_x,qreal init_y,int num_of_line,qreal init_angle,QString color,QString shape,qreal speed=0.0,qreal dspeed=0.0,qreal biasangle=0);//激光
signals:

};
#endif // BARRAGEMANAGER_H
