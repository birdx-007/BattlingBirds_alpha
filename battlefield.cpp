#include "battlefield.h"

Battlefield::Battlefield(QWidget *parent): QWidget(parent)
{
}

void Battlefield::Init(MainWidget *p, int herochoice)
{
    this->parent=p;
    //初始化计时器
    Count=0;
    this->timer=new QTimer(this);
    this->timer->setInterval(15);
    connect(this->timer,&QTimer::timeout,[=]()
    {
        qreal dx,dy;
        Count++;
        UpdateData(dx,dy);//处理键盘事件及数据、更新元素位置
        update();//绘图
        //this->parent->update();
        /*
        this->parent->setWindowTitle(QString("counter=%1 bullets=%2 dlg:%3 zakos:%4 idx:%5 bgspeed:%6 level:%7")
                             .arg(Count)
                             .arg(this->managerDep.bulletmanager.enemybullets.size()+this->managerDep.bulletmanager.herobullets.size())
                             .arg(this->managerDep.dialogplayer.speaktimes)
                             .arg(this->managerDep.enemymanager.zakos.size())
                             .arg(Idx)
                             .arg(this->managerDep.background.mainbgspeed)
                             .arg(Level)
                             );*/
    });
    //自机初始化
    this->hero.init(herochoice);

    this->managerDep.InitDep(&this->hero);
}

void Battlefield::UpdateData(qreal&dx,qreal&dy)
{
    if(this->hero.isValid)
    {
        this->hero.vector.toZeroVector();
        this->hero.vector.GenerateVector();
        int isShiftPressed=this->hero.vector.MoveKeysPressed[4]?1:0;
        this->hero.changePattern(isShiftPressed+1);
        qreal deltax=(this->hero.vector.Vx*this->hero.speed)*Width/1920;
        qreal deltay=(this->hero.vector.Vy*this->hero.speed)*Width/1920;
        dx=deltax,dy=deltay;
        this->hero.setPos(this->hero.X+deltax,this->hero.Y+deltay,this->hero.vector.Vx/4,-1);
        this->managerDep.ManageSpell();
        this->managerDep.ManageHeroGhost();
    }
    else
    {
        this->managerDep.ManageHeroDeath();
    }

    this->managerDep.ManageZakosMoving();
    this->managerDep.ManageBossesMoving();
    this->managerDep.ManageBackGroundMoving();

    this->managerDep.ManageEnemyBulletsMoving();
    this->managerDep.ManageHeroBulletsMoving();
    this->managerDep.ManagePropMoving();
    this->managerDep.ManageCollisions();
    this->managerDep.GenerateLevel();

    if(this->hero.isValid&&this->hero.isShooting&&Count%5==0&&!this->managerDep.dialogplayer.isOnDisplay)
    {
        this->managerDep.HeroShootOnce();
    }

    this->managerDep.DestoryInvalidObjects();
    this->managerDep.ManageScore();
    this->managerDep.ManageDialog();

    this->parent->UpdateData();
}

void Battlefield::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);

    this->managerDep.background.Draw(&painter);

    for(auto z:this->managerDep.enemymanager.zakos)
    {
        Zako zako=z.second;
        /*
        painter.save();
        painter.translate(zako.collibox.center());
        painter.rotate(zako.faceXYtoAngle());
        painter.translate(-zako.collibox.center());
        painter.drawPixmap(zako.X,zako.Y,zako.texture.width()*Width/1920,zako.texture.height()*Width/1920,zako.texture);
        painter.restore();*/
        zako.Draw(&painter);
    }

    for(auto b:this->managerDep.enemymanager.bosses)
    {
        Boss boss=b.second;
        /*
        painter.save();
        painter.translate(zako.collibox.center());
        painter.rotate(zako.faceXYtoAngle());
        painter.translate(-zako.collibox.center());
        painter.drawPixmap(zako.X,zako.Y,zako.texture.width()*Width/1920,zako.texture.height()*Width/1920,zako.texture);
        painter.restore();*/
        boss.Draw(&painter);

        painter.setBrush(QColor(Qt::red));
        painter.setPen(QColor(Qt::red));
        qreal herocenterx=this->hero.collibox.center().x();
        qreal leftx=boss.collibox.left();
        qreal rightx=boss.collibox.right();
        if(herocenterx>=leftx&&herocenterx<=rightx)
        {
            painter.setOpacity(0.2);
        }
        painter.drawRect(leftx,1400*Width/1920,rightx-leftx,10*Width/1920);
        painter.setOpacity(1.0);
    }

    for(auto power:this->managerDep.propmanager.powers)
    {
        power.Draw(&painter);
    }
    for(auto& score:this->managerDep.propmanager.scores)
    {
        score.Draw(&painter);
    }

    for(auto& herobullet:this->managerDep.bulletmanager.herobullets)
    {
        /*
        painter.save();
        painter.translate(herobullet.collibox.center());
        painter.rotate(herobullet.faceXYtoAngle());
        painter.translate(-herobullet.collibox.center());
        painter.drawPixmap(herobullet.X,herobullet.Y,herobullet.texture.width()*Width/1920,herobullet.texture.height()*Width/1920,herobullet.texture);
        painter.restore();*/
        herobullet.Draw(&painter);
    }

    if(this->hero.isValid){
        /*
        painter.save();
        painter.translate(hero.collibox.center());
        painter.rotate(hero.faceXYtoAngle());
        painter.translate(-hero.collibox.center());
        //this->hero.texture.fill(Qt::transparent);
        //painter.setCompositionMode(QPainter::CompositionMode_Source);
        painter.drawPixmap(hero.X,hero.Y,this->hero.texture.width()*Width/1920,this->hero.texture.width()*Width/1920,hero.texture);
        //painter.setCompositionMode(QPainter::CompositionMode_DestinationIn);
        //painter.fillRect(hero.X,hero.Y,this->hero.texture.width()*Width/1920,this->hero.texture.width()*Width/1920,QColor(0,0,0,100));
        painter.restore();*/
        this->hero.Draw(&painter);

        int isShiftPressed=this->hero.vector.MoveKeysPressed[4]?1:0;
        if(isShiftPressed==1)
        {
            painter.setBrush(QBrush(Qt::white,Qt::SolidPattern));
            painter.setPen(QColor(Qt::red));
            painter.drawRect(this->hero.collibox);
        }
    }

    for(EnemyBullet enemybullet:this->managerDep.bulletmanager.enemybullets)
    {
        /*
        painter.save();
        painter.translate(enemybullet.collibox.center());
        painter.rotate(enemybullet.faceXYtoAngle());
        painter.translate(-enemybullet.collibox.center());
        painter.drawPixmap(enemybullet.X,enemybullet.Y,enemybullet.texture.width()*Width/1920,enemybullet.texture.height()*Width/1920,enemybullet.texture);
        painter.restore();*/
        enemybullet.Draw(&painter);

        if(Difficulty==0)
        {
            painter.setBrush(QBrush(Qt::white,Qt::SolidPattern));
            painter.setPen(QColor(Qt::red));
            painter.drawRect(enemybullet.collibox);
        }
    }

    if(this->managerDep.dialogplayer.isOnDisplay)
    {
        this->managerDep.dialogplayer.Draw(&painter);
    }

    this->managerDep.titleplayer.Draw(&painter);
}

