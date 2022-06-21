#include <QIcon>
#include "configdlg.h"
#include "ui_configdlg.h"
#include "constant.h"

ConfigDlg::ConfigDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConfigDlg)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint);
    setWindowIcon(QIcon(":/myimages/res/icon.png"));
}

ConfigDlg::~ConfigDlg()
{
    delete ui;
}


void ConfigDlg::on_pushButton_clicked()
{
    extern int Width;
    extern int Height;
    if(this->ui->radioButton_2->isChecked())
    {
        Width=640;
        Height=480;
    }
    if(this->ui->radioButton_3->isChecked())
    {
        Width=960;
        Height=720;
    }
    if(this->ui->radioButton_4->isChecked())
    {
        Width=1280;
        Height=960;
    }
    if(this->ui->radioButton_5->isChecked())
    {
        Width=1920;
        Height=1440;
    }
    accept();
}
