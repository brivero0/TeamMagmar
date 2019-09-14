#include "login.h"
#include "ui_login.h"

// Default Constructor
login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

// Destructor
login::~login()
{
    delete ui;
}

/****************************************************************************
 * METHOD - connectToDB
 * --------------------------------------------------------------------------
 * This method creates and opens a database connection and displays a
 * qDebug message that the database access is open.  This method is used
 * with a valid login (traveler or admin).  If database is already
 * connected and open, then only the qDebug message is displayed.
 * NOTE: Use with valid login username/password only (traveler or admin)
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      No parameters are required.
 *
 * POST-CONDITIONS
 *      ==> Returns nothing.
 *      ==> Creates and connects to SQLite database if not open
 ***************************************************************************/
void login::connectToDB()
{
    bool isOpen = false; // CALC - Set database open status to false

    // Create and open a database connection
    // Return if database opened successfully or not
    isOpen = myDB.openDB();

    // Display message if database connection was successful
    if(isOpen)
    {
        qDebug() << "Success: Able to access open database";
    }
}

/****************************************************************************
 * METHOD - on_loginManagerButton_clicked
 * --------------------------------------------------------------------------
 * On valid username/password for traveler, the traveler window is opened.
 * Connection to database is checked.
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      No parameters are required.
 *
 * POST-CONDITIONS
 *      ==> Returns nothing.
 *      ==> Displays Traveler Window on valid login/password
 ***************************************************************************/
void login::on_loginTravelerButton_clicked()
{
    QString username;
    QString password;

        username = ui->usernameLineEdit->text();
        password = ui->passwordLineEdit->text();

    if(username == "traveler" && password == "123")
    {
        ui -> passwordLineEdit -> setText("");
        ui -> usernameLineEdit -> setText("");

        ui -> label_status ->setText("");

        connectToDB();
        travelerWindow = new traveler();
        travelerWindow->show();
        //this->close();
    }
    else if(username == "admin" && password == "456")
    {
        ui -> passwordLineEdit -> setText("");
        ui -> usernameLineEdit -> setText("");

        ui -> label_status ->setText("");

        connectToDB();
        adminWindow = new admin();
        adminWindow->show();
        //this->close();
    }
    else
    {

        ui -> label_status ->setText("Invalid Username or Password");
        ui -> passwordLineEdit -> setText("");
        ui -> usernameLineEdit -> setText("");
    }
}

/****************************************************************************
 * METHOD - on_exitProgramButton_clicked
 * --------------------------------------------------------------------------
 * This method closes database and program when exit button is clicked
 * on the login window.
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      No parameters are required.
 *
 * POST-CONDITIONS
 *      ==> Returns nothing.
 *      ==> Closes database connection
 *      ==> Closes Login Window (closes program)
 ***************************************************************************/
void login::on_exitProgramButton_clicked()
{
    myDB.closeDB();
    this->close();
}
