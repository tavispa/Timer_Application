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
    int main_h; // main timer hours
    int main_m; // main timer minutes
    int main_s; // main timer seconds
    int dep_h; // dependent timer hours
    int dep_m; // dependent timer minutes
    int dep_s; // dependent timer seconds

private slots:
    void on_pushAbout_clicked();
    void on_pushStop_clicked();
    void on_pushSet_clicked();
    void on_pushStart_clicked();
};

#endif // DEPENDENT_H
