#include <QFontDatabase>
#include <QString>
#include "mainwidget.h"
#include "configdlg.h"
#include "constant.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    extern int Width;
    QApplication a(argc, argv);
    ConfigDlg d;
    MainWidget w;
    if(d.exec()==QDialog::Accepted)
    {
        //字体加载与设置
        int fontID=QFontDatabase::addApplicationFont(QString::fromLocal8Bit(":/myfont/res/HuaKangFangYuanW7-GB.ttc"));
        QString f=QFontDatabase::applicationFontFamilies (fontID).at(0);
        QFont font(f);
        font.setPointSizeF(30*Width/1920);
        a.setFont(font);
        //显示模式设置
        w.setDispalyMode();
        //将主菜单退出程序信号连接到槽
        QObject::connect(&w,SIGNAL(ExitSignal()),&a,SLOT(quit()));
        //主窗口显示
        w.show();
        //主窗口资源加载
        w.InitResources();
        return a.exec();
    }
    return 0;
}
