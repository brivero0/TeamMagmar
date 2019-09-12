#ifndef TFOODS_H
#define TFOODS_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>
#include <QString>

namespace Ui {
class tFoods;
}

class tFoods : public QWidget
{
    Q_OBJECT

public:
    explicit tFoods(QWidget *parent = nullptr);
    ~tFoods();

private:
    Ui::tFoods *ui;

    QSqlDatabase myDB; // Database object for database connection
};

#endif //TFOODS_H
