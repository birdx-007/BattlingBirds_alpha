#include "gameheaders/enemymanager.h"

EnemyManager::EnemyManager(QObject *parent)
{
    Q_UNUSED(parent);
}

void EnemyManager::Init()
{
    this->zakos.clear();
    this->bosses.clear();
    this->dyingzakos.clear();
    this->dyingbosses.clear();
    this->disconnect();
    this->enemies_dead_of_hero=0;
}

void EnemyManager::AddOneZako(qreal maxhp, QString size, QString armor, QString species, qreal x, qreal y, qreal tx, qreal ty, qreal speed, qreal dspeed, int sp, int ss, int bp, int bs)
{
    Zako p;
    p.Init(maxhp,size,armor,species,x,y);
    this->SetOneEnemyMoveMode(&p,tx,ty,speed,dspeed);
    this->SetOneEnemyProp(&p,sp,ss,bp,bs);
    p.guid=Idx;
    this->zakos.insert({Idx,p});
}

void EnemyManager::AddOneBoss(qreal maxhp, int maxstage, QString size, QString armor, QString species, QString name, qreal x, qreal y, qreal tx, qreal ty, qreal speed, qreal dspeed, int sp, int ss, int bp, int bs)
{
    Boss p;
    p.Init(maxhp,maxstage,size,armor,species,name,x,y);
    this->SetOneEnemyMoveMode(&p,tx,ty,speed,dspeed);
    this->SetOneEnemyProp(&p,sp,ss,bp,bs);
    p.guid=Idx;
    this->bosses.insert({Idx,p});
}

void EnemyManager::SetOneEnemyProp(Enemy *t, int sp, int ss, int bp, int bs)
{
    t->smallpowercount=sp;
    t->smallscorecount=ss;
    t->bigpowercount=bp;
    t->bigscorecount=bs;
}

void EnemyManager::SetOneEnemyMoveMode(Enemy *t,qreal tx, qreal ty,qreal speed, qreal dspeed)
{
    t->targetx=tx;
    t->targety=ty;
    t->speed=speed;
    t->dspeed=dspeed;
    //t->tmpcount=Count;
}

void EnemyManager::SetOneEnemyRandomMode(Enemy *t, qreal minx, qreal maxx, qreal miny, qreal maxy, qreal speed)
{
    t->targetx=(qreal(qrand()%100)/100.0*(maxx-minx)+minx);
    t->targety=(qreal(qrand()%100)/100.0*(maxy-miny)+miny);
    t->speed=speed;
    qreal distance=qSqrt((t->X-t->targetx)*(t->X-t->targetx)+(t->Y-t->targety)*(t->Y-t->targety));
    t->dspeed=distance!=0?-speed*speed/(2.0*distance*1920/Width):0;//a=v^2/2x x应还原为1920分辨率下的距离
    //t->tmpcount=Count;
}

bool EnemyManager::MoveOneEnemy(Enemy *t)
{
    if(abs(t->X-t->targetx)+abs(t->Y-t->targety)>std::max(t->speed,6.0)*Width/1920)//未到预定位置
    {
        t->speed+=t->dspeed;
        qreal deltax=t->targetx-t->X,deltay=t->targety-t->Y;
        qreal length=qSqrt(deltax*deltax+deltay*deltay);
        qreal dx=t->speed*deltax/length*Width/1920;
        qreal dy=t->speed*deltay/length*Width/1920;
        t->setPos(t->X+dx,t->Y+dy,t->faceX,t->faceY);
        return false;
    }
    else
    {
        return true;
    }
}

void EnemyManager::DamageAllZakos(qreal value)
{
    for(auto zako=this->zakos.begin();zako!=this->zakos.end();zako++)
    {
        zako->second.setHp(zako->second.hp-value);
    }
}

void EnemyManager::DamageAllBosses(qreal value)
{
    for(auto boss=this->bosses.begin();boss!=this->bosses.end();boss++)
    {
        boss->second.setHp(boss->second.hp-value);
    }
}

