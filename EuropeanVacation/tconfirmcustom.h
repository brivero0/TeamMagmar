#ifndef TCONFIRMCUSTOM_H
#define TCONFIRMCUSTOM_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QDebug>
#include <QListWidget>
#include "ttravelsimulation.h"

namespace Ui {
class tConfirmCustom;
}

class tConfirmCustom : public QWidget
{
    Q_OBJECT

public:
    explicit tConfirmCustom(QWidget *parent = nullptr);
    //!< Constructor

    ~tConfirmCustom();
    //!< Destructor

    void defaultListView();
    //!< Sets default list view using values from the database.

    void defaultView();
    //!< Sets the default view the window by enabling and disabling items.

    void sortList();
    //!< Creates a sorted list of destinations and distances from selected.

private slots:
    void on_resetSelectionButton_clicked();
    //!< Resets the view and widget to default.

    void on_confirmSelectionButon_clicked();
    //!< Creates new list of selected cities and changes widget view.

    void on_startCityComboBox_currentIndexChanged(int index);
    //!< Updates view when valid starting city is selected from comboBox.

    void on_startSimulationButton_clicked();
    //!< Opens simulation window and closes this object.

    void on_cancelButton_clicked();
    //!< Closes this object.

private:
    Ui::tConfirmCustom *ui;     /*!< class object */
    tTravelSimulation * tTravelSimulationWindow;
                                /*!< class object for simulation window */
    QList<QListWidgetItem *> customList;
                                /*!< list of destinations selected */
    QString* sortedDestinations = nullptr;
                                /*!< list of sorted destinations */
    int* sortedDistance = nullptr;
                                /*!< list of sorted distances */
    int cityNum;                /*!< number of selected citites */
    QString startCity;          /*!< the starting city */
    QString closestCity;        /*!< next closest city to starting city */
    QSqlDatabase myDB;          /*!< database connection */
};

#endif // TCONFIRMCUSTOM_H
