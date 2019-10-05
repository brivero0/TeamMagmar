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

    void on_cancelButton_clicked();

    void on_numCitiesSpinBox_valueChanged();

private:
    Ui::tConfirmLondon *ui;
    tTravelSimulation * tTravelSimulationWindow1;
    int rowCount;
    QString * p;
    int * d;
};

#endif // TCONFIRMLONDON_H
