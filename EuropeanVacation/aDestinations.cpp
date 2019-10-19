#include "aDestinations.h"
#include "ui_aDestinations.h"

/*****************************************************************
 * aDestinations::aDestinations(QWidget *parent) : QWidget(parent),
 *                                       ui(new Ui::aDestinations)
 * ---------------------------------------------------------------
 *  non-default constructor
 * ---------------------------------------------------------------
 * PRE-CONDITIONS
 *      The following variables must be declared and initialized:
 *          parent  : QWidget
 *
 * POST-CONDITIONS
 *      ==> Returns nothing class is instantiated
 *****************************************************************/

aDestinations::aDestinations(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::aDestinations)
{
    ui->setupUi(this);
    //Create database and display the table
    myDB = QSqlDatabase::database();

    loadTableList();

}

/*****************************************************************
 * aDestinations::~aDestinations()
 * ---------------------------------------------------------------
 *  Default Destructor
 * ---------------------------------------------------------------
 * PRE-CONDITIONS
 *      The following variables must be declared and initialized:
 *          none
 *
 * POST-CONDITIONS
 *      ==> Returns nothing
 *****************************************************************/
aDestinations::~aDestinations()
{
    delete ui;
}

/*****************************************************************
 * void aDestinations::on_addFile_clicked()
 * ---------------------------------------------------------------
 *  adds file to database
 * ---------------------------------------------------------------
 * PRE-CONDITIONS
 *      The following variables must be declared and initialized:
 *          none
 *
 * POST-CONDITIONS
 *      ==> Returns nothing file is added to database
 *****************************************************************/
void aDestinations::on_addFile_clicked()
{
    QString start, end, kilometers; //IN, CALC - data fields for database
    QSqlQuery *qry = new QSqlQuery(myDB); //IN, CALC - database query
    QString filter = "All File (*.*) ;; Text File (*.txt)"; // CALC - file filter
    QString file_name = QFileDialog::getOpenFileName(this,"Open A File", "C://"); // IN, CALC - file name
    QFile file(file_name); // CALC - QFile input file

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

/*****************************************************************
 * void aDestinations::loadTableList()
 * ---------------------------------------------------------------
 *  Outputs destination database in table format
 * ---------------------------------------------------------------
 * PRE-CONDITIONS
 *      The following variables must be declared and initialized:
 *          none
 *
 * POST-CONDITIONS
 *      ==> Returns nothing destination database output
 *****************************************************************/

void aDestinations::loadTableList()
{
    QSqlQueryModel * model = new QSqlQueryModel(); //IN, CALC, OUT - destination databasee table

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


