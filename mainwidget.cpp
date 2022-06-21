#include "mainwidget.h"
#include "ui_mainwidget.h"
#include "constant.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    //只能最小化
    this->setWindowFlags(this->windowFlags()&(~Qt::WindowMinMaxButtonsHint|Qt::WindowMinimizeButtonHint));
    loadingthread = new LoadingThread();
    loadingthread->BindWidget(*this);
    connect(loadingthread,&LoadingThread::finished,this,&MainWidget::toMainMenu);
    effectvolume=1.0f;
    BGMvolume=100;
    Difficulty=1;
    //链接信号
    connect(&this->ui->battlescene->managerDep,&ManagerDep::GameOverSignal,this,&MainWidget::GameOver);
    connect(&this->ui->battlescene->managerDep,&ManagerDep::LevelClearSignal,this,&MainWidget::LevelClear);

    this->ui->stack->setCurrentIndex(0);//loading
}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::InitResources()
{
    //Resources loading
    this->loadingthread->start();
    //init all optionlabels
    this->ui->start_label->Init();
    this->ui->setting_label->Init();
    this->ui->help_label->Init();
    this->ui->exit_label->Init();
    this->ui->BGMvolume->Init();
    this->ui->effectvolume->Init();
    this->ui->tutorial_label->Init();
    this->ui->amateur_label->Init();
    this->ui->explorer_label->Init();
    this->ui->challenger_label->Init();
    this->ui->continue_label->Init();
    this->ui->esc_label->Init();
    this->ui->restart_label->Init();
    this->ui->over_esc_label->Init();
    this->ui->over_restart_label->Init();
    this->ui->over_continue_label->Init();

    this->ui->start_label->setFocus();
}

void MainWidget::setDispalyMode()
{
    this->resize(Width,Height);
}

void MainWidget::setEffectVolume(qreal volume)
{
    //this->effectvolume=volume;
    this->optionChangeEffect.setVolume(volume);
    this->optionReturnEffect.setVolume(volume);
    this->optionConfirmEffect.setVolume(volume);
}

void MainWidget::setBGMVolume(int volume)
{

}

void MainWidget::toMainMenu()
{
    this->ui->stack->setCurrentIndex(1);//main_menu
    //this->ui->start_label->setFocus();
}

void MainWidget::toSettingMenu()
{
    this->ui->stack->setCurrentIndex(2);//setting_menu
    this->ui->BGMvolume->setFocus();
}

void MainWidget::toHelpMenu()
{
    this->ui->stack->setCurrentIndex(3);//help_menu
    this->ui->helpstack->setCurrentIndex(0);
}

void MainWidget::toDifficultyMenu()
{
    this->ui->stack->setCurrentIndex(4);//difficulty_menu
    //this->ui->amateur_label->setFocus();
}

void MainWidget::toHeroMenu()
{
    this->ui->stack->setCurrentIndex(5);//hero_menu
    //this->ui->herostack->setCurrentIndex(0);
    this->ui->difficulty_marker->setText(QString("%1").arg(GetDifficulty()));
}

void MainWidget::toBattlefield()
{
    this->ui->stack->setCurrentIndex(6);//battlefield
    this->ui->battlefield_stack->setCurrentIndex(0);//battlescene
}

void MainWidget::GameOver()
{
    this->ui->stack->setCurrentIndex(6);//battlefield
    this->ui->battlefield_stack->setCurrentIndex(2);//gameoverscene
    this->ui->over_continue_label->setFocus();
    this->PauseGame();
}

void MainWidget::LevelClear()
{
    this->ui->battlescene->managerDep.isFighting=false;
    if(Level==0)
    {
        this->QuitGame();
        this->ui->stack->setCurrentIndex(0);//loading
        this->InitResources();
    }
    else if(Level!=3)//未到结尾关
    {
        this->ui->battlescene->hero.vector.init();
        this->ui->battlescene->hero.isTryingActivateSpell=false;
        this->ui->battlescene->hero.isShooting=false;
        this->ui->levelclearscene->setStyleSheet(QString("border-image: url(:/myimages/res/bg_level%1.png);").arg(Level));
        this->ui->stack->setCurrentIndex(6);//battlefield
        this->ui->battlefield_stack->setCurrentIndex(3);//levelclearscene
        qreal magnification=Difficulty==1?0.75:(Difficulty==2?1.00:1.50);
        this->ui->clearbonus_label->setText(QString("Clear Bonus: %1 * 10000").arg(QString::number(magnification,'f',2)));
        this->ui->resourcesbonus_label->setText(QString("Player Bonus: %1 * 5000\n Bombs Bonus: %2 * 2500").arg(this->ui->battlescene->hero.players).arg(this->ui->battlescene->hero.spells));
        this->ui->battlescene->managerDep.scoremanager.AddScore(int(10000*magnification));
        this->ui->battlescene->managerDep.scoremanager.AddScore(int(5000*this->ui->battlescene->hero.players));
        this->ui->battlescene->managerDep.scoremanager.AddScore(int(2500*this->ui->battlescene->hero.spells));
    }
    else//结尾关
    {
        this->QuitGame();
        this->ui->stack->setCurrentIndex(0);//loading
        this->InitResources();
    }
}

