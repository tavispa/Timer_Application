#ifndef TIMER_H
#define TIMER_H

#include <QMainWindow>
#include <QTimer>

namespace Ui {
    class timer;
}

class timer : public QMainWindow
{
    Q_OBJECT

public:
    explicit timer(QWidget *parent = 0);
    ~timer();

public slots:
    void countdownStart();
    void subtractOne();
    void setMValue();
    void setSValue();

    void countupStart();
    void addOne();
    void setMLow();
    void setSLow();


private:
    Ui::timer *ui;
    QTimer *mytimer;

private slots:
    void on_actionAbout_triggered();
};

#endif // TIMER_H
