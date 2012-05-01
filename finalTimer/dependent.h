#ifndef DEPENDENT_H
#define DEPENDENT_H

#include <QDialog>
#include <QTimer>
#include <QMessageBox>

namespace Ui {
    class dependent;
}

class dependent : public QDialog
{
    Q_OBJECT

public:
    explicit dependent(QWidget *parent = 0);
    ~dependent();

public slots:
    void stop();

    void secUp();
    void secDown();

    void depSecUp();
    void depUpStart();

    void depSecDown();

    void checkToConnect();

private:
    Ui::dependent *ui;
    QTimer *mytimer;
    int main_h;
    int main_m;
    int main_s;
    int dep_h;
    int dep_m;
    int dep_s;

private slots:
    void on_pushAbout_clicked();
    void on_pushStop_clicked();
    void on_pushSet_clicked();
    void on_pushStart_clicked();
};

#endif // DEPENDENT_H
