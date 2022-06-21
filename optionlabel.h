#ifndef OPTIONLABEL_H
#define OPTIONLABEL_H

#include <QWidget>
#include <QString>
#include <QLabel>
#include <QFocusEvent>
#include <QFont>
#include "constant.h"

extern int Width;
extern int Height;
extern bool isWindow;

class OptionLabel : public QLabel
{
    Q_OBJECT

public:
    OptionLabel(QWidget *parent);
    void Init();
    void focusInEvent(QFocusEvent * event);
    void focusOutEvent(QFocusEvent * event);
};

#endif // OPTIONLABEL_H
