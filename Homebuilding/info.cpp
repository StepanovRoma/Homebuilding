#include "info.h"
#include "ui_info.h"

Info::Info(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Info)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/house.png"));
    this->setWindowFlags(this->windowFlags().setFlag(Qt::WindowContextHelpButtonHint, false));
    this->setModal(true);
}

Info::~Info()
{
    delete ui;
}

void Info::on_pushButton_clicked()
{
    this->close();
}

void Info::setCurrentLableText(QString str, QString str_info) {
    ui->label->setText(str);
    ui->label_2->setText(str_info);
}
