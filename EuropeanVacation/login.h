#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QStackedLayout>
#include <QDebug>
#include <QMessageBox>

#include "admin.h"
#include "traveler.h"
#include "databasemanger.h"

namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

    void connectToDB();

private slots:
    void on_loginTravelerButton_clicked();

    void on_loginAdminButton_clicked();

    void on_exitProgramButton_clicked();

private:
    Ui::login *ui;

    traveler *travelerWindow;

    admin   *adminWindow;

    databaseManger myDB;
 };

#endif // LOGIN_H
