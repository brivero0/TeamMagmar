#include "tconfirmparis.h"
#include "ttravelsimulation.h"
#include "ui_tconfirmparis.h"
#include <QSqlQuery>
#include <QSql>

tConfirmParis::tConfirmParis(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tConfirmParis)
{
    ui->setupUi(this);
    myDB = QSqlDatabase::database();
//    generateList();
}

tConfirmParis::~tConfirmParis()
{
    delete ui;
}

/****************************************************************************
 * METHOD - getCityNum
 * --------------------------------------------------------------------------
 * This method sets the cityNum to total and initializes sortedDestinations
 * and sortedDistance.
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      ==> An integer representing
 *
 * POST-CONDITIONS
 *      ==> Returns nothing.
 *      ==> Sets cityNum equal to total
 *      ==> Initializes 2 dynamic arrays of size cityNum
 ***************************************************************************/

void tConfirmParis::getCityNum(int total)
{
    cityNum = total;
    qDebug() << cityNum;
    sortedDestinations= new QString[cityNum];
    sortedDistance = new int[cityNum];
}

/****************************************************************************
 * METHOD - generateList
 * --------------------------------------------------------------------------
 * This method accesses the data base and queries it to get all entries
 * where Paris is in the first collumn, sorts them ascending distance and
 * puts them into a Qlist.
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      No parameters are required.
 *
 * POST-CONDITIONS
 *      ==> Returns nothing.
 *      ==> Populates a list view with all cities from
 *          paris and the distances between them
 ***************************************************************************/

void tConfirmParis::generateList()
{
    QString idValue;
    int destValue;
    sortedDestinations[0] = startCity;

    /************************************************************************
     * PROCESS: Queries the database to find the closest city to paris and
     *          stores its data in sortedDestinations and sortedDistance
     *          as long as the closest city has not been visited before.
     ***********************************************************************/
    for(int i = 1; i < cityNum; i++)
    {
        QSqlQuery qry;
        qry.prepare("SELECT * "
                    "FROM Distances "
                    "WHERE Start = '"+startCity+"'"
                    "ORDER BY Kilometers ASC");
        qry.exec();
        qry.next();

        idValue = qry.value(1).toString();
        destValue = qry.value(2).toInt();

        /************************************************************************
         * PROCESS: checks if the the city in idValue is in the
         *          sortedDestinations array and selects the next closest city
         *          if they are the same. Checks every city in the array
         ***********************************************************************/
        for(int j=0; j<i; j++)
        {
            //qDebug() <<"here" << arr[j] << " " << idValue;
            if (idValue==sortedDestinations[j])
            {
                //qDebug() <<"arr[j" << arr[j];
                qry.next();
                idValue = qry.value(1).toString();
                destValue = qry.value(2).toInt();
                j=-1;
            }
        }
        qDebug() << "ID VALUE" << idValue << "dst" << destValue;

        sortedDestinations[i] = idValue;
        sortedDistance[i] = destValue;
        startCity = idValue; //assign test city to the new city
    }

    /************************************************************************
     * PROCESS: Copy contents of sortedDestinations into cityList,
     *          a QListWidget.
     ***********************************************************************/
    for(int i = 0; i < cityNum; i++)
    {
        qDebug() << sortedDestinations[i];
        ui->cityList->addItem(sortedDestinations[i]);
    }
}

void tConfirmParis::on_startSimulationBtn1_clicked()
{
    tTravelSimulationWindow1 = new tTravelSimulation(sortedDestinations, sortedDistance, cityNum);
    tTravelSimulationWindow1->show();
    this->close();
}

void tConfirmParis::on_cancelButton_clicked()
{
    this->close();
}
