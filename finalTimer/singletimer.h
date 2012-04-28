#ifndef SINGLETIMER_H
#define SINGLETIMER_H

#include <QDialog>
#include <QTimer>

namespace Ui {
    class singleTimer;
}

class singleTimer : public QDialog
{
    Q_OBJECT

public:
    explicit singleTimer(QWidget *parent = 0);
    ~singleTimer();

public slots:
    void countdownStart();
    void subtractOne();
    void setMValue();
    void setSValue();

    void countupStart();
    void addOne();
    void setMLow();
    void setSLow();

    void stop();

private:
    Ui::singleTimer *ui;
    QTimer *mytimer;
    int hour;
    int min;
    int sec;

private slots:
    void on_pushStart_clicked();
};

#endif // SINGLETIMER_H
