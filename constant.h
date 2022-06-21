#ifndef CONFIG_H
#define CONFIG_H
#include <QString>
#include <QObject>

extern int Width;
extern int Height;

extern int Count;
extern int Idx;//全局唯一标识
extern int Level;

extern int Difficulty;//难度0123
extern int Shottype;//机体0123

extern int BGMvolume;
extern qreal effectvolume;

QString GetDifficulty();

#endif // CONFIG_H
