#include "gameheaders/managerdep.h"
void ManagerDep::GenerateLevel2Boss()
{
    auto tmp=this->enemymanager.bosses.find(45);
    if(tmp!=this->enemymanager.bosses.end())
    {
        int Existcount=Count-tmp->second.tmpcount;
        qreal maxhp=tmp->second.maxhp;
        qreal curhp=tmp->second.hp;
        if(curhp>5100)
        {
            if(Count>=tmp->second.tmpcount+100)//缓冲时间
            {
                this->hero->isAbsorbingProps=false;
                if(Count%5==0)
                {
                    this->barragemanager.AddOneCircle(&tmp->second,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),Difficulty*6,tr("rock"),tr("bigball"),5.0,0,Count*1.8*Difficulty);
                }
                if(Count%80==0)
                {
                    for(int i=0;i<10;i++)
                        this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),1,0,tr("purple"),tr("ball"),8.5+0.5*i-Difficulty*2.5,0,0);
                }
                if(tmp->second.stagelefttime<=0)//超出时间限制
                {
                    tmp->second.setHp(5100);
                }
                tmp->second.stagelefttime=30.0-(Existcount-100)*0.015;
            }
            else
            {
                tmp->second.setHp(maxhp);//无敌
                this->hero->isAbsorbingProps=true;
            }
        }
        else if(curhp>3500)
        {
            if(tmp->second.stage==1)
            {
                tmp->second.stage=2,tmp->second.tmpcount=Count,tmp->second.stagelefttime=45,this->bulletmanager.DestoryAllEnemyBullets();
                qreal distance=qSqrt((tmp->second.X-470.0*Width/1920)*(tmp->second.X-470.0*Width/1920)+(tmp->second.Y-200.0*Width/1920)*(tmp->second.Y-200.0*Width/1920));
                this->enemymanager.SetOneEnemyMoveMode(&tmp->second,470.0*Width/1920,200.0*Width/1920,8.0,distance!=0.0?-64.0/(2.0*distance*1920/Width):0);
            }
            if(Count>=tmp->second.tmpcount+100)//缓冲时间
            {
                this->hero->isAbsorbingProps=false;
                if(Existcount%100==0)
                {
                    this->enemymanager.SetOneEnemyRandomMode(&tmp->second,100.0*Width/1920,700.0*Width/1920,100.0*Width/1920,300.0*Width/1920,8.0);
                    qreal x=tmp->second.X+100.0*Width/1920;
                    qreal y=(-200.0)*Width/1920;
                    this->enemymanager.AddOneZako(75,tr("little"),tr("helmet"),tr("pig"),x,y,x,y+5000.0*Width/1920,9.0,-0.05,0,1,0,0);
                    Idx++;
                }
                for(auto& tmp:this->enemymanager.zakos)
                {
                    if(std::abs(tmp.second.speed)<0.05||tmp.second.hp==0)
                    {
                        for(int i=0;i<2*Difficulty+1;i++)
                            this->barragemanager.AddOneAim(&tmp.second,this->hero,tmp.second.collibox.center().x(),tmp.second.collibox.center().y(),Difficulty*2,M_PI/16,tr("wooden"),tr("ball"),8.5+0.5*i-Difficulty*2.5,0,0);
                    }
                }
                if(Existcount%(9-2*Difficulty)==0&&Existcount%100!=0)
                {
                    this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,2*M_PI,tr("rock"),tr("ball"),4.0,0.01,(qrand()%10-4.5)*M_PI/24);
                }
                if(tmp->second.stagelefttime<=0)//超出时间限制
                {
                    tmp->second.setHp(3500);
                }
                tmp->second.stagelefttime=45.0-(Existcount-100)*0.015;
            }
            else
            {
                tmp->second.setHp(5100);//无敌
                this->hero->isAbsorbingProps=true;
            }
        }
        else if(curhp>2600)
        {
            if(tmp->second.stage==2)
            {
                tmp->second.stage=3,tmp->second.tmpcount=Count,tmp->second.stagelefttime=30,this->bulletmanager.DestoryAllEnemyBullets();
                this->enemymanager.DestoryAllZakos();
                qreal distance=qSqrt((tmp->second.X-470.0*Width/1920)*(tmp->second.X-470.0*Width/1920)+(tmp->second.Y-235.0*Width/1920)*(tmp->second.Y-235.0*Width/1920));
                this->enemymanager.SetOneEnemyMoveMode(&tmp->second,470.0*Width/1920,235.0*Width/1920,8.0,distance!=0.0?-64.0/(2.0*distance*1920/Width):0);
                Idx=47;//归位
            }
            if(Count>=tmp->second.tmpcount+100)//缓冲时间
            {
                this->hero->isAbsorbingProps=false;
                if(Existcount%75==0)
                {
                    this->enemymanager.SetOneEnemyRandomMode(&tmp->second,100.0*Width/1920,700.0*Width/1920,100.0*Width/1920,300.0*Width/1920,8.0);
                    for(int i=0;i<2*Difficulty+1;i++)
                        this->barragemanager.AddOneCircle(&tmp->second,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),8*Difficulty,tr("blue"),tr("arrow"),0,(i+1)*0.05,M_PI*qSin(qrand()));
                }
                if(Existcount%75==40||Existcount%75==50||Existcount%75==60)
                {
                    for(int i=0;i<Difficulty*3;i++)
                        this->barragemanager.AddOneLine(&tmp->second,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),M_PI/2,tr("purple"),tr("ball"),0,1,10+i*Difficulty*0.3,0.0);
                }
                if(tmp->second.stagelefttime<=0)//超出时间限制
                {
                    tmp->second.setHp(2600);
                }
                tmp->second.stagelefttime=30.0-(Existcount-100)*0.015;
            }
            else
            {
                tmp->second.setHp(3500);//无敌
                this->hero->isAbsorbingProps=true;
            }
        }
        else if(curhp>1000)
        {
            if(tmp->second.stage==3)
            {
                tmp->second.stage=4,tmp->second.tmpcount=Count,tmp->second.stagelefttime=45,this->bulletmanager.DestoryAllEnemyBullets();
                qreal distance=qSqrt((tmp->second.X-470.0*Width/1920)*(tmp->second.X-470.0*Width/1920)+(tmp->second.Y-235.0*Width/1920)*(tmp->second.Y-235.0*Width/1920));
                this->enemymanager.SetOneEnemyMoveMode(&tmp->second,470.0*Width/1920,235.0*Width/1920,8.0,distance!=0.0?-64.0/(2.0*distance*1920/Width):0);
            }
            if(Count>=tmp->second.tmpcount+100)//缓冲时间
            {
                this->hero->isAbsorbingProps=false;
                if(Existcount%100==0)
                {
                    this->enemymanager.SetOneEnemyRandomMode(&tmp->second,100.0*Width/1920,700.0*Width/1920,100.0*Width/1920,300.0*Width/1920,8.0);
                }
                if(Existcount%(7-Difficulty)==0)
                {
                    qreal dx=(200.0*qCos(Count*2))*Width/1920;
                    qreal dy=(200.0*qSin(Count*2))*Width/1920;
                    this->barragemanager.AddOneCircle(&tmp->second,tmp->second.collibox.center().x()+dx,tmp->second.collibox.center().y()+dy,5,tr("wooden"),tr("ball"),1+2*Difficulty,0,Count*1.8*Difficulty);
                    this->barragemanager.AddOneCircle(&tmp->second,tmp->second.collibox.center().x()-dx,tmp->second.collibox.center().y()-dy,5,tr("rock"),tr("ball"),1+2*Difficulty,0,Count*1.8*Difficulty);
                }
                if(tmp->second.stagelefttime<=0)//超出时间限制
                {
                    tmp->second.setHp(1000);
                }
                tmp->second.stagelefttime=45.0-(Existcount-100)*0.015;
            }
            else
            {
                tmp->second.setHp(2600);//无敌
                this->hero->isAbsorbingProps=true;
            }
        }
        else
        {
            if(tmp->second.stage==4)
            {
                tmp->second.stage=5,tmp->second.tmpcount=Count,tmp->second.stagelefttime=60,this->bulletmanager.DestoryAllEnemyBullets();
                qreal distance=qSqrt((tmp->second.X-470.0*Width/1920)*(tmp->second.X-470.0*Width/1920)+(tmp->second.Y-270.0*Width/1920)*(tmp->second.Y-270.0*Width/1920));
                this->enemymanager.SetOneEnemyMoveMode(&tmp->second,470.0*Width/1920,270.0*Width/1920,8.0,distance!=0.0?-64.0/(2.0*distance*1920/Width):0);
            }
            if(Count>=tmp->second.tmpcount+100)//缓冲时间
            {
                this->hero->isAbsorbingProps=false;
                for(auto& tmp:this->enemymanager.zakos)
                {
                    if(Existcount-100>100&&Existcount%(180-Difficulty*30)==0)
                    {
                        this->barragemanager.AddOneAim(&tmp.second,this->hero,tmp.second.collibox.center().x(),tmp.second.collibox.center().y(),1,0,tr("blue"),tr("arrow"),8.5,0,0);
                    }
                }
                if(Existcount-100>100&&Existcount%(40-5*Difficulty)==0)
                {
                    for(int i=0;i<2*Difficulty+1;i++)
                        this->barragemanager.AddOneRing(&tmp->second,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),-Existcount*Difficulty+i*2*M_PI/(2*Difficulty+1),80.0*Width/1920,Difficulty*5,tr("rock"),tr("bigball"),5.0,-0.1,i*2*M_PI/(2*Difficulty+1),0);
                }
                if(tmp->second.stagelefttime<=0)//超出时间限制
                {
                    tmp->second.setHp(0);
                }
                tmp->second.stagelefttime=60.0-(Existcount-100)*0.015;
            }
            else
            {
                tmp->second.setHp(1000);//无敌
                this->hero->isAbsorbingProps=true;
                if(Existcount==10)
                {
                    qreal x,y;
                    for(int i=0;i<12;i++)
                    {
                        x=(470.0+300.0*qCos(i*M_PI/6)+50.0)*Width/1920;
                        y=(270.0+300.0*qSin(i*M_PI/6)+65.0)*Width/1920;
                        this->enemymanager.AddOneZako(225,tr("big"),tr("knight"),tr("pig"),x,-300.0*Width/1920,x,y,15.0*qSqrt(300.0*Width/1920+y)/50.0,-0.044*Width/1920.0,0,1,0,0);
                        Idx++;
                    }
                }
            }
        }
    }
}
