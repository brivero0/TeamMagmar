#ifndef TCONFIRMPARIS_H
#define TCONFIRMPARIS_H

#include <QWidget>
#include "ttravelsimulation.h"

namespace Ui {
class tConfirmParis;
}

class tConfirmParis : public QWidget
{
    Q_OBJECT

public:
    explicit tConfirmParis(QWidget *parent = nullptr);
    ~tConfirmParis();

private slots:
    void on_startSimulationBtn1_clicked();

private:
    Ui::tConfirmParis *ui;
    tTravelSimulation * tTravelSimulationWindow1;
};

#endif // TCONFIRMPARIS_H
