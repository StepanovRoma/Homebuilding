#ifndef INFO_H
#define INFO_H

#include <QDialog>

namespace Ui {
class Info;
}

class Info : public QDialog
{
    Q_OBJECT

public:
    explicit Info(QWidget *parent = 0);
    void setCurrentLableText(QString str, QString str_info);
    ~Info();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Info *ui;
};

#endif // INFO_H
