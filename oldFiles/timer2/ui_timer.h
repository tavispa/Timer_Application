/********************************************************************************
** Form generated from reading UI file 'timer.ui'
**
** Created: Sun Apr 8 00:14:22 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIMER_H
#define UI_TIMER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_timer
{
public:
    QAction *actionAbout;
    QAction *actionHello_Tony;
    QWidget *centralWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QSpinBox *spinBox_h;
    QSpinBox *spinBox_m;
    QSpinBox *spinBox_s;
    QPushButton *pushButton_countdown;
    QLabel *label;
    QPushButton *countUp;
    QStatusBar *statusBar;
    QToolBar *toolBar;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;

    void setupUi(QMainWindow *timer)
    {
        if (timer->objectName().isEmpty())
            timer->setObjectName(QString::fromUtf8("timer"));
        timer->resize(762, 433);
        timer->setCursor(QCursor(Qt::CrossCursor));
        actionAbout = new QAction(timer);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionHello_Tony = new QAction(timer);
        actionHello_Tony->setObjectName(QString::fromUtf8("actionHello_Tony"));
        centralWidget = new QWidget(timer);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(100, 90, 511, 131));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        spinBox_h = new QSpinBox(horizontalLayoutWidget);
        spinBox_h->setObjectName(QString::fromUtf8("spinBox_h"));
        spinBox_h->setEnabled(true);
        spinBox_h->setMinimumSize(QSize(0, 0));
        QFont font;
        font.setPointSize(20);
        spinBox_h->setFont(font);
        spinBox_h->setCursor(QCursor(Qt::CrossCursor));

        horizontalLayout->addWidget(spinBox_h);

        spinBox_m = new QSpinBox(horizontalLayoutWidget);
        spinBox_m->setObjectName(QString::fromUtf8("spinBox_m"));
        spinBox_m->setFont(font);

        horizontalLayout->addWidget(spinBox_m);

        spinBox_s = new QSpinBox(horizontalLayoutWidget);
        spinBox_s->setObjectName(QString::fromUtf8("spinBox_s"));
        spinBox_s->setFont(font);

        horizontalLayout->addWidget(spinBox_s);

        pushButton_countdown = new QPushButton(centralWidget);
        pushButton_countdown->setObjectName(QString::fromUtf8("pushButton_countdown"));
        pushButton_countdown->setGeometry(QRect(160, 230, 151, 61));
        QFont font1;
        font1.setPointSize(16);
        pushButton_countdown->setFont(font1);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(120, 50, 471, 31));
        QFont font2;
        font2.setPointSize(20);
        font2.setBold(true);
        font2.setWeight(75);
        label->setFont(font2);
        countUp = new QPushButton(centralWidget);
        countUp->setObjectName(QString::fromUtf8("countUp"));
        countUp->setGeometry(QRect(410, 230, 151, 61));
        countUp->setFont(font1);
        countUp->setMouseTracking(false);
        timer->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(timer);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        timer->setStatusBar(statusBar);
        toolBar = new QToolBar(timer);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        timer->addToolBar(Qt::TopToolBarArea, toolBar);
        menuBar = new QMenuBar(timer);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 762, 31));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        timer->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionHello_Tony);
        menuHelp->addAction(actionAbout);

        retranslateUi(timer);
        QObject::connect(pushButton_countdown, SIGNAL(clicked()), timer, SLOT(countdownStart()));
        QObject::connect(countUp, SIGNAL(clicked()), timer, SLOT(countupStart()));

        QMetaObject::connectSlotsByName(timer);
    } // setupUi

    void retranslateUi(QMainWindow *timer)
    {
        timer->setWindowTitle(QApplication::translate("timer", "Count Up and Count Down Timers", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("timer", "About", 0, QApplication::UnicodeUTF8));
        actionHello_Tony->setText(QApplication::translate("timer", "Hello Tony", 0, QApplication::UnicodeUTF8));
        pushButton_countdown->setText(QApplication::translate("timer", "Count  Down", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("timer", " Hours             Minutes         Seconds", 0, QApplication::UnicodeUTF8));
        countUp->setText(QApplication::translate("timer", "Count  Up", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("timer", "toolBar", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("timer", "File", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("timer", "Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class timer: public Ui_timer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIMER_H
