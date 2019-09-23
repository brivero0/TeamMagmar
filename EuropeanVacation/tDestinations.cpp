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
                    "WHERE Start = '"+startCity+"'"
                    " ORDER BY 3");
    QSqlQuery qry;
    qry.prepare("SELECT * "
                "FROM Distances "
                "WHERE Start = '"+startCity+"'"
                " ORDER BY 3");


    qry.exec();
    qry.next();
    QString thisString = qry.value(1).toString();
    qDebug() << "testing" << thisString;


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
    ui->tDestinationOptionsTV->setMinimumHeight(verticalHeaderHeight+rowTotalHeight + 20);
    ui->tDestinationOptionsTV->setMaximumHeight(verticalHeaderHeight+rowTotalHeight + 20);


    QVector<QString> test;
    test = recFun("Paris", 3);

    for(int i = 0; i < 3; i++)
        qDebug() << test[i];
}

QVector<QString> recFun(QString start, int destNum)
{
    QString newCity;
    int newDestNum;

    QVector<QString> temp;

    QSqlQuery qry;
    qry.prepare("SELECT * "
                "FROM Distances "
                "WHERE Start = '"+start+"'"
                " ORDER BY 3");

    qry.exec();
    qry.next();
    newCity = qry.value(1).toString();

    if(newCity==start)
    {
        qry.next();
        newCity = qry.value(1).toString();
    }

    newDestNum = destNum - 1;

    if(newDestNum == 0)
    {
        temp.push_front(newCity);
        return temp;
    }
    else
    {
        temp.append(recFun(newCity, newDestNum));
        return temp;
    }
}
