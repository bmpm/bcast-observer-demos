#include "../../common/adapter.h"
#include "../../common/manager.h"
#include "../../common/types.h"

#include "mallobserver.h"

using namespace org::bluez;

MallObserver::MallObserver(QObject *parent) :
    ObserverAdaptor(parent), m_order("XXXX")
{
    Manager manager(BLUEZ_SERVICE_NAME, "/", QDBusConnection::systemBus());
    foreach (const QDBusObjectPath path, manager.adapters()) {
        Adapter adp(BLUEZ_SERVICE_NAME, path.path(),
                                  QDBusConnection::systemBus());
        adp.RegisterManufacturerObserver(QDBusObjectPath(FOODCOURT_OBSERVER_PATH),
                                         MALL_COMPANY_ID);
    }
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
        parseFoodCourt(value);
        break;
    default:
        qDebug() << "Invalid value";
    }
}

void MallObserver::parseFoodCourt(QByteArray value)
{
    /* Data format: Restaurant ID (1 octet)
                    Order Number (N octets) */

    int id = value.at(0);
    int size = value.size() - 1;
    bool ok;
    int order = value.right(size).toHex().toLong(&ok, 16);

    qDebug() << "Restaurant ID:" << id << "Order:" << order;

    m_order = QString::number(order);
    emit orderChanged();
}
