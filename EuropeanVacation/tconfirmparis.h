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
    void getCityNum(int);
    void generateList();
    ~tConfirmParis();

private slots:
    void on_startSimulationBtn1_clicked();

    void on_cancelButton_clicked();

private:
    Ui::tConfirmParis *ui;
    tTravelSimulation * tTravelSimulationWindow1;
    QString startCity = "Paris";
//    QVector<QString> sortedDestinations;
    QString* sortedDestinations = nullptr;
//    QVector<int> sortedDistance;
    int* sortedDistance = nullptr;
    QSqlDatabase myDB;
    int cityNum;
};

#endif // TCONFIRMPARIS_H
