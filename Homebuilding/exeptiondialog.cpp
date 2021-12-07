#include "exeptiondialog.h"
#include "ui_exeptiondialog.h"

Exeptiondialog::Exeptiondialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Exeptiondialog)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/house.png"));
    this->setWindowFlags(this->windowFlags().setFlag(Qt::WindowContextHelpButtonHint, false));
    this->setModal(true);
}

Exeptiondialog::~Exeptiondialog()
{
    delete ui;
}
