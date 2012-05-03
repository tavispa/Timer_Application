#ifndef SINGLETIMER_H
#define SINGLETIMER_H

#include <QDialog>
#include <QTimer>
#include <QMessageBox>

namespace Ui {
    class singleTimer;
}

class singleTimer : public QDialog
{
    Q_OBJECT

public:
    explicit singleTimer(QWidget *parent = 0);
    ~singleTimer();

//Everything above here is automatically created by QT
public slots:
  //functions needed to countdown to work
    void countdownStart();
    void subtractOne();
    void setMValue();
    void setSValue();

 //functions needed for countup to work
    void countupStart();
    void addOne();
    void setMLow();
    void setSLow();

 //function to stop timer
    void stop();

private:
    Ui::singleTimer *ui;
    QTimer *mytimer;

    //variables to store time in case of roll over
    int hour;
    int min;
    int sec;

private slots:
    //you can do this with a different function but this can be created automatically
    void on_pushStart_clicked();
};

#endif // SINGLETIMER_H