void EnemyManager::DestoryInvalidBosses()
{
    this->dyingbosses.clear();
    for(auto b:this->bosses)
    {
        qreal x=b.second.X;
        qreal y=b.second.Y;
        /*要留足够位置*/
        bool isXOverflow=!(x>=(-2-500)*Width/1920&&x<=(1196+500-b.second.texture.width())*Width/1920);
        bool isYOverflow=!(y>=(-1-500)*Width/1920&&y<=(1411+500-b.second.texture.height())*Width/1920);
        if(isXOverflow||isYOverflow||b.second.hp==0)
        {
            x=b.second.collibox.center().x();
            y=b.second.collibox.center().y();
            int sp=b.second.smallpowercount;
            int ss=b.second.smallscorecount;
            int bp=b.second.bigpowercount;
            int bs=b.second.bigscorecount;
            if(!isXOverflow&&!isYOverflow)
            {
                this->enemies_dead_of_hero++;
                emit BossDeath(x,y,sp,ss,bp,bs);
            }
            this->dyingbosses.push_back(b.second.guid);
            //this->bosses.erase(b.second.guid);
        }
    }
    for(int guid:this->dyingbosses)
    {
        this->bosses.erase(guid);
    }
    /*
    for(auto iter=this->bosses.begin();iter!=this->bosses.end();iter++)
    {
        qreal x=iter->second.X;
        qreal y=iter->second.Y;
        bool isXOverflow=!(x>=(-2-500)*Width/1920&&x<=(1196+500-iter->second.texture.width())*Width/1920);
        bool isYOverflow=!(y>=(-1-500)*Width/1920&&y<=(1411+500-iter->second.texture.height())*Width/1920);
        if(isXOverflow||isYOverflow||iter->second.hp==0)
        {
            auto tmpiter=iter;
            this->bosses.erase(tmpiter);
            iter--;
        }
    }*/
}

void EnemyManager::DestoryInvalidZakos()
{
    this->dyingzakos.clear();
    for(auto z:this->zakos)
    {
        qreal x=z.second.X;
        qreal y=z.second.Y;
        /*要留足够位置*/
        bool isXOverflow=!(x>=(-2-500)*Width/1920&&x<=(1196+500-z.second.texture.width())*Width/1920);
        bool isYOverflow=!(y>=(-1-500)*Width/1920&&y<=(1411+500-z.second.texture.height())*Width/1920);
        if(isXOverflow||isYOverflow||z.second.hp==0)
        {
            x=z.second.collibox.center().x();
            y=z.second.collibox.center().y();
            int sp=z.second.smallpowercount;
            int ss=z.second.smallscorecount;
            int bp=z.second.bigpowercount;
            int bs=z.second.bigscorecount;
            if(!isXOverflow&&!isYOverflow)
            {
                this->enemies_dead_of_hero++;
                emit ZakoDeath(x,y,sp,ss,bp,bs);
            }
            this->dyingzakos.push_back(z.second.guid);
            //this->zakos.erase(z.second.guid);
        }
    }
    for(int guid:this->dyingzakos)
    {
        this->zakos.erase(guid);
    }
    /*
    for(auto iter=this->zakos.begin();iter!=this->zakos.end();iter++)
    {
        qreal x=iter->X;
        qreal y=iter->Y;
        bool isXOverflow=!(x>=(-2-500)*Width/1920&&x<=(1196+500-iter->texture.width())*Width/1920);
        bool isYOverflow=!(y>=(-1-500)*Width/1920&&y<=(1411+500-iter->texture.height())*Width/1920);
        if(isXOverflow||isYOverflow||iter->hp==0)
        {
            auto tmpiter=iter;
            this->zakos.erase(tmpiter);
            iter--;
        }
    }*/
}

void EnemyManager::DestoryAllBosses()
{
    this->dyingbosses.clear();
    for(auto b:this->bosses)
    {
        qreal x=b.second.collibox.center().x();
        qreal y=b.second.collibox.center().y();
        int sp=b.second.smallpowercount;
        int ss=b.second.smallscorecount;
        int bp=b.second.bigpowercount;
        int bs=b.second.bigscorecount;
        this->dyingbosses.push_back(b.second.guid);
        emit BossDeath(x,y,sp,ss,bp,bs);
    }
    for(int guid:this->dyingbosses)
    {
        this->bosses.erase(guid);
    }
    //this->bosses.clear();
}

void EnemyManager::DestoryAllZakos()
{
    this->dyingzakos.clear();
    for(auto z:this->zakos)
    {
        qreal x=z.second.collibox.center().x();
        qreal y=z.second.collibox.center().y();
        int sp=z.second.smallpowercount;
        int ss=z.second.smallscorecount;
        int bp=z.second.bigpowercount;
        int bs=z.second.bigscorecount;
        this->dyingzakos.push_back(z.second.guid);
        emit ZakoDeath(x,y,sp,ss,bp,bs);
    }
    for(int guid:this->dyingzakos)
    {
        this->zakos.erase(guid);
    }
    //this->zakos.clear();
}
