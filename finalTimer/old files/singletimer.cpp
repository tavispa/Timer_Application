#include "singletimer.h"
#include "ui_singletimer.h"
#include <QMessageBox>

singleTimer::singleTimer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::singleTimer)
{
    ui->setupUi(this);
    mytimer = new QTimer();
    connectedDown = 0;
    connectedUp = 0;
}

singleTimer::~singleTimer()
{
    delete ui;
}


void singleTimer::countdownStart(){
    if(connectedDown == 0){
        connect(mytimer, SIGNAL(timeout()), this, SLOT(subtractOne()));
        connectedDown++;
    }
    connect(ui->spinBox_h, SIGNAL(valueChanged(int)), this, SLOT(setMValue()));
    connect(ui->spinBox_m, SIGNAL(valueChanged(int)), this, SLOT(setSValue()));
    /*
    if(ui->mainRollOver->isChecked()){
        mainHour = ui->spinBox_h->value();
        mainMin = ui->spinBox_m->value();
        mainSec = ui->spinBox_s->value();
    }
    */
    mytimer->start(1000);
    //ui->spinBox_s->stepBy(1);
}

void singleTimer::subtractOne(){
    //ui->spinBox_s->setValue(ui->spinBox_s->value()-1);
    ui->spinBox_s->stepDown();
    if(ui->spinBox_s->value() == 0){
        if(ui->spinBox_m->value()-1 == 0 && ui->spinBox_h->value()>0){
            ui->spinBox_h->stepDown();
        }
        else
            ui->spinBox_m->stepDown();
    }
    if(ui->spinBox_h->value() == 0 && ui->spinBox_m->value() == 0 && ui->spinBox_s ->value() == 0){
        /*
        if(ui->mainPlaySound->isChecked()){
            //this will be the last thing to implement in this section, phonon's are not easy
        }
        if(ui->mainShowMessage->isChecked()){
            QMessageBox::StandardButton info;
            info = QMessageBox::information(this, tr("Timer_Done"), "Finished!");
        }
        if(!ui->mainRollOver->isChecked()){
            mytimer->stop();
        }

        else{
         ui->spinBox_h->setValue(mainHour);
         ui->spinBox_m->setValue(mainMin);
         ui->spinBox_s->setValue(mainSec);
        }
        */
        mytimer->stop();
    }
}

void singleTimer::setMValue(){
    ui->spinBox_m->setValue(59);
}

void singleTimer::setSValue(){
    ui->spinBox_s->setValue(59);
}

void singleTimer::countupStart(){
    if(connectedUp == 0){
        connect(mytimer, SIGNAL(timeout()), this, SLOT(addOne()));
        connect(ui->spinBox_h, SIGNAL(valueChanged(int)), this, SLOT(setMLow()));
        connect(ui->spinBox_m, SIGNAL(valueChanged(int)), this, SLOT(setSLow()));
        connectedUp++;
    }
    mytimer->start(1000);
}

void singleTimer::addOne(){
    ui->spinBox_s->stepUp();
    if(ui->spinBox_s->value() == 60){
        ui->spinBox_m->stepUp();
        if(ui->spinBox_m->value() == 60){
            ui->spinBox_h->stepUp();
        }
    }
}

void singleTimer::setMLow(){
    ui->spinBox_m->setValue(0);
}

void singleTimer::setSLow(){
    ui->spinBox_s->setValue(0);
}
