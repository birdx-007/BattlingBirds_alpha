#include "gameheaders/managerdep.h"

ManagerDep::ManagerDep(QObject *parent)
{
    Q_UNUSED(parent);
}

void ManagerDep::InitDep(Hero* hero_)
{
    this->soundmanager.Init();
    this->hero=hero_;
    this->enemymanager.Init();
    this->bulletmanager.Init();
    this->propmanager.Init();
    this->barragemanager.Init(&this->bulletmanager,&this->enemymanager);
    this->dialogplayer.Init();
    this->background.Init(this->hero->spellcount);
    this->titleplayer.Init();
    this->scoremanager.Init();
    Idx=0;
    this->isFighting=true;
    this->isFightingBoss=false;
    this->gracecount=0;
    this->hitcount=0;
    this->propscore=0;
    //链接信号
    connect(&this->bulletmanager,SIGNAL(EnemyBulletDeath(qreal,qreal,int,int,int,int,int,int)),this,SLOT(GenerateProp(qreal,qreal,int,int,int,int,int,int)));
    connect(&this->enemymanager,SIGNAL(ZakoDeath(qreal,qreal,int,int,int,int,int,int)),this,SLOT(GenerateProp(qreal,qreal,int,int,int,int,int,int)));
    connect(&this->enemymanager,SIGNAL(BossDeath(qreal,qreal,int,int,int,int,int,int)),this,SLOT(GenerateProp(qreal,qreal,int,int,int,int,int,int)));
}

