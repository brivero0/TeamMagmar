#ifndef TCONFIRMCUSTOM_H
#define TCONFIRMCUSTOM_H

#include <QWidget>
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

private slots:
    void on_startSimulationBtn2_clicked();

    void on_cancelButton_clicked();

private:
    Ui::tConfirmCustom *ui;
    tTravelSimulation * tTravelSimulationWindow2;
};

#endif // TCONFIRMCUSTOM_H
