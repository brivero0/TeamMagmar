#include "tconfirmcustom.h"
#include "ui_tconfirmcustom.h"

tConfirmCustom::tConfirmCustom(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tConfirmCustom)
{
    ui->setupUi(this);
}

tConfirmCustom::~tConfirmCustom()
{
    delete ui;
}

void tConfirmCustom::on_startSimulationBtn2_clicked()
{
    tTravelSimulationWindow2 = new tTravelSimulation();
    tTravelSimulationWindow2->show();

    this->close();
}
