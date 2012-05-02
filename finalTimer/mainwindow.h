#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "singletimer.h"
#include "dependent.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


    //functions to open the individual timing windows
private slots:
      void openSingle();
      void openDependent();

private:
    Ui::MainWindow *ui;
    singleTimer *oneTimer;
    dependent *mainTimer;
};

#endif // MAINWINDOW_H
