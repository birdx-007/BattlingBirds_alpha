#ifndef MOVEVECTOR_H
#define MOVEVECTOR_H

#include <QtMath>
#include <QString>
#include "gameheaders/gameobj.h"
class MoveVector
{
public:
    MoveVector();
    void init();
    void toZeroVector();//置零
    void GenerateVector();//（处理数据时）生成向量
    void AddVx(qreal deltax);
    void AddVy(qreal deltay);
    bool MoveKeysPressed[5];//左上右下shift
    qreal Vx;
    qreal Vy;
};

#endif // MOVEVECTOR_H
