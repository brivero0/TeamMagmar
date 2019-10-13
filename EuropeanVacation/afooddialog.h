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

    void on_yesButton_clicked();

private:
    Ui::aFoodDialog *ui;
    QString foodName;
};

#endif // AFOODDIALOG_H
