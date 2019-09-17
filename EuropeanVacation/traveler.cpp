#include "traveler.h"
#include "ui_traveler.h"
#include "login.h"

// Default Constructor
traveler::traveler(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::traveler)
{
    ui->setupUi(this);

    // Create a stacked widget index for seperate QWidget pages
    ui->stackedWidget->insertWidget(1, &tDestinationsWindow);
    ui->stackedWidget->insertWidget(2, &tFoodsWindow);
}

// Destructor
traveler::~traveler()
{
    delete ui;
}

/****************************************************************************
 * METHOD - on_travelPackButton_clicked
 * --------------------------------------------------------------------------
 * When the Travel Packages button is clicked, the stackedWidget index
 * changes to display the travel packages available.
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      No parameters are required.
 *
 * POST-CONDITIONS
 *      ==> Returns nothing.
 *      ==> Displays Travel Packages available
 ***************************************************************************/
void traveler::on_travelPackButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

/****************************************************************************
 * METHOD - on_destinationsAvailButton_clicked
 * --------------------------------------------------------------------------
 * When the Destinations Available button is clicked, the stackedWidget
 * index changes to display the page showing all European travel
 * destinations available.
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      No parameters are required.
 *
 * POST-CONDITIONS
 *      ==> Returns nothing.
 *      ==> Displays Destinations Available QWidget
 ***************************************************************************/
void traveler::on_destinationsAvailButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

/****************************************************************************
 * METHOD - on_foodOptionsButton_clicked
 * --------------------------------------------------------------------------
 * When the Food Options button is clicked, the stackedWidget index
 * changes to display the page showing foods available for each of the
 * destinations available.
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      No parameters are required.
 *
 * POST-CONDITIONS
 *      ==> Returns nothing.
 *      ==> Displays Food Options QWidget
 ***************************************************************************/
void traveler::on_foodOptionsButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

/****************************************************************************
 * METHOD - on_logoutButton_clicked
 * --------------------------------------------------------------------------
 * When the logout button is clicked, traveler's window closes.
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      No parameters are required.
 *
 * POST-CONDITIONS
 *      ==> Returns nothing.
 *      ==> Closes Traveler's Window (returns control to login window)
 ***************************************************************************/
void traveler::on_logoutButton_clicked()
{
    this->close();
}

