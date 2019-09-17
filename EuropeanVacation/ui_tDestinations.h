/********************************************************************************
** Form generated from reading UI file 'tDestinations.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TDESTINATIONS_H
#define UI_TDESTINATIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_tDestinations
{
public:
    QLabel *label;
    QTableView *tDestinationOptionsTV;

    void setupUi(QWidget *tDestinations)
    {
        if (tDestinations->objectName().isEmpty())
            tDestinations->setObjectName(QStringLiteral("tDestinations"));
        tDestinations->resize(1200, 640);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tDestinations->sizePolicy().hasHeightForWidth());
        tDestinations->setSizePolicy(sizePolicy);
        tDestinations->setMinimumSize(QSize(1200, 640));
        tDestinations->setMaximumSize(QSize(1200, 640));
        label = new QLabel(tDestinations);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 731, 50));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);
        label->setStyleSheet(QStringLiteral("color: blue;"));
        tDestinationOptionsTV = new QTableView(tDestinations);
        tDestinationOptionsTV->setObjectName(QStringLiteral("tDestinationOptionsTV"));
        tDestinationOptionsTV->setGeometry(QRect(10, 50, 551, 571));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(3);
        sizePolicy1.setVerticalStretch(3);
        sizePolicy1.setHeightForWidth(tDestinationOptionsTV->sizePolicy().hasHeightForWidth());
        tDestinationOptionsTV->setSizePolicy(sizePolicy1);
        tDestinationOptionsTV->setStyleSheet(QLatin1String("QHeaderView::section{\n"
"background-color:qlineargradient(spread:pad, x1:1, y1:1, x2:1, y2:0.028, stop:0 rgba(255, 170, 0, 255), stop:1 rgba(255, 62, 14, 255));\n"
"border-style: solid;\n"
"border-color: black;\n"
"border-width: 2px;\n"
"border-radius: 5px;}\n"
"\n"
"QTableView QTableCornerButton::section{\n"
"background: red;\n"
"broder: 2px outset black;\n"
"}"));
        tDestinationOptionsTV->setDragEnabled(true);

        retranslateUi(tDestinations);

        QMetaObject::connectSlotsByName(tDestinations);
    } // setupUi

    void retranslateUi(QWidget *tDestinations)
    {
        tDestinations->setWindowTitle(QApplication::translate("tDestinations", "Form", nullptr));
        label->setText(QApplication::translate("tDestinations", "Destinations Available ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class tDestinations: public Ui_tDestinations {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TDESTINATIONS_H
