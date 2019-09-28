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
    ui->startSimulationButton->setEnabled(false);
    ui->confirmListWidget->setEnabled(false);
    ui->startCityComboBox->clear();
    customList.clear();
}

void tConfirmCustom::sortList()
{
    QString temp; // used as temporary storage while swapping

    // Transfer customList (selected cities) into tempList to use as argument
    for(int i = 0; i < customList.count(); i++)
    {
        temp = customList.at(i)->text();
        sortedDestinationList.push_back(temp);
    }

qDebug() << "size: " << sortedDestinationList.size();

    // If startCity is not index 0, swap.
    if(sortedDestinationList[0] != startCity)
    {
        int index = 0;


        while(index < sortedDestinationList.size() && sortedDestinationList[index] != startCity)
        {
            index++;
        }

        // swap
        temp = sortedDestinationList[index];
        sortedDestinationList[index] = sortedDestinationList[0];
        sortedDestinationList[0] = temp;
    }

    // Do other sorts here so final vector list is ready for simulation
}

void tConfirmCustom::on_resetSelectionButton_clicked()
{
    ui->availDestListWidget->reset();
    ui->stackedWidget->setCurrentIndex(0);
    defaultView();
}

void tConfirmCustom::on_confirmSelectionButon_clicked()
{
    // Stores selected items from availDestListWidget into customList
    customList = ui->availDestListWidget->selectedItems();

    ui->startCityComboBox->addItem(" ");

    for(int i = 0; i < customList.count(); i++)
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

    tTravelSimulationWindow2 = new tTravelSimulation();
    tTravelSimulationWindow2->show();
    tTravelSimulationWindow2->getList(sortedDestinationList);

    this->close();
}

void tConfirmCustom::on_cancelButton_clicked()
{
    this->close();
}
