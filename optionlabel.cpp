#include "optionlabel.h"

OptionLabel::OptionLabel(QWidget *parent)
    : QLabel(parent)
{
    //this->setFocusPolicy(Qt::StrongFocus);//futile, focuspolicy will be set in .ui later and cover this.
    this->Init();
}

void OptionLabel::Init()
{
    QFont font;
    font.setPointSize(10*Width/640);
    this->setFont(font);
    this->setAttribute(Qt::WA_TransparentForMouseEvents, true);//隐藏鼠标
    this->setStyleSheet(QString("border-image: url(:/myimages/res/mainmenu_button.png);\ncolor: rgb(0, 0, 0);"));
}

void OptionLabel::focusInEvent(QFocusEvent *event)
{
    QFont font;
    font.setPointSize(12*Width/640);
    this->setFont(font);
    this->setStyleSheet(QString("border-image: url(:/myimages/res/mainmenu_button.png);\ncolor: rgb(255, 255, 255);"));
    event->ignore();
}

void OptionLabel::focusOutEvent(QFocusEvent *event)
{
    QFont font;
    font.setPointSize(10*Width/640);
    this->setFont(font);
    this->setStyleSheet(QString("border-image: url(:/myimages/res/mainmenu_button.png);\ncolor: rgb(0, 0, 0);"));
    event->ignore();
}
