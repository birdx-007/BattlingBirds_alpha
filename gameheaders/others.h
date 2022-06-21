#ifndef TITLEPLAYER_H
#define TITLEPLAYER_H
#include <QObject>
#include <QPainter>
#include <QFileInfo>
#include <QTextStream>
#include "gameheaders/gameobj.h"
#include "constant.h"

extern int Width;
extern int Count;
extern int Level;

class TitlePlayer:public QObject//负责展示关卡标题
{
    Q_OBJECT
public:
    explicit TitlePlayer(QObject *parent = nullptr);
    void Init();
    void SetTitle(int start,int end);
    void SetClearTitle(int start,int end);
    QPixmap Title;//关卡主标题 800*250
    QPixmap ClearTitle;//800*250
    int titlestartcount;
    int titleendcount;
    int clearstartcount;
    int clearendcount;
    void Draw(QPainter* painter);
signals:
};

class ScoreManager:public QObject//负责展示关卡标题
{
    Q_OBJECT
public:
    explicit ScoreManager(QObject *parent = nullptr);
    void Init();
    void AddScore(int value);
    void UpdateScores();
    void UpdateHighScore();
    int maxscoreincrement;//每帧最大分数增量（为了显示好看）
    int targetscore;
    int targethighscore;
    int score;
    int highscore;
    int oldhighscore;
signals:
};
#endif // TITLEPLAYER_H