void ManagerDep::HeroShootOnce()
{
    int islow=this->hero->speed==this->hero->highspeed?0:1;
    int powerlevel=int(this->hero->power);
    int hnum=this->hero->heronum;
    qreal x=this->hero->collibox.center().x()-5/*偏移量*/*Width/1920,y=this->hero->collibox.center().y();
    qreal angle,anglepiece,initangle,targetangle;
    switch (hnum) {
    case 0:
    {
        if(islow)//怒鸟红，发散诱导弹
        {
            angle=2.0/6*M_PI;
            anglepiece=powerlevel==1?0:angle/(powerlevel-1);
            initangle=(-1.0/2-1.0/6)*M_PI;
            for(int i=powerlevel==1?1:0;i<powerlevel;i++)
            {
                qreal targetangle=initangle+i*anglepiece;
                this->bulletmanager.AddOneHeroBullet(this->hero,hnum,islow,x,y,qCos(targetangle),qSin(targetangle));
            }
            this->bulletmanager.AddOneHeroBullet(this->hero,hnum,islow,x,y,0,-1);
        }
        else//飞镖黄，集中直线弹
        {
            angle=5.0/6*M_PI;
            anglepiece=powerlevel==1?0.0:angle/(powerlevel-1);
            initangle=(-1.0/2-2.5/6)*M_PI;
            for(int i=powerlevel==1?1:0;i<powerlevel;i++)
            {
                targetangle=initangle+i*anglepiece;
                this->bulletmanager.AddOneHeroBullet(this->hero,hnum,islow,x+70.0*qCos(targetangle)*Width/1920,y+70.0*qSin(targetangle)*Width/1920,0,-1);
            }
            this->bulletmanager.AddOneHeroBullet(this->hero,hnum,islow,x,y-70*Width/1920,0,-1);
        }
        break;
    }
    case 1:
    {
        if(islow)//泡泡橙，全向子弹
        {
            angle=1.0/3*M_PI;
            anglepiece=powerlevel==1?0.0:angle/(powerlevel-1);
            if(powerlevel==1)
            {
                this->bulletmanager.AddOneHeroBullet(this->hero,hnum,islow,x,y-70.0*Width/1920,0,-1);
            }
            else
            {
                this->bulletmanager.AddOneHeroBullet(this->hero,hnum,islow,x+70.0*qCos((-1.0/2-1.0/10)*M_PI)*Width/1920,y+70.0*qSin((-1.0/2-1.0/10)*M_PI)*Width/1920,0,-1);
                this->bulletmanager.AddOneHeroBullet(this->hero,hnum,islow,x+70.0*qCos((-1.0/2+1.0/10)*M_PI)*Width/1920,y+70.0*qSin((-1.0/2+1.0/10)*M_PI)*Width/1920,0,-1);
            }
            angle=2*M_PI;
            anglepiece=angle/4/*powerlevel*/;
            targetangle=Count%360/360.0*2*M_PI*3;
            for(int i=0;i<4/*powerlevel*/;i++)
            {
                this->bulletmanager.AddOneHeroBullet(this->hero,hnum,islow,x+70.0*qCos(targetangle)*Width/1920,y+70.0*qSin(targetangle)*Width/1920,qCos(targetangle),qSin(targetangle));
                qreal subanglepiece=1.0/18*M_PI*(powerlevel-1)/3;
                for(int j=1;j<powerlevel;j++)
                {
                    this->bulletmanager.AddOneHeroBullet(this->hero,hnum,islow,x+70.0*qCos(targetangle+j*subanglepiece)*Width/1920,y+70.0*qSin(targetangle+j*subanglepiece)*Width/1920,qCos(targetangle+j*subanglepiece),qSin(targetangle+j*subanglepiece));
                }
                targetangle+=anglepiece;
            }
        }
        else//蓝弟弟，扩散型子弹
        {
            anglepiece=1.0/8*M_PI;
            initangle=(-1.0/2-1.0/8)*M_PI;
            for(int i=0;i<3;i++)
            {
                qreal targetangle=initangle+i*anglepiece;
                this->bulletmanager.AddOneHeroBullet(this->hero,hnum,islow,x,y,qCos(targetangle),qSin(targetangle));
            }
            if(powerlevel>1)
            {
                qreal xleft=x-150.0*Width/1920;
                qreal xright=x+150.0*Width/1920;
                angle=1.0/4*M_PI;
                anglepiece=powerlevel==2?0.0:angle/(powerlevel-2);
                initangle=powerlevel==2?(-1.0/2)*M_PI:(-1.0/2-1.0/8)*M_PI;
                for(int i=0;i<powerlevel-1;i++)
                {
                    targetangle=initangle+i*anglepiece;
                    this->bulletmanager.AddOneHeroBullet(this->hero,hnum,islow,xleft,y,qCos(targetangle),qSin(targetangle));
                    this->bulletmanager.AddOneHeroBullet(this->hero,hnum,islow,xright,y,qCos(targetangle),qSin(targetangle));
                }
                if(powerlevel>2)
                {
                    this->bulletmanager.AddOneHeroBullet(this->hero,hnum,islow,x+70.0*qCos((-1.0/2-1.0/10)*M_PI)*Width/1920,y+70.0*qSin((-1.0/2-1.0/10)*M_PI)*Width/1920,0,-1);
                    this->bulletmanager.AddOneHeroBullet(this->hero,hnum,islow,x+70.0*qCos((-1.0/2+1.0/10)*M_PI)*Width/1920,y+70.0*qSin((-1.0/2+1.0/10)*M_PI)*Width/1920,0,-1);
                }
            }
        }
        break;
    }
    case 2:
    {
        if(islow)//大红，超集中
        {
            anglepiece=1.0/16*M_PI;
            initangle=-1.0/2*M_PI-(2*powerlevel-1)*anglepiece/2;
            for(int i=0;i<powerlevel*2;i++)
            {
                targetangle=initangle+i*anglepiece;
                this->bulletmanager.AddOneHeroBullet(this->hero,hnum,islow,x+80*qCos(targetangle)*Width/1920,y+80*qSin(targetangle)*Width/1920,0,-1);
            }
        }
        else//炸弹黑，追踪爆破
        {
            angle=2*M_PI;
            anglepiece=angle/powerlevel;
            //initangle=(-1.0/2)*M_PI-(powerlevel-1)*anglepiece/2;
            initangle=-Count%360/360.0*2*M_PI*5;
            for(int i=0;i<powerlevel;i++)
            {
                targetangle=initangle+i*anglepiece;
                this->bulletmanager.AddOneHeroBullet(this->hero,hnum,islow,x+80*qCos(targetangle)*Width/1920,y+80*qSin(targetangle)*Width/1920,0,-1);
            }
        }
        break;
    }
    case 3:
    {
        if(islow)//白公主，集中
        {
            qreal shootangle;
            anglepiece=1.0/6*M_PI;
            initangle=-1.0/2*M_PI-(powerlevel)*anglepiece/2;
            for(int i=0;i<powerlevel+1;i++)
            {
                targetangle=initangle+i*anglepiece;
                shootangle=-0.5*M_PI+(powerlevel*0.5-i)*anglepiece/(y*y/100000.0);
                this->bulletmanager.AddOneHeroBullet(this->hero,hnum,islow,x+120*qCos(targetangle)*Width/1920,y+90*qSin(targetangle)*Width/1920,qCos(shootangle),qSin(shootangle));
            }
        }
        else//粉思思，舞动前进
        {
            angle=2*M_PI;
            anglepiece=angle/powerlevel;
            //initangle=(-1.0/2)*M_PI-(powerlevel-1)*anglepiece/2;
            initangle=Count%360/360.0*2*M_PI*2.5;
            for(int i=0;i<powerlevel;i++)
            {
                targetangle=qCos(initangle+i*anglepiece)*M_PI/10-1.0/2*M_PI;
                this->bulletmanager.AddOneHeroBullet(this->hero,hnum,islow,x,y-80*Width/1920,qCos(targetangle),qSin(targetangle));
            }
            this->bulletmanager.AddOneHeroBullet(this->hero,hnum,islow,x,y,0,-1);
            if((Count/5)%(6-powerlevel)==0)
            {
                this->bulletmanager.AddOneHeroBullet(this->hero,hnum,islow,x-20.0*Width/1920,y,0,-1);
                this->bulletmanager.AddOneHeroBullet(this->hero,hnum,islow,x+20.0*Width/1920,y,0,-1);
            }
        }
        break;
    }
    default:
        break;
    }
    if(!this->soundmanager.ShootEffect.isPlaying())
        this->soundmanager.ShootEffect.play();
}

