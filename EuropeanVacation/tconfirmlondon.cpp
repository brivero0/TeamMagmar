#include "tconfirmlondon.h"
#include "ui_tconfirmlondon.h"
#include "ttravelsimulation.h"

tConfirmLondon::tConfirmLondon(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tConfirmLondon)
{
    ui->setupUi(this);
}

tConfirmLondon::~tConfirmLondon()
{
    delete ui;
}

void tConfirmLondon::on_startSimulationButton_clicked()
{
    tTravelSimulationWindow1 = new tTravelSimulation();
    tTravelSimulationWindow1->show();
    this->close();
}

void tConfirmLondon::on_cancelButton_clicked()
{
    this->close();
}
