#include "gameheaders/prop.h"

Prop::Prop()
{

}

void Prop::init(int maxscore, int minscore)
{
    this->score=this->maxscore=maxscore;
    this->minscore=minscore;
    this->target=NULL;
}

Power::Power()
{

}

void Power::Init(QString size, QString type, qreal x, qreal y)
{
    //贴图
    this->setTexture(QString(":/myimages/res/prop_%1%2.png").arg(size).arg(type));
    //碰撞箱
    this->setCollibox(0.95*this->texture.width()*Width/1920,0.95*this->texture.height()*Width/1920);
    //移动属性
    this->target=NULL;
    this->speed=-4;
    this->dspeed=0.05;
    this->setPos(x,y,0,-1);
    if(size==QString("small"))
    {
        this->power=0.01;
        this->init(50,1);
    }
    else if(size==QString("big"))
    {
        this->power=0.25;
        this->init(60,2);
    }
    else if(size==QString("full"))
    {
        this->power=4.00;
        this->init(60,2);
    }
}

bool Power::isColliding(Hero *target)
{
    //bool condition_1=this->collibox.contains(target->collibox.topLeft());
    //bool condition_2=this->collibox.contains(target->collibox.topRight());
    //bool condition_3=this->collibox.contains(target->collibox.bottomLeft());
    //bool condition_4=this->collibox.contains(target->collibox.bottomRight());
    bool condition=GameObj::getMDistance(this,target)<50*Width/1920;
    if(target->isValid&&(/*condition_1||condition_2||condition_3||condition_4||*/condition))
    {
        this->isValid=false;
        target->power=std::min(4.00,target->power+this->power);
        return true;
    }
    return false;
}

Score::Score()
{

}

void Score::Init(QString size, QString type, qreal x, qreal y)
{
    //贴图
    this->setTexture(QString(":/myimages/res/prop_%1%2.png").arg(size).arg(type));
    //碰撞箱
    this->setCollibox(0.95*this->texture.width()*Width/1920,0.95*this->texture.height()*Width/1920);
    //移动属性
    this->target=NULL;
    this->speed=-4;
    this->dspeed=0.05;
    this->setPos(x,y,0,-1);
    if(size==QString("small"))
    {
        this->init(100,20);
    }
    else if(size==QString("big"))
    {
        this->init(200,40);
    }
    else if(size==QString("tiny"))
    {
        this->init(2,2);
    }
}

bool Score::isColliding(Hero *target)
{
    //bool condition_1=this->collibox.contains(target->collibox.topLeft());
    //bool condition_2=this->collibox.contains(target->collibox.topRight());
    //bool condition_3=this->collibox.contains(target->collibox.bottomLeft());
    //bool condition_4=this->collibox.contains(target->collibox.bottomRight());
    bool condition=GameObj::getMDistance(this,target)<50*Width/1920;
    if(target->isValid&&(/*condition_1||condition_2||condition_3||condition_4||*/condition))
    {
        this->isValid=false;
        return true;
    }
    return false;
}
