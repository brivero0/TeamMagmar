#ifndef DATABASEMANGER_H
#define DATABASEMANGER_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlError>

/****************************************************************************
 * SQLite FILENAME: BulkClubDB.db
 * --------------------------------------------------------------------------
 * TABLES:
 *      MembershipDB
 *          customerName (Text) : customer name
 *          membershipNumber (Integer) : membership number unique id
 *          membershipType (Text) : membership type (Regular or Executive)
 *          expireDate (Text) : membership expiration date (MM/DD/YYYY)
 *          monthExpire (Integer) : month membership expires (MM)
 *          dayExpire (Integer) : day membership expires (DD)
 *          yearExpire (Integer) : year membership expires (YYYY)
 *          totalAmountSpent (Real) : total amount spent (xx.xx)
 *          rebateAmount (Real) : rebate amount for executive members (xx.xx)
 *          isActive (Text) : if membership is active (True or False)
 *      asdf
 ***************************************************************************/
class databaseManger : public QObject
{
public:
    explicit databaseManger();
    ~databaseManger();

    bool openDB();
    //!< Creates and opens a database connection if not open
    /*!< POSTCONDITONS: return database.open(); */

    bool closeDB();
    //!< Closes database connection
    /*!< POSTCONDITONS: return database.isOpen() */

    QSqlError lastError();
    //!< Returns last database related error
    /*!< POSTCONDITONS: return database.lastError(); */

    QSqlDatabase currentDB() const;
    //!< Returns connected database object
    /*!< POSTCONDITONS: return database */

private:
    QSqlDatabase database; // SQL Database Object created for connection
};

#endif // DATABASEMANGER_H
