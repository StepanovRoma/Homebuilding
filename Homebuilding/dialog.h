#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QSqlQueryModel>
#include <QFileDialog>
#include <QFile>
#include <QDate>
#include <QIODevice>
#include <QSqlError>
#include <QTextCodec>
#include <QDataStream>
#include "info.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    void setCurrentInfo(QString LableInfo);
    ~Dialog();
    void setStepInfo(int step);
    int getStepInfo();
    void setMaterialsLables(int step);
    QString MaterialInfo;
    QString getMaterials(int step);
    int getFullPrice(QString TempMaterial);
    void clickedReload();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_pushButton_5_clicked();

signals:
    void materialChanged(QString material, int index);

private:
    Ui::Dialog *ui;
    QSqlDatabase db;
    QSqlQuery *query;
    QSqlTableModel *model;
    int row ;
    Info InfoDialog;
    int StepInfo;
    void fillComboBox();
    void deleteComboBoxInfo();
};

#endif // DIALOG_H
