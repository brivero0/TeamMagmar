/********************************************************************************
** Form generated from reading UI file 'tconfirmparis.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TCONFIRMPARIS_H
#define UI_TCONFIRMPARIS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_tConfirmParis
{
public:
    QLabel *ParisConfirmationLabel;
    QPushButton *startSimulationBtn1;

    void setupUi(QWidget *tConfirmParis)
    {
        if (tConfirmParis->objectName().isEmpty())
            tConfirmParis->setObjectName(QString::fromUtf8("tConfirmParis"));
        tConfirmParis->resize(742, 458);
        ParisConfirmationLabel = new QLabel(tConfirmParis);
        ParisConfirmationLabel->setObjectName(QString::fromUtf8("ParisConfirmationLabel"));
        ParisConfirmationLabel->setGeometry(QRect(60, 80, 261, 81));
        startSimulationBtn1 = new QPushButton(tConfirmParis);
        startSimulationBtn1->setObjectName(QString::fromUtf8("startSimulationBtn1"));
        startSimulationBtn1->setGeometry(QRect(60, 190, 101, 21));

        retranslateUi(tConfirmParis);

        QMetaObject::connectSlotsByName(tConfirmParis);
    } // setupUi

    void retranslateUi(QWidget *tConfirmParis)
    {
        tConfirmParis->setWindowTitle(QCoreApplication::translate("tConfirmParis", "Form", nullptr));
        ParisConfirmationLabel->setText(QCoreApplication::translate("tConfirmParis", "Paris Confirmation Window", nullptr));
        startSimulationBtn1->setText(QCoreApplication::translate("tConfirmParis", "Start your vacation!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class tConfirmParis: public Ui_tConfirmParis {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TCONFIRMPARIS_H
