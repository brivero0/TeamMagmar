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

void tConfirmParis::getCityNum(int total)
{
    cityNum = total;
    qDebug() << cityNum;
    sortedDestinations= new QString[cityNum];
    sortedDistance = new int[cityNum];
}

void tConfirmParis::generateList()
{
    QString idValue;
    int destValue;
    sortedDestinations[0] = startCity;
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

    for(int i = 0; i < cityNum; i++)
           {
               qDebug() << sortedDestinations[i];

               ui->cityList->addItem(sortedDestinations[i]);
           }
}

void tConfirmParis::on_startSimulationBtn1_clicked()
{
    tTravelSimulationWindow1 = new tTravelSimulation();

    tTravelSimulationWindow1->show();

    this->close();
}

void tConfirmParis::on_cancelButton_clicked()
{
    this->close();
}
