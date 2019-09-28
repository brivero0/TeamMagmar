#include "ttravelsimulation.h"
#include "ui_ttravelsimulation.h"
#include <QMessageBox>
#include <QDebug>

tTravelSimulation::tTravelSimulation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tTravelSimulation)
{
    ui->setupUi(this);
}

tTravelSimulation::~tTravelSimulation()
{
    delete ui;
}

void tTravelSimulation::getList(QVector<QString> temp)
{
    simulationList = temp;
    int index = 0;

    while(index < simulationList.size())
    {
        ui->testListWidget->addItem(simulationList[index]);
        index++;
    }
}

void tTravelSimulation::on_exitSimulationButton_clicked()
{


    QMessageBox::information(this,"Cancel","Sad to see you go!", QMessageBox::Ok);

    this->close();

}
