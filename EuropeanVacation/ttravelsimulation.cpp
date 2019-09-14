#include "ttravelsimulation.h"
#include "ui_ttravelsimulation.h"

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
