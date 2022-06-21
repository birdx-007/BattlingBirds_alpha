#include "loadingthread.h"
#include "mainwidget.h"
#include <QIcon>

LoadingThread::LoadingThread()
{

}

void LoadingThread::BindWidget(MainWidget &w)
{
    this->wptr=&w;
}

void LoadingThread::run()
{
    this->wptr->setWindowIcon(QIcon(":/myimages/res/icon.png"));
    this->wptr->optionChangeEffect.setSource(QUrl("qrc:/sfx/res/option_change.wav"));
    this->wptr->optionConfirmEffect.setSource(QUrl("qrc:/sfx/res/option_confirm.wav"));
    this->wptr->optionReturnEffect.setSource(QUrl("qrc:/sfx/res/option_return.wav"));
    sleep(1);
}