void MainWidget::StartGame()
{
    this->ui->battlescene->Init(this,Shottype);
    this->ui->score_label->setText(QString("0"));
    //this->ui->highscore_label->setText(QString("0"));
    this->ui->life_label->setText(QString("3"));
    this->ui->bomb_label->setText(QString("3"));
    this->ui->power_label->setText(QString("%1 / 4.00").arg(QString::number(this->ui->battlescene->hero.power,'f',2)));
    this->ui->difficulty_label->setText(GetDifficulty());
    this->ui->battlescene->timer->start();
    this->toBattlefield();
}

void MainWidget::PauseGame()
{
    this->ui->battlescene->managerDep.isFighting=false;
    this->ui->battlescene->timer->stop();
    this->ui->battlescene->hero.vector.init();
    this->ui->battlescene->hero.isTryingActivateSpell=false;
    this->ui->battlescene->hero.isShooting=false;
}

void MainWidget::ContinueGame()
{
    this->ui->battlescene->managerDep.isFighting=true;
    this->ui->battlescene->timer->start();
}

void MainWidget::QuitGame()
{
    delete this->ui->battlescene->timer;
    Count=0;
}

void MainWidget::UpdateData()
{
    this->ui->score_label->setText(QString("%1").arg(this->ui->battlescene->managerDep.scoremanager.score));
    this->ui->highscore_label->setText(QString("%1").arg(this->ui->battlescene->managerDep.scoremanager.highscore));
    this->ui->power_label->setText(QString("%1 / 4.00").arg(QString::number(this->ui->battlescene->hero.power,'f',2)));
    this->ui->life_label->setText(QString("%1").arg(this->ui->battlescene->hero.players));
    this->ui->bomb_label->setText(QString("%1").arg(this->ui->battlescene->hero.spells));
}

void MainWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
}

