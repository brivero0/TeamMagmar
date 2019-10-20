#include "aFoods.h"
#include "ui_aFoods.h"
#include "afooddialog.h"
#include "updatefood.h"
#include "numberformatdelegate.h"
#include <QFileDialog>
#include <QFile>
#include <QString>
#include <QVector>

// Default constructor
aFoods::aFoods(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::aFoods)
{
    ui->setupUi(this);

    myDB = QSqlDatabase::database();

    // Loads Table and List
    loadTableList();
    checkLines();

    // Sets number format for price
    ui->aFoodTV->setItemDelegateForColumn(2, new NumberFormatDelegate(this));
    ui->delButton->setEnabled(false);
    ui->updateButton->setEnabled(false);
}

// Destructor
aFoods::~aFoods()
{
    delete ui;
}

/*****************************************************************
 * METHOD - on_delButton_clicked()
 * --------------------------------------------------------------------------
 * This method will delete selected food item from
 * database and output the result to user
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      The following variables must be declared and initialized:
 *          none
 *
 * POST-CONDITIONS
 *      ==> Returns none - deletes food item
 *****************************************************************/
void aFoods::on_delButton_clicked()
{
    // Gets food item from list
    QModelIndex index = ui->foodLV->currentIndex();
    QString name = index.data(Qt::DisplayRole).toString();
//    qDebug() << name;

    // Passes food item name into delete dialog box
    afooddialog = new aFoodDialog(this, name);
    afooddialog->show();

    // If user confirmed deletion, returns true else false
    int confirm = afooddialog->exec();
//    qDebug()<<"Result: " << confirm;

    // Deletes food item and updates tables & lists
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

/*****************************************************************
 * METHOD - on_cancelAdd_clicked()
 * --------------------------------------------------------------------------
 * This method will reset the add fields
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      The following variables must be declared and initialized:
 *          none
 *
 * POST-CONDITIONS
 *      ==> Returns none - clears all add fields
 *****************************************************************/
void aFoods::on_cancelAdd_clicked()
{
    ui->cityCB->setCurrentIndex(0);
    ui->foodLE->clear();
    ui->costSB->setValue(0.00);
}

/*****************************************************************
 * METHOD - on_addFood_clicked()
 * --------------------------------------------------------------------------
 * This method will add new food item and their prices
 * to corresponding city
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      The following variables must be declared and initialized:
 *          none
 *
 * POST-CONDITIONS
 *      ==> Returns none - adds new food item with price and a city
 *****************************************************************/
void aFoods::on_addFood_clicked()
{
    // Gets data from add field lines
    QString city, foodName, price;
    city = ui->cityCB->currentText();
    foodName = ui->foodLE->text();
    price = ui->costSB->text();

    QSqlQuery qry;

    // Stores new data into database and updates table & lists
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

/*****************************************************************
 * METHOD - loadTableList()
 * --------------------------------------------------------------------------
 * This method will load the table and city lists
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      The following variables must be declared and initialized:
 *          none
 *
 * POST-CONDITIONS
 *      ==> Returns none - reloads table and city list
 *****************************************************************/
void aFoods::loadTableList()
{
    QSqlQueryModel * model = new QSqlQueryModel();

    //Loads Table
    model->setQuery("SELECT DISTINCT City, foodName, Price "
                    "FROM Food "
                    "ORDER BY City ");
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Name"));
    ui->aFoodTV->verticalHeader()->setVisible(false);
    ui->aFoodTV->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->aFoodTV->setModel(model);

    QSqlQueryModel * list = new QSqlQueryModel();

    // Loads Lists
    list->setQuery("SELECT DISTINCT City "
                   "FROM Food "
                   "ORDER BY City ");

    ui->cityCB->setModel(list);
    ui->delCityCB->setModel(list);

}

/*****************************************************************
 * METHOD - checkLines()
 * --------------------------------------------------------------------------
 * This method will check if price and food name line
 * edit are valid. If they're valid, it will enable the
 * add button on the window
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      The following variables must be declared and initialized:
 *          none
 *
 * POST-CONDITIONS
 *      ==> Returns none - enables add button if valid entries
 *****************************************************************/
void aFoods::checkLines()
{
    bool ok =  !((ui->foodLE->text()).trimmed().isEmpty())
            &&  (ui->costSB->value() != 0.00)
            && (ui->foodLE->text() != "MAX AMOUNT OF FOOD ITEM ADDED");

    ui->addFood->setEnabled(ok);

}

/*****************************************************************
 * METHOD - on_costSB_valueChanged()
 * --------------------------------------------------------------------------
 * This method will call checkLines when user changes
 * value in spin box
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      The following variables must be declared and initialized:
 *          none
 *
 * POST-CONDITIONS
 *      ==> Returns none
 *****************************************************************/
void aFoods::on_costSB_valueChanged()
{
    checkLines();
}

/*****************************************************************
 * METHOD - on_foodLE_textChanged()
 * --------------------------------------------------------------------------
 * This method will call checkLines when user changes
 * value in line edit
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      The following variables must be declared and initialized:
 *          none
 *
 * POST-CONDITIONS
 *      ==> Returns none
 *****************************************************************/
void aFoods::on_foodLE_textChanged()
{
    checkLines();
}

/*****************************************************************
 * METHOD - on_delCityCB_currentIndexChanged(const QString &cityName)
 * --------------------------------------------------------------------------
 * This method will delete selected food item
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      The following variables must be declared and initialized:
 *          cityName: name of city for the food item being deleted
 *
 * POST-CONDITIONS
 *      ==> Returns none
 *****************************************************************/
void aFoods::on_delCityCB_currentIndexChanged(const QString &cityName)
{
    QString city;
    city = ui->delCityCB->currentText();

    QSqlQueryModel *model = new QSqlQueryModel();

    // Updates food items for selected city for list view
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

/*****************************************************************
 * METHOD -on_foodLV_clicked(const QModelIndex &index)
 * --------------------------------------------------------------------------
 * This method will show the price of item selected in
 * food list view
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      The following variables must be declared and initialized:
 *          index: index of the food item selected
 *
 * POST-CONDITIONS
 *      ==> Returns none - displays food item's price
 *****************************************************************/
void aFoods::on_foodLV_clicked(const QModelIndex &index)
{
    // Enables delete and update buttons
    QString food = index.data(Qt::DisplayRole).toString();
    ui->delButton->setEnabled(true);
    ui->updateButton->setEnabled(true);


    // Shows the price of selected food item
    QSqlQuery *qry = new QSqlQuery(myDB);

    qry->prepare("SELECT Price "
                 "FROM Food "
                 "WHERE foodName = '"+food+"' " );
    qry->exec();
    qry->first();

    qDebug() << qry->value(0).toDouble();

    ui->delCostSB->setValue(qry->value(0).toDouble());

}


/*****************************************************************
 * METHOD -on_cancelDel_clicked()
 * --------------------------------------------------------------------------
 * This method will reset the delete fields
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      The following variables must be declared and initialized:
 *          none
 *
 * POST-CONDITIONS
 *      ==> Returns none - resets delete fields
 *****************************************************************/
void aFoods::on_cancelDel_clicked()
{
    ui->delButton->setEnabled(false);
    ui->foodLV->selectionModel()->clearSelection();
    ui->delCostSB->setValue(0.00);
}

/*****************************************************************
 * METHOD -on_addFile_clicked()
 * --------------------------------------------------------------------------
 * This method will open up a window that will allow
 * the user to select a file to add its data into the database.
 * It will make sure that the food added wont be more than
 * 6 total for each city
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      The following variables must be declared and initialized:
 *          none
 *
 * POST-CONDITIONS
 *      ==> Returns none - adds file's data to database
 *****************************************************************/
void aFoods::on_addFile_clicked()
{
    int itemCount = 0;
    int addCount = 0;
    QString city, food,price;
    QVector<QString> failedFood;
    QString foodFail = "<center><b>Failed to add:</b></center>\n";

    QSqlQuery *qry = new QSqlQuery(myDB);

    // Allow users to filter for all files or only text files
    QString filter = "All File (*.*) ;; Text File (*.txt)";
    // Opens Window Explorer to allow user to select a file
    QString file_name = QFileDialog::getOpenFileName(this,"Open A File", "C://");
    QFile file(file_name);

    qDebug() <<  "foodFail size: " << foodFail.size();

    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this,"Warning","File Not Added.");
    }

    // Opens input file
    QTextStream in(&file);

    while(!in.atEnd())
    {
        city = in.readLine();
        food = in.readLine();
        price = in.readLine();
        in.readLine();

        // Checks amount of food items for city read in
        itemCount = checkItems(city);

        // Adds food item only if city has less than 6 food items
        if(itemCount < 6)
        {
            qry->prepare("insert into Food (City,foodName,Price) "
                        "values('"+city+"', '"+food+"', '"+price+"') ");
        }

        if(qry->exec())
        {
            qDebug() << "Added " + food + " to Database.";
            addCount++;
        }
        else
        {
            // Saves food item that wasn't able to be added to database
            qDebug() << "Failed to add " + food + " to Database.";
            failedFood.push_front(food);
        }

    }

    // Closes file
    file.close();

   qDebug() << " addCount: " << addCount;

   // Outputs food items saved and food items unable to be saved
    if(addCount > 0)
    {
      QMessageBox::information(this,"Success", QString::number(addCount) + "  Food Item(s) Saved");
    }

    // Outputs the food items unable to be saved
    if(!failedFood.isEmpty())
    {
        for(int x =failedFood.size(); x > 1 ; --x)
        {
            foodFail += failedFood.takeLast();
            foodFail += ", ";

        }

        foodFail +=  failedFood.takeFirst();

        QMessageBox::warning(this,"Error", "<center>" + foodFail + "</center>");
    }

    loadTableList();

}

/*****************************************************************
 * METHOD -on_updateButton_clicked()
 * --------------------------------------------------------------------------
 * This method will open up a dialog box that will
 * prompt user to enter new food price.
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      The following variables must be declared and initialized:
 *          none
 *
 * POST-CONDITIONS
 *      ==> Returns none - opens updatefood dialog box
 *****************************************************************/
void aFoods::on_updateButton_clicked()
{
    QModelIndex index = ui->foodLV->currentIndex();

    // Converts selected item from index to string
    QString name = index.data(Qt::DisplayRole).toString();

    // Passes string to dialog to use
    updatefood = new updateFood(this,name);
    updatefood->show();

    // If user confirmed update reutrns true else false
    int confirm = updatefood->exec();

    // If user entered new price successfully, reloads table
    if(confirm == true)
    {
        loadTableList();
    }

}


/*****************************************************************
 * METHOD - on_cityCB_currentIndexChanged(const QString &cityName)
 * --------------------------------------------------------------------------
 * This method will prevent user from entering add fields
 * if current city selected has 6 food items
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      The following variables must be declared and initialized:
 *          cityName: city name selected
 *
 * POST-CONDITIONS
 *      ==> Returns none - prevents more than 6 food items per city
 *****************************************************************/
void aFoods::on_cityCB_currentIndexChanged(const QString &cityName)
{   

    ui->costSB->setValue(0.00);

    // Checks item count for city
    int itemCount = checkItems(cityName);


    if(itemCount > 5)
    {
        // Prevents user from editing field lines when 6 food items
        ui->foodLE->setReadOnly(true);
        ui->costSB->setReadOnly(true);
        ui->addFood->setEnabled(false);

        // Code for setting text for line edit
        QPalette *palette = new QPalette();
        palette->setColor(QPalette::Text,Qt::red);
        ui->foodLE->setPalette(*palette);
        ui->foodLE->setText("MAX AMOUNT OF FOOD ITEM ADDED");
    }
    else
    {
        // Renables editing ability for admin
        ui->foodLE->setReadOnly(false);
        ui->costSB->setReadOnly(false);
        ui->addFood->setEnabled(true);

        // Default text color
        QPalette *palette = new QPalette();
        palette->setColor(QPalette::Text,Qt::black);
        ui->foodLE->setPalette(*palette);
        ui->foodLE->clear();

    }

}

/*****************************************************************
 * METHOD - checkItems(const QString cityName)
 * --------------------------------------------------------------------------
 * This method will count how many food items
 * the selected city has
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      The following variables must be declared and initialized:
 *          cityName: city name selected
 *
 * POST-CONDITIONS
 *      ==> Returns itemCount - amount of food city has
 *****************************************************************/
int aFoods::checkItems(const QString cityName)
{
    int itemCount = 0;

    QSqlQuery *qry = new QSqlQuery(myDB);

    // Gets the food items for city
    qry->prepare("SELECT COUNT(foodName) "
                         "FROM Food "
                         "WHERE City = '"+cityName+"' ");

    qry->exec();

    // Counts the rows for food items
    if(qry->next())
    {
        itemCount = qry->value(0).toInt();
    }

    qDebug() << "itemCount: " << itemCount;

    return itemCount;
}