void ManagerDep::HeroUseSpellOnce()
{
    this->hero->spells--;
    this->hero->isGhost=true;//无敌
    this->hero->isAbsorbingProps=true;
    this->bulletmanager.DestoryAllEnemyBullets();
    if(!this->background.isSpellBackGroundOnDisplay)
    {
        bool islow=this->hero->speed==this->hero->lowspeed;
        this->background.ActivateSpellBackGround(islow);
    }
    this->hero->canActivateSpell=false;
}

void ManagerDep::HeroSpellTimeOut()
{
    this->hero->isGhost=false;
    this->hero->isAbsorbingProps=false;
    this->bulletmanager.DestoryAllEnemyBullets();
    if(this->background.isSpellBackGroundOnDisplay)
    {
        this->background.DeactivateSpellBackGround();
    }
    this->hero->canActivateSpell=true;
}

void ManagerDep::ManageDialog()
{
    if(this->dialogplayer.isOnDisplay&&this->dialogplayer.isskipping)//对话快进
    {
        this->dialogplayer.speaktimes++;
        this->dialogplayer.isskipping=false;
    }
}

void ManagerDep::ManageSpell()
{
    if(this->hero->isTryingActivateSpell)
    {
        if(!this->dialogplayer.isOnDisplay&&this->hero->spells>0&&this->hero->canActivateSpell)
        {
            //使用强力技
            this->HeroUseSpellOnce();
            this->soundmanager.SpellEffect.setVolume(effectvolume);
            this->soundmanager.SpellEffect.play();
        }
    }
    if(!this->hero->canActivateSpell)
    {
        if(Count-this->background.startcount>=this->hero->spellcount)//时间结束
        {
            //结束强力技
            this->HeroSpellTimeOut();
        }
        else//时间未结束
        {
            this->bulletmanager.DestoryAllEnemyBullets();
            if((Count-this->background.startcount)%40==0)
            {
                //敌人集体扣血
                this->enemymanager.DamageAllZakos(75);
                this->enemymanager.DamageAllBosses(80);
            }
        }
    }
}

