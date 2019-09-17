/********************************************************************************
** Form generated from reading UI file 'tFoods.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TFOODS_H
#define UI_TFOODS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_tFoods
{
public:
    QLabel *Title;
    QTableView *tFoodOptionsTV;
    QComboBox *tCityList;

    void setupUi(QWidget *tFoods)
    {
        if (tFoods->objectName().isEmpty())
            tFoods->setObjectName(QStringLiteral("tFoods"));
        tFoods->resize(1200, 640);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tFoods->sizePolicy().hasHeightForWidth());
        tFoods->setSizePolicy(sizePolicy);
        tFoods->setMinimumSize(QSize(1200, 640));
        tFoods->setMaximumSize(QSize(1200, 640));
        Title = new QLabel(tFoods);
        Title->setObjectName(QStringLiteral("Title"));
        Title->setGeometry(QRect(10, 10, 651, 50));
        QFont font;
        font.setPointSize(16);
        Title->setFont(font);
        Title->setStyleSheet(QStringLiteral("color: blue;"));
        tFoodOptionsTV = new QTableView(tFoods);
        tFoodOptionsTV->setObjectName(QStringLiteral("tFoodOptionsTV"));
        tFoodOptionsTV->setGeometry(QRect(470, 200, 311, 221));
        tCityList = new QComboBox(tFoods);
        tCityList->setObjectName(QStringLiteral("tCityList"));
        tCityList->setGeometry(QRect(22, 211, 231, 31));

        retranslateUi(tFoods);

        QMetaObject::connectSlotsByName(tFoods);
    } // setupUi

    void retranslateUi(QWidget *tFoods)
    {
        tFoods->setWindowTitle(QApplication::translate("tFoods", "Form", nullptr));
        Title->setText(QApplication::translate("tFoods", "Traveler's Food Options Widget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class tFoods: public Ui_tFoods {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TFOODS_H
