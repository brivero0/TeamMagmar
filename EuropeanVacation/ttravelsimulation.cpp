#include "ttravelsimulation.h"
#include "ui_ttravelsimulation.h"
#include "tconfirmparis.h"
#include <QMessageBox>

tTravelSimulation::tTravelSimulation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tTravelSimulation)
{
    ui->setupUi(this);
}

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
    for(int i = 0; i < total; i++)
    {
//      qDebug() << sortedDestinations[i] << ' ' << sortedDistance[i];
        qDebug() << "Total: " << total;
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

void tTravelSimulation::on_endVacationButton_clicked()
{
    this->close();
}
