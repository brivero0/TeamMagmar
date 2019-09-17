/********************************************************************************
** Form generated from reading UI file 'aDestinations.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADESTINATIONS_H
#define UI_ADESTINATIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_aDestinations
{
public:
    QLabel *label_6;

    void setupUi(QWidget *aDestinations)
    {
        if (aDestinations->objectName().isEmpty())
            aDestinations->setObjectName(QStringLiteral("aDestinations"));
        aDestinations->resize(1200, 640);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(aDestinations->sizePolicy().hasHeightForWidth());
        aDestinations->setSizePolicy(sizePolicy);
        aDestinations->setMinimumSize(QSize(1200, 640));
        aDestinations->setMaximumSize(QSize(1200, 640));
        label_6 = new QLabel(aDestinations);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 20, 601, 50));
        QFont font;
        font.setPointSize(16);
        label_6->setFont(font);

        retranslateUi(aDestinations);

        QMetaObject::connectSlotsByName(aDestinations);
    } // setupUi

    void retranslateUi(QWidget *aDestinations)
    {
        aDestinations->setWindowTitle(QApplication::translate("aDestinations", "Form", nullptr));
        label_6->setText(QApplication::translate("aDestinations", "Admin's Destinations Widget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class aDestinations: public Ui_aDestinations {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADESTINATIONS_H
