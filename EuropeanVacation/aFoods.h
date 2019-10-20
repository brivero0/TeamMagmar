#ifndef AFOODS_H
#define AFOODS_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include "afooddialog.h"
#include "updatefood.h"

namespace Ui {
class aFoods;
}

class aFoods : public QWidget
{
    Q_OBJECT

public:
    explicit aFoods(QWidget *parent = nullptr);
    void loadTableList();
    //!< Loads the table view and list view
    /*!< Used to refresh table or load when directed to page */

    void checkLines();
    //!< Checks if add field lines are changed before enabling add button

    int checkItems(const QString cityName);
    //!< Checks the current amount of food item in the database for specific city
    /*!< POST: will return int of amount of food items */
    /*!< Used for adding food item via file or manually. Limits the user from entering*/
    /*!< more than six items per city in database*/

    ~aFoods();

public slots:
    void on_delButton_clicked();
     //!< Redirects user to confirmation delete dialog box
     /*!< POST: Will prompt the user if they want to delete selected food item*/

private slots:
    void on_cancelAdd_clicked();
     //!< Resets add fields in add food item section

    void on_addFood_clicked();
     //!< Add food item based when add fields are filled out

    void on_costSB_valueChanged();
     //!< Checks if spin box and line edit are changed before enabling add button

    void on_foodLE_textChanged();
     //!< Checks if spin box and line edit are changed before enabling add button

    void on_delCityCB_currentIndexChanged(const QString &cityName);
     //!< Loads food items for current city chosen by spinbox

    void on_foodLV_clicked(const QModelIndex &index);
     //!< Enables delete and update button when a city is selected.
     /*!< Also displays the price of current food item selected*/

    void on_cancelDel_clicked();
     //!< Resets food list and price in delete/update food item section

    void on_addFile_clicked();
     //!< Will open window explorer to select file to add to city
     /*!< POST: will prepeare query from values read in by file*/
    /*!< Will output message box if query was successful. */

    void on_updateButton_clicked();
    //!< Redirects user to update the price of selected food item
    /*!< POST: Will prompt the user to enter new food price for selected item*/

    void on_cityCB_currentIndexChanged(const QString &cityName);
    //!< Disable line edit and spin box in add food item section when city has 6 food items already
    /*!< POST: Will require the user to delete a food item from city to renable fields*/
    /*!< Will output message that max food items have been reached for city. */

private:
    Ui::aFoods *ui;
    aFoodDialog *afooddialog;   // OUT - Dialog box to confirm removal of food item
    updateFood  *updatefood;    // OUT - Dialog box to update a food item

    QSqlDatabase myDB; // Database object for database connection

};

#endif // AFOODS_H
