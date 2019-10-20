#ifndef TRAVELER_H
#define TRAVELER_H

#include <QWidget>

#include "tDestinations.h"
#include "tFoods.h"
#include "tconfirmparis.h"
#include "tconfirmcustom.h"
#include "tconfirmlondon.h"

namespace Ui {
class traveler;
}

class traveler : public QWidget
{
    Q_OBJECT

public:
    explicit traveler(QWidget *parent = nullptr);
    ~traveler();

private slots:

    void on_travelPackButton_clicked();
    //!< Travel Packages page is displayed in stackedWidget

    void on_destinationsAvailButton_clicked();
    //!< European Destinations Available page is displayed in stackedWidget

    void on_foodOptionsButton_clicked();
    //!< Foods Options for cities page is displayed in stackedWidget

    void on_logoutButton_clicked();
    //!< Traveler window closes

    void on_SelectMagbyButton_clicked();
        //!< Paris 11 confirmation window opens

    void on_SelectMagmarButton_clicked();
        //!< Paris 13 confirmation window opens

    void on_SelectMagmortarButton_clicked();
        //!< London confirmation window opens

    void on_SelectShinyMagmarButton_clicked();
        //!< Custom confirmation window opens

private:
    Ui::traveler*ui;

    QSqlDatabase myDB;

    tDestinations tDestinationsWindow;
    tFoods        tFoodsWindow;

    tConfirmParis  * tConfirmWindow;
    tConfirmLondon * tConfirmWindow2;
    tConfirmCustom * tConfirmWindow3;

};

#endif // TRAVELER_H
