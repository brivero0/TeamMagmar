#include "ttravelsimulation.h"
#include "ui_ttravelsimulation.h"
#include "tconfirmparis.h"
#include <QMessageBox>

tTravelSimulation::tTravelSimulation(QString* cList, int* dList, int t, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tTravelSimulation), destinations(cList), distances(dList), total(t)
{
    ui->setupUi(this);
    tTravelSimulation::loadTables();
}

tTravelSimulation::~tTravelSimulation()
{
    delete ui;
}

void tTravelSimulation::loadTables()
{
    for(int i = 0; i < 11; i++)
    {
//      qDebug() << sortedDestinations[i] << ' ' << sortedDistance[i];

//        ui->cityList->addItem(sortedDestinations[i]);
//      ui->cityList_2->addItem(QString::number(sortedDistance[i]));
        ui->listWidget->addItem(destinations[i]);
        ui->listWidget_2->addItem(QString::number(distances[i]));
    }
}

void tTravelSimulation::on_exitSimulationButton_clicked()
{
    QMessageBox::information(this,"Cancel","Sad to see you go!", QMessageBox::Ok);

    this->close();
}
