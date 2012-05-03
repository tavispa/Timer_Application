/********************************************************************************
** Form generated from reading UI file 'dependent.ui'
**
** Created: Wed May 2 23:44:57 2012
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEPENDENT_H
#define UI_DEPENDENT_H

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
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dependent
{
public:
    QPushButton *pushSet;
    QLabel *label_2;
    QLabel *label_3;
    QCheckBox *checkReset;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_4;
    QSpinBox *spinBox_dep_h;
    QSpinBox *spinBox_dep_m;
    QSpinBox *spinBox_dep_s;
    QPushButton *pushAbout;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *radioUp;
    QRadioButton *radioDown;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout;
    QSpinBox *spinBox_main_h;
    QSpinBox *spinBox_main_m;
    QSpinBox *spinBox_main_s;
    QPushButton *pushStart;
    QPushButton *pushStop;

    void setupUi(QDialog *dependent)
    {
        if (dependent->objectName().isEmpty())
            dependent->setObjectName(QString::fromUtf8("dependent"));
        dependent->resize(455, 416);
        pushSet = new QPushButton(dependent);
        pushSet->setObjectName(QString::fromUtf8("pushSet"));
        pushSet->setGeometry(QRect(330, 160, 71, 31));
        label_2 = new QLabel(dependent);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(120, 20, 121, 16));
        QFont font;
        font.setPointSize(16);
        label_2->setFont(font);
        label_3 = new QLabel(dependent);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(90, 110, 191, 31));
        label_3->setFont(font);
        checkReset = new QCheckBox(dependent);
        checkReset->setObjectName(QString::fromUtf8("checkReset"));
        checkReset->setGeometry(QRect(310, 120, 141, 17));
        layoutWidget = new QWidget(dependent);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(60, 150, 251, 51));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        spinBox_dep_h = new QSpinBox(layoutWidget);
        spinBox_dep_h->setObjectName(QString::fromUtf8("spinBox_dep_h"));

        horizontalLayout_4->addWidget(spinBox_dep_h);

        spinBox_dep_m = new QSpinBox(layoutWidget);
        spinBox_dep_m->setObjectName(QString::fromUtf8("spinBox_dep_m"));

        horizontalLayout_4->addWidget(spinBox_dep_m);

        spinBox_dep_s = new QSpinBox(layoutWidget);
        spinBox_dep_s->setObjectName(QString::fromUtf8("spinBox_dep_s"));

        horizontalLayout_4->addWidget(spinBox_dep_s);

        pushAbout = new QPushButton(dependent);
        pushAbout->setObjectName(QString::fromUtf8("pushAbout"));
        pushAbout->setGeometry(QRect(300, 300, 101, 41));
        layoutWidget1 = new QWidget(dependent);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(50, 230, 311, 51));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        radioUp = new QRadioButton(layoutWidget1);
        radioUp->setObjectName(QString::fromUtf8("radioUp"));

        horizontalLayout_3->addWidget(radioUp);

        radioDown = new QRadioButton(layoutWidget1);
        radioDown->setObjectName(QString::fromUtf8("radioDown"));

        horizontalLayout_3->addWidget(radioDown);

        layoutWidget2 = new QWidget(dependent);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(60, 50, 251, 51));
        horizontalLayout = new QHBoxLayout(layoutWidget2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        spinBox_main_h = new QSpinBox(layoutWidget2);
        spinBox_main_h->setObjectName(QString::fromUtf8("spinBox_main_h"));

        horizontalLayout->addWidget(spinBox_main_h);

        spinBox_main_m = new QSpinBox(layoutWidget2);
        spinBox_main_m->setObjectName(QString::fromUtf8("spinBox_main_m"));

        horizontalLayout->addWidget(spinBox_main_m);

        spinBox_main_s = new QSpinBox(layoutWidget2);
        spinBox_main_s->setObjectName(QString::fromUtf8("spinBox_main_s"));

        horizontalLayout->addWidget(spinBox_main_s);

        pushStart = new QPushButton(dependent);
        pushStart->setObjectName(QString::fromUtf8("pushStart"));
        pushStart->setGeometry(QRect(20, 300, 121, 41));
        pushStop = new QPushButton(dependent);
        pushStop->setObjectName(QString::fromUtf8("pushStop"));
        pushStop->setGeometry(QRect(160, 300, 121, 41));

        retranslateUi(dependent);
        QObject::connect(pushStop, SIGNAL(clicked()), dependent, SLOT(stop()));

        QMetaObject::connectSlotsByName(dependent);
    } // setupUi

    void retranslateUi(QDialog *dependent)
    {
        dependent->setWindowTitle(QApplication::translate("dependent", "Dependent Timers", 0, QApplication::UnicodeUTF8));
        pushSet->setText(QApplication::translate("dependent", "Set", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("dependent", "Main Timer", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("dependent", "Dependent Timer", 0, QApplication::UnicodeUTF8));
        checkReset->setText(QApplication::translate("dependent", "Do Not Reset", 0, QApplication::UnicodeUTF8));
        pushAbout->setText(QApplication::translate("dependent", "About", 0, QApplication::UnicodeUTF8));
        radioUp->setText(QApplication::translate("dependent", "Count Up", 0, QApplication::UnicodeUTF8));
        radioDown->setText(QApplication::translate("dependent", "Count Down", 0, QApplication::UnicodeUTF8));
        pushStart->setText(QApplication::translate("dependent", "Start", 0, QApplication::UnicodeUTF8));
        pushStop->setText(QApplication::translate("dependent", "Stop", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class dependent: public Ui_dependent {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEPENDENT_H