void ManagerDep::ManageHeroGhost()
{
    if(this->hero->isGhost)
    {
        if(this->hero->canActivateSpell)//非强力技无敌
        {
            //this->hero->isAbsorbingProps=true;//为了平衡性，取消
            if(Count-this->hero->tmpcount>=this->hero->ghostcount)
            {
                this->hero->isGhost=false;
                //this->hero->isAbsorbingProps=false;
            }
        }
    }
}

void ManagerDep::ManageHeroDeath()
{
    this->soundmanager.MissEffect.play();
    bool isGameOver=this->hero->players==0;
    if(!isGameOver)
    {
        this->bulletmanager.DestoryAllEnemyBullets();
        this->hero->Revive(this->hero->players-1,std::max(this->hero->power-0.6,1.0));
    }
    else
    {
        this->scoremanager.UpdateHighScore();
        this->soundmanager.FailEffect.play();
        emit GameOverSignal();
    }
}

void ManagerDep::ManageScore()
{
    if(this->isFighting&&!this->dialogplayer.isOnDisplay&&!this->isFightingBoss&&!this->hero->isGhost)//非boss战正常行进时加分
    {
        this->scoremanager.AddScore(Count%5==0?1:0);
    }
    this->scoremanager.AddScore(this->hitcount*4);
    this->scoremanager.AddScore(this->gracecount*15);
    this->scoremanager.AddScore(this->propscore);
    this->scoremanager.UpdateScores();
}

void ManagerDep::ManageCollisions()
{
    //清零
    this->hitcount=0;
    this->gracecount=0;
    this->propscore=0;
    bool islowhp=false;

    for(auto boss=this->enemymanager.bosses.begin();boss!=this->enemymanager.bosses.end();boss++)
    {
        boss->second.isColliding(this->hero);
        for(auto bullet=this->bulletmanager.herobullets.begin();bullet!=this->bulletmanager.herobullets.end();bullet++)
        {
            if(GameObj::getMDistance(&boss->second,&*bullet)<=500.0*Width/1920)
                this->hitcount+=(int)boss->second.isColliding(&*bullet);//减少调用次数
        }
        islowhp=islowhp==true?true:boss->second.hp<std::min(50.0,boss->second.maxhp*0.1);
    }

    for(auto zako=this->enemymanager.zakos.begin();zako!=this->enemymanager.zakos.end();zako++)
    { 
        zako->second.isColliding(this->hero);
        for(auto bullet=this->bulletmanager.herobullets.begin();bullet!=this->bulletmanager.herobullets.end();bullet++)
        {
            if(GameObj::getMDistance(&zako->second,&*bullet)<=200.0*Width/1920)
                this->hitcount+=(int)zako->second.isColliding(&*bullet);//减少调用次数
        }
        islowhp=islowhp==true?true:zako->second.hp<std::min(50.0,zako->second.maxhp*0.1);
    }

    for(auto bullet=this->bulletmanager.enemybullets.begin();bullet!=this->bulletmanager.enemybullets.end();bullet++)
    {
        if(GameObj::getMDistance(&*bullet,this->hero)<=50.0*Width/1920)//曼哈顿距离
        {
            this->gracecount+=1;//擦弹
            bullet->isColliding(this->hero);//减少调用次数
        }
        //bullet->isColliding(this->hero);
    }

    for(auto power=this->propmanager.powers.begin();power!=this->propmanager.powers.end();power++)
    {
        if(GameObj::getMDistance(&*power,this->hero)<=50.0*Width/1920)//曼哈顿距离
        {
            bool colliding=power->isColliding(this->hero);//减少调用次数
            if(colliding)
            {
                int score=this->hero->power>3.95?power->maxscore:power->minscore;
                this->propscore+=score;
            }
        }
    }

    for(auto score=this->propmanager.scores.begin();score!=this->propmanager.scores.end();score++)
    {
        if(GameObj::getMDistance(&*score,this->hero)<=50.0*Width/1920)//曼哈顿距离
        {
            bool colliding=score->isColliding(this->hero);//减少调用次数
            if(colliding)
            {
                int Score;
                if(score->Y>200.0*Width/1920&&score->Y<800.0*Width/1920)
                {
                    Score=score->minscore+int((score->maxscore-score->minscore)*(800.0*Width/1920-score->Y)/(600.0*Width/1920));
                }
                else
                {
                    Score=score->Y<=200.0*Width/1920?score->maxscore:score->minscore;
                }
                this->propscore+=Score;
            }
        }
    }

    if(this->hitcount>0)
    {
        if(islowhp)
            this->soundmanager.HitEffect_lowhp.play();
        else
            this->soundmanager.HitEffect.play();
    }
}

