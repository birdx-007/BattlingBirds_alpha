#include "gameheaders/background.h"
BackGround::BackGround()
{
}

void BackGround::Init(int spellcount)
{
    this->mainbg.load(QString(":/myimages/res/bg_level%1.png").arg(Level));
    this->mainbg_y=0;
    this->mainbgspeed=3;
    this->mainbgdspeed=0;
    this->spellbgspeed=80;
    this->spellbgdspeed=-(this->spellbgspeed)/spellcount;
    this->isSpellBackGroundOnDisplay=false;
    this->startcount=-spellcount;
    this->endcount=0;
}

void BackGround::SetMainBackground(qreal speed, qreal dspeed, QString bgname)
{
    this->mainbgspeed=speed;
    this->mainbgdspeed=dspeed;
    if(bgname!=QString(""))
    {
        this->mainbg.load(QString(":/myimages/res/%1.png").arg(bgname));
    }
}

void BackGround::ActivateSpellBackGround(bool islow)
{
    switch (Shottype) {
    case 0:
        this->spellbgspeed=80;break;
    case 1:
        this->spellbgspeed=120;break;
    case 2:
        this->spellbgspeed=64;break;
    case 3:
        this->spellbgspeed=80;break;
    default:
        break;
    }
    //this->spellbg.load(QString(":/myimages/res/bg_hero%1_%2").arg(Shottype).arg(islow?2:1));
    this->isSpellBackGroundOnDisplay=true;
    this->spellbg_y=0*Width/1920;
    this->endcount=Count+this->endcount-this->startcount;
    this->startcount=Count;
}

void BackGround::DeactivateSpellBackGround()
{
    this->isSpellBackGroundOnDisplay=false;
    this->spellbg_y=1410*Width/1920;
}

void BackGround::MoveBackGround()
{
    this->mainbg_y+=this->mainbgspeed*Width/1920;
    if(this->mainbg_y>=1410*Width/1920)
    {
        this->mainbg_y=0;
    }
    this->mainbgspeed+=this->mainbgdspeed;
    if(isSpellBackGroundOnDisplay)
    {
        this->spellbg_y-=this->spellbgspeed*Width/1920;
        this->spellbgspeed+=this->spellbgdspeed;
        if(this->spellbg_y<=-1410*Width/1920)
        {
            this->spellbg_y=0;
        }
    }
    else
    {
        this->spellbg_y=1410*Width/1920;
    }
}

void BackGround::Draw(QPainter *painter)
{
    painter->drawPixmap(0,this->mainbg_y,1194*Width/1920,1410*Width/1920,this->mainbg);
    painter->drawPixmap(0,this->mainbg_y-1410*Width/1920,1194*Width/1920,1410*Width/1920,this->mainbg);
    if(isSpellBackGroundOnDisplay)
    {
        painter->setOpacity(1-qreal(Count-this->startcount)/qreal(this->endcount-this->startcount));
        painter->fillRect(0,0,1194.0*Width/1920,1410.0*Width/1920,QColor(255,255,255,255));
        painter->setOpacity(1.0);
    }
}
