#ifndef DIALOGPLAYER_H
#define DIALOGPLAYER_H
#include <QObject>
#include <QPainter>
#include "gameheaders/gameobj.h"
#include "constant.h"

extern int Shottype;//机体0123

class DialogPlayer:public QObject
{
    Q_OBJECT
public:
    explicit DialogPlayer(QObject *parent = nullptr);
    void Init();
    QPixmap leftspeaker;//左边默认为自机组简介图即hero(%编号).png
    QPixmap rightspeaker;
    QPixmap dlgframe;//对话框
    QString text;
    bool isOnDisplay;//是否显示
    bool isskipping;//是否正在快进对话
    qreal leftopacity,rightopacity;
    int speaktimes;
    void setLeft(QString ldir);
    void setRight(QString rdir);
    void setText(QString txt);
    void LeftSpeak(QString txt);
    void RightSpeak(QString txt);
    void Draw(QPainter* painter);
signals:
};

#endif // DIALOGPLAYER_H
