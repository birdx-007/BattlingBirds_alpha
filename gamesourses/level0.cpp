#include "gameheaders/managerdep.h"
void ManagerDep::GenerateLevel0()
{
    if(this->dialogplayer.isOnDisplay){
        Count--;
        switch (this->dialogplayer.speaktimes) {
        case 0:
            this->dialogplayer.LeftSpeak(tr("......"));
            break;
        case 1:
            this->dialogplayer.LeftSpeak(tr("一听说鸟蛋被盗就让我们立马来这里...\n可这里到底是什么地方？"));
            break;
        case 2:
            this->dialogplayer.setRight(QString(":/myimages/res/tutorpig_unknown.png"));
            this->dialogplayer.RightSpeak(tr("！！！\n\n很久都没有鸟儿来过这里了！看来那些家伙又开始行动了..."));
            break;
        case 3:
            this->dialogplayer.LeftSpeak(tr("？！哪里传来的声音？！"));
            break;
        case 4:
            this->dialogplayer.RightSpeak(tr("在你们看不到的某处哦。\n重要的不是我是谁，而是你们要在这里做的事情。"));
            break;
        case 5:
            this->dialogplayer.LeftSpeak(tr("......?"));
            break;
        case 6:
            this->dialogplayer.RightSpeak(tr("我就不卖关子了：这里是传授使用弹弓作战的初级训练场；\n（小声）也就是所谓的初级游戏教程呢"));
            break;
        case 7:
            this->dialogplayer.RightSpeak(tr("...咳咳，总之，先尝试按下↑↓←→方向键\n以及左shift键、z键试试吧!"));
            break;
        case 9:
            this->dialogplayer.RightSpeak(tr("......"));
            break;
        case 10:
            this->dialogplayer.RightSpeak(tr("习惯得还不错嘛。\n\n总之，方向键移动，z射击，shift切换高低速形态。\n（高低速除了移动速度不同，功能也有所不同，好好利用吧）\n（其实还有x释放强力技，不过等日后在战场上再体验威力吧...）"));
            break;
        case 11:
            this->dialogplayer.RightSpeak(tr("不过，战场上不可能只有你们...\n尝试消灭接下来这波敌人吧！"));
            break;
        case 13:
            if(this->enemymanager.zakos.size()>0){
                this->dialogplayer.RightSpeak(tr("...看起来没能够消灭所有敌人...还需努力呢。"));
            }
            else{
                this->dialogplayer.RightSpeak(tr("很好！不过这只是开始！"));
            }
            break;
        case 14:
            this->enemymanager.DestoryAllZakos();
            this->bulletmanager.DestoryAllEnemyBullets();
            this->dialogplayer.LeftSpeak(tr("真是棘手...\n今后也要面对这样的敌人吗？"));
            break;
        case 15:
            this->dialogplayer.RightSpeak(tr("呵呵，这种程度可不能称作棘手。\n真实的敌人不仅会有更厚的装甲、还会进行攻击。"));
            break;
        case 16:
            this->dialogplayer.RightSpeak(tr("而你们的目标，就是在不被敌人子弹击中的前提下打败敌人！\n...不过考虑到你们的程度，就让我给你们一点指导吧；"));
            break;
        case 17:
            this->dialogplayer.RightSpeak(tr("1.关于右方状态栏：\n弹弓数:剩余的可重新飞行次数，也就是“复活币”\n强力技:剩余的“清屏炸弹”数目（数量有限、谨慎使用）\n火力:射击的强度（击倒敌人升火力，被击中降火力）\n\n（不过为了帮助你们训练，这一关不许使用强力技，火力也锁定为最低。不过有足够的弹弓！）"));
            break;
        case 18:
            this->dialogplayer.RightSpeak(tr("2.关于自机判定点：\n你们的中弹判定其实很小！\n切换到低速模式时判定点就会显示出来。"));
            break;
        case 19:
            this->dialogplayer.RightSpeak(tr("3.关于子弹判定点：\n事实上敌人的子弹也没有看起来的那么大！\n（作为教程关，这一关会显示敌人子弹的判定，以便熟悉）"));
            break;
        case 20:
            this->dialogplayer.RightSpeak(tr("4.关于敌人与弹幕：\n你们面对的敌人一般会在到达指定位置才放出弹幕！\n所以如果能在那之前打倒敌人的话就再好不过了~"));
            break;
        case 21:
            this->dialogplayer.RightSpeak(tr("5.关于强力技的使用：\n每一次起飞都会把强力技初始化为3个！\n所以说在被击中前没有用完强力技可是很亏的，请尽量避免..."));
            break;
        case 22:
            this->dialogplayer.RightSpeak(tr("最后，稍微讲一讲常见的弹幕类型和应对方法吧。"));
            break;
        case 23:
            this->dialogplayer.RightSpeak(tr("①固定弹、随机弹：\n发射模式或者弹幕形状固定/随机的弹幕。\n随机弹没有什么特殊的应对办法...固定弹熟悉发射模式后就会变得很简单！"));
            break;
        case 24:
            this->dialogplayer.RightSpeak(tr("②自机狙（及变种奇数弹、偶数弹）:\n特意瞄准（狙）你们（自机）而发射的弹幕！\n面对自机狙时切忌胡乱大幅移动，一般的应对方法是“微移”与“折返”："));
            break;
        case 25:
            this->dialogplayer.RightSpeak(tr("微移是躲避自机狙的一般方法，具体操作顾名思义，沿同一个方向每次移动很小的距离即可；\n折返是面对大量长时间自机狙时常用的方法，具体做法是朝一个方向移动一大步以进行引弹，引好后继续反方向微移。"));
            break;
        case 26:
            this->dialogplayer.RightSpeak(tr("......最基础的部分大概就是这些。\n\n多说无益，剩下的就要靠你们自己去熟悉了！"));
            break;
        case 27:
            this->dialogplayer.setRight(tr(""));
            this->dialogplayer.RightSpeak(tr("待会儿见！......"));
            break;
        case 28:
            this->dialogplayer.LeftSpeak(tr("...不见了！\n\n看起来前面还有更多的敌人...只能上了！"));
            break;
        case 30:
            this->dialogplayer.setRight(QString(":/myimages/res/tutorpig_unknown.png"));
            this->dialogplayer.RightSpeak(tr("...不错嘛。"));
            break;
        case 31:
            this->dialogplayer.RightSpeak(tr("不知道你们有没有留意，之前所讲的固定弹、随机弹、自机狙，刚才你们已经全部见识过了！\n让即将飞向天空中的战场的战士熟悉这些基本的知识和技巧，正是设立这个训练场的目的。"));
            break;
        case 32:
            this->dialogplayer.RightSpeak(tr("...而这里就将是你们训练的最后一站了！\n在真实的战场上，每一道关卡的尽头都会有一个这样的镇守者，而与镇守者战斗会比你们先前所见的杂鱼战斗要困难得多。"));
            break;
        case 33:
            this->dialogplayer.RightSpeak(tr("不过，既然你们抵达了这里，就说明你们已经准备好了！\n\n优雅地打倒它，向天空展示你们愤怒的力量吧！"));
            break;
        case 35:
            this->dialogplayer.RightSpeak(tr("...干得漂亮！"));
            break;
        case 36:
            this->dialogplayer.LeftSpeak(tr("哈...终于...结束了吗？"));
            break;
        case 37:
            this->dialogplayer.RightSpeak(tr("从最初级的程度上来说，是的。你们出色地完成了我所能给你们准备的最难挑战！\n（它甚至可能比你们日后遇到的某些镇守者还要可怕呢）"));
            break;
        case 38:
            this->dialogplayer.LeftSpeak(tr("那么，接下来要...?"));
            break;
        case 39:
            this->dialogplayer.RightSpeak(tr("看看北方的天空吧。"));
            break;
        case 40:
            this->dialogplayer.LeftSpeak(tr("那是...!天空中出现了很多奇怪的飞行物啊!"));
            break;
        case 41:
            this->dialogplayer.RightSpeak(tr("通过我的挑战来到了这里，就代表你们已经下定夺回鸟蛋的决心了。"));
            break;
        case 42:
            this->dialogplayer.RightSpeak(tr("能让你们到达这里并且看到第一个目标，我的任务就完成了。\n...祝你们好运!..."));
            break;
        case 43:
            this->dialogplayer.setRight(tr(""));
            this->dialogplayer.LeftSpeak(tr("又不见了!\n事不宜迟，向北方的天空进发!"));
            break;
        default:
            this->dialogplayer.isOnDisplay=false;
            if(this->dialogplayer.speaktimes<44)
                this->dialogplayer.speaktimes++;
            this->dialogplayer.LeftSpeak("");
            this->dialogplayer.RightSpeak("");
            break;
        }
        return;
    }
    switch (Count) {
    case 50:
        this->dialogplayer.setLeft(QString(":/myimages/res/hero%1.png").arg(Shottype+1));
        this->dialogplayer.isOnDisplay=true;
        this->titleplayer.SetTitle(75,425);
        this->isFightingBoss=false;
        break; 
    case 450:
        this->dialogplayer.speaktimes=9;
        this->dialogplayer.isOnDisplay=true;
        break;
    case 500:
        Idx=1;
        this->enemymanager.AddOneZako(40,tr("little"),tr(""),tr("target"),280.0*Width/1920,-300.0*Width/1920,780.0*Width/1920,550.0*Width/1920,2.0,0.01,0,5,0,0);
        Idx=2;
        this->enemymanager.AddOneZako(40,tr("little"),tr(""),tr("target"),880.0*Width/1920,-300.0*Width/1920,380.0*Width/1920,550.0*Width/1920,2.0,0.01,0,5,0,0);
        break;
    case 800:
    {
        auto tmp=this->enemymanager.zakos.find(1);
        if(tmp!=this->enemymanager.zakos.end())
            this->enemymanager.SetOneEnemyMoveMode(&tmp->second,880.0*Width/1920,-300.0*Width/1920,1.0,0.01);
        tmp=this->enemymanager.zakos.find(2);
        if(tmp!=this->enemymanager.zakos.end())
            this->enemymanager.SetOneEnemyMoveMode(&tmp->second,280.0*Width/1920,-300.0*Width/1920,1.0,0.01);
    }
        Idx=3;
        this->enemymanager.AddOneZako(40,tr("little"),tr(""),tr("target"),280.0*Width/1920,-300.0*Width/1920,680.0*Width/1920,550.0*Width/1920,2.0,0.01,0,5,0,0);
        Idx=4;
        this->enemymanager.AddOneZako(40,tr("little"),tr(""),tr("target"),880.0*Width/1920,-300.0*Width/1920,480.0*Width/1920,550.0*Width/1920,2.0,0.01,0,5,0,0);
        break;
    case 1100:
    {
        auto tmp=this->enemymanager.zakos.find(3);
        if(tmp!=this->enemymanager.zakos.end())
            this->enemymanager.SetOneEnemyMoveMode(&tmp->second,880.0*Width/1920,-300.0*Width/1920,1.0,0.01);
        tmp=this->enemymanager.zakos.find(4);
        if(tmp!=this->enemymanager.zakos.end())
            this->enemymanager.SetOneEnemyMoveMode(&tmp->second,280.0*Width/1920,-300.0*Width/1920,1.0,0.01);
    }
        Idx=5;
        this->enemymanager.AddOneZako(40,tr("little"),tr(""),tr("target"),280.0*Width/1920,-300.0*Width/1920,680.0*Width/1920,550.0*Width/1920,2.0,0.01,0,5,0,0);
        Idx=6;
        this->enemymanager.AddOneZako(40,tr("little"),tr(""),tr("target"),880.0*Width/1920,-300.0*Width/1920,480.0*Width/1920,550.0*Width/1920,2.0,0.01,0,5,0,0);
        break;
    case 1400:
    {
        auto tmp=this->enemymanager.zakos.find(5);
        if(tmp!=this->enemymanager.zakos.end())
            this->enemymanager.SetOneEnemyMoveMode(&tmp->second,880.0*Width/1920,-300.0*Width/1920,1.0,0.01);
        tmp=this->enemymanager.zakos.find(6);
        if(tmp!=this->enemymanager.zakos.end())
            this->enemymanager.SetOneEnemyMoveMode(&tmp->second,280.0*Width/1920,-300.0*Width/1920,1.0,0.01);
    }
        break;
    case 1500:
    {
        int a=0;
        auto tmp=this->enemymanager.zakos.find(5);
        if(tmp!=this->enemymanager.zakos.end())
            a++;
        tmp=this->enemymanager.zakos.find(6);
        if(tmp!=this->enemymanager.zakos.end())
            a++;
        if(a==0)
        {
            //全击破，增援
            Idx=-1;
            this->enemymanager.AddOneZako(6,tr("little"),tr(""),tr("target"),-200.0*Width/1920,200.0*Width/1920,1800.0*Width/1920,200.0*Width/1920,12.0,0,0,1,0,0);
            Idx=-2;
            this->enemymanager.AddOneZako(6,tr("little"),tr(""),tr("target"),-200.0*Width/1920,400.0*Width/1920,1800.0*Width/1920,400.0*Width/1920,15.0,0.1,0,1,0,0);
        }
    }
        break;
    case 1575:
    {
        int a=0;
        auto tmp=this->enemymanager.zakos.find(5);
        if(tmp!=this->enemymanager.zakos.end())
            a++;
        tmp=this->enemymanager.zakos.find(6);
        if(tmp!=this->enemymanager.zakos.end())
            a++;
        if(a==0)
        {
            //全击破，增援
            Idx=-3;
            this->enemymanager.AddOneZako(6,tr("little"),tr(""),tr("target"),1250.0*Width/1920,250.0*Width/1920,-800.0*Width/1920,250.0*Width/1920,15.0,0.1,0,1,0,0);
            Idx=-4;
            this->enemymanager.AddOneZako(6,tr("little"),tr(""),tr("target"),1250.0*Width/1920,450.0*Width/1920,-800.0*Width/1920,450.0*Width/1920,12.0,0,0,1,0,0);
        }
    }
        break;
    case 1650:
    {
        int a=0;
        auto tmp=this->enemymanager.zakos.find(5);
        if(tmp!=this->enemymanager.zakos.end())
            a++;
        tmp=this->enemymanager.zakos.find(6);
        if(tmp!=this->enemymanager.zakos.end())
            a++;
        if(a==0)
        {
            //全击破，增援
            Idx=-5;
            this->enemymanager.AddOneZako(6,tr("little"),tr(""),tr("target"),-200.0*Width/1920,100.0*Width/1920,1800.0*Width/1920,100.0*Width/1920,15.0,0,0,1,0,0);
            Idx=-6;
            this->enemymanager.AddOneZako(6,tr("little"),tr(""),tr("target"),1250.0*Width/1920,300.0*Width/1920,-800.0*Width/1920,300.0*Width/1920,15.0,0,0,1,0,0);
        }
    }
        break;
    case 1800:
        this->dialogplayer.speaktimes=13;
        this->dialogplayer.isOnDisplay=true;
        break;
    case 1850:
        Idx=7;
        this->enemymanager.AddOneZako(50,tr("little"),tr(""),tr("target"),130.0*Width/1920,-200.0*Width/1920,130.0*Width/1920,800.0*Width/1920,6.0,-0.025,0,5,0,0);
        break;
    case 1900:
        Idx=8;
        this->enemymanager.AddOneZako(50,tr("little"),tr(""),tr("target"),330.0*Width/1920,-200.0*Width/1920,330.0*Width/1920,800.0*Width/1920,6.0,-0.025,0,5,0,0);
        break;
    case 1950:
        Idx=9;
        this->enemymanager.AddOneZako(50,tr("little"),tr(""),tr("target"),530.0*Width/1920,-200.0*Width/1920,530.0*Width/1920,800.0*Width/1920,6.0,-0.025,0,5,0,0);
        break;
    case 2000:
        Idx=10;
        this->enemymanager.AddOneZako(50,tr("little"),tr(""),tr("target"),730.0*Width/1920,-200.0*Width/1920,730.0*Width/1920,800.0*Width/1920,6.0,-0.025,0,5,0,0);
        break;
    case 2050:
        Idx=11;
        this->enemymanager.AddOneZako(50,tr("little"),tr(""),tr("target"),930.0*Width/1920,-200.0*Width/1920,930.0*Width/1920,800.0*Width/1920,6.0,-0.025,0,5,0,0);
        break;
    case 2100:
    {
        auto tmp=this->enemymanager.zakos.find(7);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneCircle(&tmp->second,tmp->second.X+tmp->second.colliX/2.0,tmp->second.Y+tmp->second.colliY/2.0,12,tr("wooden"),tr("ball"),12.0,0.0);
            this->barragemanager.AddOneCircle(&tmp->second,tmp->second.X+tmp->second.colliX/2.0,tmp->second.Y+tmp->second.colliY/2.0,11,tr("wooden"),tr("ball"),11.0,0.0);
            this->barragemanager.AddOneCircle(&tmp->second,tmp->second.X+tmp->second.colliX/2.0,tmp->second.Y+tmp->second.colliY/2.0,10,tr("wooden"),tr("ball"),10.0,0.0);
        }
            break;
    }
    case 2150:
    {
        auto tmp=this->enemymanager.zakos.find(8);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneCircle(&tmp->second,tmp->second.X+tmp->second.colliX/2.0,tmp->second.Y+tmp->second.colliY/2.0,12,tr("wooden"),tr("ball"),12.0,0.0);
            this->barragemanager.AddOneCircle(&tmp->second,tmp->second.X+tmp->second.colliX/2.0,tmp->second.Y+tmp->second.colliY/2.0,11,tr("wooden"),tr("ball"),11.0,0.0);
            this->barragemanager.AddOneCircle(&tmp->second,tmp->second.X+tmp->second.colliX/2.0,tmp->second.Y+tmp->second.colliY/2.0,10,tr("wooden"),tr("ball"),10.0,0.0);
        }
        break;
    }
    case 2200:
    {
        auto tmp=this->enemymanager.zakos.find(9);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneCircle(&tmp->second,tmp->second.X+tmp->second.colliX/2.0,tmp->second.Y+tmp->second.colliY/2.0,12,tr("wooden"),tr("ball"),12.0,0.0);
            this->barragemanager.AddOneCircle(&tmp->second,tmp->second.X+tmp->second.colliX/2.0,tmp->second.Y+tmp->second.colliY/2.0,11,tr("wooden"),tr("ball"),11.0,0.0);
            this->barragemanager.AddOneCircle(&tmp->second,tmp->second.X+tmp->second.colliX/2.0,tmp->second.Y+tmp->second.colliY/2.0,10,tr("wooden"),tr("ball"),10.0,0.0);
        }
        break;
    }
    case 2250:
    {
        auto tmp=this->enemymanager.zakos.find(10);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneCircle(&tmp->second,tmp->second.X+tmp->second.colliX/2.0,tmp->second.Y+tmp->second.colliY/2.0,12,tr("wooden"),tr("ball"),12.0,0.0);
            this->barragemanager.AddOneCircle(&tmp->second,tmp->second.X+tmp->second.colliX/2.0,tmp->second.Y+tmp->second.colliY/2.0,11,tr("wooden"),tr("ball"),11.0,0.0);
            this->barragemanager.AddOneCircle(&tmp->second,tmp->second.X+tmp->second.colliX/2.0,tmp->second.Y+tmp->second.colliY/2.0,10,tr("wooden"),tr("ball"),10.0,0.0);
        }
        break;
    }
    case 2300:
    {
        auto tmp=this->enemymanager.zakos.find(11);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneCircle(&tmp->second,tmp->second.X+tmp->second.colliX/2.0,tmp->second.Y+tmp->second.colliY/2.0,12,tr("wooden"),tr("ball"),12.0,0.0);
            this->barragemanager.AddOneCircle(&tmp->second,tmp->second.X+tmp->second.colliX/2.0,tmp->second.Y+tmp->second.colliY/2.0,11,tr("wooden"),tr("ball"),11.0,0.0);
            this->barragemanager.AddOneCircle(&tmp->second,tmp->second.X+tmp->second.colliX/2.0,tmp->second.Y+tmp->second.colliY/2.0,10,tr("wooden"),tr("ball"),10.0,0.0);
        }
        break;
    }
    case 2400:
        Idx=12;
        this->enemymanager.AddOneZako(12,tr("little"),tr(""),tr("target"),-200.0*Width/1920,200.0*Width/1920,1800.0*Width/1920,200.0*Width/1920,10.0,0,0,4,0,0);
        Idx=13;
        this->enemymanager.AddOneZako(12,tr("little"),tr(""),tr("target"),1250.0*Width/1920,400.0*Width/1920,-800.0*Width/1920,400.0*Width/1920,10.0,0,0,4,0,0);
        break;
    case 2425:
        Idx=14;
        this->enemymanager.AddOneZako(12,tr("little"),tr(""),tr("target"),-200.0*Width/1920,200.0*Width/1920,1800.0*Width/1920,200.0*Width/1920,10.0,0,0,4,0,0);
        Idx=15;
        this->enemymanager.AddOneZako(12,tr("little"),tr(""),tr("target"),1250.0*Width/1920,400.0*Width/1920,-800.0*Width/1920,400.0*Width/1920,10.0,0,0,4,0,0);
        break;
    case 2450:
        Idx=16;
        this->enemymanager.AddOneZako(12,tr("little"),tr(""),tr("target"),-200.0*Width/1920,200.0*Width/1920,1800.0*Width/1920,200.0*Width/1920,10.0,0,0,4,0,0);
        Idx=17;
        this->enemymanager.AddOneZako(12,tr("little"),tr(""),tr("target"),1250.0*Width/1920,400.0*Width/1920,-800.0*Width/1920,400.0*Width/1920,10.0,0,0,4,0,0);
    {
        auto tmp=this->enemymanager.zakos.find(12);
        if(tmp!=this->enemymanager.zakos.end())
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),3,M_PI/3.0,tr("wooden"),tr("ball"),12.0,0.0);
        tmp=this->enemymanager.zakos.find(13);
        if(tmp!=this->enemymanager.zakos.end())
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),3,M_PI/3.0,tr("wooden"),tr("ball"),12.0,0.0);
    }
        break;
    case 2475:
    {
        auto tmp=this->enemymanager.zakos.find(14);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),3,M_PI/3.0,tr("wooden"),tr("ball"),12.0,0.0);
            this->barragemanager.AddOneCircle(&tmp->second,tmp->second.X+tmp->second.colliX/2.0,tmp->second.Y+tmp->second.colliY/2.0,18,tr("wooden"),tr("ball"),3.5,0.0);
            this->barragemanager.AddOneCircle(&tmp->second,tmp->second.X+tmp->second.colliX/2.0,tmp->second.Y+tmp->second.colliY/2.0,36,tr("glass"),tr("bubble"),0.0,0.03);
        }
        tmp=this->enemymanager.zakos.find(15);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),3,M_PI/3.0,tr("wooden"),tr("ball"),12.0,0.0);
            this->barragemanager.AddOneCircle(&tmp->second,tmp->second.X+tmp->second.colliX/2.0,tmp->second.Y+tmp->second.colliY/2.0,18,tr("wooden"),tr("ball"),3.5,0.0);
            this->barragemanager.AddOneCircle(&tmp->second,tmp->second.X+tmp->second.colliX/2.0,tmp->second.Y+tmp->second.colliY/2.0,36,tr("glass"),tr("bubble"),0.0,0.03);
        }
    }
        break;
    case 2500:
    {
        auto tmp=this->enemymanager.zakos.find(16);
        if(tmp!=this->enemymanager.zakos.end())
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),3,M_PI/3.0,tr("wooden"),tr("ball"),12.0,0.0);
        tmp=this->enemymanager.zakos.find(17);
        if(tmp!=this->enemymanager.zakos.end())
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),3,M_PI/3.0,tr("wooden"),tr("ball"),12.0,0.0);
    }
        break;
    case 2650:
        Idx=18;
        this->enemymanager.AddOneZako(10,tr("little"),tr(""),tr("target"),150.0*Width/1920,-200.0*Width/1920,150.0*Width/1920,1800.0*Width/1920,12.0,0,0,2,0,0);
        break;
    case 2675:
        Idx=19;
        this->enemymanager.AddOneZako(10,tr("little"),tr(""),tr("target"),150.0*Width/1920,-200.0*Width/1920,150.0*Width/1920,1800.0*Width/1920,12.0,0,0,2,0,0);
        for(auto tmp:this->enemymanager.zakos)
        {
            this->barragemanager.AddOneAim(&tmp.second,this->hero,tmp.second.collibox.center().x(),tmp.second.collibox.center().y(),1,M_PI/3.0,tr("wooden"),tr("ball"),16.0,0.0);
            this->barragemanager.AddOneAim(&tmp.second,this->hero,tmp.second.collibox.center().x(),tmp.second.collibox.center().y(),1,M_PI/3.0,tr("wooden"),tr("ball"),17.0,0.0);
            this->barragemanager.AddOneAim(&tmp.second,this->hero,tmp.second.collibox.center().x(),tmp.second.collibox.center().y(),1,M_PI/3.0,tr("wooden"),tr("ball"),18.0,0.0);
        }
        break;
    case 2700:
        Idx=20;
        this->enemymanager.AddOneZako(10,tr("little"),tr(""),tr("target"),150.0*Width/1920,-200.0*Width/1920,150.0*Width/1920,1800.0*Width/1920,12.0,0,0,2,0,0);
        for(auto tmp:this->enemymanager.zakos)
        {
            this->barragemanager.AddOneAim(&tmp.second,this->hero,tmp.second.collibox.center().x(),tmp.second.collibox.center().y(),1,M_PI/3.0,tr("wooden"),tr("ball"),16.0,0.0);
            this->barragemanager.AddOneAim(&tmp.second,this->hero,tmp.second.collibox.center().x(),tmp.second.collibox.center().y(),1,M_PI/3.0,tr("wooden"),tr("ball"),17.0,0.0);
            this->barragemanager.AddOneAim(&tmp.second,this->hero,tmp.second.collibox.center().x(),tmp.second.collibox.center().y(),1,M_PI/3.0,tr("wooden"),tr("ball"),18.0,0.0);
        }
        break;
    case 2725:
        Idx=21;
        this->enemymanager.AddOneZako(10,tr("little"),tr(""),tr("target"),150.0*Width/1920,-200.0*Width/1920,150.0*Width/1920,1800.0*Width/1920,12.0,0,0,2,0,0);
        for(auto tmp:this->enemymanager.zakos)
        {
            this->barragemanager.AddOneAim(&tmp.second,this->hero,tmp.second.collibox.center().x(),tmp.second.collibox.center().y(),1,M_PI/3.0,tr("wooden"),tr("ball"),16.0,0.0);
            this->barragemanager.AddOneAim(&tmp.second,this->hero,tmp.second.collibox.center().x(),tmp.second.collibox.center().y(),1,M_PI/3.0,tr("wooden"),tr("ball"),17.0,0.0);
            this->barragemanager.AddOneAim(&tmp.second,this->hero,tmp.second.collibox.center().x(),tmp.second.collibox.center().y(),1,M_PI/3.0,tr("wooden"),tr("ball"),18.0,0.0);
        }
        break;
    case 2750:
        Idx=22;
        this->enemymanager.AddOneZako(10,tr("little"),tr(""),tr("target"),150.0*Width/1920,-200.0*Width/1920,150.0*Width/1920,1800.0*Width/1920,12.0,0,0,2,0,0);
        for(auto tmp:this->enemymanager.zakos)
        {
            this->barragemanager.AddOneAim(&tmp.second,this->hero,tmp.second.collibox.center().x(),tmp.second.collibox.center().y(),1,M_PI/3.0,tr("wooden"),tr("ball"),16.0,0.0);
            this->barragemanager.AddOneAim(&tmp.second,this->hero,tmp.second.collibox.center().x(),tmp.second.collibox.center().y(),1,M_PI/3.0,tr("wooden"),tr("ball"),17.0,0.0);
            this->barragemanager.AddOneAim(&tmp.second,this->hero,tmp.second.collibox.center().x(),tmp.second.collibox.center().y(),1,M_PI/3.0,tr("wooden"),tr("ball"),18.0,0.0);
        }
        break;
    case 2775:
        Idx=23;
        this->enemymanager.AddOneZako(10,tr("little"),tr(""),tr("target"),900.0*Width/1920,-200.0*Width/1920,900.0*Width/1920,1800.0*Width/1920,12.0,0,0,2,0,0);
        for(auto tmp:this->enemymanager.zakos)
        {
            this->barragemanager.AddOneAim(&tmp.second,this->hero,tmp.second.collibox.center().x(),tmp.second.collibox.center().y(),1,M_PI/3.0,tr("wooden"),tr("ball"),16.0,0.0);
            this->barragemanager.AddOneAim(&tmp.second,this->hero,tmp.second.collibox.center().x(),tmp.second.collibox.center().y(),1,M_PI/3.0,tr("wooden"),tr("ball"),17.0,0.0);
            this->barragemanager.AddOneAim(&tmp.second,this->hero,tmp.second.collibox.center().x(),tmp.second.collibox.center().y(),1,M_PI/3.0,tr("wooden"),tr("ball"),18.0,0.0);
        }
        break;
    case 2800:
        Idx=24;
        this->enemymanager.AddOneZako(10,tr("little"),tr(""),tr("target"),900.0*Width/1920,-200.0*Width/1920,900.0*Width/1920,1800.0*Width/1920,12.0,0,0,2,0,0);
        for(auto tmp:this->enemymanager.zakos)
        {
            this->barragemanager.AddOneAim(&tmp.second,this->hero,tmp.second.collibox.center().x(),tmp.second.collibox.center().y(),1,M_PI/3.0,tr("wooden"),tr("ball"),16.0,0.0);
            this->barragemanager.AddOneAim(&tmp.second,this->hero,tmp.second.collibox.center().x(),tmp.second.collibox.center().y(),1,M_PI/3.0,tr("wooden"),tr("ball"),17.0,0.0);
            this->barragemanager.AddOneAim(&tmp.second,this->hero,tmp.second.collibox.center().x(),tmp.second.collibox.center().y(),1,M_PI/3.0,tr("wooden"),tr("ball"),18.0,0.0);
        }
        break;
    case 2825:
        Idx=25;
        this->enemymanager.AddOneZako(10,tr("little"),tr(""),tr("target"),900.0*Width/1920,-200.0*Width/1920,900.0*Width/1920,1800.0*Width/1920,12.0,0,0,2,0,0);
        for(auto tmp:this->enemymanager.zakos)
        {
            this->barragemanager.AddOneAim(&tmp.second,this->hero,tmp.second.collibox.center().x(),tmp.second.collibox.center().y(),1,M_PI/3.0,tr("wooden"),tr("ball"),16.0,0.0);
            this->barragemanager.AddOneAim(&tmp.second,this->hero,tmp.second.collibox.center().x(),tmp.second.collibox.center().y(),1,M_PI/3.0,tr("wooden"),tr("ball"),17.0,0.0);
            this->barragemanager.AddOneAim(&tmp.second,this->hero,tmp.second.collibox.center().x(),tmp.second.collibox.center().y(),1,M_PI/3.0,tr("wooden"),tr("ball"),18.0,0.0);
        }
        break;
    case 2850:
        Idx=26;
        this->enemymanager.AddOneZako(10,tr("little"),tr(""),tr("target"),900.0*Width/1920,-200.0*Width/1920,900.0*Width/1920,1800.0*Width/1920,12.0,0,0,2,0,0);
        for(auto tmp:this->enemymanager.zakos)
        {
            this->barragemanager.AddOneAim(&tmp.second,this->hero,tmp.second.collibox.center().x(),tmp.second.collibox.center().y(),1,M_PI/3.0,tr("wooden"),tr("ball"),16.0,0.0);
            this->barragemanager.AddOneAim(&tmp.second,this->hero,tmp.second.collibox.center().x(),tmp.second.collibox.center().y(),1,M_PI/3.0,tr("wooden"),tr("ball"),17.0,0.0);
            this->barragemanager.AddOneAim(&tmp.second,this->hero,tmp.second.collibox.center().x(),tmp.second.collibox.center().y(),1,M_PI/3.0,tr("wooden"),tr("ball"),18.0,0.0);
        }
        break;
    case 2875:
        Idx=27;
        this->enemymanager.AddOneZako(10,tr("little"),tr(""),tr("target"),900.0*Width/1920,-200.0*Width/1920,900.0*Width/1920,1800.0*Width/1920,12.0,0,0,2,0,0);
        for(auto tmp:this->enemymanager.zakos)
        {
            this->barragemanager.AddOneAim(&tmp.second,this->hero,tmp.second.collibox.center().x(),tmp.second.collibox.center().y(),1,M_PI/3.0,tr("wooden"),tr("ball"),16.0,0.0);
            this->barragemanager.AddOneAim(&tmp.second,this->hero,tmp.second.collibox.center().x(),tmp.second.collibox.center().y(),1,M_PI/3.0,tr("wooden"),tr("ball"),17.0,0.0);
            this->barragemanager.AddOneAim(&tmp.second,this->hero,tmp.second.collibox.center().x(),tmp.second.collibox.center().y(),1,M_PI/3.0,tr("wooden"),tr("ball"),18.0,0.0);
        }
        break;
    case 2900:
        for(auto tmp:this->enemymanager.zakos)
        {
            this->barragemanager.AddOneAim(&tmp.second,this->hero,tmp.second.collibox.center().x(),tmp.second.collibox.center().y(),1,M_PI/3.0,tr("wooden"),tr("ball"),16.0,0.0);
            this->barragemanager.AddOneAim(&tmp.second,this->hero,tmp.second.collibox.center().x(),tmp.second.collibox.center().y(),1,M_PI/3.0,tr("wooden"),tr("ball"),17.0,0.0);
            this->barragemanager.AddOneAim(&tmp.second,this->hero,tmp.second.collibox.center().x(),tmp.second.collibox.center().y(),1,M_PI/3.0,tr("wooden"),tr("ball"),18.0,0.0);
        }
        break;
    case 3050:
        Idx=28;
        this->enemymanager.AddOneZako(500,tr(""),tr("helmet"),tr("target"),500.0*Width/1920,-200.0*Width/1920,500.0*Width/1920,325.0*Width/1920,8.0,-0.06,0,4,0,6);
        break;
    case 3200:
    {
        auto tmp=this->enemymanager.zakos.find(28);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("red"),tr("star"),10.0,-0.01);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("red"),tr("star"),11.0,-0.005);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("red"),tr("star"),12.0,0.0);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("red"),tr("star"),13.0,0.005);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("red"),tr("star"),14.0,0.01);
        }
    }
        break;
    case 3215:
    {
        auto tmp=this->enemymanager.zakos.find(28);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("red"),tr("star"),10.0,-0.01);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("red"),tr("star"),11.0,-0.005);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("red"),tr("star"),12.0,0.0);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("red"),tr("star"),13.0,0.005);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("red"),tr("star"),14.0,0.01);
        }
    }
        break;
    case 3230:
    {
        auto tmp=this->enemymanager.zakos.find(28);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("red"),tr("star"),10.0,-0.01);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("red"),tr("star"),11.0,-0.005);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("red"),tr("star"),12.0,0.0);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("red"),tr("star"),13.0,0.005);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("red"),tr("star"),14.0,0.01);
        }
    }
        break;
    case 3245:
    {
        auto tmp=this->enemymanager.zakos.find(28);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("red"),tr("star"),10.0,-0.01);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("red"),tr("star"),11.0,-0.005);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("red"),tr("star"),12.0,0.0);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("red"),tr("star"),13.0,0.005);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("red"),tr("star"),14.0,0.01);
        }
    }
        break;
    case 3260:
    {
        auto tmp=this->enemymanager.zakos.find(28);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("red"),tr("star"),10.0,-0.01);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("red"),tr("star"),11.0,-0.005);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("red"),tr("star"),12.0,0.0);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("red"),tr("star"),13.0,0.005);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("red"),tr("star"),14.0,0.01);
        }
    }
        break;
    case 3300:
    {
        auto tmp=this->enemymanager.zakos.find(28);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("yellow"),tr("star"),10.0,-0.01);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("yellow"),tr("star"),11.0,-0.005);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("yellow"),tr("star"),12.0,0.0);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("yellow"),tr("star"),13.0,0.005);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("yellow"),tr("star"),14.0,0.01);
        }
    }
        break;
    case 3315:
    {
        auto tmp=this->enemymanager.zakos.find(28);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("yellow"),tr("star"),10.0,-0.01);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("yellow"),tr("star"),11.0,-0.005);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("yellow"),tr("star"),12.0,0.0);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("yellow"),tr("star"),13.0,0.005);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("yellow"),tr("star"),14.0,0.01);
        }
    }
        break;
    case 3330:
    {
        auto tmp=this->enemymanager.zakos.find(28);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("yellow"),tr("star"),10.0,-0.01);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("yellow"),tr("star"),11.0,-0.005);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("yellow"),tr("star"),12.0,0.0);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("yellow"),tr("star"),13.0,0.005);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("yellow"),tr("star"),14.0,0.01);
        }
    }
        break;
    case 3345:
    {
        auto tmp=this->enemymanager.zakos.find(28);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("yellow"),tr("star"),10.0,-0.01);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("yellow"),tr("star"),11.0,-0.005);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("yellow"),tr("star"),12.0,0.0);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("yellow"),tr("star"),13.0,0.005);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("yellow"),tr("star"),14.0,0.01);
        }
    }
        break;
    case 3360:
    {
        auto tmp=this->enemymanager.zakos.find(28);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("yellow"),tr("star"),10.0,-0.01);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("yellow"),tr("star"),11.0,-0.005);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("yellow"),tr("star"),12.0,0.0);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("yellow"),tr("star"),13.0,0.005);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("yellow"),tr("star"),14.0,0.01);
        }
    }
        break;
    case 3400:
    {
        auto tmp=this->enemymanager.zakos.find(28);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("blue"),tr("star"),10.0,-0.01);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("blue"),tr("star"),11.0,-0.005);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("blue"),tr("star"),12.0,0.0);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("blue"),tr("star"),13.0,0.005);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("blue"),tr("star"),14.0,0.01);
        }
    }
        break;
    case 3415:
    {
        auto tmp=this->enemymanager.zakos.find(28);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("blue"),tr("star"),10.0,-0.01);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("blue"),tr("star"),11.0,-0.005);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("blue"),tr("star"),12.0,0.0);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("blue"),tr("star"),13.0,0.005);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("blue"),tr("star"),14.0,0.01);
        }
    }
        break;
    case 3430:
    {
        auto tmp=this->enemymanager.zakos.find(28);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("blue"),tr("star"),10.0,-0.01);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("blue"),tr("star"),11.0,-0.005);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("blue"),tr("star"),12.0,0.0);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("blue"),tr("star"),13.0,0.005);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("blue"),tr("star"),14.0,0.01);
        }
    }
        break;
    case 3445:
    {
        auto tmp=this->enemymanager.zakos.find(28);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("blue"),tr("star"),10.0,-0.01);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("blue"),tr("star"),11.0,-0.005);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("blue"),tr("star"),12.0,0.0);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("blue"),tr("star"),13.0,0.005);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("blue"),tr("star"),14.0,0.01);
        }
    }
        break;
    case 3460:
    {
        auto tmp=this->enemymanager.zakos.find(28);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("blue"),tr("star"),10.0,-0.01);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("blue"),tr("star"),11.0,-0.005);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("blue"),tr("star"),12.0,0.0);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("blue"),tr("star"),13.0,0.005);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("blue"),tr("star"),14.0,0.01);
        }
    }
        break;
    case 3500:
    {
        auto tmp=this->enemymanager.zakos.find(28);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("purple"),tr("star"),10.0,-0.01);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("purple"),tr("star"),11.0,-0.005);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("purple"),tr("star"),12.0,0.0);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("purple"),tr("star"),13.0,0.005);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("purple"),tr("star"),14.0,0.01);
        }
    }
        break;
    case 3515:
    {
        auto tmp=this->enemymanager.zakos.find(28);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("purple"),tr("star"),10.0,-0.01);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("purple"),tr("star"),11.0,-0.005);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("purple"),tr("star"),12.0,0.0);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("purple"),tr("star"),13.0,0.005);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("purple"),tr("star"),14.0,0.01);
        }
    }
        break;
    case 3530:
    {
        auto tmp=this->enemymanager.zakos.find(28);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("purple"),tr("star"),10.0,-0.01);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("purple"),tr("star"),11.0,-0.005);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("purple"),tr("star"),12.0,0.0);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("purple"),tr("star"),13.0,0.005);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("purple"),tr("star"),14.0,0.01);
        }
    }
        break;
    case 3545:
    {
        auto tmp=this->enemymanager.zakos.find(28);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("purple"),tr("star"),10.0,-0.01);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("purple"),tr("star"),11.0,-0.005);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("purple"),tr("star"),12.0,0.0);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("purple"),tr("star"),13.0,0.005);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("purple"),tr("star"),14.0,0.01);
        }
    }
        break;
    case 3560:
    {
        auto tmp=this->enemymanager.zakos.find(28);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("purple"),tr("star"),10.0,-0.01);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("purple"),tr("star"),11.0,-0.005);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("purple"),tr("star"),12.0,0.0);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("purple"),tr("star"),13.0,0.005);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("purple"),tr("star"),14.0,0.01);
        }
    }
        break;
    case 3600:
    {
        auto tmp=this->enemymanager.zakos.find(28);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("orange"),tr("star"),10.0,-0.01);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("orange"),tr("star"),11.0,-0.005);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("orange"),tr("star"),12.0,0.0);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("orange"),tr("star"),13.0,0.005);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("orange"),tr("star"),14.0,0.01);
        }
    }
        break;
    case 3615:
    {
        auto tmp=this->enemymanager.zakos.find(28);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("orange"),tr("star"),10.0,-0.01);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("orange"),tr("star"),11.0,-0.005);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("orange"),tr("star"),12.0,0.0);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("orange"),tr("star"),13.0,0.005);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("orange"),tr("star"),14.0,0.01);
        }
    }
        break;
    case 3630:
    {
        auto tmp=this->enemymanager.zakos.find(28);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("orange"),tr("star"),10.0,-0.01);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("orange"),tr("star"),11.0,-0.005);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("orange"),tr("star"),12.0,0.0);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("orange"),tr("star"),13.0,0.005);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("orange"),tr("star"),14.0,0.01);
        }
    }
        break;
    case 3645:
    {
        auto tmp=this->enemymanager.zakos.find(28);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("orange"),tr("star"),10.0,-0.01);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("orange"),tr("star"),11.0,-0.005);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("orange"),tr("star"),12.0,0.0);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("orange"),tr("star"),13.0,0.005);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("orange"),tr("star"),14.0,0.01);
        }
    }
        break;
    case 3660:
    {
        auto tmp=this->enemymanager.zakos.find(28);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("orange"),tr("star"),10.0,-0.01);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("orange"),tr("star"),11.0,-0.005);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("orange"),tr("star"),12.0,0.0);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("orange"),tr("star"),13.0,0.005);
            this->barragemanager.AddOneAim(&tmp->second,this->hero,tmp->second.collibox.center().x(),tmp->second.collibox.center().y(),5,M_PI*1.6,tr("orange"),tr("star"),14.0,0.01);
        }
    }
        break;
    case 3700:
    {
        auto tmp=this->enemymanager.zakos.find(28);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->enemymanager.SetOneEnemyMoveMode(&tmp->second,500.0*Width/1920,-900.0*Width/1920,0.0,0.06);
            this->barragemanager.AddOneRandomCircle(&tmp->second,tmp->second.X+tmp->second.colliX/2.0,tmp->second.Y+tmp->second.colliY/2.0,25,tr("green"),tr("star"),15,5,0.08,0.01);
        }
    }
        break;
    case 3800:
    {
        auto tmp=this->enemymanager.zakos.find(28);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneRandomCircle(&tmp->second,tmp->second.X+tmp->second.colliX/2.0,tmp->second.Y+tmp->second.colliY/2.0,25,tr("green"),tr("star"),15,5,0.08,0.01);
        }
    }
        Idx=29;
        this->enemymanager.AddOneZako(250,tr(""),tr("helmet"),tr("target"),150.0*Width/1920,-200.0*Width/1920,150.0*Width/1920,325.0*Width/1920,8.0,-0.06,0,5,0,2);
        Idx=30;
        this->enemymanager.AddOneZako(250,tr(""),tr("helmet"),tr("target"),850.0*Width/1920,-200.0*Width/1920,850.0*Width/1920,325.0*Width/1920,8.0,-0.06,0,5,0,2);
        Idx=31;
        this->enemymanager.AddOneZako(1000,tr("big"),tr("helmet"),tr("target"),420.0*Width/1920,-500.0*Width/1920,420.0*Width/1920,-400.0*Width/1920,0,0);
        break;
    case 3825:
    {
        auto tmp=this->enemymanager.zakos.find(31);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneRandomRain(&tmp->second,tr("y"),-50*Width/1920,15,M_PI/2,tr("blue"),tr("ball"),6.0,2.0,0,0);
        }
    }
        break;
    case 3875:
    {
        auto tmp=this->enemymanager.zakos.find(31);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneRandomRain(&tmp->second,tr("y"),-50*Width/1920,15,M_PI/2,tr("blue"),tr("ball"),6.0,2.0,0,0);
        }
    }
        break;
    case 3925:
    {
        auto tmp=this->enemymanager.zakos.find(31);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneRandomRain(&tmp->second,tr("y"),-50*Width/1920,15,M_PI/2,tr("blue"),tr("ball"),6.0,2.0,0,0);
        }
    }
        break;
    case 3950:
    {
        auto tmp=this->enemymanager.zakos.find(29);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneRandomCircle(&tmp->second,tmp->second.X+tmp->second.colliX/2.0,tmp->second.Y+tmp->second.colliY/2.0,std::min(int(2500.0/tmp->second.hp),40),tr("wooden"),tr("ball"),5,5,0,0);
        }
        tmp=this->enemymanager.zakos.find(30);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneRandomCircle(&tmp->second,tmp->second.X+tmp->second.colliX/2.0,tmp->second.Y+tmp->second.colliY/2.0,std::min(int(2500.0/tmp->second.hp),40),tr("wooden"),tr("ball"),5,5,0,0);
        }
    }
        break;
    case 3975:
    {
        auto tmp=this->enemymanager.zakos.find(31);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneRandomRain(&tmp->second,tr("y"),-50*Width/1920,15,M_PI/2,tr("blue"),tr("ball"),6.0,2.0,0,0);
        }
    }
        break;
    case 4000:
    {
        auto tmp=this->enemymanager.zakos.find(29);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneRandomCircle(&tmp->second,tmp->second.X+tmp->second.colliX/2.0,tmp->second.Y+tmp->second.colliY/2.0,std::min(int(2500.0/tmp->second.hp),40),tr("wooden"),tr("ball"),5,5,0,0);
        }
        tmp=this->enemymanager.zakos.find(30);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneRandomCircle(&tmp->second,tmp->second.X+tmp->second.colliX/2.0,tmp->second.Y+tmp->second.colliY/2.0,std::min(int(2500.0/tmp->second.hp),40),tr("wooden"),tr("ball"),5,5,0,0);
        }
    }
        break;
    case 4025:
    {
        auto tmp=this->enemymanager.zakos.find(31);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneRandomRain(&tmp->second,tr("y"),-50*Width/1920,15,M_PI/2,tr("blue"),tr("ball"),6.0,2.0,0,0);
        }
    }
        break;
    case 4050:
    {
        auto tmp=this->enemymanager.zakos.find(29);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneRandomCircle(&tmp->second,tmp->second.X+tmp->second.colliX/2.0,tmp->second.Y+tmp->second.colliY/2.0,std::min(int(2500.0/tmp->second.hp),40),tr("wooden"),tr("ball"),5,5,0,0);
        }
        tmp=this->enemymanager.zakos.find(30);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneRandomCircle(&tmp->second,tmp->second.X+tmp->second.colliX/2.0,tmp->second.Y+tmp->second.colliY/2.0,std::min(int(2500.0/tmp->second.hp),40),tr("wooden"),tr("ball"),5,5,0,0);
        }
    }
        break;
    case 4075:
    {
        auto tmp=this->enemymanager.zakos.find(31);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneRandomRain(&tmp->second,tr("y"),-50*Width/1920,15,M_PI/2,tr("blue"),tr("ball"),6.0,2.0,0,0);
        }
    }
        break;
    case 4100:
    {
        auto tmp=this->enemymanager.zakos.find(29);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneRandomCircle(&tmp->second,tmp->second.X+tmp->second.colliX/2.0,tmp->second.Y+tmp->second.colliY/2.0,std::min(int(2500.0/tmp->second.hp),40),tr("wooden"),tr("ball"),5,5,0,0);
        }
        tmp=this->enemymanager.zakos.find(30);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneRandomCircle(&tmp->second,tmp->second.X+tmp->second.colliX/2.0,tmp->second.Y+tmp->second.colliY/2.0,std::min(int(2500.0/tmp->second.hp),40),tr("wooden"),tr("ball"),5,5,0,0);
        }
    }
        break;
    case 4125:
    {
        auto tmp=this->enemymanager.zakos.find(31);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneRandomRain(&tmp->second,tr("y"),-50*Width/1920,15,M_PI/2,tr("blue"),tr("ball"),6.0,2.0,0,0);
        }
    }
        break;
    case 4150:
    {
        auto tmp=this->enemymanager.zakos.find(29);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneRandomCircle(&tmp->second,tmp->second.X+tmp->second.colliX/2.0,tmp->second.Y+tmp->second.colliY/2.0,std::min(int(2500.0/tmp->second.hp),40),tr("wooden"),tr("ball"),5,5,0,0);
        }
        tmp=this->enemymanager.zakos.find(30);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneRandomCircle(&tmp->second,tmp->second.X+tmp->second.colliX/2.0,tmp->second.Y+tmp->second.colliY/2.0,std::min(int(2500.0/tmp->second.hp),40),tr("wooden"),tr("ball"),5,5,0,0);
        }
    }
        break;
    case 4175:
    {
        auto tmp=this->enemymanager.zakos.find(31);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneRandomRain(&tmp->second,tr("y"),-50*Width/1920,15,M_PI/2,tr("blue"),tr("ball"),6.0,2.0,0,0);
        }
    }
        break;
    case 4200:
    {
        auto tmp=this->enemymanager.zakos.find(29);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneRandomCircle(&tmp->second,tmp->second.X+tmp->second.colliX/2.0,tmp->second.Y+tmp->second.colliY/2.0,std::min(int(2500.0/tmp->second.hp),40),tr("wooden"),tr("ball"),5,5,0,0);
        }
        tmp=this->enemymanager.zakos.find(30);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneRandomCircle(&tmp->second,tmp->second.X+tmp->second.colliX/2.0,tmp->second.Y+tmp->second.colliY/2.0,std::min(int(2500.0/tmp->second.hp),40),tr("wooden"),tr("ball"),5,5,0,0);
        }
    }
        break;
    case 4225:
    {
        auto tmp=this->enemymanager.zakos.find(31);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneRandomRain(&tmp->second,tr("y"),-50*Width/1920,15,M_PI/2,tr("blue"),tr("ball"),6.0,2.0,0,0);
        }
    }
        break;
    case 4250:
    {
        auto tmp=this->enemymanager.zakos.find(29);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneRandomCircle(&tmp->second,tmp->second.X+tmp->second.colliX/2.0,tmp->second.Y+tmp->second.colliY/2.0,std::min(int(2500.0/tmp->second.hp),40),tr("wooden"),tr("ball"),5,5,0,0);
        }
        tmp=this->enemymanager.zakos.find(30);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneRandomCircle(&tmp->second,tmp->second.X+tmp->second.colliX/2.0,tmp->second.Y+tmp->second.colliY/2.0,std::min(int(2500.0/tmp->second.hp),40),tr("wooden"),tr("ball"),5,5,0,0);
        }
    }
        break;
    case 4275:
    {
        auto tmp=this->enemymanager.zakos.find(31);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneRandomRain(&tmp->second,tr("y"),-50*Width/1920,15,M_PI/2,tr("blue"),tr("ball"),6.0,2.0,0,0);
        }
    }
        break;
    case 4300:
    {
        auto tmp=this->enemymanager.zakos.find(29);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneRandomCircle(&tmp->second,tmp->second.X+tmp->second.colliX/2.0,tmp->second.Y+tmp->second.colliY/2.0,std::min(int(2500.0/tmp->second.hp),40),tr("wooden"),tr("ball"),5,5,0,0);
        }
        tmp=this->enemymanager.zakos.find(30);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneRandomCircle(&tmp->second,tmp->second.X+tmp->second.colliX/2.0,tmp->second.Y+tmp->second.colliY/2.0,std::min(int(2500.0/tmp->second.hp),40),tr("wooden"),tr("ball"),5,5,0,0);
        }
    }
        break;
    case 4325:
    {
        auto tmp=this->enemymanager.zakos.find(31);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneRandomRain(&tmp->second,tr("y"),-50*Width/1920,15,M_PI/2,tr("blue"),tr("ball"),6.0,2.0,0,0);
        }
    }
        break;
    case 4350:
    {
        auto tmp=this->enemymanager.zakos.find(29);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneRandomCircle(&tmp->second,tmp->second.X+tmp->second.colliX/2.0,tmp->second.Y+tmp->second.colliY/2.0,std::min(int(2500.0/tmp->second.hp),40),tr("wooden"),tr("ball"),5,5,0,0);
        }
        tmp=this->enemymanager.zakos.find(30);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneRandomCircle(&tmp->second,tmp->second.X+tmp->second.colliX/2.0,tmp->second.Y+tmp->second.colliY/2.0,std::min(int(2500.0/tmp->second.hp),40),tr("wooden"),tr("ball"),5,5,0,0);
        }
    }
        break;
    case 4375:
    {
        auto tmp=this->enemymanager.zakos.find(31);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneRandomRain(&tmp->second,tr("y"),-50*Width/1920,15,M_PI/2,tr("blue"),tr("ball"),6.0,2.0,0,0);
        }
    }
        break;
    case 4400:
    {
        auto tmp=this->enemymanager.zakos.find(29);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneRandomCircle(&tmp->second,tmp->second.X+tmp->second.colliX/2.0,tmp->second.Y+tmp->second.colliY/2.0,std::min(int(2500.0/tmp->second.hp),40),tr("wooden"),tr("ball"),5,5,0,0);
        }
        tmp=this->enemymanager.zakos.find(30);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneRandomCircle(&tmp->second,tmp->second.X+tmp->second.colliX/2.0,tmp->second.Y+tmp->second.colliY/2.0,std::min(int(2500.0/tmp->second.hp),40),tr("wooden"),tr("ball"),5,5,0,0);
        }
    }
        break;
    case 4425:
    {
        auto tmp=this->enemymanager.zakos.find(31);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneRandomRain(&tmp->second,tr("y"),-50*Width/1920,15,M_PI/2,tr("blue"),tr("ball"),6.0,2.0,0,0);
        }
    }
        break;
    case 4450:
    {
        auto tmp=this->enemymanager.zakos.find(29);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneRandomCircle(&tmp->second,tmp->second.X+tmp->second.colliX/2.0,tmp->second.Y+tmp->second.colliY/2.0,std::min(int(2500.0/tmp->second.hp),40),tr("wooden"),tr("ball"),5,5,0,0);
        }
        tmp=this->enemymanager.zakos.find(30);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneRandomCircle(&tmp->second,tmp->second.X+tmp->second.colliX/2.0,tmp->second.Y+tmp->second.colliY/2.0,std::min(int(2500.0/tmp->second.hp),40),tr("wooden"),tr("ball"),5,5,0,0);
        }
    }
        break;
    case 4475:
    {
        auto tmp=this->enemymanager.zakos.find(31);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneRandomRain(&tmp->second,tr("y"),-50*Width/1920,15,M_PI/2,tr("blue"),tr("ball"),6.0,2.0,0,0);
        }
    }
        break;
    case 4500:
    {
        auto tmp=this->enemymanager.zakos.find(29);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneRandomCircle(&tmp->second,tmp->second.X+tmp->second.colliX/2.0,tmp->second.Y+tmp->second.colliY/2.0,std::min(int(2500.0/tmp->second.hp),40),tr("wooden"),tr("ball"),5,5,0,0);
        }
        tmp=this->enemymanager.zakos.find(30);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneRandomCircle(&tmp->second,tmp->second.X+tmp->second.colliX/2.0,tmp->second.Y+tmp->second.colliY/2.0,std::min(int(2500.0/tmp->second.hp),40),tr("wooden"),tr("ball"),5,5,0,0);
        }
    }
        break;
    case 4525:
    {
        auto tmp=this->enemymanager.zakos.find(31);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneRandomRain(&tmp->second,tr("y"),-50*Width/1920,15,M_PI/2,tr("blue"),tr("ball"),6.0,2.0,0,0);
        }
    }
        break;
    case 4550:
    {
        auto tmp=this->enemymanager.zakos.find(29);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneRandomCircle(&tmp->second,tmp->second.X+tmp->second.colliX/2.0,tmp->second.Y+tmp->second.colliY/2.0,std::min(int(2500.0/tmp->second.hp),40),tr("wooden"),tr("ball"),5,5,0,0);
        }
        tmp=this->enemymanager.zakos.find(30);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneRandomCircle(&tmp->second,tmp->second.X+tmp->second.colliX/2.0,tmp->second.Y+tmp->second.colliY/2.0,std::min(int(2500.0/tmp->second.hp),40),tr("wooden"),tr("ball"),5,5,0,0);
        }
    }
        break;
    case 4575:
    {
        auto tmp=this->enemymanager.zakos.find(31);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneRandomRain(&tmp->second,tr("y"),-50*Width/1920,15,M_PI/2,tr("blue"),tr("ball"),6.0,2.0,0,0);
        }
    }
        break;
    case 4600:
    {
        auto tmp=this->enemymanager.zakos.find(29);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneRandomCircle(&tmp->second,tmp->second.X+tmp->second.colliX/2.0,tmp->second.Y+tmp->second.colliY/2.0,std::min(int(2500.0/tmp->second.hp),40),tr("wooden"),tr("ball"),5,5,0,0);
        }
        tmp=this->enemymanager.zakos.find(30);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneRandomCircle(&tmp->second,tmp->second.X+tmp->second.colliX/2.0,tmp->second.Y+tmp->second.colliY/2.0,std::min(int(2500.0/tmp->second.hp),40),tr("wooden"),tr("ball"),5,5,0,0);
        }
    }
        break;
    case 4625:
    {
        auto tmp=this->enemymanager.zakos.find(31);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneRandomRain(&tmp->second,tr("y"),-50*Width/1920,15,M_PI/2,tr("blue"),tr("ball"),6.0,2.0,0,0);
        }
    }
        break;
    case 4650:
    {
        auto tmp=this->enemymanager.zakos.find(29);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneRandomCircle(&tmp->second,tmp->second.X+tmp->second.colliX/2.0,tmp->second.Y+tmp->second.colliY/2.0,std::min(int(2500.0/tmp->second.hp),40),tr("wooden"),tr("ball"),5,5,0,0);
        }
        tmp=this->enemymanager.zakos.find(30);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneRandomCircle(&tmp->second,tmp->second.X+tmp->second.colliX/2.0,tmp->second.Y+tmp->second.colliY/2.0,std::min(int(2500.0/tmp->second.hp),40),tr("wooden"),tr("ball"),5,5,0,0);
        }
    }
        break;
    case 4675:
    {
        auto tmp=this->enemymanager.zakos.find(31);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneRandomRain(&tmp->second,tr("y"),-50*Width/1920,15,M_PI/2,tr("blue"),tr("ball"),6.0,2.0,0,0);
        }
    }
        break;
    case 4700:
    {
        auto tmp=this->enemymanager.zakos.find(29);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneRandomCircle(&tmp->second,tmp->second.X+tmp->second.colliX/2.0,tmp->second.Y+tmp->second.colliY/2.0,std::min(int(2500.0/tmp->second.hp),40),tr("wooden"),tr("ball"),5,5,0,0);
        }
        tmp=this->enemymanager.zakos.find(30);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneRandomCircle(&tmp->second,tmp->second.X+tmp->second.colliX/2.0,tmp->second.Y+tmp->second.colliY/2.0,std::min(int(2500.0/tmp->second.hp),40),tr("wooden"),tr("ball"),5,5,0,0);
        }
    }
        break;
    case 4725:
    {
        auto tmp=this->enemymanager.zakos.find(31);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneRandomRain(&tmp->second,tr("y"),-50*Width/1920,15,M_PI/2,tr("blue"),tr("ball"),6.0,2.0,0,0);
        }
    }
        break;
    case 4750:
    {
        auto tmp=this->enemymanager.zakos.find(29);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneRandomCircle(&tmp->second,tmp->second.X+tmp->second.colliX/2.0,tmp->second.Y+tmp->second.colliY/2.0,std::min(int(2500.0/tmp->second.hp),40),tr("wooden"),tr("ball"),5,5,0,0);
        }
        tmp=this->enemymanager.zakos.find(30);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneRandomCircle(&tmp->second,tmp->second.X+tmp->second.colliX/2.0,tmp->second.Y+tmp->second.colliY/2.0,std::min(int(2500.0/tmp->second.hp),40),tr("wooden"),tr("ball"),5,5,0,0);
        }
    }
        break;
    case 4775:
    {
        auto tmp=this->enemymanager.zakos.find(31);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneRandomRain(&tmp->second,tr("y"),-50*Width/1920,15,M_PI/2,tr("blue"),tr("ball"),6.0,2.0,0,0);
        }
    }
        break;
    case 4800:
    {
        auto tmp=this->enemymanager.zakos.find(29);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneRandomCircle(&tmp->second,tmp->second.X+tmp->second.colliX/2.0,tmp->second.Y+tmp->second.colliY/2.0,std::min(int(2500.0/tmp->second.hp),40),tr("wooden"),tr("ball"),5,5,0,0);
            this->enemymanager.SetOneEnemyMoveMode(&tmp->second,150.0*Width/1920,1800*Width/1920,0.0,0.03);
        }
        tmp=this->enemymanager.zakos.find(30);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneRandomCircle(&tmp->second,tmp->second.X+tmp->second.colliX/2.0,tmp->second.Y+tmp->second.colliY/2.0,std::min(int(2500.0/tmp->second.hp),40),tr("wooden"),tr("ball"),5,5,0,0);
            this->enemymanager.SetOneEnemyMoveMode(&tmp->second,850.0*Width/1920,1800*Width/1920,0.0,0.03);
        }
    }
        break;
    case 4825:
    {
        auto tmp=this->enemymanager.zakos.find(31);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneRandomRain(&tmp->second,tr("y"),-50*Width/1920,15,M_PI/2,tr("blue"),tr("ball"),6.0,2.0,0,0);
        }
    }
        break;
    case 4850:
    {
        auto tmp=this->enemymanager.zakos.find(29);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneRandomCircle(&tmp->second,tmp->second.X+tmp->second.colliX/2.0,tmp->second.Y+tmp->second.colliY/2.0,std::min(int(2500.0/tmp->second.hp),40),tr("wooden"),tr("ball"),5,5,0,0);
        }
        tmp=this->enemymanager.zakos.find(30);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneRandomCircle(&tmp->second,tmp->second.X+tmp->second.colliX/2.0,tmp->second.Y+tmp->second.colliY/2.0,std::min(int(2500.0/tmp->second.hp),40),tr("wooden"),tr("ball"),5,5,0,0);
        }
    }
        break;
    case 4875:
    {
        auto tmp=this->enemymanager.zakos.find(31);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneRandomRain(&tmp->second,tr("y"),-50*Width/1920,15,M_PI/2,tr("blue"),tr("ball"),6.0,2.0,0,0);
        }
    }
        break;
    case 4925:
    {
        auto tmp=this->enemymanager.zakos.find(31);
        if(tmp!=this->enemymanager.zakos.end())
        {
            this->barragemanager.AddOneRandomRain(&tmp->second,tr("y"),-50*Width/1920,15,M_PI/2,tr("blue"),tr("ball"),6.0,2.0,0,0);
        }
    }
        break;
    case 5275:
        this->bulletmanager.DestoryAllEnemyBullets();
        this->hero->isAbsorbingProps=true;
        break;
    case 5350:
        Idx=32;
        this->enemymanager.AddOneBoss(4000,4,tr("big"),tr("helmet"),tr("target"),tr("陈旧之靶"),470.0*Width/1920,-500.0*Width/1920,470.0*Width/1920,235.0*Width/1920,10,-0.06,0,0,0,10);
        this->dialogplayer.speaktimes=30;
        this->dialogplayer.isOnDisplay=true;
    {
        auto tmp=this->enemymanager.bosses.find(32);
        if(tmp!=this->enemymanager.bosses.end())
        {
            tmp->second.tmpcount=5350;//一阶段起始时间
            tmp->second.stagelefttime=30;
        }
    }
        break;
    default:
        if(Count>5350)//boss战
        {
            if(this->isFightingBoss==false)
                this->isFightingBoss=true;
            else
            {
                this->GenerateLevel0Boss();
                if(this->enemymanager.bosses.find(32)==this->enemymanager.bosses.end())
                {
                    this->bulletmanager.DestoryAllEnemyBullets();
                    this->hero->isAbsorbingProps=true;
                    if(this->dialogplayer.speaktimes<=35)
                    {
                        this->dialogplayer.isOnDisplay=true;
                    }
                    if(this->dialogplayer.speaktimes<=43)//最后一页对话
                    {
                        this->titleplayer.SetClearTitle(Count+50,Count+400);
                    }
                    if(Count==this->titleplayer.clearendcount+50)
                    {
                        emit LevelClearSignal();
                    }
                }
            }
        }
        break;
    }
}
