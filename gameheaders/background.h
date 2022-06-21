#ifndef BACKGROUND_H
#define BACKGROUND_H
#include <QPixmap>
#include <QPainter>
#include "constant.h"

extern int Width;
extern int Height;
extern int Count;
extern int Level;

class BackGround
{
public:
    explicit BackGround();
    void Init(int spellcount);
    void SetMainBackground(qreal speed,qreal dspeed,QString bgname=QString(""));
    void ActivateSpellBackGround(bool islow);
    void DeactivateSpellBackGround();
    void MoveBackGround();
    void Draw(QPainter* painter);
    QPixmap mainbg;
    QPixmap spellbg;//强力技释放背景
    qreal mainbg_y;
    qreal spellbg_y;
    qreal mainbgspeed;
    qreal mainbgdspeed;
    qreal spellbgspeed;
    qreal spellbgdspeed;
    bool isSpellBackGroundOnDisplay;
    int startcount;//强力技起始时间
    int endcount;//强力技结束时间
};

#endif // BACKGROUND_H
