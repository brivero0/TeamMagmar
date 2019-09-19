#include "tconfirmparis.h"
#include "ttravelsimulation.h"
#include "ui_tconfirmparis.h"

tConfirmParis::tConfirmParis(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tConfirmParis)
{
    ui->setupUi(this);
}

tConfirmParis::~tConfirmParis()
{
    delete ui;
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
