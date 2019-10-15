#include "traveler.h"
#include "ui_traveler.h"
#include "login.h"

#include "tconfirmparis.h"
#include "tconfirmcustom.h"
#include "tconfirmlondon.h"
#include <QSqlDatabase>
#include <QSql>
#include <QSqlQuery>

#include <QDebug>

// Default Constructor
traveler::traveler(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::traveler)
{
    ui->setupUi(this);

    // Create a stacked widget index for seperate QWidget pages
    ui->stackedWidget->insertWidget(1, &tDestinationsWindow);
    ui->stackedWidget->insertWidget(2, &tFoodsWindow);

    myDB = QSqlDatabase::database();
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

void traveler::on_SelectMagbyButton_clicked()
{
    int total = 11;
    tConfirmWindow = new tConfirmParis();
    tConfirmWindow->getCityNum(total);
    tConfirmWindow->generateList();
    tConfirmWindow->show();

}

void traveler::on_SelectMagmarButton_clicked()
{
    QString paris = "Paris";
    QSqlQuery query;
    query.prepare("SELECT *"
                  "FROM Distances");
    int size = 1;

//    query.exec();
    while(query.next())
    {
       size++;
    }
    qDebug() << size << ' ' ;
    if(size > 11)
    {
        QMessageBox::information(this, "Sorry", "Sorry, this package is currently unavailable.", QMessageBox::Ok);
        return;
    }
    else
    {
        int total = 13;
        tConfirmWindow = new tConfirmParis();
        tConfirmWindow->getCityNum(total);
        tConfirmWindow->generateList();
        tConfirmWindow->show();
    }
}

void traveler::on_SelectMagmortarButton_clicked()
{
    tConfirmWindow2 = new tConfirmLondon();
    tConfirmWindow2->show();
}

void traveler::on_SelectShinyMagmarButton_clicked()
{
   tConfirmWindow3 = new tConfirmCustom();
    tConfirmWindow3->show();
}
