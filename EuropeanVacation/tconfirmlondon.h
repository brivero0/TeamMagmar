#ifndef TCONFIRMLONDON_H
#define TCONFIRMLONDON_H

#include <QWidget>
#include "ttravelsimulation.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>
#include <QString>
#include <QApplication>
#include <QTableView>
#include <QList>


namespace Ui {
class tConfirmLondon;
}

class tConfirmLondon : public QWidget
{
    Q_OBJECT

public:
    explicit tConfirmLondon(QWidget *parent = nullptr);
    ~tConfirmLondon();

private slots:
    void on_startSimulationButton_clicked();
        //!< Traveler simulation window opens

    void on_cancelButton_clicked();
        //!< London confirmation window closes

    void on_numCitiesSpinBox_valueChanged();
        //!< Funtion that updates the number of cities the traveler is visiting based on
        //! spin box value.

private:
    Ui::tConfirmLondon *ui;
    tTravelSimulation * tTravelSimulationWindow1;
    int rowCount;
    QString * p;
    int * d;
    int number;
};

#endif // TCONFIRMLONDON_H
