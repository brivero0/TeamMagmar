#include "updatefood.h"
#include "ui_updatefood.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QMessageBox>

/*****************************************************************
 * CONSTRUCTOR - updateFood(QWidget *parent, const QString &name)
 * --------------------------------------------------------------------------
 * This constructor will set foodName with value passed in and,
 * remove the question mark button from the window, disables the
 * confirm button, and displays the prompt for the admin
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      The following variables must be declared and initialized:
 *          name  : name of the food being updated
 *          parent: pointer of the parent class
 *
 * POST-CONDITIONS
 *      ==> Returns none - displays the dialog box
 *****************************************************************/
updateFood::updateFood(QWidget *parent, const QString &name) :
    QDialog(parent),
    ui(new Ui::updateFood),
    foodName(name)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    ui->promptLabel->setText("Enter New Price For " + name);
    ui->confirmButton->setEnabled(false);
}

updateFood::~updateFood()
{
    delete ui;
}

/*****************************************************************
 * METHOD - on_resetButton_clicked()
 * --------------------------------------------------------------------------
 * This method resets the price being entered by the admin.
 * It will also disable the the confirm button until the price is edited
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      The following variables must be declared and initialized:
 *          none
 *
 * POST-CONDITIONS
 *      ==> Returns none
 *****************************************************************/
void updateFood::on_resetButton_clicked()
{
    ui->newPrice->setValue(0.00);
    ui->confirmButton->setEnabled(false);
}

/*****************************************************************
 * METHOD - on_newPrice_valueChanged(double price)
 * --------------------------------------------------------------------------
 * This method will enable the the confirm button if value is not equal to 0
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      The following variables must be declared and initialized:
 *          price: the double value in the spin box
 *
 * POST-CONDITIONS
 *      ==> Returns none
 *****************************************************************/
void updateFood::on_newPrice_valueChanged(double price)
{
    ui->confirmButton->setEnabled(checkPrice(price));
}

/*****************************************************************
 * METHOD - on_confirmButton_clicked()
 * --------------------------------------------------------------------------
 * This method will update the price of a food item and outputs a message
 * if execution was successful
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      The following variables must be declared and initialized:
 *          none
 *
 * POST-CONDITIONS
 *      ==> Returns nothing - updates the database with new food price
 *****************************************************************/
void updateFood::on_confirmButton_clicked()
{

   if(checkPrice(ui->newPrice->value()))
   {
       QString updatedPrice = ui->newPrice->text();
       QSqlQuery *qry = new QSqlQuery(myDB);

       qry->prepare("UPDATE Food "
                            "SET Price = '"+updatedPrice+"' "
                            "WHERE foodName = '"+foodName+"' ");
       if(qry->exec())
       {
           QMessageBox::information(this,"Success","Price for " + foodName + " updated.");
           qDebug() << "Updated Food Price.";
       }
       else
       {
           QMessageBox::critical(this,"Error","Price for " + foodName + " unable to be updated.");
           qDebug() << "Failed to Update Food Price";
       }

       accept();
   }
}

/*****************************************************************
 * METHOD - on_cancelButton_clicked()
 * --------------------------------------------------------------------------
 * This method will cancel the update of the food item
 * and closes the window
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      The following variables must be declared and initialized:
 *          none
 *
 * POST-CONDITIONS
 *      ==> Returns nothing - closes dialog box
 *****************************************************************/
void updateFood::on_cancelButton_clicked()
{
    reject();
}

/*****************************************************************
 * METHOD - checkPrice(double newPrice)
 * --------------------------------------------------------------------------
 * This method will check if new price is not equal
 * to 0.
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      The following variables must be declared and initialized:
 *          newPrice - new price of food item
 *
 * POST-CONDITIONS
 *      ==> Returns bool if value is equal to 0.00
 *****************************************************************/
 bool updateFood::checkPrice(double newPrice)
{
    return (newPrice != 0.00);
}
