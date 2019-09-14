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
    ~tTravelSimulation();

private:
    Ui::tTravelSimulation *ui;


};

#endif // TTRAVELSIMULATION_H
