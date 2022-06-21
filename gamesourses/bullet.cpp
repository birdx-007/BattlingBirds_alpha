#include "gameheaders/bullet.h"

Bullet::Bullet(GameObj *p)
{
    this->init(p);
}

void Bullet::init(GameObj* p)
{
    //贴图、碰撞箱等在具体类中初始化
    this->parent=p;
    this->party=p->type;
    //this->setPos(x,y,facex,facey);
    this->type=QString("bullet");
}

void Bullet::setPos(qreal x, qreal y, qreal facex, qreal facey)
{
    this->X=x;
    this->Y=y;
    this->collibox.moveTo(this->X+this->texture.width()/2*Width/1920-colliX/2,this->Y+this->texture.height()/2*Width/1920-colliY/2);
    this->faceX=facex;
    this->faceY=facey;
}

HeroBullet::HeroBullet(GameObj *p, int hnum, bool islow, qreal x, qreal y, qreal facex, qreal facey):Bullet(p)
{
    //先确定碰撞箱才能使用setpos
    this->extraInitForHero(hnum,islow);
    this->setPos(x,y,facex,facey);
}

void HeroBullet::extraInitForHero(int hnum, bool islow)
{
    //贴图
    this->setTexture(QString(":/myimages/res/herobullet%1_%2.png").arg(hnum).arg(islow?2:1));
    //碰撞箱
    this->setCollibox(0.5*this->texture.width()*Width/1920,0.5*this->texture.height()*Width/1920);
    //杂项
    switch (hnum) {
    case 0:{this->speed=islow?30:50;
        this->istracking=islow?true:false;
        this->ap=islow?3:5;
        this->dspeed=islow?5:0;
        break;}
    case 1:{this->speed=islow?45:40;
        this->istracking=islow?false:false;
        this->ap=islow?3.5:3.5;
        this->dspeed=islow?0:0;
        break;}
    case 2:{this->speed=islow?40:0;
        this->istracking=islow?false:true;
        this->ap=islow?3.5:5;
        this->dspeed=islow?0:0.5;
        break;}
    default:{this->speed=islow?50:40;
        this->istracking=islow?false:false;
        this->ap=islow?5:3;
        this->dspeed=islow?0:0;
        break;}
    }
}

EnemyBullet::EnemyBullet(GameObj *p, QString color, QString shape, qreal x, qreal y, qreal facex, qreal facey,qreal speed,qreal dspeed):Bullet(p)
{
    this->extraInitForEnemy(color,shape,speed,dspeed);
    this->setPos(x,y,facex,facey);
}

void EnemyBullet::extraInitForEnemy(QString color, QString shape,qreal speed,qreal dspeed)
{
    //贴图
    this->setTexture(QString(":/myimages/res/%1_%2.png").arg(shape).arg(color));
    //碰撞箱
    this->setCollibox(0.4*this->texture.width()*Width/1920,0.4*this->texture.height()*Width/1920);
    //移动属性
    this->speed=speed;
    this->dspeed=dspeed;
    this->istracking=false;
}

bool EnemyBullet::isColliding(GameObj *target)
{
    bool condition_1=this->collibox.contains(target->collibox.topLeft());
    bool condition_2=this->collibox.contains(target->collibox.topRight());
    bool condition_3=this->collibox.contains(target->collibox.bottomLeft());
    bool condition_4=this->collibox.contains(target->collibox.bottomRight());
    if(target->isValid&&(condition_1||condition_2||condition_3||condition_4))
    {
        this->isValid=false;
        if(!target->isGhost)
            target->isValid=false;
        return true;
    }
    return false;
}