void MainWidget::keyPressEvent(QKeyEvent *event)
{
    if(this->ui->stack->currentIndex()==1)//main_menu
    {

        if(event->key()==Qt::Key_Up)
        {
            this->focusPreviousChild();
            //this->focusNextPrevChild(0);  //same effact
            this->optionChangeEffect.play();
        }
        if(event->key()==Qt::Key_Down)
        {
            this->focusNextChild();
            //this->focusNextPrevChild(1);  //same effact
            this->optionChangeEffect.play();
        }
        if(event->key()==Qt::Key_Return||event->key()==Qt::Key_Z)
        {
            if(this->ui->start_label->hasFocus())
            {
                this->toDifficultyMenu();
                this->ui->amateur_label->setFocus();//主菜单进时label归零
                this->ui->herostack->setCurrentIndex(0);//主菜单进时herochoice归零
            }
            if(this->ui->setting_label->hasFocus())
                this->toSettingMenu();
            if(this->ui->help_label->hasFocus())
                this->toHelpMenu();
            if(this->ui->exit_label->hasFocus())
                emit ExitSignal();
            this->optionConfirmEffect.play();
        }
        if(event->key()==Qt::Key_Escape||event->key()==Qt::Key_X)
        {
            if(this->ui->exit_label->hasFocus())
                emit ExitSignal();
            else
                this->ui->exit_label->setFocus();
            this->optionReturnEffect.play();
        }
    }
    else if(this->ui->stack->currentIndex()==2)//setting_menu
    {
        if(event->key()==Qt::Key_Up)
        {
            this->focusPreviousChild();
            this->optionChangeEffect.play();
        }
        if(event->key()==Qt::Key_Down)
        {
            this->focusNextChild();
            this->optionChangeEffect.play();
        }
        if(event->key()==Qt::Key_Left)
        {
            if(this->ui->BGMvolume->hasFocus()&&BGMvolume>0)
            {
                BGMvolume-=1;
                this->setBGMVolume(BGMvolume);
                this->ui->BGMvolumevalue->setText(QString("%1").arg(BGMvolume));
            }
            if(this->ui->effectvolume->hasFocus()&&effectvolume>0.0f)
            {
                effectvolume-=0.01f;
                this->setEffectVolume(effectvolume);
                this->ui->effectvolumevalue->setText(QString("%1").arg(int(effectvolume*100)));
            }
        }
        if(event->key()==Qt::Key_Right)
        {
            if(this->ui->BGMvolume->hasFocus()&&BGMvolume<100)
            {
                BGMvolume+=1;
                this->setBGMVolume(BGMvolume);
                this->ui->BGMvolumevalue->setText(QString("%1").arg(BGMvolume));
            }
            if(this->ui->effectvolume->hasFocus()&&effectvolume<1.0f)
            {
                effectvolume+=0.01f;
                this->setEffectVolume(effectvolume);
                this->ui->effectvolumevalue->setText(QString("%1").arg(int(effectvolume*100)));
            }
        }
        if(event->key()==Qt::Key_Escape||event->key()==Qt::Key_X)
        {
            this->toMainMenu();
            this->optionReturnEffect.play();
        }
    }
    else if(this->ui->stack->currentIndex()==3)//help_menu
    {
        int totalpages=this->ui->helpstack->count();
        int currentpage=this->ui->helpstack->currentIndex();
        if(event->key()==Qt::Key_Up||event->key()==Qt::Key_Left)
        {
            this->ui->helpstack->setCurrentIndex((currentpage+totalpages-1)%totalpages);
            this->optionConfirmEffect.play();
        }
        if(event->key()==Qt::Key_Down||event->key()==Qt::Key_Right)
        {
            this->ui->helpstack->setCurrentIndex((currentpage+1)%totalpages);
            this->optionConfirmEffect.play();
        }
        if(event->key()==Qt::Key_Escape||event->key()==Qt::Key_X)
        {
            this->toMainMenu();
            this->optionReturnEffect.play();
        }
    }
    else if(this->ui->stack->currentIndex()==4)//difficulty_menu
    {
        if(event->key()==Qt::Key_Up)
        {
            this->focusPreviousChild();
            this->optionChangeEffect.play();
        }
        if(event->key()==Qt::Key_Down)
        {
            this->focusNextChild();
            this->optionChangeEffect.play();
        }
        if(event->key()==Qt::Key_Return||event->key()==Qt::Key_Z)
        {
            if(this->ui->tutorial_label->hasFocus())
                Difficulty=0,Level=0;
            if(this->ui->amateur_label->hasFocus())
                Difficulty=1,Level=1;
            if(this->ui->explorer_label->hasFocus())
                Difficulty=2,Level=1;
            if(this->ui->challenger_label->hasFocus())
                Difficulty=3,Level=1;
            this->toHeroMenu();
            this->optionConfirmEffect.play();
        }
        if(event->key()==Qt::Key_Escape||event->key()==Qt::Key_X)
        {
            this->toMainMenu();
            this->optionReturnEffect.play();
        }
    }
    else if(this->ui->stack->currentIndex()==5)//hero_menu
    {
        int totalpages=this->ui->herostack->count();
        int currentpage=this->ui->herostack->currentIndex();
        if(event->key()==Qt::Key_Up||event->key()==Qt::Key_Left)
        {
            this->ui->herostack->setCurrentIndex((currentpage+totalpages-1)%totalpages);
            this->optionConfirmEffect.play();
        }
        if(event->key()==Qt::Key_Down||event->key()==Qt::Key_Right)
        {
            this->ui->herostack->setCurrentIndex((currentpage+1)%totalpages);
            this->optionConfirmEffect.play();
        }
        if(event->key()==Qt::Key_Escape||event->key()==Qt::Key_X)
        {
            this->toDifficultyMenu();
            this->optionReturnEffect.play();
        }
        if(event->key()==Qt::Key_Return||event->key()==Qt::Key_Z)
        {
            Shottype=this->ui->herostack->currentIndex();//0123
            this->StartGame();
            this->optionReturnEffect.play();
        }
    }
    else if(this->ui->stack->currentIndex()==6)//battlefield
    {
        if(this->ui->battlefield_stack->currentIndex()==1)//pausescene
        {
            if(event->key()==Qt::Key_Escape||event->key()==Qt::Key_X)
            {
                this->ui->esc_label->setFocus();
                this->optionChangeEffect.play();
            }
            else if(event->key()==Qt::Key_Return||event->key()==Qt::Key_Z)
            {
                if(this->ui->continue_label->hasFocus())
                {
                    this->ui->battlefield_stack->setCurrentIndex(0);//battlescene
                    this->optionConfirmEffect.play();
                    this->ContinueGame();
                }
                else if(this->ui->esc_label->hasFocus())
                {
                    this->QuitGame();
                    this->toMainMenu();
                    this->optionConfirmEffect.play();
                }
                else if(this->ui->restart_label->hasFocus())
                {
                    //重新开始游戏
                    this->QuitGame();this->StartGame();
                    this->optionConfirmEffect.play();
                }
            }
            else if(event->key()==Qt::Key_R)
            {
                //重新开始
                this->QuitGame();this->StartGame();
                this->optionConfirmEffect.play();
            }
            else if(event->key()==Qt::Key_Up)
            {
                this->focusPreviousChild();
                //this->focusNextPrevChild(0);  //same effact
                this->optionChangeEffect.play();
            }
            else if(event->key()==Qt::Key_Down)
            {
                this->focusNextChild();
                //this->focusNextPrevChild(1);  //same effact
                this->optionChangeEffect.play();
            }
        }
        else if(this->ui->battlefield_stack->currentIndex()==2)//gameoverscene
        {
            if(event->key()==Qt::Key_Escape||event->key()==Qt::Key_X)
            {
                this->ui->over_esc_label->setFocus();
                this->optionChangeEffect.play();
            }
            else if(event->key()==Qt::Key_Return||event->key()==Qt::Key_Z)
            {
                if(this->ui->over_continue_label->hasFocus())
                {
                    //续关
                    this->ui->battlefield_stack->setCurrentIndex(0);//battlescene
                    this->optionConfirmEffect.play();
                    this->ui->battlescene->managerDep.bulletmanager.DestoryAllEnemyBullets();
                    this->ui->battlescene->hero.Revive(3,4.0);
                    this->ui->battlescene->managerDep.scoremanager.Init();
                    this->ContinueGame();
                }
                else if(this->ui->over_esc_label->hasFocus())
                {
                    this->QuitGame();
                    this->toMainMenu();
                    this->optionConfirmEffect.play();
                }
                else if(this->ui->over_restart_label->hasFocus())
                {
                    //重新开始游戏
                    this->QuitGame();this->StartGame();
                    this->optionConfirmEffect.play();
                }
            }
            else if(event->key()==Qt::Key_Up)
            {
                this->focusPreviousChild();
                //this->focusNextPrevChild(0);  //same effact
                this->optionChangeEffect.play();
            }
            else if(event->key()==Qt::Key_Down)
            {
                this->focusNextChild();
                //this->focusNextPrevChild(1);  //same effact
                this->optionChangeEffect.play();
            }
        }
        else if(this->ui->battlefield_stack->currentIndex()==3)//levelclearscene
        {
            if(event->key()==Qt::Key_Return)
            {
                Level=Level!=3?Level+1:3;
                int curscore=this->ui->battlescene->managerDep.scoremanager.score;
                int curtargetscore=this->ui->battlescene->managerDep.scoremanager.targetscore;
                int curhighscore=this->ui->battlescene->managerDep.scoremanager.highscore;
                int curtargethighscore=this->ui->battlescene->managerDep.scoremanager.targethighscore;
                this->ui->battlescene->managerDep.InitDep(&this->ui->battlescene->hero);
                //由于Init后scoremanager分数会清零,故此处恢复分数
                this->ui->battlescene->managerDep.scoremanager.score=curscore;
                this->ui->battlescene->managerDep.scoremanager.targetscore=curtargetscore;
                this->ui->battlescene->managerDep.scoremanager.highscore=curhighscore;
                this->ui->battlescene->managerDep.scoremanager.targethighscore=curtargethighscore;
                this->toBattlefield();
                Count=0;
            }
        }
        else if(this->ui->battlefield_stack->currentIndex()==0)//battlescene
        {
            if(event->key()==Qt::Key_Escape)
            {
                this->PauseGame();
                this->ui->battlefield_stack->setCurrentIndex(1);//pausescene
                this->ui->continue_label->setFocus();
                this->optionReturnEffect.play();
            }
            if(event->key()==Qt::Key_Z)
            {
                //射击开启
                this->ui->battlescene->hero.isShooting=true;
                /*
                if(this->ui->battlescene->managerDep.dialogplayer.isOnDisplay)
                    this->ui->battlescene->managerDep.soundmanager.ShootEffect.setVolume(0);
                else
                    this->ui->battlescene->managerDep.soundmanager.ShootEffect.setVolume(effectvolume);
                this->ui->battlescene->managerDep.soundmanager.ShootEffect.setLoopCount(-2);
                if(!this->ui->battlescene->managerDep.soundmanager.ShootEffect.isPlaying())
                {
                    this->ui->battlescene->managerDep.soundmanager.ShootEffect.play();
                }*/
            }
            if(event->key()==Qt::Key_X)
            {
                //使用强力技
                this->ui->battlescene->hero.isTryingActivateSpell=true;
            }
            if(event->key()==Qt::Key_Left)
            {
                this->ui->battlescene->hero.vector.MoveKeysPressed[0]=true;
            }
            if(event->key()==Qt::Key_Right)
            {
                this->ui->battlescene->hero.vector.MoveKeysPressed[3]=true;
            }
            if(event->key()==Qt::Key_Up)
            {
                this->ui->battlescene->hero.vector.MoveKeysPressed[1]=true;
            }
            if(event->key()==Qt::Key_Down)
            {
                this->ui->battlescene->hero.vector.MoveKeysPressed[2]=true;
            }
            if(event->key()==Qt::Key_Shift)
            {
                this->ui->battlescene->hero.vector.MoveKeysPressed[4]=true;
            }
            if(event->key()==Qt::Key_Control)
            {
                if(this->ui->battlescene->managerDep.dialogplayer.isOnDisplay)
                {
                    this->ui->battlescene->managerDep.dialogplayer.speaktimes++;
                }
            }
            if(event->key()==Qt::Key_Return)//快进对话
            {
                if(this->ui->battlescene->managerDep.dialogplayer.isOnDisplay)
                {
                    //this->ui->battlescene->managerDep.dialogplayer.speaktimes++;
                    this->ui->battlescene->managerDep.dialogplayer.isskipping=true;
                }
            }
            /*
            //调试用
            if(event->key()==Qt::Key_1)
                this->ui->battlescene->hero.power=1;
            if(event->key()==Qt::Key_2)
                this->ui->battlescene->hero.power=2;
            if(event->key()==Qt::Key_3)
                this->ui->battlescene->hero.power=3;
            if(event->key()==Qt::Key_4)
                this->ui->battlescene->hero.power=4;
            */
        }
    }
}

