#include "gameheaders/others.h"
TitlePlayer::TitlePlayer(QObject *parent)
{
    Q_UNUSED(parent);
    this->Init();
}

void TitlePlayer::Init()
{
    this->SetTitle(0,0);
    this->SetClearTitle(0,0);
}

void TitlePlayer::SetTitle(int start, int end)
{
    this->Title.load(QString(":/myimages/res/title_level%1.png").arg(Level));
    this->titlestartcount=start;
    this->titleendcount=end;
}

void TitlePlayer::SetClearTitle(int start, int end)
{
    this->ClearTitle.load(QString(":/myimages/res/title_clear.png"));
    this->clearstartcount=start;
    this->clearendcount=end;
}

void TitlePlayer::Draw(QPainter *painter)
{
    painter->save();
    qreal value1,value2;
    if(Count>=this->titlestartcount&&Count<=this->titleendcount)
    {
        value1=-(16.0/(this->titleendcount-this->titlestartcount)/(this->titleendcount-this->titlestartcount))*(Count-this->titlestartcount)*(Count-this->titlestartcount-0.5*(this->titleendcount-this->titlestartcount));
        value2=-(16.0/(this->titleendcount-this->titlestartcount)/(this->titleendcount-this->titlestartcount))*(Count-this->titleendcount)*(Count-this->titlestartcount-0.5*(this->titleendcount-this->titlestartcount));
        painter->setOpacity(Count<this->titlestartcount+0.25*(this->titleendcount-this->titlestartcount)?value1:(Count<this->titlestartcount+0.75*(this->titleendcount-this->titlestartcount)?1.0:value2));
        painter->drawPixmap(147*Width/1920,200*Width/1920,900*Width/1920,281.25*Width/1920,this->Title);
        painter->setOpacity(1.0);
    }
    if(Count>=this->clearstartcount&&Count<=this->clearendcount)
    {
        value1=-(16.0/(this->clearendcount-this->clearstartcount)/(this->clearendcount-this->clearstartcount))*(Count-this->clearstartcount)*(Count-this->clearstartcount-0.5*(this->clearendcount-this->clearstartcount));
        value2=-(16.0/(this->clearendcount-this->clearstartcount)/(this->clearendcount-this->clearstartcount))*(Count-this->clearendcount)*(Count-this->clearstartcount-0.5*(this->clearendcount-this->clearstartcount));
        painter->setOpacity(Count<this->clearstartcount+0.25*(this->clearendcount-this->clearstartcount)?value1:(Count<this->clearstartcount+0.75*(this->clearendcount-this->clearstartcount)?1.0:value2));
        painter->drawPixmap(147*Width/1920,200*Width/1920,900*Width/1920,281.25*Width/1920,this->ClearTitle);
        painter->setOpacity(1.0);
    }
    painter->restore();
}

ScoreManager::ScoreManager(QObject *parent)
{
    Q_UNUSED(parent);
    this->Init();
}

void ScoreManager::Init()
{
    this->maxscoreincrement=1000;
    this->targetscore=0;this->targethighscore=0;
    this->score=0;
    this->highscore=0;
    this->oldhighscore=0;
    QFile fread("playerdata.txt");
    if(!fread.open(QIODevice::ReadOnly|QIODevice::Text))
        return;
    QTextStream scorein(&fread);
    scorein>>this->targethighscore;
    fread.close();
    this->highscore=this->targethighscore;
    this->oldhighscore=this->targethighscore;
}

void ScoreManager::AddScore(int value)
{
    this->targetscore+=value;
    this->targethighscore=std::max(this->targetscore,this->targethighscore);
}

void ScoreManager::UpdateScores()
{
    if(this->targetscore-this->score<this->maxscoreincrement)
    {
        this->score=this->targetscore;
    }
    else
    {
        this->score+=this->maxscoreincrement;
    }
    if(this->targethighscore-this->highscore<this->maxscoreincrement)
    {
        this->highscore=this->targethighscore;
    }
    else
    {
        this->highscore+=this->maxscoreincrement;
    }
}

void ScoreManager::UpdateHighScore()
{
    if(this->highscore>this->oldhighscore)//需要更新文件
    {
        QFile fwrite("playerdata.txt");
        if(!fwrite.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Truncate))
            return;
        QTextStream scoreout(&fwrite);
        scoreout<<this->highscore;
        fwrite.close();
    }
}
