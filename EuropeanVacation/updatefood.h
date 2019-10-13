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
    ~updateFood();

private slots:
    void on_resetButton_clicked();

    void on_newPrice_valueChanged(double price);

    void on_confirmButton_clicked();

private:
    Ui::updateFood *ui;
    QSqlDatabase myDB;
    QString foodName;
};

#endif // UPDATEFOOD_H
