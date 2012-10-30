#include <QtCore/QDataStream>
#include <QtCore/QTime>
#include "wallclockobserver.h"
#include "../../common/adapter.h"
#include "../../common/manager.h"
#include "../../common/types.h"

using namespace org::bluez;

WallClockObserver::WallClockObserver(QObject *parent)
    : ObserverAdaptor(parent)
{
    Manager manager(BLUEZ_SERVICE_NAME, "/", QDBusConnection::systemBus());
    foreach (const QDBusObjectPath path, manager.adapters()) {
        Adapter adp(BLUEZ_SERVICE_NAME, path.path(),
                                  QDBusConnection::systemBus());
        adp.RegisterManufacturerObserver(QDBusObjectPath(WALLCLOCK_OBSERVER_PATH),
                                         COMPANY_ID);
    }
}

void WallClockObserver::ManufacturerReceived(const QString &address, ushort cid,
                                             const QByteArray &value)
{
    qDebug() << address << cid << value.toHex();
    QDataStream ds(value);
    QTime time;
    ds >> time;
    m_hour = QString::number(time.hour());
    m_minute = QString::number(time.minute());
    m_second = QString::number(time.second());
    emit timeChanged();
}
