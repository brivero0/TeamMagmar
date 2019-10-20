/********************************************************************************
** Form generated from reading UI file 'afooddialog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AFOODDIALOG_H
#define UI_AFOODDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_aFoodDialog
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *promptLabel;
    QHBoxLayout *horizontalLayout;
    QPushButton *yesButton;
    QPushButton *noButton;

    void setupUi(QDialog *aFoodDialog)
    {
        if (aFoodDialog->objectName().isEmpty())
            aFoodDialog->setObjectName(QStringLiteral("aFoodDialog"));
        aFoodDialog->resize(488, 250);
        aFoodDialog->setContextMenuPolicy(Qt::NoContextMenu);
        aFoodDialog->setAcceptDrops(true);
        layoutWidget = new QWidget(aFoodDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(50, 20, 371, 211));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        promptLabel = new QLabel(layoutWidget);
        promptLabel->setObjectName(QStringLiteral("promptLabel"));
        promptLabel->setStyleSheet(QStringLiteral("font: 11pt \"Sitka\";"));
        promptLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(promptLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        yesButton = new QPushButton(layoutWidget);
        yesButton->setObjectName(QStringLiteral("yesButton"));

        horizontalLayout->addWidget(yesButton);

        noButton = new QPushButton(layoutWidget);
        noButton->setObjectName(QStringLiteral("noButton"));

        horizontalLayout->addWidget(noButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(aFoodDialog);

        QMetaObject::connectSlotsByName(aFoodDialog);
    } // setupUi

    void retranslateUi(QDialog *aFoodDialog)
    {
        aFoodDialog->setWindowTitle(QApplication::translate("aFoodDialog", "Delete Food Item", nullptr));
        promptLabel->setText(QString());
        yesButton->setText(QApplication::translate("aFoodDialog", "Yes", nullptr));
        noButton->setText(QApplication::translate("aFoodDialog", "No", nullptr));
    } // retranslateUi

};

namespace Ui {
    class aFoodDialog: public Ui_aFoodDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AFOODDIALOG_H
