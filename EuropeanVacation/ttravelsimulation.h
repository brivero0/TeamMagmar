#ifndef TTRAVELSIMULATION_H
#define TTRAVELSIMULATION_H

#include <QWidget>

namespace Ui {
class tTravelSimulation;
}

class tTravelSimulation : public QWidget
{
    Q_OBJECT

public:
    explicit tTravelSimulation(QWidget *parent = nullptr);
    //!< Default Constructor

    explicit tTravelSimulation(QString* cList, int* dList, int,
                               QWidget *parent = nullptr);
    //!< Constructor (using passed in parameters)

    ~tTravelSimulation();
    //!< Destructor

    void loadTables();
    //!< Loads destination list with starting values

    void updateFoods();
    //!< Updates food table with values for current city active

private slots:
    void on_exitSimulationButton_clicked();
    //!< Opens messagebox and then closes simulation at any time

    void on_endVacationButton_clicked();
    //!< Closes this window after simulation is all done

    void on_nextDestButton_clicked();
    //!< Sets up view for next destination

    void on_confirmFoodButton_clicked();
    //!< Creates subtotal for foods of current city

private:
    Ui::tTravelSimulation *ui;  /*!< class object */
    QString* destinations = nullptr;
                                /*!< Pointer for dynamic destination list */
    int* distances = nullptr;   /*!< Pointer for dynamic distance list*/
    QString currCity;           /*!< Current city being visited */
    int currDistance;           /*!< Distance from last to current city */
    int totalDistance;          /*!< Total distance traveled thus far */
    float currCost;             /*!< Cost of meals at current city */
    float totalCost;            /*!< Meal cost in simulation thus far */
    int total;                  /*!< Number of destinations for simulation */
    int index;                  /*!< Used to locate index of current city */
    QFont font;                 /*!< Modified font attributes in QListView */
};

#endif // TTRAVELSIMULATION_H
