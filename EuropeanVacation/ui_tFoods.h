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
    QLabel *selCity;
    QLabel *foodOption;
    QLabel *label;
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
        tFoods->setStyleSheet(QStringLiteral("color white;"));
        Title = new QLabel(tFoods);
        Title->setObjectName(QStringLiteral("Title"));
        Title->setGeometry(QRect(500, 80, 651, 50));
        QFont font;
        font.setFamily(QStringLiteral("Script MT Bold"));
        font.setPointSize(36);
        font.setBold(false);
        font.setItalic(false);
        font.setUnderline(true);
        font.setWeight(9);
        Title->setFont(font);
        Title->setStyleSheet(QLatin1String("color: black;\n"
"font: 75 36pt \"Script MT Bold\";\n"
"text-decoration: underline;\n"
""));
        selCity = new QLabel(tFoods);
        selCity->setObjectName(QStringLiteral("selCity"));
        selCity->setGeometry(QRect(190, 200, 120, 31));
        selCity->setStyleSheet(QLatin1String("color: black;\n"
"font: 16pt \"Times New Roman\";\n"
""));
        selCity->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);
        foodOption = new QLabel(tFoods);
        foodOption->setObjectName(QStringLiteral("foodOption"));
        foodOption->setGeometry(QRect(660, 170, 210, 48));
        foodOption->setStyleSheet(QStringLiteral("font: 22pt \"Sylfaen\";"));
        foodOption->setAlignment(Qt::AlignCenter);
        label = new QLabel(tFoods);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, -10, 1201, 661));
        label->setPixmap(QPixmap(QString::fromUtf8(":/images/menuBack.jpg")));
        label->setScaledContents(true);
        tFoodOptionsTV = new QTableView(tFoods);
        tFoodOptionsTV->setObjectName(QStringLiteral("tFoodOptionsTV"));
        tFoodOptionsTV->setGeometry(QRect(640, 220, 401, 281));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tFoodOptionsTV->sizePolicy().hasHeightForWidth());
        tFoodOptionsTV->setSizePolicy(sizePolicy1);
        tFoodOptionsTV->setStyleSheet(QStringLiteral(""));
        tFoodOptionsTV->setShowGrid(true);
        tFoodOptionsTV->setSortingEnabled(false);
        tFoodOptionsTV->horizontalHeader()->setCascadingSectionResizes(false);
        tFoodOptionsTV->horizontalHeader()->setDefaultSectionSize(125);
        tFoodOptionsTV->verticalHeader()->setCascadingSectionResizes(false);
        tFoodOptionsTV->verticalHeader()->setHighlightSections(false);
        tCityList = new QComboBox(tFoods);
        tCityList->setObjectName(QStringLiteral("tCityList"));
        tCityList->setGeometry(QRect(190, 230, 291, 30));
        tCityList->setMinimumSize(QSize(0, 30));
        tCityList->setMaximumSize(QSize(16777212, 16777215));
        tCityList->setStyleSheet(QStringLiteral(""));
        label->raise();
        Title->raise();
        selCity->raise();
        foodOption->raise();
        tFoodOptionsTV->raise();
        tCityList->raise();

        retranslateUi(tFoods);

        QMetaObject::connectSlotsByName(tFoods);
    } // setupUi

    void retranslateUi(QWidget *tFoods)
    {
        tFoods->setWindowTitle(QApplication::translate("tFoods", "Form", nullptr));
        Title->setText(QApplication::translate("tFoods", "Menu", nullptr));
        selCity->setText(QApplication::translate("tFoods", "Select City", nullptr));
#ifndef QT_NO_WHATSTHIS
        foodOption->setWhatsThis(QApplication::translate("tFoods", "<html><head/><body><p align=\"center\">Food Options</p></body></html>", nullptr));
#endif // QT_NO_WHATSTHIS
        foodOption->setText(QApplication::translate("tFoods", "Food Options", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class tFoods: public Ui_tFoods {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TFOODS_H
