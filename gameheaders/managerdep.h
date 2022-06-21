#ifndef MANAGERDEP_H
#define MANAGERDEP_H
#include <QObject>
#include <QtMath>
#include "gameheaders/hero.h"
#include "gameheaders/bulletmanager.h"
#include "gameheaders/enemymanager.h"
#include "gameheaders/propmanager.h"
#include "gameheaders/barragemanager.h"
#include "gameheaders/dialogplayer.h"
#include "gameheaders/background.h"
#include "gameheaders/others.h"
#include "gameheaders/soundmanager.h"

class ManagerDep : public QObject
{
    Q_OBJECT
public:
    explicit ManagerDep(QObject *parent = nullptr);
    Hero* hero;
    BulletManager bulletmanager;
    EnemyManager enemymanager;
    PropManager propmanager;
    BarrageManager barragemanager;
    DialogPlayer dialogplayer;
    BackGround background;
    TitlePlayer titleplayer;
    ScoreManager scoremanager;
    SoundManager soundmanager;
    void InitDep(Hero* hero_);
    void HeroShootOnce();
    void HeroUseSpellOnce();
    void HeroSpellTimeOut();
    void ManageDialog();
    void ManageSpell();
    void ManageHeroGhost();
    void ManageHeroDeath();
    void ManageScore();
    void ManageCollisions();
    void ManageBackGroundMoving();
    void ManageHeroBulletsMoving();
    void ManageEnemyBulletsMoving();
    void ManageZakosMoving();
    void ManageBossesMoving();
    void ManagePropMoving();
    void DestoryInvalidObjects();
    void DestoryAllObjects();
    void GenerateProp(Enemy* e);
    void GenerateLevel();
    void GenerateLevel0();
    void GenerateLevel1();
    void GenerateLevel2();
    void GenerateLevel3();
    void GenerateLevel0Boss();
    void GenerateLevel1Boss();
    void GenerateLevel2Boss();
    bool isFightingBoss;
    bool isFighting;
    int gracecount;//该帧擦弹数
    int hitcount;//该帧命中数
    int propscore;//该帧吃道具得分
signals:
    void GameOverSignal();
    void LevelClearSignal();
private slots:
    void GenerateProp(qreal x,qreal y,int sp,int ss,int bp,int bs,int fp,int ts);
};
#endif // MANAGERDEP_H
