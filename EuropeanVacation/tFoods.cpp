#include "tFoods.h"
#include "ui_tFoods.h"

tFoods::tFoods(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tFoods)
{
    ui->setupUi(this);

    myDB = QSqlDatabase::database();

    defaultReset();

}

tFoods::~tFoods()
{
    delete ui;
}

void tFoods::tFoods::defaultReset()
{

    QSqlQueryModel * model = new QSqlQueryModel;

    model->setQuery("SELECT * "
                    "FROM Food ");

    ui->tFoodOptionsTV->setModel(model);


}

