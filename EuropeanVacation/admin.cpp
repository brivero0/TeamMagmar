#include "admin.h"
#include "ui_admin.h"

/*****************************************************************
 * admin::admin(QWidget *parent) : QWidget(parent),
 *                                 ui(new Ui::admin)
 * ---------------------------------------------------------------
 *  admin non-default constructor
 * ---------------------------------------------------------------
 * PRE-CONDITIONS
 *      The following variables must be declared and initialized:
 *          none
 *
 * POST-CONDITIONS
 *      ==> Returns nothing class instantiated
 *****************************************************************/
admin::admin(QWidget *parent) : //IN - QWidget parent
             QWidget(parent),
             ui(new Ui::admin)
{
    ui->setupUi(this);

    // Create a stacked widget index for seperate QWidget pages
    ui->stackedWidget->insertWidget(1, &aDestinations);
    ui->stackedWidget->insertWidget(2, &aFoods);
}

/*****************************************************************
 * admin::~admin()
 * ---------------------------------------------------------------
 *  admin default destructor
 * ---------------------------------------------------------------
 * PRE-CONDITIONS
 *      The following variables must be declared and initialized:
 *          none
 *
 * POST-CONDITIONS
 *      ==> Returns nothing class destructed
 *****************************************************************/
admin::~admin()
{
    delete ui;
}

/****************************************************************************
 * METHOD - on_homeButton_clicked
 * --------------------------------------------------------------------------
 * When the home button is clicked, the stackedWidget index changes to
 * display the home page.
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      No parameters are required.
 *
 * POST-CONDITIONS
 *      ==> Returns nothing.
 *      ==> Displays Admin Window Home Page
 ***************************************************************************/
void admin::on_homeButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

/****************************************************************************
 * METHOD - on_destinationDBButton_clicked
 * --------------------------------------------------------------------------
 * When the Destibation DB button is clicked, the stackedWidget index
 * changes to display the Eurpoean city destination DB page for
 * functionality.
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      No parameters are required.
 *
 * POST-CONDITIONS
 *      ==> Returns nothing.
 *      ==> Displays DestibationDB QWidget
 ***************************************************************************/
void admin::on_destinationDBButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

/****************************************************************************
 * METHOD - on_foodDBButton_clicked
 * --------------------------------------------------------------------------
 * When the Food DB button is clicked, the stackedWidget index changes to
 * display the Food DB page for edit/add/delete functionality.
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      No parameters are required.
 *
 * POST-CONDITIONS
 *      ==> Returns nothing.
 *      ==> Displays FoodDB QWidget
 ***************************************************************************/
void admin::on_foodDBButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


/****************************************************************************
 * METHOD - on_logoutButton_clicked
 * --------------------------------------------------------------------------
 * When the logout button is clicked, admin window closes.
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      No parameters are required.
 *
 * POST-CONDITIONS
 *      ==> Returns nothing.
 *      ==> Closes Admin Window (returns control to login window)
 ***************************************************************************/
void admin::on_logoutButton_clicked()
{
    this->close();
}
