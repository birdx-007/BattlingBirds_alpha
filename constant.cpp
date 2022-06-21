#include "constant.h"

int Width=640;
int Height=480;
int Count=0;
int Idx=0;
int Level=1;

int Difficulty=1;
int Shottype=0;

int BGMvolume=100;
qreal effectvolume=1.0f;

QString GetDifficulty()
{
    if(Difficulty==0)
        return QString("Tutorial");
    else if(Difficulty==1)
        return QString("Amatuer");
    else if(Difficulty==2)
        return QString("Explorer");
    else
        return QString("Challenger");
}