void ManagerDep::ManageBackGroundMoving()
{
    this->background.MoveBackGround();
}

void ManagerDep::ManageHeroBulletsMoving()
{
    for(auto iter=this->bulletmanager.herobullets.begin();iter!=this->bulletmanager.herobullets.end();iter++)
    {
        if(iter->istracking==false||(this->enemymanager.bosses.size()==0&&this->enemymanager.zakos.size()==0))
            this->bulletmanager.MoveOneHeroBullet(&*iter);
        else
        {
            double mindistancesquare=1500*1500;
            Enemy* target=NULL;
            for(auto bossiter=this->enemymanager.bosses.begin();bossiter!=this->enemymanager.bosses.end();bossiter++)
            {
                if(bossiter->second.Y<=0/*||bossiter->second.Y>=1400*Width/1920*/)
                    continue;
                qreal deltaX=qAbs(bossiter->second.X+bossiter->second.colliX/2-iter->X);
                qreal deltaY=qAbs(bossiter->second.Y+bossiter->second.colliY/2-iter->Y);
                double tmpdistancesquare=deltaX*deltaX+deltaY*deltaY;
                if(tmpdistancesquare<mindistancesquare)
                {
                    mindistancesquare=tmpdistancesquare;
                    target=&bossiter->second;
                }
            }
            for(auto zakoiter=this->enemymanager.zakos.begin();zakoiter!=this->enemymanager.zakos.end();zakoiter++)
            {
                if(zakoiter->second.Y<=0/*||zakoiter->second.Y>=1400*Width/1920*/)
                    continue;
                qreal deltaX=qAbs(zakoiter->second.X-iter->X);
                qreal deltaY=qAbs(zakoiter->second.Y-iter->Y);
                qreal tmpdistancesquare=deltaX*deltaX+deltaY*deltaY;
                if(tmpdistancesquare<mindistancesquare)
                {
                    mindistancesquare=tmpdistancesquare;
                    target=&zakoiter->second;
                }
            }
            //已找到与子弹间距最小的敌人
            this->bulletmanager.MoveOneHeroBullet(&*iter,&*target);
        }
    }
}

void ManagerDep::ManageEnemyBulletsMoving()
{
    for(auto iter=this->bulletmanager.enemybullets.begin();iter!=this->bulletmanager.enemybullets.end();iter++)
    {
        if(iter->istracking==false)
            this->bulletmanager.MoveOneEnemyBullet(&*iter);
        else
            this->bulletmanager.MoveOneEnemyBullet(&*iter,this->hero);
    }
}

void ManagerDep::ManageZakosMoving()
{
    for(auto iter=this->enemymanager.zakos.begin();iter!=this->enemymanager.zakos.end();iter++)
    {
        this->enemymanager.MoveOneEnemy(&iter->second);
    }
}

void ManagerDep::ManageBossesMoving()
{
    for(auto iter=this->enemymanager.bosses.begin();iter!=this->enemymanager.bosses.end();iter++)
    {
        this->enemymanager.MoveOneEnemy(&iter->second);
    }
}

void ManagerDep::ManagePropMoving()
{
    for(auto iter=this->propmanager.powers.begin();iter!=this->propmanager.powers.end();iter++)
    {
        if(!this->hero->isAbsorbingProps && GameObj::getMDistance(&*iter,this->hero)>100*Width/1920)
            this->propmanager.MoveOneProp(&*iter);
        else
            this->propmanager.MoveOneProp(&*iter,this->hero);
    }
    for(auto iter=this->propmanager.scores.begin();iter!=this->propmanager.scores.end();iter++)
    {
        if(!this->hero->isAbsorbingProps && GameObj::getMDistance(&*iter,this->hero)>100*Width/1920)
            this->propmanager.MoveOneProp(&*iter);
        else
            this->propmanager.MoveOneProp(&*iter,this->hero);
    }
}

