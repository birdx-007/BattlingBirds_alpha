#include "gameheaders/gameobj.h"
GameObj::GameObj()
{
    //总基类构造时不能确定材质，故setPos在各具体类中确定材质后执行
    this->isValid=true;
    this->birthcount=Count;
    this->guid=0;
}

void GameObj::setPos(qreal x, qreal y, qreal facex, qreal facey)
{
    this->X=x;
    this->Y=y;
    this->collibox.moveTo(this->X+this->texture.width()/2*Width/1920-colliX/2,this->Y+this->texture.height()/2*Width/1920-colliY/2);
    this->faceX=facex;
    this->faceY=facey;
}

void GameObj::Draw(QPainter *painter)
{
    painter->save();
    painter->translate(this->collibox.center());
    painter->rotate(this->faceXYtoAngle());
    painter->translate(-this->collibox.center());
    //painter->setOpacity(0.5);
    painter->drawPixmap(this->X,this->Y,this->texture.width()*Width/1920,this->texture.height()*Width/1920,this->texture);
    painter->restore();
}

void GameObj::setCollibox(qreal collix, qreal colliy)
{
    this->colliX=collix;
    this->colliY=colliy;
    this->collibox.setWidth(collix);
    this->collibox.setHeight(colliy);
}

void GameObj::setTexture(QString picdir)
{
    this->texture.load(picdir);
}

qreal GameObj::faceXYtoAngle()
{
    //返回角度而非弧度
    return qAtan2(this->faceY,this->faceX)/M_PI*180+90;
}

qreal GameObj::getMDistance(GameObj *a, GameObj *b)
{
    return abs(a->collibox.center().x()-b->collibox.center().x())+abs(a->collibox.center().y()-b->collibox.center().y());
}
