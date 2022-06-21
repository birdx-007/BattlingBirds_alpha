#include "gameheaders/propmanager.h"

PropManager::PropManager(QObject *parent)
{
    Q_UNUSED(parent);
}

void PropManager::Init()
{
    this->powers.clear();
    this->scores.clear();
    this->disconnect();
}

void PropManager::AddOnePower(QString size, qreal x, qreal y)
{
    Power p;
    p.Init(size,tr("power"),x,y);
    this->powers.push_back(p);
}

void PropManager::AddOneScore(QString size, qreal x, qreal y)
{
    Score s;
    s.Init(size,tr("score"),x,y);
    this->scores.push_back(s);
}

void PropManager::MoveOneProp(Prop *prop, Hero *target)
{
    if(target!=NULL||prop->target!=NULL)
    {
        if(prop->target==NULL)
        {
            prop->target=target;
        }
        target=prop->target;
        qreal propx=prop->X+prop->colliX/2,propy=prop->Y+prop->colliY/2;
        qreal targetx=target->collibox.center().x(),targety=target->collibox.center().y();
        qreal deltax=targetx-propx,deltay=targety-propy;
        qreal length=qSqrt(deltax*deltax+deltay*deltay);
        qreal dspeedx=prop->dspeed*((targetx-propx)/length);
        qreal dspeedy=prop->dspeed*((targety-propy)/length);
        prop->dspeed+=prop->dspeed>=50?0:0.5;

        qreal dx=(prop->speed*qCos((prop->faceXYtoAngle()-90)*M_PI/180.0)+dspeedx)*Width/1920;
        qreal dy=(prop->speed*qSin((prop->faceXYtoAngle()-90)*M_PI/180.0)+dspeedy)*Width/1920;
        prop->setPos(prop->X+dx,prop->Y+dy,dx,dy);
    }
    else
    {
        qreal deltax=prop->speed*Width/1920*qCos((prop->faceXYtoAngle()+90)*M_PI/180.0);
        qreal deltay=prop->speed*Width/1920*qSin((prop->faceXYtoAngle()+90)*M_PI/180.0);
        prop->setPos(prop->X+deltax,prop->Y+deltay,prop->faceX,prop->faceY);
        if(prop->speed<5)//最大速度为5
        {
            prop->speed+=prop->dspeed;
        }
    }
}

void PropManager::DestoryInvalidProps()
{
    for(auto iter=this->powers.begin();iter!=this->powers.end();iter++)
    {
        qreal x=iter->X;
        qreal y=iter->Y;
        bool isXOverflow=!(x>=(-2-100)*Width/1920&&x<=(1196+100-iter->texture.width())*Width/1920);
        bool isYOverflow=!(y>=(-1-500)*Width/1920&&y<=(1411+100-iter->texture.height())*Width/1920);
        if(isXOverflow||isYOverflow||!iter->isValid)
        {
            x=iter->collibox.center().x();
            y=iter->collibox.center().y();
            auto tmpiter=iter;
            this->powers.erase(tmpiter);
            iter--;
            emit PowerDeath(x,y);//发射信号，中心坐标
        }
    }
    for(auto iter=this->scores.begin();iter!=this->scores.end();iter++)
    {
        qreal x=iter->X;
        qreal y=iter->Y;
        bool isXOverflow=!(x>=(-2-100)*Width/1920&&x<=(1196+100-iter->texture.width())*Width/1920);
        bool isYOverflow=!(y>=(-1-500)*Width/1920&&y<=(1411+100-iter->texture.height())*Width/1920);
        if(isXOverflow||isYOverflow||!iter->isValid)
        {
            x=iter->collibox.center().x();
            y=iter->collibox.center().y();
            auto tmpiter=iter;
            this->scores.erase(tmpiter);
            iter--;
            emit ScoreDeath(x,y);//发射信号，中心坐标
        }
    }
}

void PropManager::DestoryAllPowers()
{
    while(!this->powers.empty())
    {
        this->powers.pop_back();
        emit PowerDeath(this->powers.back().collibox.center().x(),this->powers.back().collibox.center().y());
    }
}

void PropManager::DestoryAllScores()
{
    while(!this->scores.empty())
    {
        this->scores.pop_back();
        emit ScoreDeath(this->scores.back().collibox.center().x(),this->scores.back().collibox.center().y());
    }
}
