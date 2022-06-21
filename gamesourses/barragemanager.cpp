#include "gameheaders/barragemanager.h"

BarrageManager::BarrageManager(QObject *parent)
{
    Q_UNUSED(parent);
}

void BarrageManager::Init(BulletManager *bm, EnemyManager *em)
{
    this->bulletmanager=bm;
    this->enemymanager=em;
}

void BarrageManager::AddOneCircle(GameObj *parent, qreal center_x, qreal center_y, int num_in_circle, QString color, QString shape, qreal speed, qreal dspeed, qreal biasangle)
{
    qreal piece=2*M_PI/num_in_circle;
    for(int i=0;i<num_in_circle;i++)
    {
        this->bulletmanager->AddOneEnemyBullet(parent,color,shape,center_x,center_y,qCos(biasangle+piece*i),qSin(biasangle+piece*i),speed,dspeed);
    }
}

void BarrageManager::AddOneAim(GameObj *parent, GameObj *target, qreal init_x, qreal init_y, int num_of_line, qreal angle, QString color, QString shape,qreal speed,qreal dspeed,qreal biasangle)
{
    qreal targetx=target->collibox.x(),targety=target->collibox.y();
    qreal deltax=targetx-init_x,deltay=targety-init_y;
    qreal center_angle=qAtan2(deltay,deltax)+M_PI/184/*偏移量，为使自机狙能打中*/+biasangle;
    qreal anglepiece=0;
    qreal initangle=center_angle;
    if(num_of_line>1)
    {
        anglepiece=angle/(num_of_line-1.0);
        initangle=center_angle-angle/2.0;
    }
    for(int i=0;i<num_of_line;i++)
    {
        qreal targetangle=initangle+i*anglepiece;
        this->bulletmanager->AddOneEnemyBullet(parent,color,shape,init_x,init_y,qCos(targetangle),qSin(targetangle),speed,dspeed);
    }
}

void BarrageManager::AddOneRandomCircle(GameObj *parent, qreal center_x, qreal center_y, int num_in_circle, QString color, QString shape, qreal maxspeed, qreal minspeed, qreal maxdspeed, qreal mindspeed)
{
    int* pieces=new int[num_in_circle+1];
    int sum=0.0;
    for(int i=0;i<num_in_circle+1;i++)
    {
        pieces[i]=qrand()%90+10;
        sum+=pieces[i];
    }
    qreal angle=0.0,speed,dspeed;
    for(int i=0;i<num_in_circle;i++)
    {
        angle+=2*M_PI*qreal(pieces[i])/(qreal)sum;
        speed=qreal(qrand()%100)/100.0*(maxspeed-minspeed)+minspeed;
        dspeed=qreal(qrand()%100)/100.0*(maxdspeed-mindspeed)+mindspeed;
        this->bulletmanager->AddOneEnemyBullet(parent,color,shape,center_x,center_y,qCos(angle),qSin(angle),speed,dspeed);
    }
}

void BarrageManager::AddOneRandomRain(GameObj *parent, QString x_or_y, qreal init_x_or_y, int num, qreal angle, QString color, QString shape, qreal maxspeed, qreal minspeed, qreal maxdspeed, qreal mindspeed)
{
    int* spacings=new int[num+1];
    int sum=0.0;
    for(int i=0;i<num+1;i++)
    {
        spacings[i]=qrand()%100;
        sum+=spacings[i];
    }
    qreal target_x_or_y=0.0,speed,dspeed;
    if(x_or_y==tr("x"))//竖直
    {
        for(int i=0;i<num;i++)
        {
            target_x_or_y+=1410.0*(Width/1920.0)*(qreal)spacings[i]/(qreal)sum;
            speed=qreal(qrand()%100)/100.0*(maxspeed-minspeed)+minspeed;
            dspeed=qreal(qrand()%100)/100.0*(maxdspeed-mindspeed)+mindspeed;
            this->bulletmanager->AddOneEnemyBullet(parent,color,shape,init_x_or_y,target_x_or_y,qCos(angle),qSin(angle),speed,dspeed);
        }
    }
    else if(x_or_y==tr("y"))//水平
    {
        for(int i=0;i<num;i++)
        {
            target_x_or_y+=1194.0*(Width/1920.0)*(qreal)spacings[i]/(qreal)sum;
            speed=qreal(qrand()%100)/100.0*(maxspeed-minspeed)+minspeed;
            dspeed=qreal(qrand()%100)/100.0*(maxdspeed-mindspeed)+mindspeed;
            this->bulletmanager->AddOneEnemyBullet(parent,color,shape,target_x_or_y,init_x_or_y,qCos(angle),qSin(angle),speed,dspeed);
        }
    }
}

void BarrageManager::AddOneRing(GameObj *parent, qreal center_x, qreal center_y, qreal angle, qreal radius, int num_in_ring, QString color, QString shape, qreal speed, qreal dspeed, qreal init_angle, qreal biasangle)
{
    qreal piece=2*M_PI/num_in_ring;
    for(int i=0;i<num_in_ring;i++)
    {
        this->bulletmanager->AddOneEnemyBullet(parent,color,shape,center_x+radius*qCos(init_angle+piece*i),center_y+radius*qSin(init_angle+piece*i),qCos(biasangle+angle),qSin(biasangle+angle),speed,dspeed);
    }
}

void BarrageManager::AddOneLine(GameObj *parent, qreal init_x, qreal init_y, qreal angle, QString color, QString shape, qreal spacing, int num_in_line, qreal speed, qreal dspeed, qreal biasangle)
{
    for(int i=0;i<num_in_line;i++)
    {
        this->bulletmanager->AddOneEnemyBullet(parent,color,shape,init_x+i*qCos(angle+biasangle)*spacing,init_y+i*qSin(angle+biasangle)*spacing,qCos(angle+biasangle),qSin(angle+biasangle),speed,dspeed);
    }
}

void BarrageManager::AddOneLaser(GameObj *parent, qreal init_x, qreal init_y, int num_of_line, qreal init_angle, QString color, QString shape,qreal speed,qreal dspeed,qreal biasangle)
{
    qreal anglepiece=2*M_PI/(num_of_line);
    for(int i=0;i<num_of_line;i++)
    {
        qreal targetangle=init_angle+i*anglepiece+biasangle;
        this->AddOneLine(parent,init_x,init_y,targetangle,color,shape,3.0*Width/1920,500,speed,dspeed);
    }
}

