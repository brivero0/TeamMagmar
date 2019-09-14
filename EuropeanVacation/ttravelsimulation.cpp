#include "ttravelsimulation.h"
#include "ui_ttravelsimulation.h"
#include <QMessageBox>

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

void tTravelSimulation::on_exitSimulationButton_clicked()
{


    QMessageBox::information(this,"Cancel","Sad to see you go!", QMessageBox::Ok);

    this->close();

}
