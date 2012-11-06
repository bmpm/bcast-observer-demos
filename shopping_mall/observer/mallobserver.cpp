#include "../../common/adapter.h"
#include "../../common/manager.h"
#include "../../common/types.h"

#include "mallobserver.h"

using namespace org::bluez;

MallObserver::MallObserver(QObject *parent) :
    ObserverAdaptor(parent)
{
    Manager manager(BLUEZ_SERVICE_NAME, "/", QDBusConnection::systemBus());
    foreach (const QDBusObjectPath path, manager.adapters()) {
        Adapter adp(BLUEZ_SERVICE_NAME, path.path(),
                                  QDBusConnection::systemBus());
        adp.RegisterManufacturerObserver(QDBusObjectPath(MALL_OBSERVER_PATH),
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
        break;
    default:
        qDebug() << "Invalid value";
    }
}
