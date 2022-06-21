#include "gameheaders/dialogplayer.h"

DialogPlayer::DialogPlayer(QObject *parent)
{
    Q_UNUSED(parent);
    this->Init();
}

void DialogPlayer::Init()
{
    this->isOnDisplay=false;
    this->isskipping=false;
    this->leftspeaker.load("");
    this->rightspeaker.load("");
    this->dlgframe.load(QString(":/myimages/res/dialogframe.png"));
    this->text="";
    this->leftopacity=this->rightopacity=1.0;
    this->speaktimes=0;
}

void DialogPlayer::setLeft(QString ldir)
{
    this->leftspeaker.load(ldir);
}

void DialogPlayer::setRight(QString rdir)
{
    this->rightspeaker.load(rdir);
}

void DialogPlayer::setText(QString txt)
{
    this->text=txt;
}

void DialogPlayer::LeftSpeak(QString txt)
{
    this->leftopacity=1.0,this->rightopacity=0.4;
    this->setText(txt);
}

void DialogPlayer::RightSpeak(QString txt)
{
    this->rightopacity=1.0,this->leftopacity=0.4;
    this->setText(txt);
}

void DialogPlayer::Draw(QPainter *painter)
{
    //两张pixmap为300*300，对话框1194*400
    painter->save();
    painter->setOpacity(this->leftopacity);
    painter->drawPixmap(0*Width/1920,(1410-400-300+25)*Width/1920,300*Width/1920,300*Width/1920,this->leftspeaker);
    painter->setOpacity(this->rightopacity);
    painter->drawPixmap((1194-300)*Width/1920,(1410-400-300+25)*Width/1920,300*Width/1920,300*Width/1920,this->rightspeaker);
    painter->setOpacity(1.0);
    painter->drawPixmap(0*Width/1920,(1410-400)*Width/1920,this->dlgframe.width()*Width/1920,this->dlgframe.height()*Width/1920,this->dlgframe);
    painter->setPen(QColor(Qt::black));
    painter->drawText(40*Width/1920,(1410-400)*Width/1920,(this->dlgframe.width()-80)*Width/1920,this->dlgframe.height()*Width/1920,Qt::AlignVCenter|Qt::TextWordWrap,this->text);
    painter->restore();
}
