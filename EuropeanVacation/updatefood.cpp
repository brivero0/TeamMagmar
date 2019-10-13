#include "updatefood.h"
#include "ui_updatefood.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QMessageBox>


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

void updateFood::on_resetButton_clicked()
{
    ui->newPrice->setValue(0.00);
    ui->confirmButton->setEnabled(false);
}

void updateFood::on_newPrice_valueChanged(double price)
{
    if(price != 0.00)
    {
        ui->confirmButton->setEnabled(true);
    }
}

void updateFood::on_confirmButton_clicked()
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
