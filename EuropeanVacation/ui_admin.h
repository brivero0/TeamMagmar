/********************************************************************************
** Form generated from reading UI file 'admin.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMIN_H
#define UI_ADMIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_admin
{
public:
    QStackedWidget *stackedWidget;
    QWidget *mainPage;
    QLabel *adminImage;
    QLabel *label;
    QGroupBox *pushButtonGroup;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *homeButton;
    QPushButton *destinationDBButton;
    QPushButton *foodDBButton;
    QPushButton *logoutButton;

    void setupUi(QWidget *admin)
    {
        if (admin->objectName().isEmpty())
            admin->setObjectName(QStringLiteral("admin"));
        admin->resize(1200, 700);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(admin->sizePolicy().hasHeightForWidth());
        admin->setSizePolicy(sizePolicy);
        admin->setMinimumSize(QSize(1200, 700));
        admin->setMaximumSize(QSize(1200, 700));
        stackedWidget = new QStackedWidget(admin);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 60, 1200, 640));
        mainPage = new QWidget();
        mainPage->setObjectName(QStringLiteral("mainPage"));
        adminImage = new QLabel(mainPage);
        adminImage->setObjectName(QStringLiteral("adminImage"));
        adminImage->setGeometry(QRect(0, 0, 1201, 641));
        adminImage->setPixmap(QPixmap(QString::fromUtf8(":/images/sandshrewsnowbg2.png")));
        label = new QLabel(mainPage);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 555, 731, 71));
        QFont font;
        font.setPointSize(36);
        label->setFont(font);
        label->setStyleSheet(QStringLiteral("color: #3a546b;"));
        stackedWidget->addWidget(mainPage);
        pushButtonGroup = new QGroupBox(admin);
        pushButtonGroup->setObjectName(QStringLiteral("pushButtonGroup"));
        pushButtonGroup->setGeometry(QRect(0, 0, 1200, 60));
        pushButtonGroup->setStyleSheet(QStringLiteral("background-color: #ecf1f5;"));
        layoutWidget = new QWidget(pushButtonGroup);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 20, 1161, 24));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        homeButton = new QPushButton(layoutWidget);
        homeButton->setObjectName(QStringLiteral("homeButton"));
        QFont font1;
        font1.setPointSize(9);
        font1.setBold(true);
        font1.setWeight(75);
        homeButton->setFont(font1);
        homeButton->setStyleSheet(QLatin1String("background-color:#ccccff;\n"
"border-style: solid;\n"
"border-color: black;\n"
"border-width: 2px;\n"
"border-radius: 5px;"));

        horizontalLayout->addWidget(homeButton);

        destinationDBButton = new QPushButton(layoutWidget);
        destinationDBButton->setObjectName(QStringLiteral("destinationDBButton"));
        destinationDBButton->setMaximumSize(QSize(16777215, 16777215));
        destinationDBButton->setFont(font1);
        destinationDBButton->setStyleSheet(QLatin1String("background-color:#ccccff;\n"
"border-style: solid;\n"
"border-color: black;\n"
"border-width: 2px;\n"
"border-radius: 5px;"));

        horizontalLayout->addWidget(destinationDBButton);

        foodDBButton = new QPushButton(layoutWidget);
        foodDBButton->setObjectName(QStringLiteral("foodDBButton"));
        foodDBButton->setMaximumSize(QSize(16777215, 16777215));
        foodDBButton->setFont(font1);
        foodDBButton->setStyleSheet(QLatin1String("background-color:#ccccff;\n"
"border-style: solid;\n"
"border-color: black;\n"
"border-width: 2px;\n"
"border-radius: 5px;"));

        horizontalLayout->addWidget(foodDBButton);

        logoutButton = new QPushButton(layoutWidget);
        logoutButton->setObjectName(QStringLiteral("logoutButton"));
        logoutButton->setFont(font1);
        logoutButton->setStyleSheet(QLatin1String("background-color:#ccccff;\n"
"border-style: solid;\n"
"border-color: black;\n"
"border-width: 2px;\n"
"border-radius: 5px;"));

        horizontalLayout->addWidget(logoutButton);


        retranslateUi(admin);

        QMetaObject::connectSlotsByName(admin);
    } // setupUi

    void retranslateUi(QWidget *admin)
    {
        admin->setWindowTitle(QApplication::translate("admin", "Admin Window", nullptr));
        adminImage->setText(QString());
        label->setText(QApplication::translate("admin", "Welcome Admin!", nullptr));
        pushButtonGroup->setTitle(QString());
        homeButton->setText(QApplication::translate("admin", "HOME", nullptr));
        destinationDBButton->setText(QApplication::translate("admin", "Destinations Database", nullptr));
        foodDBButton->setText(QApplication::translate("admin", "Foods Database", nullptr));
        logoutButton->setText(QApplication::translate("admin", "LOGOUT", nullptr));
    } // retranslateUi

};

namespace Ui {
    class admin: public Ui_admin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMIN_H
