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

private slots:
    void on_exitSimulationButton_clicked();

private:
    Ui::tTravelSimulation *ui;
    QString* destinations = nullptr;
    int* distances = nullptr;
    int total;

};

#endif // TTRAVELSIMULATION_H
