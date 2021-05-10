#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "dialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QTimer *timer;
    int hours, minutes, seconds;

private slots:
    void updateTime();
    void start();
    void stop();
//    void reset();
    void setTime();

private:
    Ui::MainWindow *ui;
    Dialog *myDialog;
};
#endif // MAINWINDOW_H
