#ifndef TRAVELER_H
#define TRAVELER_H

#include <QWidget>

#include "tDestinations.h"
#include "tFoods.h"
#include "tconfirmparis.h"
#include "tconfirmcustom.h"

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

    void on_SelectMagmarButton_clicked();

    void on_SelectMagmortarButton_clicked();

    void on_SelectShinyMagmarButton_clicked();

private:
    Ui::traveler*ui;

    tDestinations tDestinationsWindow;
    tFoods        tFoodsWindow;

    tConfirmParis * tConfirmWindow;
    tConfirmCustom * tConfirmWindow2;

};

#endif // TRAVELER_H
