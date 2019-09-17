#ifndef TCONFIRMLONDON_H
#define TCONFIRMLONDON_H

#include <QWidget>
#include "ttravelsimulation.h"

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

private:
    Ui::tConfirmLondon *ui;
    tTravelSimulation * tTravelSimulationWindow1;
};

#endif // TCONFIRMLONDON_H
