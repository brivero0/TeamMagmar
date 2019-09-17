#include "tDestinations.h"
#include "ui_tDestinations.h"

// Default Constructor
tDestinations::tDestinations(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tDestinations)
{
    ui->setupUi(this);

    myDB = QSqlDatabase::database();

    defualtReset();
}

// Destructor
tDestinations::~tDestinations()
{
    delete ui;
}
//model->setHEaderData(#. Qt::horizontal, QObject::tr(""))
void tDestinations::tDestinations::defualtReset()
{
    QSqlQueryModel * model = new QSqlQueryModel;

    model->setQuery("SELECT * "
                    "FROM Distances "
                    "WHERE Start = '"+startCity+"'");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Starting location"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Destination"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Distance(km)"));

    ui->tDestinationOptionsTV->verticalHeader()->setVisible(false);
    ui->tDestinationOptionsTV->setModel(model);
    ui->tDestinationOptionsTV->setCornerButtonEnabled(true);
}
