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

namespace Ui {
class aFoods;
}

class aFoods : public QWidget
{
    Q_OBJECT

public:
    explicit aFoods(QWidget *parent = nullptr);
    ~aFoods();

private:
    Ui::aFoods *ui;

    QSqlDatabase myDB; // Database object for database connection

};

#endif // AFOODS_H
