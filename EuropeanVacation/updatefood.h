#ifndef UPDATEFOOD_H
#define UPDATEFOOD_H

#include <QDialog>
#include <QSqlDatabase>

namespace Ui {
class updateFood;
}

class updateFood : public QDialog
{
    Q_OBJECT

public:
    explicit updateFood(QWidget *parent = nullptr, const QString &name = " ");

    bool checkPrice(double newPrice);

    ~updateFood();

private slots:
    void on_resetButton_clicked();
     //!< Resets price field

    void on_newPrice_valueChanged(double price);
     //!< Enables confirm button if price field isn't 0

    void on_confirmButton_clicked();
    //!< Confirms updated food price
    /*!< POST: Returns code execution is true*/

    void on_cancelButton_clicked();

private:
    Ui::updateFood *ui;
    QSqlDatabase myDB;
    QString foodName;   // IN & OUT - Contains the name of food item being updated
                                    //                  passed in from aFood into constructor
};

#endif // UPDATEFOOD_H
