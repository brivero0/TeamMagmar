#include "ttravelsimulation.h"
#include "ui_ttravelsimulation.h"
#include "tconfirmparis.h"
#include <QMessageBox>
#include <QSpinBox> // Needed for spinbox object in QTableWidget

/****************************************************************************
 * METHOD - tTravelSimulation
 * --------------------------------------------------------------------------
 * This method is a default constructor
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      None.
 *
 * POST-CONDITIONS
 *      ==> Returns nothing.
 ***************************************************************************/
tTravelSimulation::tTravelSimulation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tTravelSimulation)
{
    ui->setupUi(this);
}

/****************************************************************************
 * METHOD - tTravelSimulation
 * --------------------------------------------------------------------------
 * This method is a contructor that uses passed parameters.
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      *cList: the list of selected destinations sorted
 *      *dList: the list of selected destination distances
 *      t:      the number of selected cities
 *
 * POST-CONDITIONS
 *      ==> Returns nothing.
 ***************************************************************************/
tTravelSimulation::tTravelSimulation(QString* cList, int* dList, int t,
                                     QWidget *parent) :
    QWidget(parent), ui(new Ui::tTravelSimulation), destinations(cList),
    distances(dList), total(t)
{
    ui->setupUi(this);

    // Initialize starting variables
    index         = 0;
    totalCost     = 0;
    totalDistance = 0;
    currCost      = 0;

    ui->totalCostLine->setText(QString::number(totalCost));
    ui->totalDistLine->setText(QString::number(totalDistance));
    ui->currDestCostLine->setText(QString::number(currCost));

    tTravelSimulation::loadTables();
    ui->endVacationButton->setEnabled(false);
    ui->goodbyeLabel->setVisible(false);
}

/****************************************************************************
 * METHOD - tTravelSimulation
 * --------------------------------------------------------------------------
 * This method is the destructor
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      None.
 *
 * POST-CONDITIONS
 *      ==> Returns nothing.
 ***************************************************************************/
tTravelSimulation::~tTravelSimulation()
{
    delete ui;
}

/****************************************************************************
 * METHOD - loadTables
 * --------------------------------------------------------------------------
 * This method loads the destinations into the list view and sets default
 * starting view.
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      None.
 *
 * POST-CONDITIONS
 *      ==> Returns nothing.
 ***************************************************************************/
void tTravelSimulation::loadTables()
{
    // Load all cities into list view
    for(int i = 0; i < total; i++)
    {
//      qDebug() << sortedDestinations[i] << ' ' << sortedDistance[i];
        qDebug() << "Total: " << total;
        ui->destinationWidget->addItem(destinations[i]);
    }

    // Set colors
    font.setBold(true);
    ui->destinationWidget->item(index)->setFont(font);
    ui->destinationWidget->item(index)->setForeground(Qt::yellow);
    ui->destinationWidget->item(index)->setBackground(Qt::black);

    updateFoods();
}

/****************************************************************************
 * METHOD - updateFoods
 * --------------------------------------------------------------------------
 * This method updates the food table view using values from the database
 * for the active city.
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      Database must exist and be open.
 *
 * POST-CONDITIONS
 *      ==> Returns nothing.
 ***************************************************************************/
void tTravelSimulation::updateFoods()
{
    int row = 0;        // CALC - Used to count rows for displaying to table
    int rowCount = 0;   // CALC - Used for number of rows needed for table

    // Get and display current city
    QString currCity = ui->destinationWidget->item(index)->text();
    ui->currCityLabel->setText(currCity);

    /************************************************************************
     * QUERY qryRows - Used to get the number of rows (rowCount) needed for
     *                 the table (foodTableWidget).
     ***********************************************************************/
    QSqlQuery qryRows;
    qryRows.prepare("SELECT foodName "
                    "FROM Food "
                    "WHERE City = '"+currCity+"'");

    // Count each row from the query
    qryRows.exec();
    while(qryRows.next())
    {
        rowCount++;
    }

//    qDebug() << "Row count: " << rowCount << endl;

    /************************************************************************
     * Modifying the table's (foodTableWidget's) display.
     ***********************************************************************/
    // Sets column and row
    ui->foodTableWidget->setColumnCount(3);
    ui->foodTableWidget->setRowCount(rowCount);
    // Sets name labels
    ui->foodTableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Qty"));
    ui->foodTableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Food Name"));
    ui->foodTableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("Price"));
    // Sets column widths
    ui->foodTableWidget->setColumnWidth(0, 50);
    ui->foodTableWidget->setColumnWidth(1, 200);
    ui->foodTableWidget->setColumnWidth(2, 50);

    /************************************************************************
     * QUERY qry - Used for displaying all food items and price into the
     *             table (foodTableWidget) for the current city (currCity).
     ***********************************************************************/
    QSqlQuery qry;
    qry.prepare("SELECT foodName, Price "
                "FROM Food "
                "WHERE City = '"+currCity+"'");

    if(qry.exec())
    {
        // Displays each row in foodTableWidget
        while(qry.next())
        {
            // Sets up column 1 view and text to display
            // Makes it uneditable
            QTableWidgetItem *item1 = new QTableWidgetItem;
            item1->setFlags(item1->flags() ^ Qt::ItemIsEnabled);
            item1->setTextColor(Qt::black);

            // Sets up column 2 view and text to display
            // Makes it uneditable
            // Includes two decimal place floating point precision
            QTableWidgetItem *item2 = new QTableWidgetItem;
            item2->setTextAlignment(Qt::AlignRight);
            item2->setFlags(item2->flags() ^ Qt::ItemIsEnabled);
            item2->setTextColor(Qt::black);
            item1->setText(qry.value(0).toString());
            item2->setText(QString::number(qry.value(1).toFloat(), 'f', 2));

            // Populate one row of the foodTableWidget
            ui->foodTableWidget->setCellWidget(row,0, new QSpinBox(ui->foodTableWidget));
            ui->foodTableWidget->setItem(row, 1, item1);
            ui->foodTableWidget->setItem(row, 2, item2);

            // Old method of populating table that is not uneditable
            // and lacks floating point precision
//            ui->foodTableWidget->setItem(row,1, new QTableWidgetItem(qry.value(0).toString()));
//            ui->foodTableWidget->setItem(row,2, new QTableWidgetItem(qry.value(1).toString()));

            row++;
        }
    }
    else
    {
       qDebug() << qry.lastError();
    }

    ui->nextDestButton->setEnabled(false);
}

