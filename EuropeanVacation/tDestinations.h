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

private:
    Ui::tDestinations *ui;

    QSqlDatabase myDB; // Database object for database connection
};

#endif // TDESTINATIONS_H
