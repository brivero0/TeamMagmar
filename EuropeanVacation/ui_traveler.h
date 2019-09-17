/********************************************************************************
** Form generated from reading UI file 'traveler.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRAVELER_H
#define UI_TRAVELER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_traveler
{
public:
    QGroupBox *pushButtonGroup;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *travelPackButton;
    QPushButton *destinationsAvailButton;
    QPushButton *foodOptionsButton;
    QPushButton *logoutButton;
    QStackedWidget *stackedWidget;
    QWidget *mainPage;
    QLabel *managerImage;
    QGroupBox *MagbyPackage;
    QPushButton *SelectMagbyButton;
    QLabel *MagbyPackName;
    QLabel *MagbyPic;
    QLabel *MagbyStartLoc;
    QFrame *MagbyLine1;
    QLabel *MagbyNumDest;
    QFrame *MagbyLine2;
    QLabel *MagbyFoodOptions;
    QGroupBox *MagmarPackage;
    QPushButton *SelectMagmarButton;
    QLabel *MagmarPackName;
    QLabel *MagmarPic;
    QLabel *MagmarStartLoc;
    QFrame *MagmarLine1;
    QLabel *MagmarNumDest;
    QFrame *MagmarLine2;
    QLabel *MagmarFoodOptions;
    QGroupBox *MagmortarPackage;
    QPushButton *SelectMagmortarButton;
    QLabel *MagmortarPackName;
    QLabel *MagmortarPic;
    QLabel *MagmortarStartLoc;
    QFrame *MagmortarLine1;
    QLabel *MagmortarNumDest;
    QFrame *MagmortarLine2;
    QLabel *MagmortarFoodOptions;
    QGroupBox *ShinyMagmarPackage;
    QPushButton *SelectShinyMagmarButton;
    QLabel *ShinyMagmarPackName;
    QLabel *ShinyMagmarPic;
    QLabel *ShinyMagmarStartLoc;
    QFrame *ShinyMagmarLine1;
    QLabel *ShinyMagmarNumDest;
    QFrame *ShinyMagmarLine2;
    QLabel *ShinyMagmarFoodOptions;

    void setupUi(QWidget *traveler)
    {
        if (traveler->objectName().isEmpty())
            traveler->setObjectName(QStringLiteral("traveler"));
        traveler->resize(1200, 700);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(traveler->sizePolicy().hasHeightForWidth());
        traveler->setSizePolicy(sizePolicy);
        traveler->setMinimumSize(QSize(1200, 700));
        traveler->setMaximumSize(QSize(1200, 700));
        traveler->setStyleSheet(QStringLiteral(""));
        pushButtonGroup = new QGroupBox(traveler);
        pushButtonGroup->setObjectName(QStringLiteral("pushButtonGroup"));
        pushButtonGroup->setGeometry(QRect(0, 0, 1200, 60));
        pushButtonGroup->setStyleSheet(QStringLiteral("background-color: #ecf1f5;"));
        layoutWidget = new QWidget(pushButtonGroup);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(12, 20, 1171, 24));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        travelPackButton = new QPushButton(layoutWidget);
        travelPackButton->setObjectName(QStringLiteral("travelPackButton"));
        QFont font;
        font.setPointSize(9);
        font.setBold(true);
        font.setWeight(75);
        travelPackButton->setFont(font);
        travelPackButton->setStyleSheet(QLatin1String("background-color:#ccccff;\n"
"border-style: solid;\n"
"border-color: black;\n"
"border-width: 2px;\n"
"border-radius: 5px;"));

        horizontalLayout->addWidget(travelPackButton);

        destinationsAvailButton = new QPushButton(layoutWidget);
        destinationsAvailButton->setObjectName(QStringLiteral("destinationsAvailButton"));
        destinationsAvailButton->setMaximumSize(QSize(16777215, 16777215));
        destinationsAvailButton->setFont(font);
        destinationsAvailButton->setStyleSheet(QLatin1String("background-color:#ccccff;\n"
"border-style: solid;\n"
"border-color: black;\n"
"border-width: 2px;\n"
"border-radius: 5px;"));

        horizontalLayout->addWidget(destinationsAvailButton);

        foodOptionsButton = new QPushButton(layoutWidget);
        foodOptionsButton->setObjectName(QStringLiteral("foodOptionsButton"));
        foodOptionsButton->setMaximumSize(QSize(16777215, 16777215));
        foodOptionsButton->setFont(font);
        foodOptionsButton->setStyleSheet(QLatin1String("background-color:#ccccff;\n"
"border-style: solid;\n"
"border-color: black;\n"
"border-width: 2px;\n"
"border-radius: 5px;"));

        horizontalLayout->addWidget(foodOptionsButton);

        logoutButton = new QPushButton(layoutWidget);
        logoutButton->setObjectName(QStringLiteral("logoutButton"));
        logoutButton->setFont(font);
        logoutButton->setStyleSheet(QLatin1String("background-color:#ccccff;\n"
"border-style: solid;\n"
"border-color: black;\n"
"border-width: 2px;\n"
"border-radius: 5px;"));

        horizontalLayout->addWidget(logoutButton);

        stackedWidget = new QStackedWidget(traveler);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 60, 1200, 640));
        mainPage = new QWidget();
        mainPage->setObjectName(QStringLiteral("mainPage"));
        managerImage = new QLabel(mainPage);
        managerImage->setObjectName(QStringLiteral("managerImage"));
        managerImage->setGeometry(QRect(0, 0, 1201, 641));
        managerImage->setPixmap(QPixmap(QString::fromUtf8(":/images/sandshrewsnowbg.png")));
        MagbyPackage = new QGroupBox(mainPage);
        MagbyPackage->setObjectName(QStringLiteral("MagbyPackage"));
        MagbyPackage->setGeometry(QRect(10, 100, 285, 381));
        MagbyPackage->setStyleSheet(QStringLiteral("background-color:#ffff99;"));
        SelectMagbyButton = new QPushButton(MagbyPackage);
        SelectMagbyButton->setObjectName(QStringLiteral("SelectMagbyButton"));
        SelectMagbyButton->setGeometry(QRect(165, 345, 115, 28));
        MagbyPackName = new QLabel(MagbyPackage);
        MagbyPackName->setObjectName(QStringLiteral("MagbyPackName"));
        MagbyPackName->setGeometry(QRect(10, 10, 265, 50));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        MagbyPackName->setFont(font1);
        MagbyPackName->setAlignment(Qt::AlignCenter);
        MagbyPic = new QLabel(MagbyPackage);
        MagbyPic->setObjectName(QStringLiteral("MagbyPic"));
        MagbyPic->setGeometry(QRect(10, 60, 265, 151));
        MagbyPic->setFrameShape(QFrame::Box);
        MagbyPic->setLineWidth(3);
        MagbyStartLoc = new QLabel(MagbyPackage);
        MagbyStartLoc->setObjectName(QStringLiteral("MagbyStartLoc"));
        MagbyStartLoc->setGeometry(QRect(10, 215, 265, 41));
        QFont font2;
        font2.setPointSize(10);
        MagbyStartLoc->setFont(font2);
        MagbyLine1 = new QFrame(MagbyPackage);
        MagbyLine1->setObjectName(QStringLiteral("MagbyLine1"));
        MagbyLine1->setGeometry(QRect(10, 250, 265, 16));
        MagbyLine1->setFrameShadow(QFrame::Plain);
        MagbyLine1->setLineWidth(3);
        MagbyLine1->setFrameShape(QFrame::HLine);
        MagbyNumDest = new QLabel(MagbyPackage);
        MagbyNumDest->setObjectName(QStringLiteral("MagbyNumDest"));
        MagbyNumDest->setGeometry(QRect(10, 265, 265, 31));
        MagbyNumDest->setFont(font2);
        MagbyLine2 = new QFrame(MagbyPackage);
        MagbyLine2->setObjectName(QStringLiteral("MagbyLine2"));
        MagbyLine2->setGeometry(QRect(10, 295, 265, 16));
        MagbyLine2->setFrameShadow(QFrame::Plain);
        MagbyLine2->setLineWidth(3);
        MagbyLine2->setFrameShape(QFrame::HLine);
        MagbyFoodOptions = new QLabel(MagbyPackage);
        MagbyFoodOptions->setObjectName(QStringLiteral("MagbyFoodOptions"));
        MagbyFoodOptions->setGeometry(QRect(10, 310, 265, 21));
        MagbyFoodOptions->setFont(font2);
        MagmarPackage = new QGroupBox(mainPage);
        MagmarPackage->setObjectName(QStringLiteral("MagmarPackage"));
        MagmarPackage->setGeometry(QRect(310, 100, 285, 381));
        MagmarPackage->setStyleSheet(QStringLiteral("background-color:#ffe699;"));
        SelectMagmarButton = new QPushButton(MagmarPackage);
        SelectMagmarButton->setObjectName(QStringLiteral("SelectMagmarButton"));
        SelectMagmarButton->setGeometry(QRect(165, 345, 115, 28));
        MagmarPackName = new QLabel(MagmarPackage);
        MagmarPackName->setObjectName(QStringLiteral("MagmarPackName"));
        MagmarPackName->setGeometry(QRect(10, 10, 265, 50));
        MagmarPackName->setFont(font1);
        MagmarPackName->setAlignment(Qt::AlignCenter);
        MagmarPic = new QLabel(MagmarPackage);
        MagmarPic->setObjectName(QStringLiteral("MagmarPic"));
        MagmarPic->setGeometry(QRect(10, 60, 265, 151));
        MagmarPic->setFrameShape(QFrame::Box);
        MagmarPic->setLineWidth(3);
        MagmarStartLoc = new QLabel(MagmarPackage);
        MagmarStartLoc->setObjectName(QStringLiteral("MagmarStartLoc"));
        MagmarStartLoc->setGeometry(QRect(10, 215, 265, 41));
        MagmarStartLoc->setFont(font2);
        MagmarLine1 = new QFrame(MagmarPackage);
        MagmarLine1->setObjectName(QStringLiteral("MagmarLine1"));
        MagmarLine1->setGeometry(QRect(10, 250, 265, 16));
        MagmarLine1->setFrameShadow(QFrame::Plain);
        MagmarLine1->setLineWidth(3);
        MagmarLine1->setFrameShape(QFrame::HLine);
        MagmarNumDest = new QLabel(MagmarPackage);
        MagmarNumDest->setObjectName(QStringLiteral("MagmarNumDest"));
        MagmarNumDest->setGeometry(QRect(10, 265, 265, 31));
        MagmarNumDest->setFont(font2);
        MagmarLine2 = new QFrame(MagmarPackage);
        MagmarLine2->setObjectName(QStringLiteral("MagmarLine2"));
        MagmarLine2->setGeometry(QRect(10, 295, 265, 16));
        MagmarLine2->setFrameShadow(QFrame::Plain);
        MagmarLine2->setLineWidth(3);
        MagmarLine2->setFrameShape(QFrame::HLine);
        MagmarFoodOptions = new QLabel(MagmarPackage);
        MagmarFoodOptions->setObjectName(QStringLiteral("MagmarFoodOptions"));
        MagmarFoodOptions->setGeometry(QRect(10, 310, 265, 21));
        MagmarFoodOptions->setFont(font2);
        MagmortarPackage = new QGroupBox(mainPage);
        MagmortarPackage->setObjectName(QStringLiteral("MagmortarPackage"));
        MagmortarPackage->setGeometry(QRect(605, 100, 285, 381));
        MagmortarPackage->setStyleSheet(QStringLiteral("background-color:#ffa500;"));
        SelectMagmortarButton = new QPushButton(MagmortarPackage);
        SelectMagmortarButton->setObjectName(QStringLiteral("SelectMagmortarButton"));
        SelectMagmortarButton->setGeometry(QRect(165, 345, 115, 28));
        MagmortarPackName = new QLabel(MagmortarPackage);
        MagmortarPackName->setObjectName(QStringLiteral("MagmortarPackName"));
        MagmortarPackName->setGeometry(QRect(10, 10, 265, 50));
        MagmortarPackName->setFont(font1);
        MagmortarPackName->setAlignment(Qt::AlignCenter);
        MagmortarPic = new QLabel(MagmortarPackage);
        MagmortarPic->setObjectName(QStringLiteral("MagmortarPic"));
        MagmortarPic->setGeometry(QRect(10, 60, 265, 151));
        MagmortarPic->setFrameShape(QFrame::Box);
        MagmortarPic->setLineWidth(3);
        MagmortarStartLoc = new QLabel(MagmortarPackage);
        MagmortarStartLoc->setObjectName(QStringLiteral("MagmortarStartLoc"));
        MagmortarStartLoc->setGeometry(QRect(10, 215, 265, 41));
        MagmortarStartLoc->setFont(font2);
        MagmortarLine1 = new QFrame(MagmortarPackage);
        MagmortarLine1->setObjectName(QStringLiteral("MagmortarLine1"));
        MagmortarLine1->setGeometry(QRect(10, 250, 265, 16));
        MagmortarLine1->setFrameShadow(QFrame::Plain);
        MagmortarLine1->setLineWidth(3);
        MagmortarLine1->setFrameShape(QFrame::HLine);
        MagmortarNumDest = new QLabel(MagmortarPackage);
        MagmortarNumDest->setObjectName(QStringLiteral("MagmortarNumDest"));
        MagmortarNumDest->setGeometry(QRect(10, 265, 265, 31));
        MagmortarNumDest->setFont(font2);
        MagmortarLine2 = new QFrame(MagmortarPackage);
        MagmortarLine2->setObjectName(QStringLiteral("MagmortarLine2"));
        MagmortarLine2->setGeometry(QRect(10, 295, 265, 16));
        MagmortarLine2->setFrameShadow(QFrame::Plain);
        MagmortarLine2->setLineWidth(3);
        MagmortarLine2->setFrameShape(QFrame::HLine);
        MagmortarFoodOptions = new QLabel(MagmortarPackage);
        MagmortarFoodOptions->setObjectName(QStringLiteral("MagmortarFoodOptions"));
        MagmortarFoodOptions->setGeometry(QRect(10, 310, 265, 21));
        MagmortarFoodOptions->setFont(font2);
        ShinyMagmarPackage = new QGroupBox(mainPage);
        ShinyMagmarPackage->setObjectName(QStringLiteral("ShinyMagmarPackage"));
        ShinyMagmarPackage->setGeometry(QRect(900, 100, 285, 381));
        ShinyMagmarPackage->setStyleSheet(QStringLiteral("background-color:#ffb399;"));
        SelectShinyMagmarButton = new QPushButton(ShinyMagmarPackage);
        SelectShinyMagmarButton->setObjectName(QStringLiteral("SelectShinyMagmarButton"));
        SelectShinyMagmarButton->setGeometry(QRect(165, 345, 115, 28));
        ShinyMagmarPackName = new QLabel(ShinyMagmarPackage);
        ShinyMagmarPackName->setObjectName(QStringLiteral("ShinyMagmarPackName"));
        ShinyMagmarPackName->setGeometry(QRect(10, 10, 265, 50));
        ShinyMagmarPackName->setFont(font1);
        ShinyMagmarPackName->setAlignment(Qt::AlignCenter);
        ShinyMagmarPic = new QLabel(ShinyMagmarPackage);
        ShinyMagmarPic->setObjectName(QStringLiteral("ShinyMagmarPic"));
        ShinyMagmarPic->setGeometry(QRect(10, 60, 265, 151));
        ShinyMagmarPic->setFrameShape(QFrame::Box);
        ShinyMagmarPic->setLineWidth(3);
        ShinyMagmarStartLoc = new QLabel(ShinyMagmarPackage);
        ShinyMagmarStartLoc->setObjectName(QStringLiteral("ShinyMagmarStartLoc"));
        ShinyMagmarStartLoc->setGeometry(QRect(10, 215, 265, 41));
        ShinyMagmarStartLoc->setFont(font2);
        ShinyMagmarLine1 = new QFrame(ShinyMagmarPackage);
        ShinyMagmarLine1->setObjectName(QStringLiteral("ShinyMagmarLine1"));
        ShinyMagmarLine1->setGeometry(QRect(10, 250, 265, 16));
        ShinyMagmarLine1->setFrameShadow(QFrame::Plain);
        ShinyMagmarLine1->setLineWidth(3);
        ShinyMagmarLine1->setFrameShape(QFrame::HLine);
        ShinyMagmarNumDest = new QLabel(ShinyMagmarPackage);
        ShinyMagmarNumDest->setObjectName(QStringLiteral("ShinyMagmarNumDest"));
        ShinyMagmarNumDest->setGeometry(QRect(10, 265, 265, 31));
        ShinyMagmarNumDest->setFont(font2);
        ShinyMagmarLine2 = new QFrame(ShinyMagmarPackage);
        ShinyMagmarLine2->setObjectName(QStringLiteral("ShinyMagmarLine2"));
        ShinyMagmarLine2->setGeometry(QRect(10, 295, 265, 16));
        ShinyMagmarLine2->setFrameShadow(QFrame::Plain);
        ShinyMagmarLine2->setLineWidth(3);
        ShinyMagmarLine2->setFrameShape(QFrame::HLine);
        ShinyMagmarFoodOptions = new QLabel(ShinyMagmarPackage);
        ShinyMagmarFoodOptions->setObjectName(QStringLiteral("ShinyMagmarFoodOptions"));
        ShinyMagmarFoodOptions->setGeometry(QRect(10, 310, 265, 21));
        ShinyMagmarFoodOptions->setFont(font2);
        stackedWidget->addWidget(mainPage);

        retranslateUi(traveler);

        QMetaObject::connectSlotsByName(traveler);
    } // setupUi

    void retranslateUi(QWidget *traveler)
    {
        traveler->setWindowTitle(QApplication::translate("traveler", "Traveler Window", nullptr));
        pushButtonGroup->setTitle(QString());
        travelPackButton->setText(QApplication::translate("traveler", "TRAVEL PACKAGES", nullptr));
        destinationsAvailButton->setText(QApplication::translate("traveler", "Destinations Available", nullptr));
        foodOptionsButton->setText(QApplication::translate("traveler", "Food Options Available", nullptr));
        logoutButton->setText(QApplication::translate("traveler", "LOGOUT", nullptr));
        managerImage->setText(QString());
        MagbyPackage->setTitle(QString());
        SelectMagbyButton->setText(QApplication::translate("traveler", "Select Package", nullptr));
        MagbyPackName->setText(QApplication::translate("traveler", "Magby \"Baby\" Package", nullptr));
        MagbyPic->setText(QApplication::translate("traveler", "Picture Goes Here", nullptr));
        MagbyStartLoc->setText(QApplication::translate("traveler", "Starting Location: Paris", nullptr));
        MagbyNumDest->setText(QApplication::translate("traveler", "Number of Destinations: 11", nullptr));
        MagbyFoodOptions->setText(QApplication::translate("traveler", "Food Options: Custom", nullptr));
        MagmarPackage->setTitle(QString());
        SelectMagmarButton->setText(QApplication::translate("traveler", "Select Package", nullptr));
        MagmarPackName->setText(QApplication::translate("traveler", "Magmar Package", nullptr));
        MagmarPic->setText(QApplication::translate("traveler", "Picture Goes Here", nullptr));
        MagmarStartLoc->setText(QApplication::translate("traveler", "Starting Location: Paris", nullptr));
        MagmarNumDest->setText(QApplication::translate("traveler", "Number of Destinations: 13", nullptr));
        MagmarFoodOptions->setText(QApplication::translate("traveler", "Food Options: Custom", nullptr));
        MagmortarPackage->setTitle(QString());
        SelectMagmortarButton->setText(QApplication::translate("traveler", "Select Package", nullptr));
        MagmortarPackName->setText(QApplication::translate("traveler", "Magmortar Package", nullptr));
        MagmortarPic->setText(QApplication::translate("traveler", "Picture Goes Here", nullptr));
        MagmortarStartLoc->setText(QApplication::translate("traveler", "Starting Location: London", nullptr));
        MagmortarNumDest->setText(QApplication::translate("traveler", "Number of Destinations: Custom", nullptr));
        MagmortarFoodOptions->setText(QApplication::translate("traveler", "Food Options: Custom", nullptr));
        ShinyMagmarPackage->setTitle(QString());
        SelectShinyMagmarButton->setText(QApplication::translate("traveler", "Select Package", nullptr));
        ShinyMagmarPackName->setText(QApplication::translate("traveler", "Shiny Magmar Package", nullptr));
        ShinyMagmarPic->setText(QApplication::translate("traveler", "Picture Goes Here", nullptr));
        ShinyMagmarStartLoc->setText(QApplication::translate("traveler", "Starting Location: Custom", nullptr));
        ShinyMagmarNumDest->setText(QApplication::translate("traveler", "Number of Destinations: Custom", nullptr));
        ShinyMagmarFoodOptions->setText(QApplication::translate("traveler", "Food Options: Custom", nullptr));
    } // retranslateUi

};

namespace Ui {
    class traveler: public Ui_traveler {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRAVELER_H
