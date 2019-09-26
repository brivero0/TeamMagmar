#include "tDestinations.h"
#include "ui_tDestinations.h"
#include <QSqlQuery>
#include <QSql>

// Default Constructor
tDestinations::tDestinations(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tDestinations)
{
    ui->setupUi(this);

    myDB = QSqlDatabase::database();

    defaultReset();
}

// Destructor
tDestinations::~tDestinations()
{
    delete ui;
}

void tDestinations::tDestinations::defaultReset()
{
    QSqlQueryModel * model = new QSqlQueryModel;

    model->setQuery("SELECT * "
                    "FROM Distances "
                    "WHERE Start = '"+startCity+"'"
                    " ORDER BY 3");


    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Starting location"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Destination"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Distance(km)"));

    ui->tDestinationOptionsTV->verticalHeader()->setVisible(false);
    ui->tDestinationOptionsTV->setModel(model);

    int countH=ui->tDestinationOptionsTV->verticalHeader()->count();
    int horizontalHeaderHeight=ui->tDestinationOptionsTV->horizontalHeader()->height();
    int rowTotalHeight=0;
    for (int i = 0; i < countH; ++i) {
        rowTotalHeight+=ui->tDestinationOptionsTV->verticalHeader()->sectionSize(i);
    }
    ui->tDestinationOptionsTV->setMinimumHeight(horizontalHeaderHeight+rowTotalHeight + 20);
    ui->tDestinationOptionsTV->setMaximumHeight(horizontalHeaderHeight+rowTotalHeight + 20);

    int count=ui->tDestinationOptionsTV->horizontalHeader()->count();
    int verticalHeaderHeight=ui->tDestinationOptionsTV->verticalHeader()->height();
    int collumnTotalWidth=0;
    for (int i = 0; i < count; ++i) {
        collumnTotalWidth+=ui->tDestinationOptionsTV->verticalHeader()->sectionSize(i);
    }
    ui->tDestinationOptionsTV->setMinimumHeight(verticalHeaderHeight+collumnTotalWidth + 20);
    ui->tDestinationOptionsTV->setMaximumHeight(verticalHeaderHeight+collumnTotalWidth + 20);
}