void ManagerDep::DestoryInvalidObjects()
{
    this->enemymanager.enemies_dead_of_hero=0;
    this->bulletmanager.DestoryInvalidBullets();
    this->enemymanager.DestoryInvalidBosses();
    this->enemymanager.DestoryInvalidZakos();
    this->propmanager.DestoryInvalidProps();
    if(this->enemymanager.enemies_dead_of_hero>0)
    {
        this->soundmanager.Pig_DeadEffect.play();
    }
}

void ManagerDep::DestoryAllObjects()
{
    this->bulletmanager.DestoryAllHeroBullets();
    this->bulletmanager.DestoryAllEnemyBullets();
    this->enemymanager.DestoryAllBosses();
    this->enemymanager.DestoryAllZakos();
    this->propmanager.DestoryAllPowers();
    this->propmanager.DestoryAllScores();
}

void ManagerDep::GenerateProp(Enemy *e)
{
    int sp=e->smallpowercount;
    int ss=e->smallscorecount;
    int bp=e->bigpowercount;
    int bs=e->bigscorecount;
    this->GenerateProp(e->collibox.center().x(),e->collibox.center().y(),sp,ss,bp,bs,0,0);
}

void ManagerDep::GenerateProp(qreal x, qreal y, int sp, int ss, int bp, int bs,int fp,int ts)
{
    int countsum=sp+ss+bp+bs;
    qreal edgelength=countsum<=10?180.0*Width/1920:480.0*Width/1920;
    qreal propx,propy;
    int i;
    for(i=0;i<sp;i++)
    {
        propx=x+(qrand()%100-49.5)*edgelength/100.0*(countsum!=1);
        propy=y+(qrand()%100-49.5)*edgelength/100.0*(countsum!=1);
        this->propmanager.AddOnePower(tr("small"),propx,propy);
    }
    for(i=0;i<ss;i++)
    {
        propx=x+(qrand()%100-49.5)*edgelength/100.0*(countsum!=1);
        propy=y+(qrand()%100-49.5)*edgelength/100.0*(countsum!=1);
        this->propmanager.AddOneScore(tr("small"),propx,propy);
    }
    for(i=0;i<bp;i++)
    {
        propx=x+(qrand()%100-49.5)*edgelength/100.0*(countsum!=1);
        propy=y+(qrand()%100-49.5)*edgelength/100.0*(countsum!=1);
        this->propmanager.AddOnePower(tr("big"),propx,propy);
    }
    for(i=0;i<bs;i++)
    {
        propx=x+(qrand()%100-49.5)*edgelength/100.0*(countsum!=1);
        propy=y+(qrand()%100-49.5)*edgelength/100.0*(countsum!=1);
        this->propmanager.AddOneScore(tr("big"),propx,propy);
    }
    for(i=0;i<fp;i++)
    {
        propx=x+(qrand()%100-49.5)*edgelength/100.0*(countsum!=1);
        propy=y+(qrand()%100-49.5)*edgelength/100.0*(countsum!=1);
        this->propmanager.AddOnePower(tr("full"),propx,propy);
    }
    for(i=0;i<ts;i++)
    {
        propx=x+(qrand()%100-49.5)*edgelength/100.0*(countsum!=1);
        propy=y+(qrand()%100-49.5)*edgelength/100.0*(countsum!=1);
        this->propmanager.AddOneScore(tr("tiny"),propx,propy);
    }
}

void ManagerDep::GenerateLevel()
{
    if(Level==0)
        this->GenerateLevel0();
    else if(Level==1)
        this->GenerateLevel1();
    else if(Level==2)
        this->GenerateLevel2();
    else if(Level==3)
        this->GenerateLevel3();
    if(this->background.isSpellBackGroundOnDisplay)
    {
        this->hero->isAbsorbingProps=true;
    }
}
