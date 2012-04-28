#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "singletimer.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openSingle(){
    singleTimer oneTimer;
    oneTimer.setModal(true);
    oneTimer.exec();
}
