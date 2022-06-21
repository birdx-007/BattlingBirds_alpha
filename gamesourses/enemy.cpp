#include <QString>
#include "gameheaders/enemy.h"
//#include "mainwidget.h"

Enemy::Enemy()
{

}

void Enemy::init(qreal maxhp)
{
    this->bigpowercount=this->bigscorecount=this->smallpowercount=this->smallscorecount=0;
    //贴图、碰撞箱等在具体类中初始化
    this->hp=this->maxhp=maxhp;
    this->isValid=true;
    this->isGhost=false;
    this->type=QString("enemy");
}

void Enemy::setPos(qreal x, qreal y, qreal facex, qreal facey)
{
    this->X=x;
    this->Y=y;
    this->collibox.moveTo(this->X+this->texture.width()/2*Width/1920-colliX/2,this->Y+this->texture.height()/2*Width/1920-colliY/2);
    this->faceX=facex;
    this->faceY=facey;
}

void Enemy::setHp(qreal value)
{
    this->hp=(value>=0)?(value<=this->maxhp?value:this->maxhp):0;
}


bool Enemy::isColliding(Bullet *target)
{
    bool condition_1=this->collibox.contains(target->collibox.topLeft());
    bool condition_2=this->collibox.contains(target->collibox.topRight());
    bool condition_3=this->collibox.contains(target->collibox.bottomLeft());
    bool condition_4=this->collibox.contains(target->collibox.bottomRight());
    if(target->isValid&&!target->isGhost&&(condition_1||condition_2||condition_3||condition_4))
    {
        this->setHp(this->hp-target->ap);
        target->isValid=false;
        return true;
    }
    return false;
}

bool Enemy::isColliding(Hero *target)
{
    bool condition_1=this->collibox.contains(target->collibox.topLeft());
    bool condition_2=this->collibox.contains(target->collibox.topRight());
    bool condition_3=this->collibox.contains(target->collibox.bottomLeft());
    bool condition_4=this->collibox.contains(target->collibox.bottomRight());
    if(target->isValid&&!target->isGhost&&(condition_1||condition_2||condition_3||condition_4))
    {
        target->isValid=false;
        return true;
    }
    return false;
}

Zako::Zako()
{

}

void Zako::Init(qreal maxhp, QString size, QString armor, QString species, qreal x, qreal y, qreal facex, qreal facey)
{
    this->init(maxhp);
    this->extraInit(size,armor,species);
    this->setPos(x,y,facex,facey);
}

void Zako::extraInit(QString size, QString armor, QString species)
{
    //贴图
    this->setTexture(QString(":/myimages/res/enemy_%1%2%3.png").arg(size).arg(armor).arg(species));
    //碰撞箱
    this->setCollibox(0.6*this->texture.width()*Width/1920,0.6*this->texture.height()*Width/1920);
}

Boss::Boss()
{

}

void Boss::Init(qreal maxhp, int maxstage, QString size, QString armor, QString species, QString name, qreal x, qreal y, qreal facex, qreal facey)
{
    this->init(maxhp);
    this->extraInit(maxstage,size,armor,species,name);
    this->setPos(x,y,facex,facey);
}

void Boss::extraInit(int maxstage,QString size, QString armor, QString species,QString name)
{
    //贴图
    this->setTexture(QString(":/myimages/res/enemy_%1%2%3.png").arg(size).arg(armor).arg(species));
    //碰撞箱
    this->setCollibox(0.9*this->texture.width()*Width/1920,0.9*this->texture.height()*Width/1920);
    this->name=name;
    this->maxstage=maxstage;
    this->stagelefttime=30.00;
    this->stage=1;
}

void Boss::Draw(QPainter *painter)
{
    painter->save();

    painter->translate(this->collibox.center());
    painter->rotate(this->faceXYtoAngle());
    painter->translate(-this->collibox.center());
    painter->drawPixmap(this->X,this->Y,this->texture.width()*Width/1920,this->texture.height()*Width/1920,this->texture);

    QPixmap frame(":/myimages/res/bossframe.png");
    painter->setOpacity(0.5);
    painter->drawPixmap(0,0,frame.width()*Width/1920,frame.height()*Width/1920,frame);
    painter->setOpacity(1.0);

    painter->setPen(QColor(Qt::white));
    QFont font = painter->font();
    font.setPixelSize(30*Width/1920);
    painter->setFont(font);
    painter->drawText(15*Width/1920,0,(frame.width()-30)*Width/1920,frame.height()*Width/1920,Qt::AlignVCenter|Qt::TextWordWrap,QString("%1 stage%2/%3").arg(this->name).arg(this->stage).arg(this->maxstage));

    painter->setPen(QColor(Qt::black));
    font.setPixelSize(50*Width/1920);
    painter->setFont(font);
    painter->drawText(525*Width/1920,20*Width/1920,144*Width/1920,72*Width/1920,Qt::AlignCenter,QString("%1").arg(QString::number(this->stagelefttime,'f',2)));

    painter->restore();
}
