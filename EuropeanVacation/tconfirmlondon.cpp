#include "tconfirmlondon.h"
#include "ui_tconfirmlondon.h"
#include "ttravelsimulation.h"

tConfirmLondon::tConfirmLondon(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tConfirmLondon)
{
    ui->setupUi(this);

    QSqlQuery qry;
    QString testCity = "London";
    qry.prepare("SELECT * "
                "FROM Distances "
                "WHERE Start = '"+testCity+"'"
                "ORDER BY Kilometers ASC");
        rowCount = 1;

        qry.exec();
        while(qry.next())
        {
           rowCount++;
        }


    ui->numCitiesSpinBox->setMinimum(2);
    qDebug() << "ROW COUNT: " << rowCount;
    ui->numCitiesSpinBox->setMaximum(rowCount);
    on_numCitiesSpinBox_valueChanged();

}

tConfirmLondon::~tConfirmLondon()
{
    delete ui;
}

void tConfirmLondon::on_startSimulationButton_clicked()
{
    tTravelSimulationWindow1 = new tTravelSimulation();
    tTravelSimulationWindow1->show();
    this->close();
}

void tConfirmLondon::on_cancelButton_clicked()
{
    this->close();
}

void tConfirmLondon::on_numCitiesSpinBox_valueChanged()
{

    ui->LondonListWidget->clear();

    QString start = "London";

    int number = ui->numCitiesSpinBox->value();

    QString testCity;
    testCity = "London";

    QString arr[11];

    arr[0] = testCity;

    for(int i = 1; i<number;i++)
    {
        QSqlQuery qry;
        qry.prepare("SELECT * "
                    "FROM Distances "
                    "WHERE Start = '"+testCity+"'"
                    "ORDER BY Kilometers ASC");
        qry.exec();
        qry.next();

       QString idValue = qry.value(1).toString();

      for(int j=0; j<i; j++)
      {
          //qDebug() <<"here" << arr[j] << " " << idValue;
          if (idValue==arr[j])
          {
              //qDebug() <<"arr[j" << arr[j];
              qry.next();
              idValue = qry.value(1).toString();
              j=-1;
          }

      }



        //qDebug() << "ID VALUE" << idValue;

        arr[i] = idValue;

        testCity = idValue; //assign test city to the new city

    }

        qDebug() << "Printing array";

       for(int i = 0; i < number; i++)
       {
           qDebug() << arr[i];
          ui->LondonListWidget->addItem(arr[i]);
       }


       ui->LondonListWidget->show();

}




