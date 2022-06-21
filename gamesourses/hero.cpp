#include <QString>
#include "gameheaders/hero.h"
//#include "mainwidget.h"

Hero::Hero()
{
}

void Hero::init(int herochoice)
{
    //初始化加载飞机图片资源
    this->setTexture(QString(":/myimages/res/hero%1_1.png").arg(herochoice));
    //初始化坐标
    this->X=(597-this->texture.width()/2)*Width/1920;
    this->Y=(1410-this->texture.height())*Width/1920;
    //初始化碰撞箱
    qreal collix,colliy;
    switch (herochoice) {
    case 0:{collix=colliy=8*Width/1920;break;}
    case 1:{collix=colliy=4*Width/1920;break;}
    case 2:{collix=colliy=16*Width/1920;break;}
    default:{collix=colliy=12*Width/1920;break;}
    }
    this->colliX=collix;
    this->colliY=colliy;
    this->collibox.setWidth(collix);
    this->collibox.setHeight(colliy);
    //杂项初始化
    this->vector.toZeroVector();
    this->heronum=herochoice;
    switch (herochoice) {
    case 0:{highspeed=13.5;lowspeed=5.94;break;}
    case 1:{highspeed=10.8;lowspeed=6.21;break;}
    case 2:{highspeed=10.8;lowspeed=5.13;break;}
    default:{highspeed=10.8;lowspeed=5.4;break;}
    }
    this->power=1;
    this->players=3;
    this->spells=3;
    if(Level==0)
    {
        this->players=99;
        this->spells=0;
    }
    this->spellcount=250;
    this->ghostcount=120;
    this->isShooting=false;
    this->isTryingActivateSpell=false;
    this->canActivateSpell=true;
    this->isValid=true;
    this->isGhost=false;
    this->isAbsorbingProps=false;
    this->type=QString("hero");
}

void Hero::Revive(int leftplayers, qreal leftpower)
{
    this->players=leftplayers;
    this->spells=3;
    this->power=leftpower;
    this->setPos((597-this->texture.width()/2)*Width/1920,(1410-this->texture.height())*Width/1920);
    this->isValid=true;
    this->isGhost=true;
    this->tmpcount=Count;//无敌时间起始
    if(Level==0)
    {
        this->spells=0;
        this->power=1.0;
    }
}

void Hero::setPos(qreal x, qreal y, qreal facex, qreal facey)
{
    int isXOverflow=(x>=-2*Width/1920&&x<=(1196-this->texture.width())*Width/1920)?0:1;
    int isYOverflow=(y>=-1*Width/1920&&y<=(1411-this->texture.height())*Width/1920)?0:1;
    this->X=isXOverflow?this->X:x;
    this->Y=isYOverflow?this->Y:y;
    this->collibox.moveTo(this->X+this->texture.width()/2*Width/1920-colliX/2,this->Y+this->texture.height()/2*Width/1920-colliY/2+4/*偏移量*/*Width/1920);
    this->faceX=facex;
    this->faceY=facey;
}

void Hero::Draw(QPainter *painter)
{
    painter->save();
    painter->translate(this->collibox.center());
    painter->rotate(this->faceXYtoAngle());
    painter->translate(-this->collibox.center());
    if(this->isGhost)
        painter->setOpacity(0.4);
    painter->drawPixmap(this->X,this->Y,this->texture.width()*Width/1920,this->texture.height()*Width/1920,this->texture);
    painter->restore();
}

void Hero::changePattern(int pattern)//1高速2低速
{
    this->speed=pattern==1?highspeed:lowspeed;
    this->setTexture(QString(":/myimages/res/hero%1_%2.png").arg(this->heronum).arg(pattern));
}







