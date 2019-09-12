#include "aDestinations.h"
#include "ui_aDestinations.h"

//Default Constructor
aDestinations::aDestinations(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::aDestinations)
{
    ui->setupUi(this);
    //Create database and display the table
    myDB = QSqlDatabase::database();
}

//Destructor
aDestinations::~aDestinations()
{
    delete ui;
}
