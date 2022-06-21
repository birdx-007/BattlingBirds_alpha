#ifndef LOADINGTHREAD_H
#define LOADINGTHREAD_H

#include <QThread>

class MainWidget;

class LoadingThread : public QThread
{
    Q_OBJECT
public:
    LoadingThread();
    void BindWidget(MainWidget &w);

protected:
    void run();

private:
    MainWidget *wptr;
};

#endif // LOADINGTHREAD_H
