#include "numberformatdelegate.h"

NumberFormatDelegate::NumberFormatDelegate(QObject *parent) :
    QStyledItemDelegate(parent)
{
}

/*****************************************************************
 * METHOD - displayText(const QVariant &value, const QLocale &locale) const
 * --------------------------------------------------------------------------
 * This method will reset the delete fields
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      The following variables must be declared and initialized:
 *          value  - value function
 *          locale -  locale function
 *
 * POST-CONDITIONS
 *      ==> Returns formattedNum: specified number format
 *****************************************************************/
QString NumberFormatDelegate::displayText(const QVariant &value, const QLocale &locale) const
{
    QString formattedNum = locale.toString(value.toDouble(), 'f', 2);
    return formattedNum;
}
