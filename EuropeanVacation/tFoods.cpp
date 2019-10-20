#include "tFoods.h"
#include "ui_tFoods.h"
#include"numberformatdelegate.h"

tFoods::tFoods(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tFoods)
{
    ui->setupUi(this);

    // Sets the format for the price
    ui->tFoodOptionsTV->setItemDelegateForColumn(1, new NumberFormatDelegate(this));

    myDB = QSqlDatabase::database();

    defaultReset();
}

tFoods::~tFoods()
{
    delete ui;
}

/*****************************************************************
 * METHOD - defaultReset()
 * --------------------------------------------------------------------------
 * This method sets the default food table and list
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      The following variables must be declared and initialized:
 *          none
 *
 * POST-CONDITIONS
 *      ==> Returns nothing - updates food table and list
 *****************************************************************/
void tFoods::tFoods::defaultReset()
{
    QString start = ui->tCityList->currentText();

    QSqlQueryModel * model = new QSqlQueryModel();

    // Gets the food name and their price for selected city
    model->setQuery("SELECT foodName, Price "
                 "FROM Food "
                 "WHERE City = '"+start+"'");


    ui->tFoodOptionsTV->setModel(model);
    ui->tFoodOptionsTV->verticalHeader()->setVisible(false);
    ui->tFoodOptionsTV->setCornerButtonEnabled(true);

    QSqlQueryModel * list = new QSqlQueryModel();

    // Gets the city in the database
    list->setQuery("SELECT DISTINCT City "
                          "FROM Food ");

    ui->tCityList->setModel(list);

        //dynamicly sets the width and height of the table to match the num of
        //   rows and columns

    QAbstractItemModel* tableModel = ui->tFoodOptionsTV->model();

    int w = ui->tFoodOptionsTV->verticalHeader()->width()+2;//change +2 if its too big or small
    for (int i = 0; i < tableModel->columnCount(); i++)
       w += ui->tFoodOptionsTV->columnWidth(i); // seems to include gridline
    int h = ui->tFoodOptionsTV->horizontalHeader()->height()+2;//change +2 if its too big or small
    for (int i = 0; i < tableModel->rowCount(); i++)
       h += ui->tFoodOptionsTV->rowHeight(i);

    ui->tFoodOptionsTV->setMinimumWidth(w);
    ui->tFoodOptionsTV->setMaximumWidth(w);

    ui->tFoodOptionsTV->setMinimumHeight(h);
    ui->tFoodOptionsTV->setMaximumHeight(h);
}

/*****************************************************************
 * METHOD - on_tCityList_currentIndexChanged(const QString &arg1)
 * --------------------------------------------------------------------------
 * This method will update the food table when user
 * chooses a different city from city list
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      The following variables must be declared and initialized:
 *          arg1 - name of city
 *
 * POST-CONDITIONS
 *      ==> Returns nothing - updates food table
 *****************************************************************/
void tFoods::on_tCityList_currentIndexChanged(const QString &arg1)
{
    QSqlQueryModel * model = new QSqlQueryModel;

    // Updates Table based on city selected
    model->setQuery("SELECT foodName, Price "
                    "FROM Food "
                    "WHERE City = '"+arg1+"'");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Name"));

    ui->tFoodOptionsTV->setModel(model);

    QAbstractItemModel* tableModel = ui->tFoodOptionsTV->model();

        //dynamicly sets the width and height of the table to match the num of
        //   rows and columns

    int w = ui->tFoodOptionsTV->verticalHeader()->width()+2;//change +2 if its too big or small
    for (int i = 0; i < tableModel->columnCount(); i++)
       w += ui->tFoodOptionsTV->columnWidth(i); // seems to include gridline
    int h = ui->tFoodOptionsTV->horizontalHeader()->height()+2;//change +2 if its too big or small
    for (int i = 0; i < tableModel->rowCount(); i++)
       h += ui->tFoodOptionsTV->rowHeight(i);

    ui->tFoodOptionsTV->setMinimumWidth(w);
    ui->tFoodOptionsTV->setMaximumWidth(w);

    ui->tFoodOptionsTV->setMinimumHeight(h);
    ui->tFoodOptionsTV->setMaximumHeight(h);
}
