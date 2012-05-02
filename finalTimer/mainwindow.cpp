#include "mainwindow.h"
#include "ui_mainwindow.h"


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

//open a single timer window
void MainWindow::openSingle(){
    //open multiple timing windows and allow control to main
    //I chose this since one of the ideas of the project was
    //to have multiple timers available to someone
    oneTimer = new singleTimer(this);
    oneTimer->show();

    //you would use these lines if you only wanted the user to have one window
    //disables control leaving the opened window
    //singleTimer oneTimer;
    //oneTimer.setModal(true);
    //oneTimer.exec();
}

//open a timing window with one dependent timer and one independent timer
void MainWindow::openDependent(){
    mainTimer = new dependent();
    mainTimer->show();
    /*
    dependent mainTimer;
    mainTimer.setModal(true);
    mainTimer.exec();
    */
}

