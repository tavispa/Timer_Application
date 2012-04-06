#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

void MainWindow::countdownStart(){
    //ui->spinBox->setValue(40);
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(subtractOne()));
    timer->start(1000);
}

void MainWindow::subtractOne(){
    ui->spinBox->setValue(ui->spinBox->value()-1);
}

MainWindow::~MainWindow()
{
    delete ui;
}
