#ifndef PROPMANAGER_H
#define PROPMANAGER_H
#include <QObject>
#include <QtMath>
#include <vector>
#include "gameheaders/gameobj.h"
#include "gameheaders/prop.h"
class PropManager : public QObject
{
    Q_OBJECT
public:
    explicit PropManager(QObject *parent = nullptr);
    void Init();
    std::vector<Power> powers;
    std::vector<Score> scores;
    void AddOnePower(QString size, qreal x, qreal y);
    void AddOneScore(QString size, qreal x, qreal y);
    void MoveOneProp(Prop *prop,Hero *target=NULL);
    void DestoryInvalidProps();
    void DestoryAllPowers();
    void DestoryAllScores();
signals:
    void PowerDeath(qreal x,qreal y);
    void ScoreDeath(qreal x,qreal y);
};
#endif // PROPMANAGER_H
