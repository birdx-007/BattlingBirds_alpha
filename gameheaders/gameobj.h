#ifndef GAMEOBJ_H
#define GAMEOBJ_H

#include <QPixmap>
#include <QPainter>
#include <QRect>
#include <QFont>
#include <QtMath>
#include <QString>
#include "constant.h"
//#include "mainwidget.h"

extern int Width;
extern int Height;
extern int Count;
extern int Idx;
extern int Level;
extern int Difficulty;

class GameObj
{
public:
    explicit GameObj();
    virtual void setPos(qreal x,qreal y,qreal facex=0,qreal facey=-1);//xy均为屏幕上的真实坐标，不再进行缩放
    virtual void Draw(QPainter* painter);
    void setCollibox(qreal collix,qreal colliy);
    void setTexture(QString picdir);
    qreal faceXYtoAngle();
    static qreal getMDistance(GameObj* a,GameObj* b);//返回曼哈顿距离
    bool isValid=true;//是否有效
    bool isGhost=false;//是否无视其他物体判定
    qreal X=0;
    qreal Y=0;
    qreal faceX=0;//朝向向量的X分量，无需归一化
    qreal faceY=-1;//朝向向量的Y分量，无需归一化
    qreal colliX=0;//碰撞箱x宽度
    qreal colliY=0;//碰撞箱y宽度
    QPixmap texture;//贴图
    QRect collibox;//碰撞箱
    QString type;
    int guid=0;
    //运动相关
    qreal speed=0;//速度
    qreal anglespeed=0;//角速度，顺时针为正
    qreal dspeed=0;//加速度
    qreal danglespeed=0;//角加速度
    qreal targetx=0;//某段运动目标x
    qreal targety=0;//某段运动目标y
    int birthcount=0;//诞生时刻
    int tmpcount=0;//某段运动起始时刻
};

#endif // GAMEOBJ_H
