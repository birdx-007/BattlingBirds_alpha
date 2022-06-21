#include "gameheaders/managerdep.h"
void ManagerDep::GenerateLevel2()
{
    if(this->dialogplayer.isOnDisplay){
        Count--;
        switch (this->dialogplayer.speaktimes) {
        case 0:
            this->dialogplayer.setLeft(QString(":/myimages/res/hero%1.png").arg(Shottype+1));
            this->dialogplayer.setRight(QString(":/myimages/res/knightpig_normal.png"));
            this->dialogplayer.RightSpeak(tr("......"));
            break;
        case 1:
            this->dialogplayer.RightSpeak(tr("我可亲可敬的战士们，看来正面防守已经失效..."));
            break;
        case 2:
            this->dialogplayer.setRight(QString(":/myimages/res/knightpig_shield.png"));
            this->dialogplayer.RightSpeak(tr("那么...出发去敌人的背后吧!\n我来负责掩护!"));
            this->hero->isAbsorbingProps=false;
            this->background.SetMainBackground(8,0,tr(""));
            break;
        case 4:
            this->dialogplayer.setRight(QString(":/myimages/res/knightpig_shield.png"));
            this->dialogplayer.RightSpeak(tr("......"));
            break;
        case 5:
            this->dialogplayer.RightSpeak(tr("何等强悍的战斗力。"));
            break;
        case 6:
            this->dialogplayer.setRight(QString(":/myimages/res/knightpig_normal.png"));
            this->dialogplayer.RightSpeak(tr("作为骑士，请允许我先自我介绍。\n我们是绿猪皇家空中骑士团。\n我就是骑士团的团长。"));
        {
            auto tmp=this->enemymanager.bosses.find(45);
            if(tmp!=this->enemymanager.bosses.end())
            {
                tmp->second.name=tr("骑士团长");
                tmp->second.texture.load(QString(":/myimages/res/enemy_greatknightpig.png"));
            }
        }
            break;
        case 7:
            this->dialogplayer.LeftSpeak(tr("我们是小鸟岛来的鸟儿。\n你们绿猪，究竟想要做什么？"));
            break;
        case 8:
            this->dialogplayer.RightSpeak(tr("骑士不会说谎。\n鸟蛋在我们绿猪眼里，是无上的珍馐。"));
            break;
        case 9:
            this->dialogplayer.RightSpeak(tr("这次我们派遣大量战斗飞行员前来的目的，也正是得到你们的鸟蛋。"));
            break;
        case 10:
            this->dialogplayer.LeftSpeak(tr("...作为骑士，你竟然没有保护弱者(鸟蛋)的觉悟吗？"));
            break;
        case 11:
            this->dialogplayer.RightSpeak(tr("我的保护，正是为了使它们安全地被运回猪猪岛。"));
            break;
        case 12:
            this->dialogplayer.LeftSpeak(tr("看起来已经没有讲道理的余地了呢。\n准备好如一个骑士那般被击落了吗？"));
            break;
        case 13:
            this->dialogplayer.RightSpeak(tr("赌上骑士团的荣耀，绝不会让你们过去!"));
            break;
        case 15:
            this->dialogplayer.LeftSpeak(tr("...真是担心。\n前面究竟还有多少这样的家伙啊。"));
            if(this->background.mainbgspeed<8)
            {
                this->background.SetMainBackground(this->background.mainbgspeed,0.2,tr(""));
            }
            else
            {
                this->background.SetMainBackground(8,0,tr(""));
            }
            break;
        case 16:
            this->dialogplayer.LeftSpeak(tr("......\n没时间担心来担心去了!\n得在天黑之前冲出这片云层才行!"));
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
        this->isFightingBoss=false;
        this->background.SetMainBackground(8,0,tr(""));
        this->titleplayer.SetTitle(50,400);
        this->hero->isAbsorbingProps=false;
        break;
    case 450:
        for(Idx=1;Idx<=5;Idx++)
        {
            qreal x=(50.0+(Idx-1)*50.0)*Width/1920;
            qreal y=(-140.0-(Idx-1)*75.0)*Width/1920;
            this->enemymanager.AddOneZako(15,tr("little"),tr("snow"),tr("pig"),x,y,x,y+5000.0*Width/1920,15.0,-0.1-0.01*(Idx-1),2,2,0,0);
        }
        Idx--;
        break;
    case 600:
        for(Idx=6;Idx<=10;Idx++)
        {
            qreal x=(975.0-(Idx-6)*50.0)*Width/1920;
            qreal y=(-140.0-(Idx-6)*75.0)*Width/1920;
            this->enemymanager.AddOneZako(15,tr("little"),tr("snow"),tr("pig"),x,y,x,y+5000.0*Width/1920,15.0,-0.1-0.01*(Idx-6),2,2,0,0);
        }
        Idx--;
        break;
    case 900:
        Idx=11;
        this->enemymanager.AddOneZako(225,tr("little"),tr("helmet"),tr("pig"),540.0*Width/1920,-250.0*Width/1920,540.0*Width/1920,150.0*Width/1920,8.0,-0.046,15,5,0,0);
        break;
    case 1000:
        for(Idx=12;Idx<=14;Idx++)
        {
            qreal x=(-400.0+(Idx-12)*100.0)*Width/1920;
            qreal y=((Idx-12)*60.0)*Width/1920;
            this->enemymanager.AddOneZako(18,tr("little"),tr("red"),tr("pig"),x,y,x+3600.0*Width/1920,y+500.0*Width/1920,2.0,0.015,2,0,0,0);
        }
        for(Idx=15;Idx<=17;Idx++)
        {
            qreal x=(1500.0-(Idx-15)*100.0)*Width/1920;
            qreal y=((Idx-15)*60.0)*Width/1920;
            this->enemymanager.AddOneZako(18,tr("little"),tr("blue"),tr("pig"),x,y,x-3600.0*Width/1920,y+500.0*Width/1920,2.0,0.015,0,2,0,0);
        }
        break;
    case 1300:
        for(Idx=18;Idx<=22;Idx++)
        {
            qreal x=(-400.0+(Idx-18)*60.0)*Width/1920;
            qreal y=((Idx-18)*70.0)*Width/1920;
            this->enemymanager.AddOneZako(18,tr("little"),tr("red"),tr("pig"),x,y,x+3600.0*Width/1920,y+500.0*Width/1920,2.0,0.01,2,0,0,0);
        }
        for(Idx=23;Idx<=27;Idx++)
        {
            qreal x=(1500.0-(Idx-23)*60.0)*Width/1920;
            qreal y=((Idx-23)*70.0)*Width/1920;
            this->enemymanager.AddOneZako(18,tr("little"),tr("blue"),tr("pig"),x,y,x-3600.0*Width/1920,y+500.0*Width/1920,2.0,0.01,0,2,0,0);
        }
        break;
    case 1600:
    {
        auto tmp=this->enemymanager.zakos.find(11);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->enemymanager.SetOneEnemyMoveMode(&tmp->second,tmp->second.X,-800.0*Width/1920,0.0,0.05);
        }
        for(Idx=28;Idx<=34;Idx++)
        {
            qreal x=(-400.0+(Idx-28)*40.0)*Width/1920;
            qreal y=((Idx-28)*80.0)*Width/1920;
            this->enemymanager.AddOneZako(18,tr("little"),tr("red"),tr("pig"),x,y,x+3600.0*Width/1920,y+500.0*Width/1920,2.0,0.015,2,0,0,0);
        }
        for(Idx=35;Idx<=41;Idx++)
        {
            qreal x=(1500.0-(Idx-35)*40.0)*Width/1920;
            qreal y=((Idx-35)*80.0)*Width/1920;
            this->enemymanager.AddOneZako(18,tr("little"),tr("blue"),tr("pig"),x,y,x-3600.0*Width/1920,y+500.0*Width/1920,2.0,0.015,0,2,0,0);
        }
        Idx--;
    }
        break;
    case 2000:
        Idx=42;
        this->enemymanager.AddOneZako(450,tr("big"),tr("knight"),tr("pig"),520.0*Width/1920,-250.0*Width/1920,520.0*Width/1920,150.0*Width/1920,8.0,-0.078,15,20,0,0);
        Idx=43;
        this->enemymanager.AddOneZako(450,tr("big"),tr("knight"),tr("pig"),120.0*Width/1920,-250.0*Width/1920,120.0*Width/1920,350.0*Width/1920,8.0,-0.052,15,20,0,0);
        Idx=44;
        this->enemymanager.AddOneZako(450,tr("big"),tr("knight"),tr("pig"),920.0*Width/1920,-250.0*Width/1920,920.0*Width/1920,350.0*Width/1920,8.0,-0.052,15,20,0,0);
        break;
    case 2300:
    case 2500:
    case 2700:
    case 2900:
    case 3100:
    case 3200:
    case 3300:
    case 3400:
        if(this->bulletmanager.enemybullets.size()<=150&&this->enemymanager.zakos.size()==0&&this->hero->canActivateSpell)
        {
            Count=3900;
        }
        break;
    case 3500:
    {
        for(auto& tmp:this->enemymanager.zakos)
        {
            this->enemymanager.SetOneEnemyMoveMode(&tmp.second,tmp.second.X,-800.0*Width/1920,0.0,0.05);
        }

    }
        break;
    case 3950:
        this->bulletmanager.DestoryAllEnemyBullets();
        this->hero->isAbsorbingProps=true;
        this->background.SetMainBackground(2,0,tr(""));
        Idx=45;
        this->enemymanager.AddOneBoss(1000,1,tr("great"),tr("knight"),tr("pig"),tr("???"),470.0*Width/1920,-400.0*Width/1920,470.0*Width/1920,200.0*Width/1920,15.0,-0.185,25,25,0,0);
        this->enemymanager.bosses[45].tmpcount=4000;
        break;
    case 6000://道中boss30s结束
    {
        this->bulletmanager.DestoryAllEnemyBullets();
        this->hero->isAbsorbingProps=true;

        auto tmp=this->enemymanager.bosses.find(45);
        if(tmp!=this->enemymanager.bosses.end())
        {
            tmp->second.stagelefttime=0;
            this->dialogplayer.speaktimes=0;
            this->dialogplayer.isOnDisplay=true;
        }
    }
        break;
    case 6050:
        Idx=-1;//绕后战队
        break;
    case 7800:
        Idx=46;
        this->bulletmanager.DestoryAllEnemyBullets();
        this->hero->isAbsorbingProps=true;
        this->background.SetMainBackground(this->background.mainbgspeed,-0.08,tr(""));
        for(auto& tmp:this->enemymanager.zakos)
        {
            this->enemymanager.SetOneEnemyMoveMode(&tmp.second,tmp.second.X,-800.0*Width/1920,0.0,0.1);
        }
        break;
    case 7900:
        this->background.SetMainBackground(0,0,tr(""));
    {
        auto tmp=this->enemymanager.bosses.find(45);
        if(tmp!=this->enemymanager.bosses.end())
        {
            tmp->second.setHp(tmp->second.maxhp);
        }
    }
        break;
    case 8000:
        this->dialogplayer.speaktimes=4;
        this->dialogplayer.isOnDisplay=true;
        this->hero->isAbsorbingProps=false;
        break;
    default:
        if(Count>8000)//boss
        {
            if(this->isFightingBoss==false)
                this->isFightingBoss=true;
            else
            {
                this->GenerateLevel2Boss();
                if(this->enemymanager.bosses.find(45)==this->enemymanager.bosses.end())
                {
                    this->bulletmanager.DestoryAllEnemyBullets();
                    this->enemymanager.DestoryAllZakos();
                    this->hero->isAbsorbingProps=true;
                    if(this->background.mainbgspeed<8)
                    {
                        this->background.SetMainBackground(this->background.mainbgspeed,0.2,tr(""));
                    }
                    else
                    {
                        this->background.SetMainBackground(8,0,tr(""));
                    }
                    if(this->dialogplayer.speaktimes<=15)
                    {
                        this->dialogplayer.isOnDisplay=true;
                    }
                    if(this->dialogplayer.speaktimes<=16)//最后一页对话
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
    case 5:
        for(auto tmp:this->enemymanager.zakos)
        {
            if(std::abs(tmp.second.speed)<0.05)
                this->barragemanager.AddOneCircle(&tmp.second,tmp.second.collibox.center().x(),tmp.second.collibox.center().y(),Difficulty*6,tr("snow"),tr("bigball"),5.0,-0.1,tmp.second.guid);
            if(tmp.second.hp==0)//死尸弹
            {
                this->barragemanager.AddOneCircle(&tmp.second,tmp.second.collibox.center().x(),tmp.second.collibox.center().y(),Difficulty*6,tr("red"),tr("ball"),5.0,-0.1,tmp.second.guid+5);
            }
        }
        break;
    case 10:
        for(auto tmp:this->enemymanager.zakos)
        {
            if(std::abs(tmp.second.speed)<0.05)
                this->barragemanager.AddOneCircle(&tmp.second,tmp.second.collibox.center().x(),tmp.second.collibox.center().y(),Difficulty*6,tr("snow"),tr("bigball"),5.0,-0.1,-tmp.second.guid+5);
            if(tmp.second.hp==0)//死尸弹
            {
                this->barragemanager.AddOneCircle(&tmp.second,tmp.second.collibox.center().x(),tmp.second.collibox.center().y(),Difficulty*6,tr("red"),tr("ball"),5.0,-0.1,-tmp.second.guid+5);
            }
        }
        break;
    case 11:
    case 18:
    case 28:
    case 41:
    {
        auto tmp=this->enemymanager.zakos.find(11);
        if(tmp!=this->enemymanager.zakos.end())
        {
            if(Count<1600&&Count%35==0&&Count%70!=0)
            {
                this->enemymanager.SetOneEnemyRandomMode(&tmp->second,200.0*Width/1920,700.0*Width/1920,100.0*Width/1920,200.0*Width/1920,8.0);
                this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),2*Difficulty,M_PI/8,tr("blue"),tr("ball"),5.0,0,0);
            }
            if(tmp->second.hp==0)//死尸弹
            {
                for(int i=0;i<Difficulty*6;i++)
                    this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),3*Difficulty,M_PI/3,tr("red"),tr("ball"),2.0+0.5*i,0,0);
            }
        }
        for(auto tmp:this->enemymanager.zakos)
        {
            if(tmp.second.guid==11)
                continue;
            if(Count%70==0)
                this->barragemanager.AddOneRandomCircle(&tmp.second,tmp.second.collibox.center().x(),tmp.second.collibox.center().y(),Difficulty*3,tr("snow"),tr("bigball"),6.0,3.0,0,0);
            if(tmp.second.hp==0)//死尸弹
            {
                this->barragemanager.AddOneCircle(&tmp.second,tmp.second.collibox.center().x(),tmp.second.collibox.center().y(),Difficulty*4,tr("red"),tr("ball"),5.0,-0.1,Count);
            }
        }
    }
        break;
    case 44:
    {
        for(auto tmp:this->enemymanager.zakos)
        {
            if(Count%700==0)
            {
                for(int i=0;i<Difficulty*3;i++)
                    this->barragemanager.AddOneAim(&tmp.second,this->hero,tmp.second.collibox.center().x(),tmp.second.collibox.center().y(),15+2*Difficulty,2*M_PI,tr("red"),tr("ball"),0.5+0.3*i,-0.0001*i,0);
            }
            if(Count%60==0)
            {
                this->barragemanager.AddOneRandomCircle(&tmp.second,tmp.second.collibox.center().x(),tmp.second.collibox.center().y(),Difficulty*7,tr("snow"),tr("bigball"),8.0,3.0,0,0);
            }
            if(tmp.second.hp==0)//死尸弹
            {
                for(int i=0;i<Difficulty*3;i++)
                    this->barragemanager.AddOneAim(&tmp.second,this->hero,tmp.second.collibox.center().x(),tmp.second.collibox.center().y(),15+2*Difficulty,2*M_PI,tr("blue"),tr("ball"),5+0.5*i+Difficulty,0,0);
            }
        }
    }
        break;
    case 45:
        if(Count>4000&&Count<6000)
        {
            this->hero->isAbsorbingProps=false;
            auto tmp=this->enemymanager.bosses.find(45);
            if(tmp!=this->enemymanager.bosses.end())
            {
                if(tmp->second.hp>=100)
                {
                    tmp->second.stagelefttime=std::max(0.0,30.0-(Count-tmp->second.tmpcount)*0.015);
                    if(Count%(10)==0&&(Count/(10))%10!=0)
                    {
                        this->barragemanager.AddOneCircle(&tmp->second,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),Difficulty*6,tr("rock"),tr("bigball"),5.0,0,Count*1.8*Difficulty);
                    }
                    if(Count%100==0)
                    {
                        for(int i=0;i<10;i++)
                            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),1,0,tr("purple"),tr("ball"),10.0+0.5*i-Difficulty*2.5,0,0);
                    }
                }
                else
                {
                    //提前击破(把血量打到100)，进入对话，无增援
                    //Idx=-1;
                    Count=5999;
                    tmp->second.setHp(tmp->second.maxhp);
                    this->GenerateProp(&tmp->second);
                }
            }
        }
        else
        {
            auto tmp=this->enemymanager.bosses.find(45);
            if(tmp!=this->enemymanager.bosses.end())
            {
                if(Count>6000&&Count<6005)
                    tmp->second.texture.load(QString(":/myimages/res/enemy_greatshieldpig.png"));
                tmp->second.setHp(tmp->second.maxhp);
            }
        }
        break;
    case 46:
    {
        auto tmp=this->enemymanager.bosses.find(45);
        if(tmp!=this->enemymanager.bosses.end())
        {
            qreal distance=qSqrt((tmp->second.X-470.0*Width/1920)*(tmp->second.X-470.0*Width/1920)+(tmp->second.Y-200.0*Width/1920)*(tmp->second.Y-200.0*Width/1920));
            this->enemymanager.SetOneEnemyMoveMode(&tmp->second,470.0*Width/1920,200.0*Width/1920,8.0,distance!=0.0?-64.0/(2.0*distance*1920/Width):0);
            tmp->second.hp=tmp->second.maxhp=6000;
            tmp->second.maxstage=5;
            tmp->second.stage=1;
            tmp->second.stagelefttime=30;
            tmp->second.tmpcount=7950;
        }
        Idx=47;
    }
        break;
    default:
        if(Idx<0)//绕后战队
        {
            auto tmp=this->enemymanager.bosses.find(45);
            if(tmp!=this->enemymanager.bosses.end())
            {
                tmp->second.stagelefttime=std::max(0.0,(7800-Count)*0.015);
                tmp->second.setHp(tmp->second.maxhp);
                if(Count%100==0)
                {
                    this->enemymanager.SetOneEnemyRandomMode(&tmp->second,150.0*Width/1920,750.0*Width/1920,100.0*Width/1920,200.0*Width/1920,8.0);
                }
                if(Count%100==50)
                {
                    for(int i=0;i<10;i++)
                        this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),4,2*M_PI/3,tr("purple"),tr("ball"),10.0+0.5*i-Difficulty*2.5,0,0);
                    qreal x=tmp->second.targetx+100.0*Width/1920;
                    qreal y=(-200.0)*Width/1920;
                    this->enemymanager.AddOneZako(75,tr("little"),tr("helmet"),tr("pig"),x,y,x,y+1800.0*Width/1920,6.0,-0.05,2,4,0,0);
                    Idx--;
                }
            }
            for(auto& tmp:this->enemymanager.zakos)
            {
                if(std::abs(tmp.second.speed)<0.05)
                {
                    this->barragemanager.AddOneCircle(&tmp.second,tmp.second.collibox.center().x(),tmp.second.collibox.center().y(),Difficulty*6,tr("blue"),tr("ball"),5.0,-0.1,tmp.second.guid);
                    this->enemymanager.SetOneEnemyMoveMode(&tmp.second,tmp.second.X,1550.0*Width/1920,0.0,0.2);
                }
                if(tmp.second.Y>1500*Width/1920)
                    this->enemymanager.SetOneEnemyMoveMode(&tmp.second,tmp.second.X,-800.0*Width/1920,0.0,0.1);
                if(tmp.second.targety==-800.00*Width/1920)
                {
                    if(Count%100==0&&tmp.second.Y>300.0*Width/1920)
                    {
                        this->barragemanager.AddOneAim(&tmp.second,this->hero,tmp.second.collibox.center().x(),tmp.second.collibox.center().y(),Difficulty*2-1,M_PI/9,tr("red"),tr("ball"),5.0,0,0);
                    }
                }
            }
        }
        break;
    }
}
