#include "gameheaders/bulletmanager.h"

BulletManager::BulletManager(QObject *parent)
{
    Q_UNUSED(parent);
}

void BulletManager::Init()
{
    this->herobullets.clear();
    this->enemybullets.clear();
    this->disconnect();
}

void BulletManager::AddOneHeroBullet(GameObj *p, int hnum, bool islow, qreal x, qreal y, qreal facex, qreal facey)
{
    this->herobullets.push_back(HeroBullet(p,hnum,islow,x,y,facex,facey));
}

void BulletManager::AddOneEnemyBullet(GameObj *p, QString color, QString shape, qreal x, qreal y, qreal facex, qreal facey, qreal speed, qreal dspeed)
{
    this->enemybullets.push_back(EnemyBullet(p,color,shape,x,y,facex,facey,speed,dspeed));
}

void BulletManager::MoveOneHeroBullet(HeroBullet *bullet, GameObj *target)
{
    if(bullet->istracking&&target!=NULL)
    {
        qreal bulletx=bullet->X+bullet->colliX/2,bullety=bullet->Y+bullet->colliY/2;
        qreal targetx=target->collibox.center().x(),targety=target->collibox.center().y();
        qreal deltax=targetx-bulletx,deltay=targety-bullety;
        qreal length=qSqrt(deltax*deltax+deltay*deltay);
        qreal dspeedx=bullet->dspeed*((targetx-bulletx)/length);
        qreal dspeedy=bullet->dspeed*((targety-bullety)/length);
        qreal dx,dy;
        if(Shottype!=2)
        {
            bullet->dspeed=1800.0/(length+0.01);//防止圆周运动
        }
        else
        {
            bullet->dspeed+=0.01;
            bullet->speed=bullet->speed<40.0?bullet->speed+bullet->dspeed:40.0;
        }
        dx=(bullet->speed*qCos((bullet->faceXYtoAngle()-90)*M_PI/180.0)+dspeedx)*Width/1920;
        dy=(bullet->speed*qSin((bullet->faceXYtoAngle()-90)*M_PI/180.0)+dspeedy)*Width/1920;
        bullet->setPos(bullet->X+dx,bullet->Y+dy,dx,dy);
    }
    else
    {
        qreal deltax=bullet->speed*Width/1920*qCos((bullet->faceXYtoAngle()-90)*M_PI/180.0);
        qreal deltay=bullet->speed*Width/1920*qSin((bullet->faceXYtoAngle()-90)*M_PI/180.0);
        bullet->setPos(bullet->X+deltax,bullet->Y+deltay,bullet->faceX,bullet->faceY);
        if(Shottype==2)
        {
            bullet->dspeed=0.5;
            bullet->speed=bullet->speed<40.0?bullet->speed+bullet->dspeed:40.0;
        }
    }
}

void BulletManager::MoveOneEnemyBullet(EnemyBullet *bullet, GameObj *target)
{
    if(bullet->istracking&&target!=NULL)
    {
        qreal bulletx=bullet->X+bullet->colliX/2,bullety=bullet->Y+bullet->colliY/2;
        qreal targetx=target->collibox.center().x(),targety=target->collibox.center().y();
        qreal deltax=targetx-bulletx,deltay=targety-bullety;
        qreal length=qSqrt(deltax*deltax+deltay*deltay);
        qreal dspeedx=bullet->dspeed*((targetx-bulletx)/length);
        qreal dspeedy=bullet->dspeed*((targety-bullety)/length);
        bullet->dspeed+=0.5;//加速度递增防止圆周运动

        qreal dx=(bullet->speed*qCos((bullet->faceXYtoAngle()-90)*M_PI/180.0)+dspeedx)*Width/1920;
        qreal dy=(bullet->speed*qSin((bullet->faceXYtoAngle()-90)*M_PI/180.0)+dspeedy)*Width/1920;
        bullet->setPos(bullet->X+dx,bullet->Y+dy,dx,dy);
    }
    else
    {
        qreal deltax=bullet->speed*Width/1920*qCos((bullet->faceXYtoAngle()-90)*M_PI/180.0);
        qreal deltay=bullet->speed*Width/1920*qSin((bullet->faceXYtoAngle()-90)*M_PI/180.0);
        bullet->setPos(bullet->X+deltax,bullet->Y+deltay,bullet->faceX,bullet->faceY);
        bullet->speed+=bullet->dspeed;
    }
}

void BulletManager::DestoryInvalidBullets()
{
    for(auto iter=this->herobullets.begin();iter!=this->herobullets.end();iter++)//自机子弹
    {
        qreal x=iter->X;
        qreal y=iter->Y;
        bool isXOverflow=!(x>=(-2-80)*Width/1920&&x<=(1196+80-iter->collibox.width())*Width/1920);
        bool isYOverflow=!(y>=(-1-80)*Width/1920&&y<=(1411+80-iter->collibox.height())*Width/1920);
        if(isXOverflow||isYOverflow||!iter->isValid)
        {
            x=iter->collibox.center().x();
            y=iter->collibox.center().y();
            auto tmpiter=iter;
            this->herobullets.erase(tmpiter);
            iter--;
            if(!isXOverflow&&!isYOverflow)
                emit HeroBulletDeath(x,y);//发射信号，传出子弹的中心坐标
        }
    }
    for(auto iter=this->enemybullets.begin();iter!=this->enemybullets.end();iter++)//敌机子弹
    {
        qreal x=iter->X;
        qreal y=iter->Y;
        bool isXOverflow=!(x>=(-2-600)*Width/1920&&x<=(1196+600-iter->texture.width())*Width/1920);
        bool isYOverflow=!(y>=(-1-600)*Width/1920&&y<=(1411+600-iter->texture.height())*Width/1920);
        if(isXOverflow||isYOverflow||!iter->isValid)
        {
            x=iter->collibox.center().x();
            y=iter->collibox.center().y();
            auto tmpiter=iter;
            this->enemybullets.erase(tmpiter);
            iter--;
            if(!isXOverflow&&!isYOverflow)
                emit EnemyBulletDeath(x,y);//发射信号，传出子弹的中心坐标
        }
    }
}

void BulletManager::DestoryAllHeroBullets()
{
    while(!this->herobullets.empty())
    {
        emit HeroBulletDeath(this->herobullets.back().collibox.center().x(),this->herobullets.back().collibox.center().y());
        this->herobullets.pop_back();
    }
}

void BulletManager::DestoryAllEnemyBullets()
{
    while(!this->enemybullets.empty())
    {
        emit EnemyBulletDeath(this->enemybullets.back().collibox.center().x(),this->enemybullets.back().collibox.center().y());
        this->enemybullets.pop_back();
    }
}
