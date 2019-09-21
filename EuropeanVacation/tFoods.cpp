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
    QString start = ui->tCityList->currentText();

    QSqlQueryModel * model = new QSqlQueryModel();

    model->setQuery("SELECT foodName, Price "
                 "FROM Food "
                 "WHERE City = '"+start+"'");


    ui->tFoodOptionsTV->setModel(model);
    ui->tFoodOptionsTV->verticalHeader()->setVisible(false);
    ui->tFoodOptionsTV->setCornerButtonEnabled(true);

    QSqlQueryModel * list = new QSqlQueryModel();

    list->setQuery("SELECT DISTINCT City "
                   "FROM Food ");

    ui->tCityList->setModel(list);


}


void tFoods::on_tCityList_currentIndexChanged(const QString &arg1)
{
    QSqlQueryModel * model = new QSqlQueryModel;
    model->setQuery("SELECT foodName, Price "
                    "FROM Food "
                    "WHERE City = '"+arg1+"'");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Name"));

    ui->tFoodOptionsTV->setModel(model);
}
