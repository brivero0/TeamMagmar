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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_aFoods
{
public:
    QTableView *aFoodTV;
    QLabel *foodDBLabel;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *addLabel;
    QVBoxLayout *addFields;
    QHBoxLayout *citySection;
    QLabel *cityLabel;
    QComboBox *cityCB;
    QHBoxLayout *nameSection;
    QLabel *foodLabel;
    QLineEdit *foodLE;
    QHBoxLayout *costSection;
    QLabel *costLE;
    QDoubleSpinBox *costSB;
    QHBoxLayout *buttonSection;
    QPushButton *cancelAdd;
    QPushButton *addFood;
    QPushButton *addFile;
    QLabel *delUpLabel;
    QVBoxLayout *deleteFields;
    QVBoxLayout *deleteChoices;
    QHBoxLayout *delCityField;
    QLabel *delCityLabel;
    QComboBox *delCityCB;
    QListView *foodLV;
    QHBoxLayout *delCost;
    QLabel *delCostLabel;
    QDoubleSpinBox *delCostSB;
    QHBoxLayout *deleteButtons;
    QPushButton *cancelDel;
    QPushButton *delButton;
    QPushButton *updateButton;

    void setupUi(QWidget *aFoods)
    {
        if (aFoods->objectName().isEmpty())
            aFoods->setObjectName(QStringLiteral("aFoods"));
        aFoods->resize(1200, 640);
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(aFoods->sizePolicy().hasHeightForWidth());
        aFoods->setSizePolicy(sizePolicy);
        aFoods->setMinimumSize(QSize(1200, 640));
        aFoods->setMaximumSize(QSize(1200, 640));
        aFoodTV = new QTableView(aFoods);
        aFoodTV->setObjectName(QStringLiteral("aFoodTV"));
        aFoodTV->setGeometry(QRect(60, 60, 701, 531));
#ifndef QT_NO_ACCESSIBILITY
        aFoodTV->setAccessibleDescription(QStringLiteral(""));
#endif // QT_NO_ACCESSIBILITY
        foodDBLabel = new QLabel(aFoods);
        foodDBLabel->setObjectName(QStringLiteral("foodDBLabel"));
        foodDBLabel->setGeometry(QRect(240, 10, 281, 41));
        foodDBLabel->setStyleSheet(QStringLiteral("font: 18pt \"Segoe UI Emoji\";"));
        foodDBLabel->setAlignment(Qt::AlignCenter);
        layoutWidget = new QWidget(aFoods);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(790, 20, 381, 591));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        addLabel = new QLabel(layoutWidget);
        addLabel->setObjectName(QStringLiteral("addLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(addLabel->sizePolicy().hasHeightForWidth());
        addLabel->setSizePolicy(sizePolicy1);
        addLabel->setMinimumSize(QSize(0, 15));
        addLabel->setStyleSheet(QLatin1String("font: 12pt \"Franklin Gothic Demi\";\n"
""));
        addLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(addLabel);

        addFields = new QVBoxLayout();
        addFields->setObjectName(QStringLiteral("addFields"));
        citySection = new QHBoxLayout();
        citySection->setObjectName(QStringLiteral("citySection"));
        cityLabel = new QLabel(layoutWidget);
        cityLabel->setObjectName(QStringLiteral("cityLabel"));
        cityLabel->setStyleSheet(QStringLiteral(""));

        citySection->addWidget(cityLabel);

        cityCB = new QComboBox(layoutWidget);
        cityCB->setObjectName(QStringLiteral("cityCB"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(cityCB->sizePolicy().hasHeightForWidth());
        cityCB->setSizePolicy(sizePolicy2);

        citySection->addWidget(cityCB);


        addFields->addLayout(citySection);

        nameSection = new QHBoxLayout();
        nameSection->setObjectName(QStringLiteral("nameSection"));
        foodLabel = new QLabel(layoutWidget);
        foodLabel->setObjectName(QStringLiteral("foodLabel"));
        foodLabel->setStyleSheet(QStringLiteral(""));

        nameSection->addWidget(foodLabel);

        foodLE = new QLineEdit(layoutWidget);
        foodLE->setObjectName(QStringLiteral("foodLE"));
        sizePolicy2.setHeightForWidth(foodLE->sizePolicy().hasHeightForWidth());
        foodLE->setSizePolicy(sizePolicy2);

        nameSection->addWidget(foodLE);


        addFields->addLayout(nameSection);

        costSection = new QHBoxLayout();
        costSection->setObjectName(QStringLiteral("costSection"));
        costLE = new QLabel(layoutWidget);
        costLE->setObjectName(QStringLiteral("costLE"));
        costLE->setStyleSheet(QStringLiteral(""));

        costSection->addWidget(costLE);

        costSB = new QDoubleSpinBox(layoutWidget);
        costSB->setObjectName(QStringLiteral("costSB"));
        sizePolicy2.setHeightForWidth(costSB->sizePolicy().hasHeightForWidth());
        costSB->setSizePolicy(sizePolicy2);
        costSB->setWrapping(true);
        costSB->setReadOnly(false);
        costSB->setButtonSymbols(QAbstractSpinBox::NoButtons);
        costSB->setMaximum(1e+07);

        costSection->addWidget(costSB);


        addFields->addLayout(costSection);

        buttonSection = new QHBoxLayout();
        buttonSection->setObjectName(QStringLiteral("buttonSection"));
        cancelAdd = new QPushButton(layoutWidget);
        cancelAdd->setObjectName(QStringLiteral("cancelAdd"));

        buttonSection->addWidget(cancelAdd);

        addFood = new QPushButton(layoutWidget);
        addFood->setObjectName(QStringLiteral("addFood"));

        buttonSection->addWidget(addFood);

        addFile = new QPushButton(layoutWidget);
        addFile->setObjectName(QStringLiteral("addFile"));

        buttonSection->addWidget(addFile);


        addFields->addLayout(buttonSection);


        verticalLayout->addLayout(addFields);

        delUpLabel = new QLabel(layoutWidget);
        delUpLabel->setObjectName(QStringLiteral("delUpLabel"));
        sizePolicy1.setHeightForWidth(delUpLabel->sizePolicy().hasHeightForWidth());
        delUpLabel->setSizePolicy(sizePolicy1);
        delUpLabel->setMinimumSize(QSize(0, 30));
        delUpLabel->setStyleSheet(QLatin1String("font: 12pt \"Franklin Gothic Demi\";\n"
""));
        delUpLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(delUpLabel);

        deleteFields = new QVBoxLayout();
        deleteFields->setObjectName(QStringLiteral("deleteFields"));
        deleteChoices = new QVBoxLayout();
        deleteChoices->setObjectName(QStringLiteral("deleteChoices"));
        delCityField = new QHBoxLayout();
        delCityField->setObjectName(QStringLiteral("delCityField"));
        delCityField->setSizeConstraint(QLayout::SetNoConstraint);
        delCityLabel = new QLabel(layoutWidget);
        delCityLabel->setObjectName(QStringLiteral("delCityLabel"));
        delCityLabel->setStyleSheet(QStringLiteral(""));

        delCityField->addWidget(delCityLabel);

        delCityCB = new QComboBox(layoutWidget);
        delCityCB->setObjectName(QStringLiteral("delCityCB"));
        sizePolicy2.setHeightForWidth(delCityCB->sizePolicy().hasHeightForWidth());
        delCityCB->setSizePolicy(sizePolicy2);

        delCityField->addWidget(delCityCB);


        deleteChoices->addLayout(delCityField);

        foodLV = new QListView(layoutWidget);
        foodLV->setObjectName(QStringLiteral("foodLV"));

        deleteChoices->addWidget(foodLV);


        deleteFields->addLayout(deleteChoices);

        delCost = new QHBoxLayout();
        delCost->setObjectName(QStringLiteral("delCost"));
        delCostLabel = new QLabel(layoutWidget);
        delCostLabel->setObjectName(QStringLiteral("delCostLabel"));
        delCostLabel->setStyleSheet(QStringLiteral(""));

        delCost->addWidget(delCostLabel);

        delCostSB = new QDoubleSpinBox(layoutWidget);
        delCostSB->setObjectName(QStringLiteral("delCostSB"));
        sizePolicy2.setHeightForWidth(delCostSB->sizePolicy().hasHeightForWidth());
        delCostSB->setSizePolicy(sizePolicy2);
        delCostSB->setReadOnly(true);
        delCostSB->setButtonSymbols(QAbstractSpinBox::NoButtons);
        delCostSB->setMaximum(1e+07);

        delCost->addWidget(delCostSB);


        deleteFields->addLayout(delCost);

        deleteButtons = new QHBoxLayout();
        deleteButtons->setObjectName(QStringLiteral("deleteButtons"));
        cancelDel = new QPushButton(layoutWidget);
        cancelDel->setObjectName(QStringLiteral("cancelDel"));

        deleteButtons->addWidget(cancelDel);

        delButton = new QPushButton(layoutWidget);
        delButton->setObjectName(QStringLiteral("delButton"));

        deleteButtons->addWidget(delButton);

        updateButton = new QPushButton(layoutWidget);
        updateButton->setObjectName(QStringLiteral("updateButton"));

        deleteButtons->addWidget(updateButton);


        deleteFields->addLayout(deleteButtons);


        verticalLayout->addLayout(deleteFields);


        retranslateUi(aFoods);

        QMetaObject::connectSlotsByName(aFoods);
    } // setupUi

    void retranslateUi(QWidget *aFoods)
    {
        aFoods->setWindowTitle(QApplication::translate("aFoods", "Form", nullptr));
        foodDBLabel->setText(QApplication::translate("aFoods", "Food Database", nullptr));
        addLabel->setText(QApplication::translate("aFoods", "Add Food Item", nullptr));
        cityLabel->setText(QApplication::translate("aFoods", "City:", nullptr));
        foodLabel->setText(QApplication::translate("aFoods", "Food Name:", nullptr));
        costLE->setText(QApplication::translate("aFoods", "Cost:", nullptr));
        cancelAdd->setText(QApplication::translate("aFoods", "Cancel", nullptr));
        addFood->setText(QApplication::translate("aFoods", "Add Food", nullptr));
        addFile->setText(QApplication::translate("aFoods", "Add From File", nullptr));
        delUpLabel->setText(QApplication::translate("aFoods", "Delete and Update Food Item", nullptr));
        delCityLabel->setText(QApplication::translate("aFoods", "City: ", nullptr));
        delCostLabel->setText(QApplication::translate("aFoods", "Price:", nullptr));
        cancelDel->setText(QApplication::translate("aFoods", "Cancel", nullptr));
        delButton->setText(QApplication::translate("aFoods", "Delete Food", nullptr));
        updateButton->setText(QApplication::translate("aFoods", "Update Price", nullptr));
    } // retranslateUi

};

namespace Ui {
    class aFoods: public Ui_aFoods {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AFOODS_H
