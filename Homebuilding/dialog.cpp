#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/house.png"));
    this->setWindowFlags(this->windowFlags().setFlag(Qt::WindowContextHelpButtonHint, false));
    this->setModal(true);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./testDB.db");
    if (db.open()) {
        qDebug() << "Open";
    } else {
        qDebug() << "No open";
    }
    query = new QSqlQuery(db);
    query->exec("CREATE TABLE Materials(Name TEXT, Step INT, AvgPrice INT, Photo TEXT, Specifications TEXT);");
    model = new QSqlTableModel(this, db);
    model->setTable("Materials");
    model->select();

    ui->tableView->setModel(model);
    fillComboBox();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::setCurrentInfo(QString LableInfo) {
    ui->label->setText(LableInfo);
}

void Dialog::on_pushButton_3_clicked()
{
    model->insertRow(model->rowCount());
}

void Dialog::on_pushButton_4_clicked()
{
    QMessageBox::StandardButton reply;
      reply = QMessageBox::question(this, "Удалить материал", "Вы действительно хотите удалить материал?",
                                    QMessageBox::Yes|QMessageBox::No);
      if (reply == QMessageBox::Yes) {
        model->removeRow(row);
      }
    //model->removeRow(row);
}

void Dialog::on_tableView_clicked(const QModelIndex &index)
{
    row = index.row();
}

void Dialog::on_pushButton_clicked()
{
    materialChanged(ui->comboBox->currentText(), StepInfo);
    close();
}

void Dialog::on_pushButton_2_clicked()
{
    close();
}

void Dialog::setStepInfo(int step) {
    StepInfo = step;
}

int Dialog::getStepInfo() {
    return StepInfo;
}

void Dialog::on_comboBox_currentIndexChanged(const QString &arg1)
{
    if (arg1 != "Выбирите материал") {
    ui->pushButton->setEnabled(true);
    QString sql_query = QString("SELECT Specifications, Photo FROM Materials WHERE Name='%1'").arg(arg1);
    query->exec(sql_query);
    //qDebug() << sql_query << query->isSelect();
    while (query->next()) {
        ui->textEdit->setText(query->value(0).toString());
        ui->MaterialPhoto->setPixmap(QPixmap::fromImage(QImage (query->value(1).toString())));
    }

    } else {
        ui->pushButton->setEnabled(false);
        ui->textEdit->clear();
        ui->MaterialPhoto->clear();
    }
}

void Dialog::fillComboBox() {
    ui->comboBox->addItem("Выбирите материал");
    query->exec("SELECT Name FROM Materials");
    while (query->next()) {
        if (ui->comboBox->findText(query->value(0).toString()) == -1) {
            ui->comboBox->addItem(query->value(0).toString());
        }
    }
}

void Dialog::deleteComboBoxInfo() {
    ui->comboBox->clear();
}

void Dialog::on_pushButton_5_clicked()
{
    model->sort(1, Qt::AscendingOrder);
    deleteComboBoxInfo();
    fillComboBox();
}

void Dialog::setMaterialsLables(int step) {
    QString sql_query = QString("SELECT Name FROM Materials WHERE Step=%1").arg(step);
    query->exec(sql_query);
    //qDebug() << sql_query;
    bool flag = true;
    while (query->next()) {
        if (flag) {
            ui->label_3->setText(query->value(0).toString());
            flag = false;
        } else {
            ui->label_4->setText(query->value(0).toString());
        }
    }
}

QString Dialog::getMaterials(int step) {
    QString sql_query = QString("SELECT Name FROM Materials WHERE Step=%1").arg(step);
    query->exec(sql_query);
    while (query->next()) {
        return query->value(0).toString();
        }
}

int Dialog::getFullPrice(QString TempMaterial) {
    QString sql_query = QString("SELECT AvgPrice FROM Materials WHERE Name='%1'").arg(TempMaterial);
    query->exec(sql_query);
    while (query->next()) {
        return query->value(0).toInt();
        }
}


void Dialog::clickedReload() {
    on_pushButton_5_clicked();
}
