#ifndef AFOODS_H
#define AFOODS_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include "afooddialog.h"
#include "updatefood.h"

namespace Ui {
class aFoods;
}

class aFoods : public QWidget
{
    Q_OBJECT

public:
    explicit aFoods(QWidget *parent = nullptr);
    void loadTableList();
    void checkLines();
    ~aFoods();

public slots:
    void on_delButton_clicked();

private slots:
    void on_cancelAdd_clicked();

    void on_addFood_clicked();

    void on_costSB_valueChanged();

    void on_foodLE_textChanged();

    void on_delCityCB_currentIndexChanged(const QString &cityName);


    void on_foodLV_clicked(const QModelIndex &index);

    void on_cancelDel_clicked();

    void on_addFile_clicked();

    void on_updateButton_clicked();

private:
    Ui::aFoods *ui;
    aFoodDialog *afooddialog;
    updateFood  *updatefood;

    QSqlDatabase myDB; // Database object for database connection

};

#endif // AFOODS_H
