/********************************************************************************
** Form generated from reading UI file 'ttravelsimulation.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TTRAVELSIMULATION_H
#define UI_TTRAVELSIMULATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_tTravelSimulation
{
public:
    QLabel *label;
    QPushButton *exitSimulationButton;

    void setupUi(QWidget *tTravelSimulation)
    {
        if (tTravelSimulation->objectName().isEmpty())
            tTravelSimulation->setObjectName(QStringLiteral("tTravelSimulation"));
        tTravelSimulation->resize(400, 300);
        label = new QLabel(tTravelSimulation);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(120, 110, 161, 51));
        exitSimulationButton = new QPushButton(tTravelSimulation);
        exitSimulationButton->setObjectName(QStringLiteral("exitSimulationButton"));
        exitSimulationButton->setGeometry(QRect(220, 250, 121, 31));

        retranslateUi(tTravelSimulation);

        QMetaObject::connectSlotsByName(tTravelSimulation);
    } // setupUi

    void retranslateUi(QWidget *tTravelSimulation)
    {
        tTravelSimulation->setWindowTitle(QApplication::translate("tTravelSimulation", "Form", nullptr));
        label->setText(QApplication::translate("tTravelSimulation", "BadAss Travel simulation!!!!!!!", nullptr));
        exitSimulationButton->setText(QApplication::translate("tTravelSimulation", "Cancel Simulation?", nullptr));
    } // retranslateUi

};

namespace Ui {
    class tTravelSimulation: public Ui_tTravelSimulation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TTRAVELSIMULATION_H
