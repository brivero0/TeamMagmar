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


void aFoodDialog::on_noButton_clicked()
{
    reject();
}

void aFoodDialog::on_yesButton_clicked()
{
    accept();
}
