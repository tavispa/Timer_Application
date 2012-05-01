#include "timer.h"
#include "ui_timer.h"
#include "about.h"

timer::timer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::timer)
{
    ui->setupUi(this);
    mytimer = new QTimer();
}

timer::~timer()
{
    delete ui;
}

void timer::countdownStart(){
    //mytimer = new QTimer();
    connect(mytimer, SIGNAL(timeout()), this, SLOT(subtractOne()));
    connect(ui->spinBox_h, SIGNAL(valueChanged(int)), this, SLOT(setMValue()));
    connect(ui->spinBox_m, SIGNAL(valueChanged(int)), this, SLOT(setSValue()));
    mytimer->start(1000);
}

void timer::subtractOne(){
    ui->spinBox_s->setValue(ui->spinBox_s->value()-1);
    if(ui->spinBox_s->value() == 0){
        if(ui->spinBox_m->value()-1 == 0 && ui->spinBox_h->value()>0){
            ui->spinBox_h->stepDown();
        }
        else
            ui->spinBox_m->stepDown();
    }
    if(ui->spinBox_h->value() == 0 && ui->spinBox_m->value() == 0 && ui->spinBox_s ->value() == 0)
        mytimer->stop();
}

void timer::setMValue(){
    ui->spinBox_m->setValue(59);
}

void timer::setSValue(){
    ui->spinBox_s->setValue(59);
}

void timer::countupStart(){
    connect(mytimer, SIGNAL(timeout()), this, SLOT(addOne()));
    connect(ui->spinBox_h, SIGNAL(valueChanged(int)), this, SLOT(setMLow()));
    connect(ui->spinBox_m, SIGNAL(valueChanged(int)), this, SLOT(setSLow()));
    mytimer->start(1000);
}

void timer::addOne(){
    ui->spinBox_s->stepUp();
    if(ui->spinBox_s->value() == 60){
        ui->spinBox_m->stepUp();
        if(ui->spinBox_m->value() == 60){
            ui->spinBox_h->stepUp();
        }
    }
}

void timer::setMLow(){
    ui->spinBox_m->setValue(0);
}

void timer::setSLow(){
    ui->spinBox_s->setValue(0);
}

void timer::on_actionAbout_triggered()
{
    about aboutWindow;
    aboutWindow.setModal(true);
    aboutWindow.exec();
}
