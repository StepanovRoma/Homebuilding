#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "info.h"
#include "finish.h"
#include "exeptiondialog.h"
#include "dialog.h"
#include <QFileDialog>
#include <QSignalMapper>
#include <QStringList>
#include <iostream>
#include <QDebug>
#include <QPdfWriter>
#include <QPainter>
#include <QFont>
#include <QProcess>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    QString material_info;
    ~MainWindow();

private slots:
    void on_comboModelName_currentIndexChanged(int index);

    void on_comboModelName_activated(int index);

    void on_helpButton_clicked();

    void on_nextStep_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_26_clicked();

    void on_pushButton_30_clicked();

    void on_pushButton_34_clicked();

    void on_pushButton_38_clicked();

    void on_pushButton_42_clicked();

    void on_pushButton_46_clicked();

    void showInfo(int index);

    void showMaterial(int index);

    void setImageLable(int index);

    void on_pushButton_31_clicked();

    void on_pushButton_6_clicked();

    void on_action_triggered();

public slots:
    void setMaterial(QString material, int index);
    void savePlane(QString price);

private:
    Ui::MainWindow *ui;
    void ShowAllTabs();
    void HideAllTabs();
    void getPlan(QString FileName);
    void clearAllElements();
    Info infoDialog;
    finish finishDialog;
    Dialog dialogDialog;
    Exeptiondialog exceptionDialog;
};

#endif // MAINWINDOW_H
