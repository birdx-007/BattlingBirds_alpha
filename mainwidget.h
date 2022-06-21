#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPixmap>
#include <QKeyEvent>
#include <QString>
#include <QUrl>
#include <QSound>
#include <QSoundEffect>
#include <QMediaPlayer>
#include "constant.h"
#include "loadingthread.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWidget; }
QT_END_NAMESPACE

extern int Width;
extern int Height;

extern int Count;
extern int Level;
extern int Difficulty;//难度0123
extern int Shottype;//机体0123

extern int BGMvolume;
extern qreal effectvolume;

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    friend class LoadingThread;
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();
    void InitResources();
    void setDispalyMode();
    void setEffectVolume(qreal volume);
    void setBGMVolume(int volume);
    void toMainMenu();
    void toSettingMenu();
    void toHelpMenu();
    void toDifficultyMenu();
    void toHeroMenu();
    void toBattlefield();
    void GameOver();
    void LevelClear();
    void StartGame();
    void PauseGame();//暂停游戏
    void ContinueGame();//（从暂停界面）继续游戏
    void QuitGame();
    void UpdateData();
    void paintEvent(QPaintEvent*event);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

signals:
    void ExitSignal();

private:
    Ui::MainWidget *ui;
    QSoundEffect optionChangeEffect;
    QSoundEffect optionConfirmEffect;
    QSoundEffect optionReturnEffect;
    LoadingThread *loadingthread;
};
#endif // MAINWIDGET_H
