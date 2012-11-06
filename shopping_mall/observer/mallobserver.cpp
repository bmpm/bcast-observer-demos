#include "../../common/types.h"

#include "mallobserver.h"

MallObserver::MallObserver(QObject *parent) :
    ObserverAdaptor(parent)
{
}

void MallObserver::ManufacturerReceived(const QString &address, ushort cid,
                                             const QByteArray &value)
{
    qDebug() << address << cid << value.toHex();

    switch (value[0]) {
    case GEN_INFO:
        qDebug() << "General Information";
        break;
    case SPECIAL_OFFERS:
        qDebug() << "Special Offers";
        break;
    case FOOD_COURT:
        qDebug() << "Food Court";
        break;
    default:
        qDebug() << "Invalid value";
    }
}
