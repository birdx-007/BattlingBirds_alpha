#include "gameheaders/managerdep.h"
void ManagerDep::GenerateLevel3()
{
    if(this->dialogplayer.isOnDisplay){
        Count--;
        switch (this->dialogplayer.speaktimes) {
        case 0:
            this->dialogplayer.setLeft(QString(":/myimages/res/hero%1.png").arg(Shottype+1));
            this->dialogplayer.setRight(QString(":/myimages/res/tutorpig_unknown.png"));
            this->dialogplayer.RightSpeak(tr("哎呀哎呀。\n你们不能再继续前进了哦。"));
            break;
        case 1:
            this->dialogplayer.RightSpeak(tr("你们急于夺回鸟蛋的心态自然可以理解...\n不过...后面没有敌人也没有弹幕。（而且没有鸟蛋）"));
            break;
        case 2:
            this->dialogplayer.LeftSpeak(tr("?!!"));
            break;
        case 3:
            this->dialogplayer.RightSpeak(tr("因为...体验版的内容到这里就结束了呢。(^^;;)"));
            break;
        case 4:
            this->dialogplayer.LeftSpeak(tr("那我们的鸟蛋...!\n你到底...是什么家伙!"));
            break;
        case 5:
            this->dialogplayer.RightSpeak(tr("...呵呵呵。\n...游戏到此为止!回到半小时前重新来吧!"));
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
    switch (Count) {
    case 50:
        this->dialogplayer.isOnDisplay=true;
        this->titleplayer.SetClearTitle(75,425);
        this->isFightingBoss=false;
        break;
    default:
        if(Count==this->titleplayer.clearendcount+50)
        {
            emit LevelClearSignal();
        }
        break;
    }
}
