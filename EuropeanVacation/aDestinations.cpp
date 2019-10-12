#include "aDestinations.h"
#include "ui_aDestinations.h"

//Default Constructor
aDestinations::aDestinations(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::aDestinations)
{
    ui->setupUi(this);
    //Create database and display the table
    myDB = QSqlDatabase::database();

    loadTableList();

}

//Destructor
aDestinations::~aDestinations()
{
    delete ui;
}



void aDestinations::on_addFile_clicked()
{
    QString start, end, kilometers;
    QSqlQuery *qry = new QSqlQuery(myDB);
    QString filter = "All File (*.*) ;; Text File (*.txt)";
    QString file_name = QFileDialog::getOpenFileName(this,"Open A File", "C://");
    QFile file(file_name);

    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this,"Warning","File Not Added.");
    }
    else
    {
        QMessageBox::information(this,"Success","File Added.");
    }

    QTextStream in(&file);

    while(!in.atEnd())
    {
        start = in.readLine();
        end = in.readLine();
        kilometers = in.readLine();


        qry->prepare("insert into Distances (Start,End,Kilometers) "
                    "values('"+start+"', '"+end+"', '"+kilometers+"') ");

        if(qry->exec())
        {

            qDebug() << "Database updated with file.";
        }
        else
        {
            qDebug() << "Failed to add file to Database.";
        }

    }
    in.readLine();
    file.close();

    loadTableList();
}

void aDestinations::loadTableList()
{
    QSqlQueryModel * model = new QSqlQueryModel();

    model->setQuery("SELECT Start, End, Kilometers "
                    "FROM Distances "
                    "ORDER BY Start ");


    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Starting location"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Destination"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Distance(km)"));

    ui->aDestinationOptionsTV->verticalHeader()->setVisible(false);
    ui->aDestinationOptionsTV->horizontalHeader()->setVisible(true);
    ui->aDestinationOptionsTV->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->aDestinationOptionsTV->setModel(model);



}


