#include "singletimer.h"
#include "ui_singletimer.h"


singleTimer::singleTimer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::singleTimer)
{
    ui->setupUi(this);
    //create timer pointer
    mytimer = new QTimer();
}

singleTimer::~singleTimer()
{
    delete ui;
}

/*countdownStart -
       connects the signals from the timer to the second portion of the timing box
       then connects the seconds to minutes, minutes to hours
       starts the timer
       if rollOver is checked, then it saves where the values will need to go back to
*/
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


/*subtractOne

  subtract one from the second box, then check to see if other boxes need to be subtracted from
  and reset seconds to 59 (or minutes to 59) based on what happens in more significant places

  control what happens if check boxes are/aren't checked

 */
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

        //display a message
        if(ui->checkMessage->isChecked()){
            QMessageBox::information(this, "Timer Stop", "Countdown finished!");
        }

        //if it's not rolling over, stop the timer
        if(!ui->checkRollover->isChecked()){
            stop();
        }
        //if the timer doesn't stop, reset to the roll over values
        else{
         ui->spinBox_h->setValue(hour);
         ui->spinBox_m->setValue(min);
         ui->spinBox_s->setValue(sec);
        }
    }
}

//setMValue and setSValue set the spin boxes to 59 when they hit 0 and you get a carry from
//a more significant section
void singleTimer::setMValue(){
    ui->spinBox_m->setValue(59);
}

void singleTimer::setSValue(){
    ui->spinBox_s->setValue(59);
}


/*countupStart
  connects the spin boxes so they change as necessary when seconds hits 60, or minutes hits 60

 */
void singleTimer::countupStart(){
        connect(mytimer, SIGNAL(timeout()), this, SLOT(addOne()));
        connect(ui->spinBox_h, SIGNAL(valueChanged(int)), this, SLOT(setMLow()));
        connect(ui->spinBox_m, SIGNAL(valueChanged(int)), this, SLOT(setSLow()));
}

//addOne
//add one to the seconds, if it hits 60, add one to minutes, if minutes hits 60, add one to hours,
//roll seconds/minutes back over to 0
void singleTimer::addOne(){
    ui->spinBox_s->stepUp();
    if(ui->spinBox_s->value() == 60){
        ui->spinBox_m->stepUp();
        if(ui->spinBox_m->value() == 60){
            ui->spinBox_h->stepUp();
        }
    }
}

//setMLow and setSLow set minutes and seconds to 0 as needed
void singleTimer::setMLow(){
    ui->spinBox_m->setValue(0);
}

void singleTimer::setSLow(){
    ui->spinBox_s->setValue(0);
}


//when the pushButton is clicked, determine if the timer is counting up or down,
//call those functions to connect signals
//start the timer
void singleTimer::on_pushStart_clicked()
{

   if(ui->radioDown->isChecked())
        countdownStart();
    else if(ui->radioUp->isChecked())
        countupStart();
    mytimer->start(1000);
}


//stop
//stop the timer, and disconnect the signals
//if you don't disconnect the signals, everytime you click start it will add 1 to how much seconds is
//increased/decreased by (click it once, increases by 1, click it again, starts increasing by 2, then 3, etc)
void singleTimer::stop()
{
    mytimer->stop();
    disconnect(mytimer, SIGNAL(timeout()), this, SLOT(addOne()));
    disconnect(mytimer, SIGNAL(timeout()), this, SLOT(subtractOne()));
}
