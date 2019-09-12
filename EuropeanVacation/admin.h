#ifndef ADMIN_H
#define ADMIN_H

#include <QWidget>

#include "aDestinations.h"
#include "aFoods.h"

namespace Ui {
class admin;
}

class admin : public QWidget
{
    Q_OBJECT

public:
    explicit admin(QWidget *parent = nullptr);
    ~admin();

private slots:

    void on_homeButton_clicked();
    //!< Home page is displayed in stackedWidget

    void on_destinationDBButton_clicked();
    //!< Destination DB page is displayed in stackedWidget

    void on_foodDBButton_clicked();
    //!< Food DB page is displayed in stackedWidget

    void on_logoutButton_clicked();
    //!< Admin window closes

private:
    Ui::admin *ui;

    aDestinations aDestinations;
    aFoods        aFoods;
};

#endif // ADMIN_H
