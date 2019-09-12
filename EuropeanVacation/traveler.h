#ifndef TRAVELER_H
#define TRAVELER_H

#include <QWidget>

#include "tDestinations.h"
#include "tFoods.h"

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

private:
    Ui::traveler*ui;

    tDestinations tDestinationsWindow;
    tFoods        tFoodsWindow;
};

#endif // TRAVELER_H
