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
    ~tConfirmCustom();
    void defaultListView();
    void defaultView();
    void sortList();

private slots:
    void on_resetSelectionButton_clicked();
    void on_confirmSelectionButon_clicked();
    void on_startCityComboBox_currentIndexChanged(int index);
    void on_startSimulationButton_clicked();
    void on_cancelButton_clicked();

private:
    Ui::tConfirmCustom *ui;
    tTravelSimulation * tTravelSimulationWindow2;
    QList<QListWidgetItem *> customList;
    QVector<QString> sortedDestinationList;
    QVector<QString> sortedDistancesList;
    QString startCity;
    QSqlDatabase myDB;
};

#endif // TCONFIRMCUSTOM_H
