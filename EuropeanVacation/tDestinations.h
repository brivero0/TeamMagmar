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
    //!< Constructor

    ~tDestinations();
    //! Destructor

    void defaultReset();
    //!< initializes the QTableWidget and loads with data from a database query

private:
    Ui::tDestinations *ui;          /*!< class object */
    QString startCity = "Paris";    /*!< QString for the database query */

    QSqlDatabase myDB;              /*!< database connection */
};

#endif // TDESTINATIONS_H
