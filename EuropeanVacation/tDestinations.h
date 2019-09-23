#ifndef TDESTINATIONS_H
#define TDESTINATIONS_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QDebug>

namespace Ui {
class tDestinations;
}

class tDestinations : public QWidget
{
    Q_OBJECT

public:

    explicit tDestinations(QWidget *parent = nullptr);
    ~tDestinations();

    void defualtReset();

    QVector<QString> recFun(QString, int);


private:
    Ui::tDestinations *ui;
    QString startCity = "Paris";

    QSqlDatabase myDB; // Database object for database connection
};

#endif // TDESTINATIONS_H
