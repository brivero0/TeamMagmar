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

    QSqlQueryModel * model = new QSqlQueryModel;
    QSqlQueryModel * table = new QSqlQueryModel;

    table->setHeaderData(0, Qt::Horizontal, QObject::tr("Food Name"));
    table->setHeaderData(1, Qt::Horizontal, QObject::tr("Name"));

    table->setQuery("SELECT foodName, Price "
                    "FROM Food "
                    "WHERE City = '"+start+"'");

    model->setQuery("SELECT DISTINCT City "
                    "FROM Food ");



    ui->tFoodOptionsTV->verticalHeader()->setVisible(false);
    ui->tFoodOptionsTV->setModel(table);
    ui->tCityList->setModel(model);
    ui->tFoodOptionsTV->setCornerButtonEnabled(true);

}


void tFoods::on_tCityList_currentIndexChanged(const QString &arg1)
{
    QSqlQueryModel * model = new QSqlQueryModel;
    model->setQuery("SELECT foodName, Price "
                    "FROM Food "
                    "WHERE City = '"+arg1+"'");

    ui->tFoodOptionsTV->setModel(model);
}
