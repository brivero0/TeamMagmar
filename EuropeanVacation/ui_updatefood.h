/********************************************************************************
** Form generated from reading UI file 'updatefood.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPDATEFOOD_H
#define UI_UPDATEFOOD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_updateFood
{
public:
    QLabel *promptLabel;
    QWidget *layoutWidget;
    QVBoxLayout *editGroup;
    QDoubleSpinBox *newPrice;
    QHBoxLayout *buttonGroup;
    QPushButton *confirmButton;
    QPushButton *resetButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *updateFood)
    {
        if (updateFood->objectName().isEmpty())
            updateFood->setObjectName(QStringLiteral("updateFood"));
        updateFood->resize(415, 243);
        promptLabel = new QLabel(updateFood);
        promptLabel->setObjectName(QStringLiteral("promptLabel"));
        promptLabel->setGeometry(QRect(60, 50, 291, 71));
        promptLabel->setAlignment(Qt::AlignCenter);
        layoutWidget = new QWidget(updateFood);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(60, 140, 297, 61));
        editGroup = new QVBoxLayout(layoutWidget);
        editGroup->setObjectName(QStringLiteral("editGroup"));
        editGroup->setContentsMargins(0, 0, 0, 0);
        newPrice = new QDoubleSpinBox(layoutWidget);
        newPrice->setObjectName(QStringLiteral("newPrice"));
        newPrice->setButtonSymbols(QAbstractSpinBox::NoButtons);
        newPrice->setMaximum(1e+07);

        editGroup->addWidget(newPrice);

        buttonGroup = new QHBoxLayout();
        buttonGroup->setObjectName(QStringLiteral("buttonGroup"));
        confirmButton = new QPushButton(layoutWidget);
        confirmButton->setObjectName(QStringLiteral("confirmButton"));

        buttonGroup->addWidget(confirmButton);

        resetButton = new QPushButton(layoutWidget);
        resetButton->setObjectName(QStringLiteral("resetButton"));

        buttonGroup->addWidget(resetButton);

        cancelButton = new QPushButton(layoutWidget);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        buttonGroup->addWidget(cancelButton);


        editGroup->addLayout(buttonGroup);


        retranslateUi(updateFood);

        QMetaObject::connectSlotsByName(updateFood);
    } // setupUi

    void retranslateUi(QDialog *updateFood)
    {
        updateFood->setWindowTitle(QApplication::translate("updateFood", "Dialog", nullptr));
        promptLabel->setText(QString());
        confirmButton->setText(QApplication::translate("updateFood", "Update", nullptr));
        resetButton->setText(QApplication::translate("updateFood", "Reset", nullptr));
        cancelButton->setText(QApplication::translate("updateFood", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class updateFood: public Ui_updateFood {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPDATEFOOD_H
