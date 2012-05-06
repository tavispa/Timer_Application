/********************************************************************************
** Form generated from reading UI file 'singletimer.ui'
**
** Created: Sun May 6 01:43:24 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SINGLETIMER_H
#define UI_SINGLETIMER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_singleTimer
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QSpinBox *spinBox_h;
    QSpinBox *spinBox_m;
    QSpinBox *spinBox_s;
    QLabel *label;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *radioUp;
    QRadioButton *radioDown;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QCheckBox *checkMessage;
    QCheckBox *checkRollover;
    QPushButton *pushStart;
    QPushButton *pushStop;
    QLabel *label_2;

    void setupUi(QDialog *singleTimer)
    {
        if (singleTimer->objectName().isEmpty())
            singleTimer->setObjectName(QString::fromUtf8("singleTimer"));
        singleTimer->resize(619, 367);
        horizontalLayoutWidget = new QWidget(singleTimer);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(40, 60, 231, 71));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        spinBox_h = new QSpinBox(horizontalLayoutWidget);
        spinBox_h->setObjectName(QString::fromUtf8("spinBox_h"));

        horizontalLayout->addWidget(spinBox_h);

        spinBox_m = new QSpinBox(horizontalLayoutWidget);
        spinBox_m->setObjectName(QString::fromUtf8("spinBox_m"));

        horizontalLayout->addWidget(spinBox_m);

        spinBox_s = new QSpinBox(horizontalLayoutWidget);
        spinBox_s->setObjectName(QString::fromUtf8("spinBox_s"));

        horizontalLayout->addWidget(spinBox_s);

        label = new QLabel(singleTimer);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(360, 150, 201, 31));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        label->setTextFormat(Qt::RichText);
        layoutWidget = new QWidget(singleTimer);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 160, 291, 51));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        radioUp = new QRadioButton(layoutWidget);
        radioUp->setObjectName(QString::fromUtf8("radioUp"));

        horizontalLayout_2->addWidget(radioUp);

        radioDown = new QRadioButton(layoutWidget);
        radioDown->setObjectName(QString::fromUtf8("radioDown"));

        horizontalLayout_2->addWidget(radioDown);

        layoutWidget1 = new QWidget(singleTimer);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(360, 190, 211, 101));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        checkMessage = new QCheckBox(layoutWidget1);
        checkMessage->setObjectName(QString::fromUtf8("checkMessage"));

        verticalLayout->addWidget(checkMessage);

        checkRollover = new QCheckBox(layoutWidget1);
        checkRollover->setObjectName(QString::fromUtf8("checkRollover"));

        verticalLayout->addWidget(checkRollover);

        pushStart = new QPushButton(singleTimer);
        pushStart->setObjectName(QString::fromUtf8("pushStart"));
        pushStart->setGeometry(QRect(40, 250, 111, 41));
        QFont font1;
        font1.setPointSize(16);
        pushStart->setFont(font1);
        pushStop = new QPushButton(singleTimer);
        pushStop->setObjectName(QString::fromUtf8("pushStop"));
        pushStop->setGeometry(QRect(190, 250, 111, 41));
        pushStop->setFont(font1);
        label_2 = new QLabel(singleTimer);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(90, 20, 141, 23));
        label_2->setFont(font1);

        retranslateUi(singleTimer);
        QObject::connect(pushStop, SIGNAL(clicked()), singleTimer, SLOT(stop()));

        QMetaObject::connectSlotsByName(singleTimer);
    } // setupUi

    void retranslateUi(QDialog *singleTimer)
    {
        singleTimer->setWindowTitle(QApplication::translate("singleTimer", "Single Timer", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("singleTimer", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Bitstream Charter'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:14pt;\">Count Down Options</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        radioUp->setText(QApplication::translate("singleTimer", "Count Up", 0, QApplication::UnicodeUTF8));
        radioDown->setText(QApplication::translate("singleTimer", "Count Down", 0, QApplication::UnicodeUTF8));
        checkMessage->setText(QApplication::translate("singleTimer", "Show Message", 0, QApplication::UnicodeUTF8));
        checkRollover->setText(QApplication::translate("singleTimer", "Rollover", 0, QApplication::UnicodeUTF8));
        pushStart->setText(QApplication::translate("singleTimer", "Start", 0, QApplication::UnicodeUTF8));
        pushStop->setText(QApplication::translate("singleTimer", "Stop", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("singleTimer", "Single Timer", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class singleTimer: public Ui_singleTimer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SINGLETIMER_H
