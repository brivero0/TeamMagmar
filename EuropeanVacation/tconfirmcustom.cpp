#include "tconfirmcustom.h"
#include "ui_tconfirmcustom.h"

tConfirmCustom::tConfirmCustom(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tConfirmCustom)
{
    ui->setupUi(this);

    myDB = QSqlDatabase::database();

    defaultListView();
    defaultView();
    ui->startSimulationButton->setEnabled(false);
}

tConfirmCustom::~tConfirmCustom()
{
    delete ui;
}

void tConfirmCustom::defaultListView()
{
    QString cityName; // Place holder for setting up List

    QSqlQuery * qry = new QSqlQuery(myDB);

    qry->prepare("SELECT DISTINCT Start "
                    "FROM Distances "
                    "ORDER BY Start COLLATE NOCASE ASC ");

    if(qry->exec())
    {
        // Populating list from query
        while(qry->next())
        {
            cityName = qry->value(0).toString();
            ui->availDestListWidget->addItem(cityName);
        }
    }
    else
    {
        qDebug() << ("tConfirmCustom Error: qry failed.");
    }
}

void tConfirmCustom::defaultView()
{
    ui->confirmListWidget->clear();
    ui->confirmSelectionButon->setEnabled(true);
    ui->availDestListWidget->setEnabled(true);
    ui->confirmListWidget->setEnabled(false);
    ui->startCityComboBox->clear();
    customList.clear();
}

void tConfirmCustom::sortList()
{
    QString temp; // used as temporary storage while swapping
    sortedDestinations = new QString[cityNum];
    sortedDistance = new int[cityNum];

    /************************************************************************
     * PROCESS: Copy contents of customList (traveler's selected citites)
     *          into tempList (QVector <QString> array).
     ***********************************************************************/
    for(int i = 0; i < customList.count(); i++)
    {
        temp = customList.at(i)->text();
        sortedDestinations[i] = temp;
    }

    qDebug() << "size: " << cityNum;

    /************************************************************************
     * PROCESS: Check if traveler's selected startCity is index 0 in
     *          sortedDestinationList array.
     *          If startCity is not at index 0, swap position.
     ***********************************************************************/
    if(sortedDestinations[0] != startCity)
    {
        int index = 0;

        // Find index location of the startCity
        while(index < cityNum &&
              sortedDestinations[index] != startCity)
        {
            index++;
        }

        // Do the swap
        temp = sortedDestinations[index];
        sortedDestinations[index] = sortedDestinations[0];
        sortedDestinations[0] = temp;
    }

    // Redundant code
    // Make sure startCity is first element in array
    startCity = sortedDestinations[0];
    sortedDistance[0] = 0;

    qDebug() << "start city: " << startCity;
    
    /************************************************************************
     * PROCESS: Sort array from index 1 to n (max index) -1.
     *          Index 0 is the start destination.
     *          Index n (max index for array) is last element, which does
     *              not require sorting.  It is the end.
     ***********************************************************************/
    for(int i = 1; i < (cityNum-1); i++)
    {
        bool isFound = false; // CALC - used to determine if closestCity
                              //        to the startCity is a remaining
                              //        city in the array.
        int  j = i;           // CALC - used to check the remaining array
                              //        for closestCity not yet sorted


        // Create query for list of cities closest to the startCity in order
        // by distance.
        QSqlQuery sortQry;
        sortQry.prepare("SELECT * "
                        "FROM Distances "
                        "WHERE Start = '"+startCity+"' "
                        "ORDER BY Kilometers ASC");
        sortQry.exec();

        // Select first row of query and set closestCity to first item
        sortQry.next();
        closestCity = sortQry.value(1).toString();

        qDebug() << "The next closest city is: " << closestCity;

        /********************************************************************
         * PROCESS: Find next closestCity to the StartCity that is in the
         *          array sortedDestinationList.
         *******************************************************************/
        while(!isFound)
        {
            // Stay within array boundry
            if(j < cityNum)
            {
                // closestCity found
                if(closestCity == sortedDestinations[j])
                {
                    isFound = true;
                    qDebug() << "It matches next item in array: "
                             << closestCity << endl;
                }
                // Check next element in array
                else
                {
                    qDebug() << "It does not match next item in array: "
                             << closestCity << endl;
                    j++;
                }
            }
            // If out of array boundry, move to next row in query and make
            // that city the next closestCity
            else
            {
                j = i;
                sortQry.next();
                closestCity = sortQry.value(1).toString();
            }
        }

        // If closestCity is found in the array, do the swap
        if(isFound)
        {
            temp = sortedDestinations[j];
            sortedDestinations[j] = sortedDestinations[i];
            sortedDestinations[i] = temp;
            startCity = sortedDestinations[i];
            sortedDistance[i] = sortQry.value(2).toInt();

            qDebug() << sortedDestinations[i];
        }

        qDebug() << "start city: " << startCity;
    }

    closestCity = sortedDestinations[cityNum-1];

    // Last destination distance in list
    QSqlQuery qry;
    qry.prepare("SELECT * "
                "FROM Distances "
                "WHERE Start = '"+startCity+"' AND End = '"+closestCity+"' "
                "ORDER BY Kilometers ASC");
    qry.exec();
    // Select first row of query and set closestCity to first item
    qry.next();
    sortedDistance[cityNum-1] = qry.value(2).toInt();
}

void tConfirmCustom::on_resetSelectionButton_clicked()
{
    ui->availDestListWidget->reset();
    ui->stackedWidget->setCurrentIndex(0);
    defaultView();
    ui->startSimulationButton->setEnabled(false);
}

void tConfirmCustom::on_confirmSelectionButon_clicked()
{
    // Stores selected items from availDestListWidget into customList
    customList = ui->availDestListWidget->selectedItems();
    cityNum = customList.count();

    if(cityNum >= 2)
    {
        ui->startCityComboBox->addItem(" ");

        for(int i = 0; i < cityNum; i++)
        {
            ui->confirmListWidget->addItem(customList.at(i)->text());
            ui->startCityComboBox->addItem(customList.at(i)->text());
            qDebug() << "selected item : " << customList.at(i)->text()
                     << " , row number id " << ui->availDestListWidget->row(customList.at(i));
        }

        ui->confirmSelectionButon->setEnabled(false);
        ui->availDestListWidget->setEnabled(false);
        ui->confirmListWidget->setEnabled(true);
        ui->stackedWidget->setCurrentIndex(1);
    }
}

void tConfirmCustom::on_startCityComboBox_currentIndexChanged(int index)
{
    if(index != 0)
    {
        startCity = ui->startCityComboBox->currentText();
        ui->startSimulationButton->setEnabled(true);
    }
    else
    {
        ui->startSimulationButton->setEnabled(false);
    }
}

void tConfirmCustom::on_startSimulationButton_clicked()
{
    sortList();

    tTravelSimulationWindow = new tTravelSimulation(sortedDestinations, sortedDistance, cityNum);
    tTravelSimulationWindow->show();

    sortedDestinations = nullptr;
    sortedDistance = nullptr;

    this->close();
}

void tConfirmCustom::on_cancelButton_clicked()
{
    this->close();
}
