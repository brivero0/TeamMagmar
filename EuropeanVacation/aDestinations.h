#ifndef ADESTINATIONS_H
#define ADESTINATIONS_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>

/*!
 *\namespace Ui
 */
namespace Ui {
class aDestinations;
}


class aDestinations : public QWidget
{
    Q_OBJECT

public:
    explicit aDestinations(QWidget *parent = nullptr);

    ~aDestinations();

private:
    Ui::aDestinations *ui;

    QSqlDatabase myDB; // Database object for database connection
};

#endif // ADESTINATIONS_H
