#include "afooddialog.h"
#include "ui_afooddialog.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>

aFoodDialog::aFoodDialog(QWidget *parent, const QString &name):
    QDialog(parent),
    ui(new Ui::aFoodDialog),
    foodName(name)
{
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    ui->setupUi(this);
    ui->promptLabel->setText("Are you sure you want to remove \n" + name + " from database?");

}

aFoodDialog::~aFoodDialog()
{
    delete ui;
}

/*****************************************************************
 * METHOD - on_noButton_clicked()
 * --------------------------------------------------------------------------
 * This method will return the dialog box as false
 * and close it
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      The following variables must be declared and initialized:
 *          none
 *
 * POST-CONDITIONS
 *      ==> Returns none - closes the dialog box
 *****************************************************************/
void aFoodDialog::on_noButton_clicked()
{
    reject();
}

/*****************************************************************
 * METHOD - on_yesButton_clicked()
 * --------------------------------------------------------------------------
 * This method will return the dialog box as true
 * and close it
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      The following variables must be declared and initialized:
 *          none
 *
 * POST-CONDITIONS
 *      ==> Returns none - closes the dialog box
 *****************************************************************/
void aFoodDialog::on_yesButton_clicked()
{
    accept();
}
