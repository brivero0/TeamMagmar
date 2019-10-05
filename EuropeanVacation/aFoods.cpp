#include "aFoods.h"
#include "ui_aFoods.h"
#include "afooddialog.h"
#include "updatefood.h"
#include <QFileDialog>
#include <QFile>

// Default constructor
aFoods::aFoods(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::aFoods)
{
    ui->setupUi(this);

    myDB = QSqlDatabase::database();

    loadTableList();
    checkLines();

     ui->delButton->setEnabled(false);
     ui->updateButton->setEnabled(false);
}

// Destructor
aFoods::~aFoods()
{
    delete ui;
}

void aFoods::on_delButton_clicked()
{
    QModelIndex index = ui->foodLV->currentIndex();
    QString name = index.data(Qt::DisplayRole).toString();
//    qDebug() << name;
    afooddialog = new aFoodDialog(this, name);
    afooddialog->show();
    int confirm = afooddialog->exec();
//    qDebug()<<"Result: " << confirm;

    if(confirm == true)
    {
        QSqlQuery *qry = new QSqlQuery(myDB);

        qry->prepare("DELETE from Food "
                     "WHERE  foodName = '"+name+"' ");

        if(qry->exec())
        {
            QMessageBox::information(this, tr("Success"),tr("Food Successfully Deleted"));
            loadTableList();
            on_cancelAdd_clicked();
        }
        else
        {
            QMessageBox::critical(this, tr("Error"),"Could not delete " + name + " from database.");
        }

    }
}

void aFoods::on_cancelAdd_clicked()
{
    ui->cityCB->setCurrentIndex(0);
    ui->foodLE->clear();
    ui->costSB->setValue(0.00);
}

void aFoods::on_addFood_clicked()
{
    QString city, foodName, price;
    city = ui->cityCB->currentText();
    foodName = ui->foodLE->text();
    price = ui->costSB->text();

    QSqlQuery qry;

    qry.prepare("insert into Food (City,foodName,Price) "
                "values('"+city+"', '"+foodName+"', '"+price+"') ");

    if(qry.exec())
    {
        QMessageBox::information(this, tr("Success"),tr("Food Successfully Added"));
        loadTableList();
        on_cancelAdd_clicked();
    }
    else
    {
        QMessageBox::critical(this, tr("Error"),foodName + " already exists in the database.\n Database not updated.");
    }

}

void aFoods::loadTableList()
{
    QSqlQueryModel * model = new QSqlQueryModel();

    model->setQuery("SELECT DISTINCT City, foodName, Price "
                    "FROM Food "
                    "ORDER BY City ");
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Name"));
    ui->aFoodTV->verticalHeader()->setVisible(false);
    ui->aFoodTV->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->aFoodTV->setModel(model);

    QSqlQueryModel * list = new QSqlQueryModel();

    list->setQuery("SELECT DISTINCT City "
                   "FROM Food "
                   "ORDER BY City ");

    ui->cityCB->setModel(list);
    ui->delCityCB->setModel(list);

}

void aFoods::checkLines()
{
    bool ok =  !((ui->foodLE->text()).trimmed().isEmpty())
            &&  (ui->costSB->value() != 0.00);

    ui->addFood->setEnabled(ok);

}

void aFoods::on_costSB_valueChanged()
{
    checkLines();
}

void aFoods::on_foodLE_textChanged()
{
    checkLines();
}

void aFoods::on_delCityCB_currentIndexChanged(const QString &cityName)
{
    QString city;
    city = ui->delCityCB->currentText();

    QSqlQueryModel *model = new QSqlQueryModel();

    QSqlQuery *qry = new QSqlQuery(myDB);

    qry->prepare("SELECT foodName "
                "FROM Food "
                "WHERE City = '"+cityName+"'"
                "ORDER BY foodName ");

    qry->exec();
    model->setQuery(*qry);
    ui->foodLV->setModel(model);
    ui->delButton->setEnabled(false);
    ui->updateButton->setEnabled(false);
    ui->delCostSB->setValue(0.00);
}

void aFoods::on_foodLV_clicked(const QModelIndex &index)
{
    QString food = index.data(Qt::DisplayRole).toString();
    ui->delButton->setEnabled(true);
    ui->updateButton->setEnabled(true);


    QSqlQuery *qry = new QSqlQuery(myDB);

    qry->prepare("SELECT Price "
                 "FROM Food "
                 "WHERE foodName = '"+food+"' " );
    qry->exec();
    qry->first();

    qDebug() << qry->value(0).toDouble();

    ui->delCostSB->setValue(qry->value(0).toDouble());

}

void aFoods::on_cancelDel_clicked()
{
    ui->delButton->setEnabled(false);
    ui->foodLV->selectionModel()->clearSelection();
    ui->delCostSB->setValue(0.00);
}

void aFoods::on_addFile_clicked()
{
    QString city, food,price;
    QSqlQuery *qry = new QSqlQuery(myDB);
    QString filter = "All File (*.*) ;; Text File (*.txt)";
    QString file_name = QFileDialog::getOpenFileName(this,"Open A File", "C://");
    QFile file(file_name);

    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this,"Warning","File Not Added.");
    }
    else
    {
        QMessageBox::information(this,"Success","File Added.");
    }

    QTextStream in(&file);

    while(!in.atEnd())
    {
        city = in.readLine();
        food = in.readLine();
        price= in.readLine();
        in.readLine();

        qry->prepare("insert into Food (City,foodName,Price) "
                    "values('"+city+"', '"+food+"', '"+price+"') ");
        if(qry->exec())
        {
            qDebug() << "Database updated with file.";
        }
        else
        {
            qDebug() << "Failed to add file to Database.";
        }

    }

    file.close();

    loadTableList();

}

void aFoods::on_updateButton_clicked()
{
    QModelIndex index = ui->foodLV->currentIndex();
    QString name = index.data(Qt::DisplayRole).toString();
    updatefood = new updateFood(this,name);
    updatefood->show();

    int confirm = updatefood->exec();

    if(confirm == true)
    {
        loadTableList();
    }

}
