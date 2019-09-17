#include "tDestinations.h"
#include "ui_tDestinations.h"

// Default Constructor
tDestinations::tDestinations(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tDestinations)
{
    ui->setupUi(this);

    myDB = QSqlDatabase::database();
}

// Destructor
tDestinations::~tDestinations()
{
    delete ui;
}

