#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->comboBox->addItem("25 Minutes");
    ui->comboBox->addItem("45 Minutes");

    hours = 0;
    minutes = 25;
    seconds = 0;

    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(setTime()));

    timer = new QTimer(this); // pointer points to a new timer
    connect(timer, SIGNAL(timeout()), this, SLOT(updateTime()));
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(start()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(stop()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(setTime()));

//    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(reset()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateTime()
{
        seconds--;
        if(seconds < 0){
            seconds = 59;
            minutes--;
        }

//    if(minutes == 60){
//        minutes = 0;
//        hours++;
//    }

        QString strHrs = QString::number(hours);
        QString strMin = QString::number(minutes);
        QString strSec = QString::number(seconds);

        if(hours < 10){
            strHrs = "0" + strHrs;
        }
        if(minutes < 10){
            strMin = "0" + strMin;
        }
        if(seconds < 10){
            strSec = "0" + strSec;
        }

        ui->label_2->setText(strHrs);
        ui->label_4->setText(strMin);
        ui->label_5->setText(strSec);


    if((minutes == 0) && (seconds == 0)){
        timer->stop();

        // modal approach
//        Dialog myDialog; // creating an object
//        myDialog.setModal(true);
//        myDialog.exec();

//        modal-less approach
        hide();
        myDialog = new Dialog(this);
        myDialog->show();
    }


}

void MainWindow::start()
{
    timer->start(1000); // QTimer is in ms, 1000ms = 1s
}

void MainWindow::stop()
{
    timer->stop();
}

void MainWindow::setTime()
{
    if((ui->comboBox->currentText())[0] == "4" ){
//        ui->label_4->setText("45");
        hours = 0;
        minutes = 45;
        seconds = 0;

        ui->label_4->setText("45");
        ui->label_2->setText("00");
        ui->label_5->setText("00");
    }
    else{
//        ui->label_4->setText("25");
        hours = 0;
        minutes = 0; // FIX LATER
        seconds = 7;

        ui->label_4->setText("25");
        ui->label_2->setText("00");
        ui->label_5->setText("00");
    }
}