/****************************************************************************
 * METHOD - on_exitSimulationButton_clicked
 * --------------------------------------------------------------------------
 * This method allows traveler to exit in the middle of the simulation.
 * It opens a message box then closes this object
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      None.
 *
 * POST-CONDITIONS
 *      ==> Returns nothing.
 ***************************************************************************/
void tTravelSimulation::on_exitSimulationButton_clicked()
{
    QMessageBox::information(this,"Cancel","Sad to see you go!",
                             QMessageBox::Ok);

    this->close();
}

/****************************************************************************
 * METHOD - on_endVacationButton_clicked
 * --------------------------------------------------------------------------
 * This method ends the simulation upon completion of the travel
 * simulation.
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      None.
 *
 * POST-CONDITIONS
 *      ==> Returns nothing.
 ***************************************************************************/
void tTravelSimulation::on_endVacationButton_clicked()
{
    this->close();
}

/****************************************************************************
 * METHOD - on_nextDestButton_clicked
 * --------------------------------------------------------------------------
 * This method updates view for the next destination in the list.
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      None.
 *
 * POST-CONDITIONS
 *      ==> Returns nothing.
 ***************************************************************************/
void tTravelSimulation::on_nextDestButton_clicked()
{
    /************************************************************************
     * Only execute the following codes if there is another city after
     * the current index.  The index changes inside the code, so there
     * must be at least one more city needed to run these codes.
     ***********************************************************************/
    if(index+1 < total)
    {
        // Reset last dest to default in listWidget
        font.setBold(false);
        ui->destinationWidget->item(index)->setFont(font);
        ui->destinationWidget->item(index)->setForeground(Qt::black);
        ui->destinationWidget->item(index)->setBackground(Qt::white);

        // Update Index
        index++;

        // Set current dest to active in listWidget
        font.setBold(true);
        ui->destinationWidget->item(index)->setFont(font);
        ui->destinationWidget->item(index)->setForeground(Qt::yellow);
        ui->destinationWidget->item(index)->setBackground(Qt::black);

        updateFoods();

        // Updates distance lines
        totalDistance = totalDistance + distances[index];
        ui->totalDistLine->setText(QString::number(totalDistance));

        // Updates cost lines
        totalCost = totalCost + currCost;
        ui->totalCostLine->setText(QString::number(totalCost));

        // Reset values
        ui->currDestCostLine->clear();
        ui->nextDestButton->setEnabled(false);
        if(index+1 >= total)
        {
            ui->nextDestButton->setText("End Vacation");
        }
    }
    else
    {
        // Updates cost lines
        totalCost = totalCost + currCost;
        ui->totalCostLine->setText(QString::number(totalCost));

        // Reset values
        ui->currDestCostLine->clear();
        ui->nextDestButton->setEnabled(false);

        ui->endVacationButton->setEnabled(true);
        ui->goodbyeLabel->setVisible(true);
        ui->exitSimulationButton->setEnabled(false);
    }
}

/****************************************************************************
 * METHOD - on_confirmFoodButton_clicked
 * --------------------------------------------------------------------------
 * This method generates the subtotal for the selected food items for the
 * current city.
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      None.
 *
 * POST-CONDITIONS
 *      ==> Returns nothing.
 ***************************************************************************/
void tTravelSimulation::on_confirmFoodButton_clicked()
{
    int i = 0;
    int itemQty = 0;
    float itemPrice = 0;
    currCost = 0;

    while(i < ui->foodTableWidget->rowCount())
    {
        itemQty = ui->foodTableWidget->cellWidget(i,0)->property("value").value<int>();
        itemPrice = (ui->foodTableWidget->item(i,2)->text()).toFloat();
        currCost = currCost + (itemQty * itemPrice);
        qDebug() << itemQty << " " << currCost;
    i++;
    }
    ui->currDestCostLine->setText(QString::number(currCost));
    ui->nextDestButton->setEnabled(true);
}
