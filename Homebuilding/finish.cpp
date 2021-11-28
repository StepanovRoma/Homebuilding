#include "finish.h"
#include "ui_finish.h"

finish::finish(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::finish)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/house.png"));
    this->setWindowFlags(this->windowFlags().setFlag(Qt::WindowContextHelpButtonHint, false));
    this->setModal(true);

    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(close()));
}

finish::~finish()
{
    delete ui;
}

void finish::setFullPrice(int price) {
    ui->FullPrice->setText(QString::number(price) + "$");
}

QString finish::getFullPrice() {
    return ui->FullPrice->text();
}

void finish::on_pushButton_2_clicked()
{
    saveFile(ui->FullPrice->text());
    close();
}
