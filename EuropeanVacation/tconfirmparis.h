#ifndef TCONFIRMPARIS_H
#define TCONFIRMPARIS_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QDebug>
#include <QListWidget>
#include "ttravelsimulation.h"

namespace Ui {
class tConfirmParis;
}

class tConfirmParis : public QWidget
{
    Q_OBJECT

public:
    explicit tConfirmParis(QWidget *parent = nullptr);
    //!< Constructor

    void getCityNum(int);
    //!< cityNum is set to the int passed in and determines how many cities will be selected

    void generateList();
    //!< Sets list view using values from the database

    ~tConfirmParis();
    //!< Destructor

private slots:
    void on_startSimulationBtn1_clicked();
    //!< Opens and passes travel data to simulation window and closes this object.

    void on_cancelButton_clicked();
    //!< Closes this object.

private:
    Ui::tConfirmParis *ui;                          /*!< class object */
    tTravelSimulation * tTravelSimulationWindow1;   /*!< class object for simulation window */
    QString startCity = "Paris";                    /*!< QString for the database query */
    QString* sortedDestinations = nullptr;          /*!< list of sorted destinations */
    int* sortedDistance = nullptr;                  /*!< list of sorted distances */
    QSqlDatabase myDB;                              /*!< database connection */
    int cityNum;                                    /*!< number of selected citites */
};

#endif // TCONFIRMPARIS_H
