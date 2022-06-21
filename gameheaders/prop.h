#ifndef PROP_H
#define PROP_H
#include "gameheaders/gameobj.h"
#include "gameheaders/hero.h"

class Prop:public GameObj
{
public:
    explicit Prop();
    void init(int maxscore,int minscore);
    Hero* target;
    int maxscore=0;
    int minscore=0;
    int score=0;
};

class Power:public Prop
{
public:
    explicit Power();
    void Init(QString size,QString type,qreal x,qreal y);
    bool isColliding(Hero *target);
    qreal power=0;
};

class Score:public Prop
{
public:
    explicit Score();
    void Init(QString size,QString type,qreal x,qreal y);
    bool isColliding(Hero *target);
};

#endif // PROP_H
