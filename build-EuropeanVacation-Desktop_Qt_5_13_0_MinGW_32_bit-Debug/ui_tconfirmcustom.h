/********************************************************************************
** Form generated from reading UI file 'tconfirmcustom.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TCONFIRMCUSTOM_H
#define UI_TCONFIRMCUSTOM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_tConfirmCustom
{
public:
    QLabel *label;
    QPushButton *startSimulationBtn2;

    void setupUi(QWidget *tConfirmCustom)
    {
        if (tConfirmCustom->objectName().isEmpty())
            tConfirmCustom->setObjectName(QString::fromUtf8("tConfirmCustom"));
        tConfirmCustom->resize(699, 454);
        label = new QLabel(tConfirmCustom);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(100, 110, 231, 61));
        startSimulationBtn2 = new QPushButton(tConfirmCustom);
        startSimulationBtn2->setObjectName(QString::fromUtf8("startSimulationBtn2"));
        startSimulationBtn2->setGeometry(QRect(60, 200, 161, 41));

        retranslateUi(tConfirmCustom);

        QMetaObject::connectSlotsByName(tConfirmCustom);
    } // setupUi

    void retranslateUi(QWidget *tConfirmCustom)
    {
        tConfirmCustom->setWindowTitle(QCoreApplication::translate("tConfirmCustom", "Form", nullptr));
        label->setText(QCoreApplication::translate("tConfirmCustom", "Custom Confirmation Window ", nullptr));
        startSimulationBtn2->setText(QCoreApplication::translate("tConfirmCustom", "Travel Simulation YO ho yo ho!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class tConfirmCustom: public Ui_tConfirmCustom {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TCONFIRMCUSTOM_H
