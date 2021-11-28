#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/house.png"));
    HideAllTabs();
    ui->nextStep->setEnabled(false);

    QSignalMapper* signalMapperInfo = new QSignalMapper (this);
    connect(ui->pushButton_6, SIGNAL(clicked(bool)), signalMapperInfo, SLOT(map()));
    connect(ui->pushButton_16, SIGNAL(clicked(bool)), signalMapperInfo, SLOT(map()));
    connect(ui->pushButton_20, SIGNAL(clicked(bool)), signalMapperInfo, SLOT(map()));
    connect(ui->pushButton_24, SIGNAL(clicked(bool)), signalMapperInfo, SLOT(map()));
    connect(ui->pushButton_28, SIGNAL(clicked(bool)), signalMapperInfo, SLOT(map()));
    connect(ui->pushButton_32, SIGNAL(clicked(bool)), signalMapperInfo, SLOT(map()));
    connect(ui->pushButton_36, SIGNAL(clicked(bool)), signalMapperInfo, SLOT(map()));
    connect(ui->pushButton_40, SIGNAL(clicked(bool)), signalMapperInfo, SLOT(map()));
    connect(ui->pushButton_44, SIGNAL(clicked(bool)), signalMapperInfo, SLOT(map()));
    connect(ui->pushButton_48, SIGNAL(clicked(bool)), signalMapperInfo, SLOT(map()));

    signalMapperInfo -> setMapping (ui->pushButton_6, 1) ;
    signalMapperInfo -> setMapping (ui->pushButton_16, 2) ;
    signalMapperInfo -> setMapping (ui->pushButton_20, 3) ;
    signalMapperInfo -> setMapping (ui->pushButton_24, 4) ;
    signalMapperInfo -> setMapping (ui->pushButton_28, 5) ;
    signalMapperInfo -> setMapping (ui->pushButton_32, 6) ;
    signalMapperInfo -> setMapping (ui->pushButton_36, 7) ;
    signalMapperInfo -> setMapping (ui->pushButton_40, 8) ;
    signalMapperInfo -> setMapping (ui->pushButton_44, 9) ;
    signalMapperInfo -> setMapping (ui->pushButton_48, 10) ;

    connect (signalMapperInfo, SIGNAL(mapped(int)), this, SLOT(showInfo(int))) ;

    QSignalMapper* signalMapperMaterial = new QSignalMapper (this);
    connect(ui->pushButton_4, SIGNAL(clicked(bool)), signalMapperMaterial, SLOT(map()));
    connect(ui->pushButton_13, SIGNAL(clicked(bool)), signalMapperMaterial, SLOT(map()));
    connect(ui->pushButton_17, SIGNAL(clicked(bool)), signalMapperMaterial, SLOT(map()));
    connect(ui->pushButton_21, SIGNAL(clicked(bool)), signalMapperMaterial, SLOT(map()));
    connect(ui->pushButton_25, SIGNAL(clicked(bool)), signalMapperMaterial, SLOT(map()));
    connect(ui->pushButton_29, SIGNAL(clicked(bool)), signalMapperMaterial, SLOT(map()));
    connect(ui->pushButton_33, SIGNAL(clicked(bool)), signalMapperMaterial, SLOT(map()));
    connect(ui->pushButton_37, SIGNAL(clicked(bool)), signalMapperMaterial, SLOT(map()));
    connect(ui->pushButton_41, SIGNAL(clicked(bool)), signalMapperMaterial, SLOT(map()));
    connect(ui->pushButton_45, SIGNAL(clicked(bool)), signalMapperMaterial, SLOT(map()));

    signalMapperMaterial -> setMapping (ui->pushButton_4, 1) ;
    signalMapperMaterial -> setMapping (ui->pushButton_13, 2) ;
    signalMapperMaterial -> setMapping (ui->pushButton_17, 3) ;
    signalMapperMaterial -> setMapping (ui->pushButton_21, 4) ;
    signalMapperMaterial -> setMapping (ui->pushButton_25, 5) ;
    signalMapperMaterial -> setMapping (ui->pushButton_29, 6) ;
    signalMapperMaterial -> setMapping (ui->pushButton_33, 7) ;
    signalMapperMaterial -> setMapping (ui->pushButton_37, 8) ;
    signalMapperMaterial -> setMapping (ui->pushButton_41, 9) ;
    signalMapperMaterial -> setMapping (ui->pushButton_45, 10) ;

    connect (signalMapperMaterial, SIGNAL(mapped(int)), this, SLOT(showMaterial(int))) ;

    QSignalMapper* signalMapper = new QSignalMapper (this);
    connect(ui->pushButton_3, SIGNAL(clicked(bool)), signalMapper, SLOT(map()));
    connect(ui->pushButton_15, SIGNAL(clicked(bool)), signalMapper, SLOT(map()));
    connect(ui->pushButton_19, SIGNAL(clicked(bool)), signalMapper, SLOT(map()));
    connect(ui->pushButton_23, SIGNAL(clicked(bool)), signalMapper, SLOT(map()));
    connect(ui->pushButton_27, SIGNAL(clicked(bool)), signalMapper, SLOT(map()));
    connect(ui->pushButton_31, SIGNAL(clicked(bool)), signalMapper, SLOT(map()));
    connect(ui->pushButton_35, SIGNAL(clicked(bool)), signalMapper, SLOT(map()));
    connect(ui->pushButton_39, SIGNAL(clicked(bool)), signalMapper, SLOT(map()));
    connect(ui->pushButton_43, SIGNAL(clicked(bool)), signalMapper, SLOT(map()));
    connect(ui->pushButton_47, SIGNAL(clicked(bool)), signalMapper, SLOT(map()));

    signalMapper -> setMapping (ui->pushButton_3, 1) ;
    signalMapper -> setMapping (ui->pushButton_15, 2) ;
    signalMapper -> setMapping (ui->pushButton_19, 3) ;
    signalMapper -> setMapping (ui->pushButton_23, 4) ;
    signalMapper -> setMapping (ui->pushButton_27, 5) ;
    signalMapper -> setMapping (ui->pushButton_31, 6) ;
    signalMapper -> setMapping (ui->pushButton_35, 7) ;
    signalMapper -> setMapping (ui->pushButton_39, 8) ;
    signalMapper -> setMapping (ui->pushButton_43, 9) ;
    signalMapper -> setMapping (ui->pushButton_47, 10) ;

    connect (signalMapper, SIGNAL(mapped(int)), this, SLOT(setImageLable(int))) ;

    connect(ui->comboModelName, SIGNAL(currentIndexChanged(int)), this, SLOT(on_comboModelName_currentIndexChanged(int)));

    connect(&dialogDialog, SIGNAL(materialChanged(QString,int)), this, SLOT(setMaterial(QString,int)));

    connect(&finishDialog, SIGNAL(saveFile(QString)), this, SLOT(savePlane(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ShowAllTabs() {
    for (size_t i = 1; i < 11; i++) {
        ui->tabWidget->setTabEnabled(i, true);
    }
    ui->nextStep->setEnabled(true);
}

void MainWindow::HideAllTabs() {
    for (size_t i = 1; i < 11; i++) {
        ui->tabWidget->setTabEnabled(i, false);
    }
    ui->nextStep->setEnabled(false);
}

void MainWindow::on_comboModelName_currentIndexChanged(int index)
{
    switch(index) {
    case 0:
        HideAllTabs();
        clearAllElements();
        break;
    case 1:
        clearAllElements();
        //getPlan("D:/Code/QT/Homebuilding/1.txt");
        getPlan(":/1.txt");
        ShowAllTabs();
        //first plan
        break;
    case 2:
        clearAllElements();
        //getPlan("D:/Code/QT/Homebuilding/2.txt");
        getPlan(":/2.txt");
        ShowAllTabs();
        //second plan
        break;
    case 3:
        clearAllElements();
        //getPlan("D:/Code/QT/Homebuilding/3.txt");
        getPlan(":/3.txt");
        ShowAllTabs();
        //third plan
        break;
    case 4:
        clearAllElements();
        //getPlan("D:/Code/QT/Homebuilding/4.txt");
        getPlan(":/4.txt");
        ShowAllTabs();
        //forth plan
        break;
    case 5:
        clearAllElements();
        //getPlan("D:/Code/QT/Homebuilding/5.txt");
        getPlan(":/5.txt");
        ShowAllTabs();
        //fifth plan
        break;
    };
}

void MainWindow::on_comboModelName_activated(int index)
{
    if (index == index) {
        return;
    };
}

void MainWindow::on_helpButton_clicked()
{
    QString str, str_info;
    str = "Выбора плана\nдачного домика";
    str_info = "Выбирите план, после чего станут\nдоступны шаги выбранного плана!";
    infoDialog.setCurrentLableText(str, str_info);
    infoDialog.show();
}

void MainWindow::on_nextStep_clicked()
{
    ui->tabWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->tabWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_14_clicked()
{
    ui->tabWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_18_clicked()
{
    ui->tabWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_22_clicked()
{
    ui->tabWidget->setCurrentIndex(5);
}

void MainWindow::on_pushButton_26_clicked()
{
    ui->tabWidget->setCurrentIndex(6);
}

void MainWindow::on_pushButton_30_clicked()
{
    ui->tabWidget->setCurrentIndex(7);
}

void MainWindow::on_pushButton_34_clicked()
{
    ui->tabWidget->setCurrentIndex(8);
}

void MainWindow::on_pushButton_38_clicked()
{
    ui->tabWidget->setCurrentIndex(9);
}

void MainWindow::on_pushButton_42_clicked()
{
    ui->tabWidget->setCurrentIndex(10);
}

void MainWindow::on_pushButton_46_clicked()
{
    int price = 0;
    price+=dialogDialog.getFullPrice(ui->textEdit_2->toPlainText());
    price+=dialogDialog.getFullPrice(ui->textEdit_5->toPlainText());
    price+=dialogDialog.getFullPrice(ui->textEdit_7->toPlainText());
    price+=dialogDialog.getFullPrice(ui->textEdit_9->toPlainText());
    price+=dialogDialog.getFullPrice(ui->textEdit_11->toPlainText());
    price+=dialogDialog.getFullPrice(ui->textEdit_13->toPlainText());
    price+=dialogDialog.getFullPrice(ui->textEdit_15->toPlainText());
    price+=dialogDialog.getFullPrice(ui->textEdit_17->toPlainText());
    price+=dialogDialog.getFullPrice(ui->textEdit_19->toPlainText());
    price+=dialogDialog.getFullPrice(ui->textEdit_21->toPlainText());

    finishDialog.setFullPrice(price);
    finishDialog.show();
}

void MainWindow::showInfo(int index) {
    QString str, str_info;
    str_info = "Нажав на кнопку 'выбрать изображение' вы можете прикрепить свое изображение.\n"
               "Нажав на кнопку 'выбрать материалы' вы можете выбрать нужные вам материалы.\n"
               "Нажав на поле 'сделано' вы можете помететь сделаный этап.\n"
               "Вы можете редактировать готовый шаг нажав на текстовое поле.\n"
               "Если вы выполнили этот шаг строительства нажмите на кнопку 'следующий этап'.";
    switch (index) {
    case 1:
        str = "Первый шаг";
        infoDialog.setCurrentLableText(str, str_info);
        infoDialog.show();
        break;
    case 2:
        str = "Второй шаг";
        infoDialog.setCurrentLableText(str, str_info);
        infoDialog.show();
        break;
    case 3:
        str = "Третий шаг";
        infoDialog.setCurrentLableText(str, str_info);
        infoDialog.show();
        break;
    case 4:
        str = "Четвертый шаг";
        infoDialog.setCurrentLableText(str, str_info);
        infoDialog.show();
        break;
    case 5:
        str = "Пятый шаг";
        infoDialog.setCurrentLableText(str, str_info);
        infoDialog.show();
        break;
    case 6:
        str = "Шестой шаг";
        infoDialog.setCurrentLableText(str, str_info);
        infoDialog.show();
        break;
    case 7:
        str = "Седьмой шаг";
        infoDialog.setCurrentLableText(str, str_info);
        infoDialog.show();
        break;
    case 8:
        str = "Восьмой шаг";
        infoDialog.setCurrentLableText(str, str_info);
        infoDialog.show();
        break;
    case 9:
        str = "Девятый шаг";
        infoDialog.setCurrentLableText(str, str_info);
        infoDialog.show();
        break;
    case 10:
        str = "Десятый шаг";
        str_info = "Нажав на кнопку 'выбрать изображение' вы можете прикрепить свое изображение.\n"
                   "Нажав на кнопку 'выбрать материалы' вы можете выбрать нужные вам материалы.\n"
                   "Нажав на поле 'сделано' вы можете помететь сделаный этап.\n"
                   "Вы можете редактировать готовый шаг нажав на текстовое поле.\n"
                   "Если вы закончили с планом нажмите на кнопку 'завершить план'\n"
                   "После чего ваш план, цена материалов и их количество сохранятся в 2 файла.";
        infoDialog.setCurrentLableText(str, str_info);
        infoDialog.show();
        break;
    }
}

void MainWindow::showMaterial(int index) {
    dialogDialog.clickedReload();
    switch (index) {
    case 1:
        dialogDialog.setMaterialsLables(index);
        dialogDialog.setStepInfo(index);
        dialogDialog.setCurrentInfo(ui->label_23->text());
        dialogDialog.show();
        break;
    case 2:
        dialogDialog.setMaterialsLables(index);
        dialogDialog.setStepInfo(index);
        dialogDialog.setCurrentInfo(ui->label_22->text());
        dialogDialog.show();
        break;
    case 3:
        dialogDialog.setMaterialsLables(index);
        dialogDialog.setStepInfo(index);
        dialogDialog.setCurrentInfo(ui->label_21->text());
        dialogDialog.show();
        break;
    case 4:
        dialogDialog.setMaterialsLables(index);
        dialogDialog.setStepInfo(index);
        dialogDialog.setCurrentInfo(ui->label_20->text());
        dialogDialog.show();
        break;
    case 5:
        dialogDialog.setMaterialsLables(index);
        dialogDialog.setStepInfo(index);
        dialogDialog.setCurrentInfo(ui->label_19->text());
        dialogDialog.show();
        break;
    case 6:
        dialogDialog.setMaterialsLables(index);
        dialogDialog.setStepInfo(index);
        dialogDialog.setCurrentInfo(ui->label_18->text());
        dialogDialog.show();
        break;
    case 7:
        dialogDialog.setMaterialsLables(index);
        dialogDialog.setStepInfo(index);
        dialogDialog.setCurrentInfo(ui->label_17->text());
        dialogDialog.show();
        break;
    case 8:
        dialogDialog.setMaterialsLables(index);
        dialogDialog.setStepInfo(index);
        dialogDialog.setCurrentInfo(ui->label_16->text());
        dialogDialog.show();
        break;
    case 9:
        dialogDialog.setMaterialsLables(index);
        dialogDialog.setStepInfo(index);
        dialogDialog.setCurrentInfo(ui->label_15->text());
        dialogDialog.show();
        break;
    case 10:
        dialogDialog.setMaterialsLables(index);
        dialogDialog.setStepInfo(index);
        dialogDialog.setCurrentInfo(ui->label_14->text());
        dialogDialog.show();
        break;
    }
}

void MainWindow::setImageLable(int index) {
    QString filename = QFileDialog::getOpenFileName(this, "Выберите изображение", QDir::currentPath(), "*.png *.jpg");
    if (filename != "") {
        switch (index) {
        case 1: {
            QPixmap image;
            image = image.fromImage(QImage (filename));
            ui->label_2->setPixmap(image);
            ui->label_2->setScaledContents(true);
            break;
        }
        case 2:
            ui->label_5->setPixmap(QPixmap::fromImage(QImage (filename)));
            ui->label_5->setScaledContents(true);
            break;
        case 3:
            ui->label_6->setPixmap(QPixmap::fromImage(QImage (filename)));
            ui->label_6->setScaledContents(true);
            break;
        case 4:
            ui->label_7->setPixmap(QPixmap::fromImage(QImage (filename)));
            ui->label_7->setScaledContents(true);
            break;
        case 5:
            ui->label_8->setPixmap(QPixmap::fromImage(QImage (filename)));
            ui->label_8->setScaledContents(true);
            break;
        case 6:
            ui->label_9->setPixmap(QPixmap::fromImage(QImage (filename)));
            ui->label_9->setScaledContents(true);
            break;
        case 7:
            ui->label_10->setPixmap(QPixmap::fromImage(QImage (filename)));
            ui->label_10->setScaledContents(true);
            break;
        case 8:
            ui->label_11->setPixmap(QPixmap::fromImage(QImage (filename)));
            ui->label_11->setScaledContents(true);
            break;
        case 9:
            ui->label_12->setPixmap(QPixmap::fromImage(QImage (filename)));
            ui->label_12->setScaledContents(true);
            break;
        case 10:
            ui->label_13->setPixmap(QPixmap::fromImage(QImage (filename)));
            ui->label_13->setScaledContents(true);
            break;
        }
    }
}


void MainWindow::getPlan(QString FileName) {
    QFile file(FileName);
    QStringList strList;
    int i = 0;
    /*Считываем исходный файл в контейнер*/
    if ((file.exists())&&(file.open(QIODevice::ReadOnly)))
    {
        while(!file.atEnd())
        {
        strList << file.readLine();
        i++;
        }
        file.close();
    }
    strList[0].resize(strList[0].size() - 2);
    QPixmap temp(strList[0]);
    ui->homeImage->setPixmap(temp);
    ui->homeImage->setScaledContents(true);
    ui->label_23->setText(strList[1]);
    ui->label_22->setText(strList[3]);
    ui->label_21->setText(strList[5]);
    ui->label_20->setText(strList[7]);
    ui->label_19->setText(strList[9]);
    ui->label_18->setText(strList[11]);
    ui->label_17->setText(strList[13]);
    ui->label_16->setText(strList[15]);
    ui->label_15->setText(strList[17]);
    ui->label_14->setText(strList[19]);

    ui->textEdit->setText(strList[2]);
    ui->textEdit_6->setText(strList[4]);
    ui->textEdit_8->setText(strList[6]);
    ui->textEdit_10->setText(strList[8]);
    ui->textEdit_12->setText(strList[10]);
    ui->textEdit_14->setText(strList[12]);
    ui->textEdit_16->setText(strList[14]);
    ui->textEdit_18->setText(strList[16]);
    ui->textEdit_20->setText(strList[18]);
    ui->textEdit_22->setText(strList[20]);

    ui->textEdit_2->setText(dialogDialog.getMaterials(1));
    ui->textEdit_5->setText(dialogDialog.getMaterials(2));
    ui->textEdit_7->setText(dialogDialog.getMaterials(3));
    ui->textEdit_9->setText(dialogDialog.getMaterials(4));
    ui->textEdit_11->setText(dialogDialog.getMaterials(5));
    ui->textEdit_13->setText(dialogDialog.getMaterials(6));
    ui->textEdit_15->setText(dialogDialog.getMaterials(7));
    ui->textEdit_17->setText(dialogDialog.getMaterials(8));
    ui->textEdit_19->setText(dialogDialog.getMaterials(9));
    ui->textEdit_21->setText(dialogDialog.getMaterials(10));
}

void MainWindow::clearAllElements(){
    ui->homeImage->clear();
    ui->label_23->setText("");
    ui->label_22->setText("");
    ui->label_21->setText("");
    ui->label_20->setText("");
    ui->label_19->setText("");
    ui->label_18->setText("");
    ui->label_17->setText("");
    ui->label_16->setText("");
    ui->label_15->setText("");
    ui->label_14->setText("");

    ui->textEdit->setText("");
    ui->textEdit_6->setText("");
    ui->textEdit_8->setText("");
    ui->textEdit_10->setText("");
    ui->textEdit_12->setText("");
    ui->textEdit_14->setText("");
    ui->textEdit_16->setText("");
    ui->textEdit_18->setText("");
    ui->textEdit_20->setText("");
    ui->textEdit_22->setText("");

    ui->label_2->clear();
    ui->label_5->clear();
    ui->label_6->clear();
    ui->label_7->clear();
    ui->label_8->clear();
    ui->label_9->clear();
    ui->label_10->clear();
    ui->label_11->clear();
    ui->label_12->clear();
    ui->label_13->clear();


    ui->checkBox->setChecked(false);
    ui->checkBox_3->setChecked(false);
    ui->checkBox_4->setChecked(false);
    ui->checkBox_5->setChecked(false);
    ui->checkBox_6->setChecked(false);
    ui->checkBox_7->setChecked(false);
    ui->checkBox_8->setChecked(false);
    ui->checkBox_9->setChecked(false);
    ui->checkBox_10->setChecked(false);
    ui->checkBox_11->setChecked(false);
}

void MainWindow::setMaterial(QString material, int index) {
    switch (index) {
    case 1:
        ui->textEdit_2->setText(material);
        break;
    case 2:
        ui->textEdit_5->setText(material);
        break;
    case 3:
        ui->textEdit_7->setText(material);
        break;
    case 4:
        ui->textEdit_9->setText(material);
        break;
    case 5:
        ui->textEdit_11->setText(material);
        break;
    case 6:
        ui->textEdit_13->setText(material);
        break;
    case 7:
        ui->textEdit_15->setText(material);
        break;
    case 8:
        ui->textEdit_17->setText(material);
        break;
    case 9:
        ui->textEdit_19->setText(material);
        break;
    case 10:
        ui->textEdit_21->setText(material);
        break;

    }
}

void MainWindow::savePlane(QString price) {
    QString filename = QFileDialog::getSaveFileName(this, "Сохранить план", QDir::currentPath(), "*.pdf");

    if (filename != "") {
        QPdfWriter pdf(filename);
        QPainter painter(&pdf);
        QFont font = painter.font() ;
        QRectF target(0.0, 0, 1200, 900);
        QRectF source(0.0, 0, 1200, 900);

        /* twice the size than the current font size */
        font.setPointSize(font.pointSize() / 1.35);

        /* set the modified font to the painter */
        painter.setFont(font);

        painter.drawText(0,0,ui->comboModelName->currentText());
       // painter.drawImage(0,100,ui->homeImage->pixmap()->toImage(),0,100);
        painter.drawImage(target,ui->homeImage->pixmap()->toImage(),source);

        painter.drawText(0,1000,"1. Шаг: " + ui->label_23->text());
        painter.drawText(0,1100,"Описание шага: " + ui->textEdit->toPlainText());
        painter.drawText(0,1200,"Необходимые материалы: " + ui->textEdit_2->toPlainText());
        if (ui->checkBox->isChecked()) {
            painter.drawText(0,1300,"Это шаг выполнен!");
        }
        if (ui->label_2->pixmap() != NULL) {
            painter.drawImage(0,1400,ui->label_2->pixmap()->toImage());
        }

        painter.drawText(0,2300,"2. Шаг: " + ui->label_22->text());
        painter.drawText(0,2400,"Описание шага: " + ui->textEdit_6->toPlainText());
        painter.drawText(0,2500,"Необходимые материалы: " + ui->textEdit_5->toPlainText());
        if (ui->checkBox->isChecked()) {
            painter.drawText(0,2600,"Это шаг выполнен!");
        }
        if (ui->label_5->pixmap() != NULL) {
            painter.drawImage(0,2700,ui->label_5->pixmap()->toImage());
        }

        painter.drawText(0,3600,"3. Шаг: " + ui->label_21->text());
        painter.drawText(0,3700,"Описание шага: " + ui->textEdit_8->toPlainText());
        painter.drawText(0,3800,"Необходимые материалы: " + ui->textEdit_7->toPlainText());
        if (ui->checkBox->isChecked()) {
            painter.drawText(0,3900,"Это шаг выполнен!");
        }
        if (ui->label_6->pixmap() != NULL) {
            painter.drawImage(0,4000,ui->label_6->pixmap()->toImage());
        }

        painter.drawText(0,4900,"4. Шаг: " + ui->label_20->text());
        painter.drawText(0,5000,"Описание шага: " + ui->textEdit_10->toPlainText());
        painter.drawText(0,5100,"Необходимые материалы: " + ui->textEdit_9->toPlainText());
        if (ui->checkBox->isChecked()) {
            painter.drawText(0,5200,"Это шаг выполнен!");
        }
        if (ui->label_7->pixmap() != NULL) {
            painter.drawImage(0,5300,ui->label_7->pixmap()->toImage());
        }

        painter.drawText(0,6200,"5. Шаг: " + ui->label_19->text());
        painter.drawText(0,6300,"Описание шага: " + ui->textEdit_12->toPlainText());
        painter.drawText(0,6400,"Необходимые материалы: " + ui->textEdit_11->toPlainText());
        if (ui->checkBox->isChecked()) {
            painter.drawText(0,6500,"Это шаг выполнен!");
        }
        if (ui->label_8->pixmap() != NULL) {
            painter.drawImage(0,6600,ui->label_8->pixmap()->toImage());
        }

        painter.drawText(0,7500,"6. Шаг: " + ui->label_18->text());
        painter.drawText(0,7600,"Описание шага: " + ui->textEdit_14->toPlainText());
        painter.drawText(0,7700,"Необходимые материалы: " + ui->textEdit_13->toPlainText());
        if (ui->checkBox->isChecked()) {
            painter.drawText(0,7800,"Это шаг выполнен!");
        }
        if (ui->label_9->pixmap() != NULL) {
            painter.drawImage(0,7900,ui->label_9->pixmap()->toImage());
        }

        painter.drawText(0,8800,"7. Шаг: " + ui->label_17->text());
        painter.drawText(0,8900,"Описание шага: " + ui->textEdit_16->toPlainText());
        painter.drawText(0,9000,"Необходимые материалы: " + ui->textEdit_15->toPlainText());
        if (ui->checkBox->isChecked()) {
            painter.drawText(0,9100,"Это шаг выполнен!");
        }
        if (ui->label_10->pixmap() != NULL) {
            painter.drawImage(0,9200,ui->label_10->pixmap()->toImage());
        }

        painter.drawText(0,10100,"8. Шаг: " + ui->label_16->text());
        painter.drawText(0,10200,"Описание шага: " + ui->textEdit_18->toPlainText());
        painter.drawText(0,10300,"Необходимые материалы: " + ui->textEdit_17->toPlainText());
        if (ui->checkBox->isChecked()) {
            painter.drawText(0,10400,"Это шаг выполнен!");
        }
        if (ui->label_11->pixmap() != NULL) {
            painter.drawImage(0,10500,ui->label_11->pixmap()->toImage());
        }

        painter.drawText(0,11400,"9. Шаг: " + ui->label_15->text());
        painter.drawText(0,11500,"Описание шага: " + ui->textEdit_20->toPlainText());
        painter.drawText(0,11600,"Необходимые материалы: " + ui->textEdit_19->toPlainText());
        if (ui->checkBox->isChecked()) {
            painter.drawText(0,11700,"Это шаг выполнен!");
        }
        if (ui->label_12->pixmap() != NULL) {
            painter.drawImage(0,11800,ui->label_12->pixmap()->toImage());
        }

        painter.drawText(0,12700,"10. Шаг: " + ui->label_14->text());
        painter.drawText(0,12800,"Описание шага: " + ui->textEdit_22->toPlainText());
        painter.drawText(0,12900,"Необходимые материалы: " + ui->textEdit_21->toPlainText());
        if (ui->checkBox->isChecked()) {
            painter.drawText(0,13000,"Это шаг выполнен!");
        }
        if (ui->label_13->pixmap() != NULL) {
            painter.drawImage(0,13100,ui->label_13->pixmap()->toImage());
        }

       painter.drawText(0,14000,"Полная стоимость: " + finishDialog.getFullPrice());
       ui->tabWidget->setCurrentIndex(0);
       ui->comboModelName->setCurrentIndex(0);
        HideAllTabs();
        clearAllElements();
    }
}

void MainWindow::on_pushButton_31_clicked()
{

}
