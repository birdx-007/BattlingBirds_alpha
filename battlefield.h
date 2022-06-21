#ifndef BATTLEFIELD_H
#define BATTLEFIELD_H

#include <QWidget>
#include <QIcon>
#include <QTimer>
#include <QPainter>
#include <QKeyEvent>
#include "gameheaders/gameobj.h"
#include "gameheaders/hero.h"
#include "gameheaders/managerdep.h"
#include "mainwidget.h"

class Battlefield : public QWidget
{
    Q_OBJECT
public:
    Battlefield(QWidget *parent = nullptr);
    QTimer* timer;
    void Init(MainWidget *p,int herochoice);//在mainwidget调用startgame时初始化场景所有元素
    void UpdateData(qreal&dx,qreal&dy);
    void paintEvent(QPaintEvent*event);
    MainWidget *parent;
    Hero hero;
    ManagerDep managerDep;
};

#endif // BATTLEFIELD_H
