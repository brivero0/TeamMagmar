#ifndef TTRAVELSIMULATION_H
#define TTRAVELSIMULATION_H

#include <QWidget>

namespace Ui {
class tTravelSimulation;
}

class tTravelSimulation : public QWidget
{
    Q_OBJECT

public:
    explicit tTravelSimulation(QWidget *parent = nullptr);
    explicit tTravelSimulation(QString* cList, int* dList, int, QWidget *parent = nullptr);
    ~tTravelSimulation();

    void loadTables();
    void updateFoods();

private slots:
    void on_exitSimulationButton_clicked();

    void on_endVacationButton_clicked();

    void on_nextDestButton_clicked();

private:
    Ui::tTravelSimulation *ui;
    QString* destinations = nullptr;
    int* distances = nullptr;
    QString currCity; // Name of current city being visited
    int currDistance; // Distance from last city to current city
    int totalDistance; // Total distance traveled in simulation thus far
    float currCost; // Cost of meals selected at current city
    float totalCost; // Total meal cost in simulation thus far
    int total; // Total number of destinations for the simulation
    int index; // Used to locate index of current city
    QFont font; // Used to modify font attributes in QListView
};

#endif // TTRAVELSIMULATION_H
