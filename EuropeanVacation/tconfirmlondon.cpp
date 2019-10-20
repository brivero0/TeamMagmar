#include "tconfirmlondon.h"
#include "ui_tconfirmlondon.h"
#include "ttravelsimulation.h"

/****************************************************************************
 * Constructor - tConfirmLondon
 * --------------------------------------------------------------------------
 * When this window opens, the constructor determines how many cities are currently in the
 * database and sets the maximum value of the spin box to the # of cities in the DB. It
 * also sets the minimum value to 2 (since 2 cities are required for travel). It also
 * sets the starting city in London.
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *     Database has cities to do a row count.
 *
 * POST-CONDITIONS
 *      ==> Spin box values are populated based on # of cities in DB.
 ***************************************************************************/

tConfirmLondon::tConfirmLondon(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tConfirmLondon)
{
    ui->setupUi(this);

    QSqlQuery qry;
    QString testCity = "London";
    qry.prepare("SELECT * "
                "FROM Distances "
                "WHERE Start = '"+testCity+"'"
                "ORDER BY Kilometers ASC");
        rowCount = 1;

        qry.exec();
        while(qry.next())
        {
           rowCount++;
        }


    ui->numCitiesSpinBox->setMinimum(2);
    //qDebug() << "ROW COUNT: " << rowCount;
    ui->numCitiesSpinBox->setMaximum(rowCount);
    on_numCitiesSpinBox_valueChanged();

}

/****************************************************************************
 * Destructor - tConfirmLondon
 * --------------------------------------------------------------------------
 * Deletes ui
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *     None
 *
 * POST-CONDITIONS
 *      ==> Deletes ui
 ***************************************************************************/

tConfirmLondon::~tConfirmLondon()
{
    delete ui;
}

/****************************************************************************
 * METHOD - on_startSimulationButton_clicked
 * --------------------------------------------------------------------------
 * When this button is clicked, the travel simulation window opens and populates
 * cities and distances between each city based on the cities selected in the
 * london window.
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      Cities, distances and the number of cities selected will be passed to the
 *      travel simuation.
 *
 * POST-CONDITIONS
 *      ==> Returns nothing.
 *      ==> Displays Travel Simulation Window
 ***************************************************************************/
void tConfirmLondon::on_startSimulationButton_clicked()
{
    tTravelSimulationWindow1 = new tTravelSimulation(p,d,number);
    //qDebug() << "rowCount: " << rowCount;
    tTravelSimulationWindow1->show();
    p=nullptr;
    d=nullptr;
    this->close();

}

/****************************************************************************
 * METHOD - on_cancelButton_clicked
 * --------------------------------------------------------------------------
 * When this button is clicked, the confirmation window closes.
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *     None
 *
 * POST-CONDITIONS
 *      ==> Returns nothing.
 *      ==> Closes window
 ***************************************************************************/

void tConfirmLondon::on_cancelButton_clicked()
{
    this->close();
}


/****************************************************************************
 * METHOD - on_numCitiesSpinBox_valueChanged()
 * --------------------------------------------------------------------------
 * When the spinbox value changes, this function will update the number of cities
 * included in the trip.
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *     None
 *
 * POST-CONDITIONS
 *      ==> Updates the number of cities included in the trip, and stores the cities and their
 *      distances in a dynamic array (to pass to travel simulation).
 *
 ***************************************************************************/
void tConfirmLondon::on_numCitiesSpinBox_valueChanged()
{

    ui->LondonListWidget->clear();

    QString start = "London";

    number = ui->numCitiesSpinBox->value();

    QString testCity;
    testCity = "London";

    p = new QString[rowCount]; // dynamic array to store cities
    d = new int[rowCount]; // dynamic array to store distances

    p[0] = testCity;
    d[0] = 0;

    for(int i = 1; i<number;i++)
    {
        QSqlQuery qry;
        qry.prepare("SELECT * "
                    "FROM Distances "
                    "WHERE Start = '"+testCity+"'"
                    "ORDER BY Kilometers ASC");
        qry.exec();
        qry.next();

       QString idValue = qry.value(1).toString();
       int distance =  qry.value(2).toInt();

      for(int j=0; j<i; j++)
      {
          //qDebug() <<"here" << arr[j] << " " << idValue;
          if (idValue==p[j])
          {
              //qDebug() <<"arr[j" << arr[j];
              qry.next();
              idValue = qry.value(1).toString();
              distance = qry.value(2).toInt();
              j=-1;
          }

      }



        //qDebug() << "ID VALUE" << idValue;

        p[i] = idValue;
        d[i] = distance;

        testCity = idValue; //assign test city to the new city

    }

        qDebug() << "Printing array";

       for(int i = 0; i < number; i++)
       {
           qDebug() << p[i];         
          ui->LondonListWidget->addItem(p[i]);
       }

       for(int i = 0; i < number; i++)
       {
           qDebug() << d[i];
       }

       ui->LondonListWidget->show();

}




