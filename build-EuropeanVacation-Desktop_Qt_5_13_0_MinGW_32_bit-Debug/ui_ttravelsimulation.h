/********************************************************************************
** Form generated from reading UI file 'ttravelsimulation.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TTRAVELSIMULATION_H
#define UI_TTRAVELSIMULATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_tTravelSimulation
{
public:
    QLabel *label;

    void setupUi(QWidget *tTravelSimulation)
    {
        if (tTravelSimulation->objectName().isEmpty())
            tTravelSimulation->setObjectName(QString::fromUtf8("tTravelSimulation"));
        tTravelSimulation->resize(400, 300);
        label = new QLabel(tTravelSimulation);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(120, 110, 161, 51));

        retranslateUi(tTravelSimulation);

        QMetaObject::connectSlotsByName(tTravelSimulation);
    } // setupUi

    void retranslateUi(QWidget *tTravelSimulation)
    {
        tTravelSimulation->setWindowTitle(QCoreApplication::translate("tTravelSimulation", "Form", nullptr));
        label->setText(QCoreApplication::translate("tTravelSimulation", "BadAss Travel simulation!!!!!!!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class tTravelSimulation: public Ui_tTravelSimulation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TTRAVELSIMULATION_H
