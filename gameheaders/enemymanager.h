#ifndef ENEMYMANAGER_H
#define ENEMYMANAGER_H
#include <QObject>
#include <QtMath>
#include <unordered_map>
#include <vector>
#include "gameheaders/gameobj.h"
#include "gameheaders/enemy.h"
class EnemyManager : public QObject
{
    Q_OBJECT
public:
    explicit EnemyManager(QObject *parent = nullptr);
    void Init();
    std::unordered_map<int,Boss> bosses;
    std::unordered_map<int,Zako> zakos;
    std::vector<int> dyingbosses;
    std::vector<int> dyingzakos;
    void AddOneZako(qreal maxhp,QString size,QString armor,QString species,qreal x,qreal y,qreal tx, qreal ty,qreal speed,qreal dspeed,int sp=0,int ss=0,int bp=0,int bs=0);
    void AddOneBoss(qreal maxhp,int maxstage,QString size,QString armor,QString species,QString name,qreal x,qreal y,qreal tx, qreal ty,qreal speed,qreal dspeed,int sp=0,int ss=0,int bp=0,int bs=0);
    void SetOneEnemyProp(Enemy* t,int sp=0,int ss=0,int bp=0,int bs=0);
    void SetOneEnemyMoveMode(Enemy* t,qreal tx, qreal ty,qreal speed,qreal dspeed);//设定移动，x y为目标位置，标记运动起始时间tmpcount
    void SetOneEnemyRandomMode(Enemy* t,qreal minx,qreal maxx,qreal miny,qreal maxy,qreal speed);//设定矩形内随机移动目标
    bool MoveOneEnemy(Enemy* t);//facemode为face是否随位移而变，返回值为是否完成移动
    void DamageAllZakos(qreal value);
    void DamageAllBosses(qreal value);
    void DestoryInvalidBosses();
    void DestoryInvalidZakos();
    void DestoryAllBosses();
    void DestoryAllZakos();
    int enemies_dead_of_hero;
signals:
    void ZakoDeath(qreal x,qreal y,int sp,int ss,int bp,int bs,int fp=0,int ts=0);
    void BossDeath(qreal x,qreal y,int sp,int ss,int bp,int bs,int fp=0,int ts=0);
};
#endif // ENEMYMANAGER_H
