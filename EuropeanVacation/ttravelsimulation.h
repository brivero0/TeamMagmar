#ifndef TTRAVELSIMULATION_H
#define TTRAVELSIMULATION_H

#include <QWidget>
#include <QListWidget>

namespace Ui {
class tTravelSimulation;
}

class tTravelSimulation : public QWidget
{
    Q_OBJECT

public:
    explicit tTravelSimulation(QWidget *parent = nullptr);
    ~tTravelSimulation();
    void getList(QVector<QString> temp);

private slots:
    void on_exitSimulationButton_clicked();

private:
    Ui::tTravelSimulation *ui;
    QVector<QString> simulationList;

};

#endif // TTRAVELSIMULATION_H