void MainWidget::keyReleaseEvent(QKeyEvent *event)
{
    if(this->ui->stack->currentIndex()==6&&this->ui->battlefield_stack->currentIndex()==0)//battlescene
    {
        if(event->key()==Qt::Key_Z)
        {
            this->ui->battlescene->hero.isShooting=false;
            //this->ui->battlescene->managerDep.soundmanager.ShootEffect.setLoopCount(0);
            //this->ui->battlescene->managerDep.soundmanager.ShootEffect.stop();
        }
        if(event->key()==Qt::Key_X)
        {
            this->ui->battlescene->hero.isTryingActivateSpell=false;
        }
        if(event->key()==Qt::Key_Left)
        {
            this->ui->battlescene->hero.vector.MoveKeysPressed[0]=false;
        }
        if(event->key()==Qt::Key_Right)
        {
            this->ui->battlescene->hero.vector.MoveKeysPressed[3]=false;
        }
        if(event->key()==Qt::Key_Up)
        {
            this->ui->battlescene->hero.vector.MoveKeysPressed[1]=false;
        }
        if(event->key()==Qt::Key_Down)
        {
            this->ui->battlescene->hero.vector.MoveKeysPressed[2]=false;
        }
        if(event->key()==Qt::Key_Shift)
        {
            this->ui->battlescene->hero.vector.MoveKeysPressed[4]=false;
        }
        if(event->key()==Qt::Key_Return)
        {
            this->ui->battlescene->managerDep.dialogplayer.isskipping=false;
        }
    }
}

