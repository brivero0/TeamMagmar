#include "aFoods.h"
#include "ui_aFoods.h"

// Default constructor
aFoods::aFoods(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::aFoods)
{
    ui->setupUi(this);

    myDB = QSqlDatabase::database();
}

// Destructor
aFoods::~aFoods()
{
    delete ui;
}
