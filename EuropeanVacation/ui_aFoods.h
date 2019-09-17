/********************************************************************************
** Form generated from reading UI file 'aFoods.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AFOODS_H
#define UI_AFOODS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_aFoods
{
public:
    QLabel *label_7;

    void setupUi(QWidget *aFoods)
    {
        if (aFoods->objectName().isEmpty())
            aFoods->setObjectName(QStringLiteral("aFoods"));
        aFoods->resize(1200, 640);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(aFoods->sizePolicy().hasHeightForWidth());
        aFoods->setSizePolicy(sizePolicy);
        aFoods->setMinimumSize(QSize(1200, 640));
        aFoods->setMaximumSize(QSize(1200, 640));
        label_7 = new QLabel(aFoods);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(20, 20, 1081, 50));
        QFont font;
        font.setPointSize(16);
        label_7->setFont(font);

        retranslateUi(aFoods);

        QMetaObject::connectSlotsByName(aFoods);
    } // setupUi

    void retranslateUi(QWidget *aFoods)
    {
        aFoods->setWindowTitle(QApplication::translate("aFoods", "Form", nullptr));
        label_7->setText(QApplication::translate("aFoods", "Admin's Foods Options Widget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class aFoods: public Ui_aFoods {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AFOODS_H
