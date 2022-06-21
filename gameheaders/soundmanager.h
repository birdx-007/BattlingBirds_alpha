#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H
#include <QObject>
#include <QSound>
#include <QSoundEffect>
#include <QMediaPlayer>
#include "gameheaders/gameobj.h"
class SoundManager : public QObject
{
    Q_OBJECT
public:
    explicit SoundManager(QObject *parent = nullptr);
    void Init();
    QSoundEffect ShootEffect;
    QSoundEffect SpellEffect;
    QSoundEffect HitEffect;
    QSoundEffect HitEffect_lowhp;
    QSoundEffect Pig_DeadEffect;
    QSoundEffect MissEffect;
    QSoundEffect ClearEffect;
    QSoundEffect FailEffect;
signals:
};
#endif // SOUNDMANAGER_H
