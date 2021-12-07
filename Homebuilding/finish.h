#ifndef FINISH_H
#define FINISH_H

#include <QDialog>

namespace Ui {
class finish;
}

class finish : public QDialog
{
    Q_OBJECT

public:
    explicit finish(QWidget *parent = 0);
    void setFullPrice(int price);
    QString getFullPrice();
    ~finish();

private slots:
    void on_pushButton_2_clicked();

signals:
    void saveFile(QString price);

private:
    Ui::finish *ui;
};

#endif // FINISH_H
