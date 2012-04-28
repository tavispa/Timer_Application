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

private:
    Ui::singleTimer *ui;
    int connectedDown;
    int connectedUp;
    QTimer *mytimer;
};

#endif // SINGLETIMER_H
