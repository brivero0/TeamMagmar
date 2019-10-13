#include "ttravelsimulation.h"
#include "ui_ttravelsimulation.h"
#include "tconfirmparis.h"
#include <QMessageBox>

tTravelSimulation::tTravelSimulation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tTravelSimulation)
{
    ui->setupUi(this);
}

tTravelSimulation::tTravelSimulation(QString* cList, int* dList, int t, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tTravelSimulation), destinations(cList), distances(dList), total(t)
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
}

tTravelSimulation::~tTravelSimulation()
{
    delete ui;
}

void tTravelSimulation::loadTables()
{
    for(int i = 0; i < total; i++)
    {
//      qDebug() << sortedDestinations[i] << ' ' << sortedDistance[i];
        qDebug() << "Total: " << total;
        ui->destinationWidget->addItem(destinations[i]);
        ui->listWidget_2->addItem(QString::number(distances[i]));
    }

    font.setBold(true);
    ui->destinationWidget->item(index)->setFont(font);
    ui->destinationWidget->item(index)->setForeground(Qt::red);
    ui->destinationWidget->item(index)->setBackground(Qt::black);

    updateFoods();
}

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
}

void tTravelSimulation::on_exitSimulationButton_clicked()
{
    QMessageBox::information(this,"Cancel","Sad to see you go!", QMessageBox::Ok);

    this->close();
}

void tTravelSimulation::on_endVacationButton_clicked()
{
    this->close();
}

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
        ui->destinationWidget->item(index)->setForeground(Qt::red);
        ui->destinationWidget->item(index)->setBackground(Qt::black);

        updateFoods();

        // Updates distance lines
        totalDistance = totalDistance + distances[index];
        ui->totalDistLine->setText(QString::number(totalDistance));
    }

}
