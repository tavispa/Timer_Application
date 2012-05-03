#include "dependent.h"
#include "ui_dependent.h"

dependent::dependent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dependent)
{
    ui->setupUi(this);
    mytimer = new QTimer();
    dep_h = 0;
    dep_m = 0;
    dep_s = 0;
}

dependent::~dependent()
{
    delete ui;
}
/*
*on_pushStart_clicked
* On click event function for starting execution and connecting 
* appropiate signals and slots.
*/
void dependent::on_pushStart_clicked()
{

    if(ui->radioUp->isChecked()){
        connect(mytimer, SIGNAL(timeout()), this, SLOT(secUp()));
        connect(mytimer, SIGNAL(timeout()), this, SLOT(depSecUp()));
    }
    if(ui->radioDown->isChecked()){
        connect(mytimer, SIGNAL(timeout()), this, SLOT(secDown()));
        connect(mytimer, SIGNAL(timeout()), this, SLOT(checkToConnect()));
    }
    mytimer->start(1000);
}

/*stop
* Function to disconnect slots and signals  when timers expire
* checks the main timer spin box values
*/

void dependent::stop()
{
    if(ui->spinBox_main_h->value() == 0 && ui->spinBox_main_m->value() == 0 && ui->spinBox_main_s->value() == 0){
        disconnect(mytimer, SIGNAL(timeout()), this, SLOT(secDown()));
    }
   
}

/*secUp
* Updates the main timer spin boxes and resets the boxes
* as dependent timer counts up
*/

void dependent::secUp(){
    ui->spinBox_main_s->stepUp();
    if(ui->spinBox_main_s->value()==60){
        ui->spinBox_main_m->stepUp();
        if(ui->spinBox_main_m->value() == 60){
            ui->spinBox_main_h->stepUp();
            ui->spinBox_main_m->setValue(0);
        }
        ui->spinBox_main_s->setValue(0);
    }
}

/*secDown
* Updates the main timer spin boxes and reset as needed
* as dependent timer counts down
*/

void dependent::secDown(){
    ui->spinBox_main_s->stepDown();
    if(ui->spinBox_main_s->value() == 0){
        if(ui->spinBox_main_m->value() == 0 && ui->spinBox_main_h->value() > 0){
            ui->spinBox_main_h->stepDown();
            ui->spinBox_main_m->setValue(59);
        }
        else
            ui->spinBox_main_m->stepDown();
    }
    if(ui->spinBox_main_h->value() == 0 && ui->spinBox_main_m->value() == 0 && ui->spinBox_main_s->value() == 0){
        stop();
    }
    else if(ui->spinBox_main_s->value() == 0)
        ui->spinBox_main_s->setValue(59);
}

/*on_pushSet_Clicked
* 
*/
void dependent::on_pushSet_clicked()
{
       dep_h = ui->spinBox_main_h->value();
       dep_m = ui->spinBox_main_m->value();
       dep_s = ui->spinBox_main_s->value();
       if(!ui->checkReset->isChecked()){
           ui->spinBox_main_h->setValue(0);
           ui->spinBox_main_m->setValue(0);
           ui->spinBox_main_s->setValue(0);
       }
}
/*depSecUp
*
*/
void dependent::depSecUp(){
    if(dep_h == ui->spinBox_main_h->value() && dep_m == ui->spinBox_main_m->value() && dep_s == ui->spinBox_main_s->value()){
       connect(mytimer, SIGNAL(timeout()), this, SLOT(depUpStart()));
    }
}
/*depUpStart
* Starts the depenent timer up
*/
void dependent::depUpStart(){
    ui->spinBox_dep_s->stepUp();
    if(ui->spinBox_dep_s->value()==60){
        ui->spinBox_dep_m->stepUp();
        if(ui->spinBox_dep_m->value() == 60){
            ui->spinBox_dep_h->stepUp();
            ui->spinBox_dep_m->setValue(0);
        }
        ui->spinBox_dep_s->setValue(0);
    }
}

/*
* Updates the dependent timer seconds spinbox
*/
void dependent::depSecDown(){
    ui->spinBox_dep_s->stepDown();
    if(ui->spinBox_dep_s->value() == 0){
        if(ui->spinBox_dep_m->value() == 0 && ui->spinBox_dep_h->value() > 0){
            ui->spinBox_dep_h->stepDown();
            ui->spinBox_dep_m->setValue(59);
        }
        else
            ui->spinBox_dep_m->stepDown();
    }
    if(ui->spinBox_dep_h->value() == 0 && ui->spinBox_dep_m->value() == 0 && ui->spinBox_dep_s->value() == 0)
        stop();
    else if(ui->spinBox_dep_s->value() == 0)
        ui->spinBox_dep_s->setValue(59);
}

/*
*  
*/

void dependent::checkToConnect(){
    if(dep_h == ui->spinBox_main_h->value() && dep_m == ui->spinBox_main_m->value() && dep_s == ui->spinBox_main_s->value()-1)
        connect(mytimer, SIGNAL(timeout()), this, SLOT(depSecDown()));
}

/*
* Function disconnects the signal from the slot and stops countings
*/
void dependent::on_pushStop_clicked()
{
    mytimer->disconnect();
    mytimer->stop();
}

/*
*  Message box for user instructions
*/
void dependent::on_pushAbout_clicked()
{
    QMessageBox::information(this, "How to use", 
             "Count Up Instructions:\nSet the main timer to when you want the dependent timer to start and click 'set'.\n You can change the dependent timer after this. For example, if you want to start the dependent timer at 5s, set the main timer, and then change the\ndependent timer input box to 5.\n Count Down Instructions:\nThe dependent timer can start when the main timer is 0:0:0 or you can set the dependent timer to start at specific time.\n  Set the dependent timer per the Count Up instructions.\n You can then change the dependent timer.\n For example, set main timer to 5s, click set. Then\n change the dependent timer spin boxes to where you want to start.");
}
