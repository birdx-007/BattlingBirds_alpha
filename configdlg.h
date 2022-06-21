#ifndef CONFIGDLG_H
#define CONFIGDLG_H

#include <QDialog>

namespace Ui {
class ConfigDlg;
}

class ConfigDlg : public QDialog
{
    Q_OBJECT

public:
    explicit ConfigDlg(QWidget *parent = nullptr);
    ~ConfigDlg();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ConfigDlg *ui;
};

#endif // CONFIGDLG_H
