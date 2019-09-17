/********************************************************************************
** Form generated from reading UI file 'tconfirmparis.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
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
            tConfirmParis->setObjectName(QStringLiteral("tConfirmParis"));
        tConfirmParis->resize(742, 458);
        ParisConfirmationLabel = new QLabel(tConfirmParis);
        ParisConfirmationLabel->setObjectName(QStringLiteral("ParisConfirmationLabel"));
        ParisConfirmationLabel->setGeometry(QRect(60, 80, 261, 81));
        startSimulationBtn1 = new QPushButton(tConfirmParis);
        startSimulationBtn1->setObjectName(QStringLiteral("startSimulationBtn1"));
        startSimulationBtn1->setGeometry(QRect(60, 190, 101, 21));

        retranslateUi(tConfirmParis);

        QMetaObject::connectSlotsByName(tConfirmParis);
    } // setupUi

    void retranslateUi(QWidget *tConfirmParis)
    {
        tConfirmParis->setWindowTitle(QApplication::translate("tConfirmParis", "Form", nullptr));
        ParisConfirmationLabel->setText(QApplication::translate("tConfirmParis", "Paris Confirmation Window", nullptr));
        startSimulationBtn1->setText(QApplication::translate("tConfirmParis", "Start your vacation!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class tConfirmParis: public Ui_tConfirmParis {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TCONFIRMPARIS_H
