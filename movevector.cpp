#include "movevector.h"

MoveVector::MoveVector()
{
    init();
}

void MoveVector::init()
{
    for(int i=0;i<5;i++)
    {
        this->MoveKeysPressed[i]=false;
    }
    this->toZeroVector();
}

void MoveVector::toZeroVector()
{
    this->Vx=0;
    this->Vy=0;
}

void MoveVector::GenerateVector()
{
    if(this->MoveKeysPressed[0])//left
    {
        this->AddVx(-1.0);
    }
    if(this->MoveKeysPressed[1])//up
    {
        this->AddVy(-1.0);
    }
    if(this->MoveKeysPressed[2])//down
    {
        this->AddVy(1.0);
    }
    if(this->MoveKeysPressed[3])//right
    {
        this->AddVx(1.0);
    }
    qreal length=qSqrt(this->Vx*this->Vx+this->Vy*this->Vy);
    if(length!=qreal(0.0))
    {
        this->Vx=this->Vx/length;
        this->Vy=this->Vy/length;
    }
}

void MoveVector::AddVx(qreal deltax)
{
    this->Vx+=deltax;
}

void MoveVector::AddVy(qreal deltay)
{
    this->Vy+=deltay;
}
