#ifndef AFOODDIALOG_H
#define AFOODDIALOG_H

#include <QDialog>

namespace Ui {
class aFoodDialog;
}

class aFoodDialog : public QDialog
{
    Q_OBJECT

public:
    explicit aFoodDialog(QWidget *parent = nullptr, const QString &name = " ");
    ~aFoodDialog();

private slots:
    void on_noButton_clicked();
    //!< Cancels food item deletion
    /*!< POST: Returns the code as false*/

    void on_yesButton_clicked();
    //!< Confirms food item deletion
    /*!< POST: Returns execution of dialog box as true*/

private:
    Ui::aFoodDialog *ui;
    QString foodName;       // IN & OUT - Name of the food being removed from the database
};

#endif // AFOODDIALOG_H
