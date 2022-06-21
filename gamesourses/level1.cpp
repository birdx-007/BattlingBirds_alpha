#include "gameheaders/managerdep.h"
void ManagerDep::GenerateLevel1()
{
    if(this->dialogplayer.isOnDisplay){
        Count--;
        switch (this->dialogplayer.speaktimes) {
        case 0:
            this->dialogplayer.setLeft(QString(":/myimages/res/hero%1.png").arg(Shottype+1));
            this->dialogplayer.setRight(QString(":/myimages/res/pilotpig_normal.png"));
            this->dialogplayer.RightSpeak(tr("......"));
            this->background.SetMainBackground(2,0,tr(""));
            break;
        case 1:
            this->dialogplayer.RightSpeak(tr("这里是护卫队队长...我们正在遭受攻击！"));
            break;
        case 3:
            this->dialogplayer.setRight(QString(""));
            this->dialogplayer.LeftSpeak(tr("...怎么天上尽是这些乱七八糟的飞行物呀。"));
            break;
        case 4:
            this->dialogplayer.setRight(QString(":/myimages/res/pilotpig_normal.png"));
            this->dialogplayer.RightSpeak(tr("那样称呼我们天空护卫队真是失礼啊。"));
            if(this->enemymanager.bosses.find(63)==this->enemymanager.bosses.end())
            {
                Idx=63;
                this->enemymanager.AddOneBoss(1800,4,tr("big"),tr("snow"),tr("pig"),tr("???"),1200.0*Width/1920,-100.0*Width/1920,470.0*Width/1920,200.0*Width/1920,12.0,-0.078,10,10,1,1);
                this->enemymanager.bosses[63].tmpcount=7900;
                this->enemymanager.bosses[63].stagelefttime=30;
            }
            break;
        case 5:
            this->dialogplayer.LeftSpeak(tr("...刚刚不是把你击落了来着？\n还有，你们究竟是什么家伙啊!"));
            break;
        case 6:
            this->dialogplayer.RightSpeak(tr("呵呵，这可是最先进的隐身战机ICEPIG-20，刚刚那只是战略撤退!\n...扯远了。我们是从遥远的猪猪岛来的绿猪。\n而我是绿猪天空护卫队的队长。"));
        {
            auto tmp=this->enemymanager.bosses.find(63);
            if(tmp!=this->enemymanager.bosses.end())
            {
                tmp->second.name=tr("护卫队长");
            }
        }
            break;
        case 7:
            this->dialogplayer.LeftSpeak(tr("那这么说，你们算是远客咯。\n...那么，你们知道我们的鸟蛋的去向么？"));
            break;
        case 8:
            this->dialogplayer.RightSpeak(tr("...你说鸟蛋？...\n原来如此，你们就是传说中的小鸟岛的鸟啊。"));
            break;
        case 9:
            this->dialogplayer.RightSpeak(tr("...不妨告诉你们，我的确知道你们的鸟蛋的下落。"));
            break;
        case 10:
            this->dialogplayer.LeftSpeak(tr("...?!"));
            break;
        case 11:
            this->dialogplayer.RightSpeak(tr("不过在让你们知道答案之前...要先把你们击落!!"));
            break;
        case 13:
            this->dialogplayer.LeftSpeak(tr("...真是奇怪的家伙。"));
            if(this->background.mainbgspeed<8)
            {
                this->background.SetMainBackground(this->background.mainbgspeed,0.2,tr(""));
            }
            else
            {
                this->background.SetMainBackground(8,0,tr(""));
            }
            break;
        case 14:
            this->dialogplayer.LeftSpeak(tr("总觉得这些绿猪和鸟蛋的失踪有关...\n有种不太好的预感..."));
            break;
        case 15:
            this->dialogplayer.LeftSpeak(tr("...不好，那个奇怪的飞行物躲进云层了，快追!"));
            break;
        default:
            this->dialogplayer.isOnDisplay=false;
            this->dialogplayer.speaktimes++;
            this->dialogplayer.setRight(QString(""));
            this->dialogplayer.LeftSpeak("");
            this->dialogplayer.RightSpeak("");
            break;
        }
        return;
    }
    //敌机移动设置
    switch (Count) {
    case 1:
        this->background.SetMainBackground(8,0,tr(""));
        break;
    case 50:
        this->isFightingBoss=false;
        for(Idx=1;Idx<=5;Idx++)
        {
            qreal x=(50.0+(Idx-1)*100.0)*Width/1920;
            qreal y=(-400.0+(Idx-1)*45.0)*Width/1920;
            this->enemymanager.AddOneZako(5,tr("little"),tr("blue"),tr("pig"),x,y,x,y+1000.0*Width/1920,8.0,-0.06,0,1,0,0);
        }
        for(Idx=6;Idx<=10;Idx++)
        {
            qreal x=(650.0+(Idx-6)*100.0)*Width/1920;
            qreal y=(-400.0+180.0-(Idx-6)*45.0)*Width/1920;
            this->enemymanager.AddOneZako(5,tr("little"),tr("red"),tr("pig"),x,y,x,y+1000.0*Width/1920,8.0,-0.06,1,0,0,0);
        }
        break;
    case 450:
        this->titleplayer.SetTitle(500,850);
        break;
    case 900:
        for(Idx=11;Idx<=15;Idx++)
        {
            qreal x=(20.0+(Idx-11)*260.0)*Width/1920;
            qreal y=(-200.0+qrand()%100)*Width/1920;
            this->enemymanager.AddOneZako(15,tr("little"),tr("blue"),tr("pig"),x,y,x,y+2000.0*Width/1920,1.0,0,0,1,0,0);
        }
        Idx=16;
        this->enemymanager.AddOneZako(50,tr("little"),tr("red"),tr("pig"),650.0*Width/1920,-150.0*Width/1920,650.0*Width/1920,350.0*Width/1920,7.0,-0.049,3,0,0,0);
        break;
    case 1300:
    {
        for(Idx=17;Idx<=21;Idx++)
        {
            qreal x=(20.0+(Idx-17)*260.0)*Width/1920;
            qreal y=(-200.0+qrand()%100)*Width/1920;
            this->enemymanager.AddOneZako(15,tr("little"),tr("red"),tr("pig"),x,y,x,y+2000.0*Width/1920,1.0,0,1,0,0,0);
        }
        auto tmp=this->enemymanager.zakos.find(16);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->enemymanager.SetOneEnemyMoveMode(&tmp->second,650.0*Width/1920,-800.0*Width/1920,0.0,0.05);
        }
        Idx=22;
        this->enemymanager.AddOneZako(50,tr("little"),tr("blue"),tr("pig"),400.0*Width/1920,-150.0*Width/1920,400.0*Width/1920,350.0*Width/1920,7.0,-0.049,0,3,0,0);
        break;
    }
    case 1700:
    {
        for(Idx=23;Idx<=27;Idx++)
        {
            qreal x=(20.0+(Idx-23)*260.0)*Width/1920;
            qreal y=(-200.0+qrand()%100)*Width/1920;
            this->enemymanager.AddOneZako(15,tr("little"),tr("blue"),tr("pig"),x,y,x,y+2000.0*Width/1920,1.0,0,0,1,0,0);
        }
        auto tmp=this->enemymanager.zakos.find(22);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->enemymanager.SetOneEnemyMoveMode(&tmp->second,400.0*Width/1920,-800.0*Width/1920,0.0,0.05);
        }
        Idx=28;
        this->enemymanager.AddOneZako(50,tr("little"),tr("red"),tr("pig"),650.0*Width/1920,-150.0*Width/1920,650.0*Width/1920,350.0*Width/1920,7.0,-0.049,3,0,0,0);
        break;
    }
    case 2100:
    {
        for(Idx=29;Idx<=33;Idx++)
        {
            qreal x=(20.0+(Idx-29)*260.0)*Width/1920;
            qreal y=(-200.0+qrand()%100)*Width/1920;
            this->enemymanager.AddOneZako(15,tr("little"),tr("red"),tr("pig"),x,y,x,y+2000.0*Width/1920,1.0,0,1,0,0,0);
        }
        auto tmp=this->enemymanager.zakos.find(28);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->enemymanager.SetOneEnemyMoveMode(&tmp->second,650.0*Width/1920,-800.0*Width/1920,0.0,0.05);
        }
        Idx=34;
        this->enemymanager.AddOneZako(50,tr("little"),tr("blue"),tr("pig"),400.0*Width/1920,-150.0*Width/1920,400.0*Width/1920,350.0*Width/1920,7.0,-0.049,0,3,0,0);
        break;
    }
    case 2500:
    {
        auto tmp=this->enemymanager.zakos.find(34);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->enemymanager.SetOneEnemyMoveMode(&tmp->second,400.0*Width/1920,-800.0*Width/1920,0.0,0.05);
        }
        for(Idx=35;Idx<=37;Idx++)
        {
            qreal x=(-400.0+(Idx-35)*100.0)*Width/1920;
            qreal y=((Idx-35)*60.0)*Width/1920;
            this->enemymanager.AddOneZako(9,tr("little"),tr("red"),tr("pig"),x,y,x+3600.0*Width/1920,y+1500.0*Width/1920,2.0,0.015,2,0,0,0);
        }
        for(Idx=38;Idx<=40;Idx++)
        {
            qreal x=(1500.0-(Idx-38)*100.0)*Width/1920;
            qreal y=((Idx-38)*60.0)*Width/1920;
            this->enemymanager.AddOneZako(9,tr("little"),tr("blue"),tr("pig"),x,y,x-3600.0*Width/1920,y+1500.0*Width/1920,2.0,0.015,0,2,0,0);
        }
        break;
    }
    case 2700:
        for(Idx=41;Idx<=43;Idx++)
        {
            qreal x=(-400.0+(Idx-41)*100.0)*Width/1920;
            qreal y=((Idx-41)*50.0)*Width/1920;
            this->enemymanager.AddOneZako(9,tr("little"),tr("red"),tr("pig"),x,y,x+3600.0*Width/1920,y+1500.0*Width/1920,2.0,0.015,2,0,0,0);
        }
        for(Idx=44;Idx<=46;Idx++)
        {
            qreal x=(1500.0-(Idx-44)*100.0)*Width/1920;
            qreal y=((Idx-44)*50.0)*Width/1920;
            this->enemymanager.AddOneZako(9,tr("little"),tr("blue"),tr("pig"),x,y,x-3600.0*Width/1920,y+1500.0*Width/1920,2.0,0.015,0,2,0,0);
        }
        break;
    case 2900:
        for(Idx=47;Idx<=49;Idx++)
        {
            qreal x=(-400.0+(Idx-47)*100.0)*Width/1920;
            qreal y=((Idx-47)*40.0)*Width/1920;
            this->enemymanager.AddOneZako(9,tr("little"),tr("red"),tr("pig"),x,y,x+3600.0*Width/1920,y+1500.0*Width/1920,2.0,0.015,2,0,0,0);
        }
        for(Idx=50;Idx<=52;Idx++)
        {
            qreal x=(1500.0-(Idx-50)*100.0)*Width/1920;
            qreal y=((Idx-50)*40.0)*Width/1920;
            this->enemymanager.AddOneZako(9,tr("little"),tr("blue"),tr("pig"),x,y,x-3600.0*Width/1920,y+1500.0*Width/1920,2.0,0.015,0,2,0,0);
        }
        break;
    case 3000:
        Idx=54;
        this->enemymanager.AddOneZako(180,tr("big"),tr("rainbow"),tr("pig"),520.0*Width/1920,-250.0*Width/1920,520.0*Width/1920,150.0*Width/1920,8.0,-0.046,10,10,0,0);
        break;
    case 3600:
    {
        auto tmp=this->enemymanager.zakos.find(54);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->enemymanager.SetOneEnemyMoveMode(&tmp->second,520.0*Width/1920,-800.0*Width/1920,0.0,0.08);
        }
        break;
    }
    case 3700:
        Idx=55;
        this->enemymanager.AddOneBoss(500,1,tr("big"),tr("snow"),tr("pig"),tr("???"),-400.0*Width/1920,-100.0*Width/1920,470.0*Width/1920,200.0*Width/1920,12.0,-0.078,15,15,0,0);
        this->enemymanager.bosses[55].tmpcount=3800;
        break;
    case 3750:
        this->bulletmanager.DestoryAllEnemyBullets();
        this->hero->isAbsorbingProps=true;
        this->dialogplayer.speaktimes=0;
        this->dialogplayer.isOnDisplay=true;
        break;
    case 5800://道中boss30s结束
    {
        auto tmp=this->enemymanager.bosses.find(55);
        if(tmp!=this->enemymanager.bosses.end())
        {
            tmp->second.stagelefttime=0;
            this->enemymanager.SetOneEnemyMoveMode(&tmp->second,1900.0*Width/1920,-100.0*Width/1920,0.0,0.1);
        }
        this->background.SetMainBackground(8,0,tr(""));
    }
        break;
    case 6000:
        Idx=56;
        this->enemymanager.AddOneZako(36,tr("big"),tr("rainbow"),tr("pig"),1250.0*Width/1920,180.0*Width/1920,-2000.0*Width/1920,180.0*Width/1920,10.0,-0.045,3,2,0,0);
        Idx=57;
        this->enemymanager.AddOneZako(36,tr("big"),tr("rainbow"),tr("pig"),-200.0*Width/1920,180.0*Width/1920,3000.0*Width/1920,180.0*Width/1920,10.0,-0.045,3,2,0,0);
        break;
    case 6400:
        Idx=58;
        this->enemymanager.AddOneZako(36,tr("big"),tr("rainbow"),tr("pig"),1250.0*Width/1920,180.0*Width/1920,-2000.0*Width/1920,180.0*Width/1920,10.0,-0.042,3,2,0,0);
        Idx=59;
        this->enemymanager.AddOneZako(36,tr("big"),tr("rainbow"),tr("pig"),-200.0*Width/1920,180.0*Width/1920,3000.0*Width/1920,180.0*Width/1920,10.0,-0.048,3,2,0,0);
        break;
    case 6800:
        Idx=60;
        this->enemymanager.AddOneZako(36,tr("big"),tr("rainbow"),tr("pig"),1250.0*Width/1920,180.0*Width/1920,-2000.0*Width/1920,180.0*Width/1920,10.0,-0.048,3,2,0,0);
        Idx=61;
        this->enemymanager.AddOneZako(36,tr("big"),tr("rainbow"),tr("pig"),-200.0*Width/1920,180.0*Width/1920,3000.0*Width/1920,180.0*Width/1920,10.0,-0.042,3,2,0,0);
        break;
    case 7200:
        Idx=62;
        this->enemymanager.AddOneZako(180,tr("big"),tr("rainbow"),tr("pig"),520.0*Width/1920,-250.0*Width/1920,520.0*Width/1920,150.0*Width/1920,8.0,-0.046,10,10,0,0);
        break;
    case 7800:
    {
        auto tmp=this->enemymanager.zakos.find(62);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->enemymanager.SetOneEnemyMoveMode(&tmp->second,520.0*Width/1920,-800.0*Width/1920,0.0,0.08);
        }
        this->background.SetMainBackground(this->background.mainbgspeed,-0.08,tr(""));
        break;
    }
    case 7900:
        this->bulletmanager.DestoryAllEnemyBullets();
        this->hero->isAbsorbingProps=true;
        this->background.SetMainBackground(0,0,tr(""));
        break;
    case 8000:
        this->dialogplayer.speaktimes=3;
        this->dialogplayer.isOnDisplay=true;
        break;
    default:
        if(Count>8000)//boss
        {
            if(this->isFightingBoss==false)
                this->isFightingBoss=true;
            else
            {
                this->GenerateLevel1Boss();
                if(this->enemymanager.bosses.find(63)==this->enemymanager.bosses.end())
                {
                    this->bulletmanager.DestoryAllEnemyBullets();
                    this->hero->isAbsorbingProps=true;
                    if(this->background.mainbgspeed<8)
                    {
                        this->background.SetMainBackground(this->background.mainbgspeed,0.2,tr(""));
                    }
                    else
                    {
                        this->background.SetMainBackground(8,0,tr(""));
                    }
                    if(this->dialogplayer.speaktimes<=13)
                    {
                        this->dialogplayer.isOnDisplay=true;
                    }
                    if(this->dialogplayer.speaktimes<=15)//最后一页对话
                    {
                        this->titleplayer.SetClearTitle(Count+50,Count+400);
                    }
                    if(Count==this->titleplayer.clearendcount+50)
                    {
                        this->soundmanager.ClearEffect.play();
                        emit LevelClearSignal();
                    }
                }
            }
        }
        break;
    }
    //敌机弹幕设置
    switch (Idx) {
    case 11:
        if(Count<450&&Count%80==0&&Difficulty>=2)
        {
            for(auto tmp:this->enemymanager.zakos)
            {
                for(int i=0;i<3*Difficulty-5;i++)
                {
                    this->barragemanager.AddOneAim(&tmp.second,this->hero,tmp.second.collibox.center().x(),tmp.second.collibox.center().y(),1,M_PI/3.0,tr("steel"),tr("ball"),5.0+0.5*i,0.0);
                }
            }
        }
        break;
    case 16:
        if(Count%100==0)
        {
            for(auto tmp:this->enemymanager.zakos)
            {
                if(tmp.second.guid==16)
                    continue;
                for(int i=0;i<4*Difficulty-5;i++)
                {
                    this->barragemanager.AddOneAim(&tmp.second,this->hero,tmp.second.collibox.center().x(),tmp.second.collibox.center().y(),2,M_PI/5.0,tr("steel"),tr("ball"),10.0+0.5*i,0.0);
                }
            }
        }
        if(Count%75==0)
        {
            auto tmp=this->enemymanager.zakos.find(16);
            if(tmp!=this->enemymanager.zakos.end())
            {
                for(int i=0;i<4*Difficulty-3;i++)
                {
                    this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),7+2*i+2*Difficulty,4*M_PI/3.0,tr("wooden"),tr("ball"),6.0-0.5*i+2*Difficulty,0.0);
                }
            }
        }
        break;
    case 22:
        if(Count%100==0)
        {
            for(auto tmp:this->enemymanager.zakos)
            {
                if(tmp.second.guid==22)
                    continue;
                for(int i=0;i<4*Difficulty-5;i++)
                {
                    this->barragemanager.AddOneAim(&tmp.second,this->hero,tmp.second.collibox.center().x(),tmp.second.collibox.center().y(),2,M_PI/5.0,tr("steel"),tr("ball"),10.0+0.5*i,0.0);
                }
            }
        }
        if(Count%75==0)
        {
            auto tmp=this->enemymanager.zakos.find(22);
            if(tmp!=this->enemymanager.zakos.end())
            {
                for(int i=0;i<4*Difficulty-3;i++)
                {
                    this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),7+2*i+2*Difficulty,4*M_PI/3.0,tr("wooden"),tr("ball"),6.0-0.5*i+2*Difficulty,0.0);
                }
            }
        }
        break;
    case 28:
        if(Count%100==0)
        {
            for(auto tmp:this->enemymanager.zakos)
            {
                if(tmp.second.guid==28)
                    continue;
                for(int i=0;i<4*Difficulty-5;i++)
                {
                    this->barragemanager.AddOneAim(&tmp.second,this->hero,tmp.second.collibox.center().x(),tmp.second.collibox.center().y(),2,M_PI/5.0,tr("steel"),tr("ball"),10.0+0.5*i,0.0);
                }
            }
        }
        if(Count%75==0)
        {
            auto tmp=this->enemymanager.zakos.find(28);
            if(tmp!=this->enemymanager.zakos.end())
            {
                for(int i=0;i<4*Difficulty-3;i++)
                {
                    this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),7+2*i+2*Difficulty,4*M_PI/3.0,tr("wooden"),tr("ball"),6.0-0.5*i+2*Difficulty,0.0);
                }
            }
        }
        break;
    case 34:
        if(Count%100==0)
        {
            for(auto tmp:this->enemymanager.zakos)
            {
                if(tmp.second.guid==34)
                    continue;
                for(int i=0;i<4*Difficulty-5;i++)
                {
                    this->barragemanager.AddOneAim(&tmp.second,this->hero,tmp.second.collibox.center().x(),tmp.second.collibox.center().y(),2,M_PI/5.0,tr("steel"),tr("ball"),10.0+0.5*i,0.0);
                }
            }
        }
        if(Count%75==0)
        {
            auto tmp=this->enemymanager.zakos.find(34);
            if(tmp!=this->enemymanager.zakos.end())
            {
                for(int i=0;i<4*Difficulty-3;i++)
                {
                    this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),7+2*i+2*Difficulty,4*M_PI/3.0,tr("wooden"),tr("ball"),6.0-0.5*i+2*Difficulty,0.0);
                }
            }
        }
        break;
    case 41:
    case 47:
    case 53:
    case 54:
    {
        if(Count%20==0)
        {
            for(auto tmp:this->enemymanager.zakos)
            {
                for(int i=0;i<2*Difficulty-1;i++)
                {
                    if(tmp.second.guid==54)
                        continue;
                    if(tmp.second.guid<=34)
                    {
                        this->barragemanager.AddOneAim(&tmp.second,this->hero,tmp.second.collibox.center().x(),tmp.second.collibox.center().y(),2,M_PI/5.0,tr("steel"),tr("ball"),10.0+0.5*i,0.0);
                        continue;
                    }
                    this->barragemanager.AddOneLine(&tmp.second,tmp.second.collibox.center().x(),tmp.second.collibox.center().y(),M_PI/2,tr("red"),tr("arrow"),5.0,1,12.0+Difficulty+1.0*i,0.0);
                }
            }
        }
        auto tmp=this->enemymanager.zakos.find(54);
        if(tmp!=this->enemymanager.zakos.end())
        {
            if((tmp->second.Y>=140.0*Width/1920)&&Count%(10+int(tmp->second.hp)/4)==0)
            {
                this->barragemanager.AddOneRandomCircle(&tmp->second,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),std::min(int(3000.0/tmp->second.hp),5+Difficulty*20),tr("wooden"),tr("pellet"),6,3,0,0);
            }
        }
    }
        break;
    case 55:
        if(Count>3800&&Count<5800)
        {
            this->hero->isAbsorbingProps=false;
            auto tmp=this->enemymanager.bosses.find(55);
            if(tmp!=this->enemymanager.bosses.end())
            {
                tmp->second.stagelefttime=std::max(0.0,30.0-(Count-tmp->second.tmpcount)*0.015);
                if(Count%75==0&&Count%150!=0)
                {
                    this->enemymanager.SetOneEnemyMoveMode(&tmp->second,this->hero->collibox.center().x()-150*Width/1920,tmp->second.Y,12,-72.0/std::abs(this->hero->collibox.center().x()-150*Width/1920-tmp->second.X)*(Width/1920.0));
                }

                if(Count%150==0)
                {
                    for(int i=0;i<4*Difficulty-3;i++)
                    {
                        this->barragemanager.AddOneLine(&tmp->second,tmp->second.collibox.center().x()-75*Width/1920,tmp->second.collibox.center().y(),M_PI/2,tr("snow"),tr("bubble"),5.0,1,6.0+2*i,0.0);
                    }
                    for(int i=0;i<3*Difficulty+1;i++)
                    {
                        this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x()-85.0*Width/1920,tmp->second.collibox.center().y(),20-2*i,11*M_PI/6+i*M_PI/80,tr("snow"),tr("ball"),5.0+i,-0.001,M_PI);
                        this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x()+85.0*Width/1920,tmp->second.collibox.center().y(),20-2*i,11*M_PI/6+i*M_PI/80,tr("snow"),tr("ball"),5.0+i,-0.001,M_PI);
                    }
                }
            }
            else
            {
                //提前击破，增援
                Idx=-1;
            }
        }
        else
        {
            auto tmp=this->enemymanager.bosses.find(55);
            if(tmp!=this->enemymanager.bosses.end())
            {
                tmp->second.setHp(tmp->second.maxhp);
            }
        }
        break;
    case 57:
    case 59:
    case 61:
        if(Count%25==0)
        {
            for(auto tmp:this->enemymanager.zakos)
            {
                if(Idx==57)
                    this->barragemanager.AddOneCircle(&tmp.second,tmp.second.collibox.center().x(),tmp.second.collibox.center().y(),Difficulty*6,tr("purple"),tr("ball"),0,0.1,(Count/25)%4*M_PI/2);
                else if(Idx==59)
                    this->barragemanager.AddOneCircle(&tmp.second,tmp.second.collibox.center().x(),tmp.second.collibox.center().y(),Difficulty*6,tr("orange"),tr("ball"),0,0.1,(Count/25)%4*M_PI/2);
                else if(Idx==61)
                    this->barragemanager.AddOneCircle(&tmp.second,tmp.second.collibox.center().x(),tmp.second.collibox.center().y(),Difficulty*6,tr("green"),tr("ball"),0,0.1,(Count/25)%4*M_PI/2);
            }
        }
        break;
    case 62:
    {
        auto tmp=this->enemymanager.zakos.find(62);
        if(tmp!=this->enemymanager.zakos.end())
        {
            if((tmp->second.Y>=140.0*Width/1920)&&Count%(10+int(tmp->second.maxhp-tmp->second.hp)/4)==0)
            {
                this->barragemanager.AddOneRandomCircle(&tmp->second,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),std::min(int(3000.0/tmp->second.hp),5+Difficulty*20),tr("snow"),tr("pellet"),6,3,0,0);
            }
        }
    }
        break;
    default:
        if(Idx<0)//增援
        {
            if(Count%100==0)
            {
                qreal x=(-200.0)*Width/1920;
                qreal y=(40.0)*Width/1920;
                this->enemymanager.AddOneZako(9,tr("little"),tr("blue"),tr("pig"),x,y,x+3600.0*Width/1920,y+1500.0*Width/1920,2.0,0.025,0,1,0,0);
                Idx--;
                x=(1300.0)*Width/1920;
                y=(40.0)*Width/1920;
                this->enemymanager.AddOneZako(9,tr("little"),tr("blue"),tr("pig"),x,y,x-3600.0*Width/1920,y+1500.0*Width/1920,2.0,0.025,0,1,0,0);
                Idx--;
            }
            if(Count%40==0&&Count%200!=0)
            {
                for(auto tmp:this->enemymanager.zakos)
                {
                    this->barragemanager.AddOneAim(&tmp.second,this->hero,tmp.second.collibox.center().x(),tmp.second.collibox.center().y(),2*Difficulty-1,M_PI/24.0,tr("red"),tr("arrow"),10.0,0.0);
                }
            }
        }
        break;
    }
}
