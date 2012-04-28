#include "singletimer.h"
#include "ui_singletimer.h"
#include <QMessageBox>

singleTimer::singleTimer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::singleTimer)
{
    ui->setupUi(this);
    mytimer = new QTimer();
}

singleTimer::~singleTimer()
{
    delete ui;
}


void singleTimer::countdownStart(){
    connect(mytimer, SIGNAL(timeout()), this, SLOT(subtractOne()));
    connect(ui->spinBox_h, SIGNAL(valueChanged(int)), this, SLOT(setMValue()));
    connect(ui->spinBox_m, SIGNAL(valueChanged(int)), this, SLOT(setSValue()));
    if(ui->checkRollover->isChecked()){
        hour = ui->spinBox_h->value();
        min = ui->spinBox_m->value();
        sec = ui->spinBox_s->value();
    }
    mytimer->start(1000);
}

void singleTimer::subtractOne(){
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
        if(ui->checkSound->isChecked()){
            //possible implementation
        }
        */
        if(ui->checkMessage->isChecked()){
            QMessageBox::information(this, "Timer Stop", "Countdown finished!");
        }
        if(!ui->checkRollover->isChecked()){
            stop();
        }

        else{
         ui->spinBox_h->setValue(hour);
         ui->spinBox_m->setValue(min);
         ui->spinBox_s->setValue(sec);
        }
    }
}

void singleTimer::setMValue(){
    ui->spinBox_m->setValue(59);
}

void singleTimer::setSValue(){
    ui->spinBox_s->setValue(59);
}

void singleTimer::countupStart(){
        connect(mytimer, SIGNAL(timeout()), this, SLOT(addOne()));
        connect(ui->spinBox_h, SIGNAL(valueChanged(int)), this, SLOT(setMLow()));
        connect(ui->spinBox_m, SIGNAL(valueChanged(int)), this, SLOT(setSLow()));
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


void singleTimer::on_pushStart_clicked()
{

   if(ui->radioDown->isChecked())
        countdownStart();
    else if(ui->radioUp->isChecked())
        countupStart();
    mytimer->start(1000);
}

void singleTimer::stop()
{
    mytimer->stop();
    disconnect(mytimer, SIGNAL(timeout()), this, SLOT(addOne()));
    disconnect(mytimer, SIGNAL(timeout()), this, SLOT(subtractOne()));
}
