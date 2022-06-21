#ifndef BULLETMANAGER_H
#define BULLETMANAGER_H
#include <QObject>
#include <QtMath>
#include <vector>
#include "gameheaders/gameobj.h"
#include "gameheaders/bullet.h"
class BulletManager : public QObject
{
    Q_OBJECT
public:
    explicit BulletManager(QObject *parent = nullptr);
    void Init();
    std::vector<HeroBullet> herobullets;
    std::vector<EnemyBullet> enemybullets;
    void AddOneHeroBullet(GameObj *p, int hnum, bool islow, qreal x, qreal y, qreal facex, qreal facey);
    void AddOneEnemyBullet(GameObj *p, QString color, QString shape, qreal x, qreal y, qreal facex, qreal facey,qreal speed=10.0,qreal dspeed=0.0);
    void MoveOneHeroBullet(HeroBullet *bullet,GameObj *target=NULL);
    void MoveOneEnemyBullet(EnemyBullet *bullet,GameObj *target=NULL);
    void DestoryInvalidBullets();
    void DestoryAllHeroBullets();
    void DestoryAllEnemyBullets();
signals:
    void HeroBulletDeath(qreal x,qreal y);
    void EnemyBulletDeath(qreal x,qreal y,int sp=0,int ss=0,int bp=0,int bs=0,int fp=0,int ts=1);
};
#endif // BULLETMANAGER_H
