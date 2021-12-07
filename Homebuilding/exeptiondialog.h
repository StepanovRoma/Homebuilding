#ifndef EXEPTIONDIALOG_H
#define EXEPTIONDIALOG_H

#include <QDialog>

namespace Ui {
class Exeptiondialog;
}

class Exeptiondialog : public QDialog
{
    Q_OBJECT

public:
    explicit Exeptiondialog(QWidget *parent = 0);
    ~Exeptiondialog();

private:
    Ui::Exeptiondialog *ui;
};

#endif // EXEPTIONDIALOG_H
