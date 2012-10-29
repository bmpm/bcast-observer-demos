#include <QtCore/QDataStream>
#include <QtCore/QTime>
#include "wallclocksetter.h"
#include "../../common/types.h"

using namespace org::bluez;

WallClockSetter::WallClockSetter(QObject *parent)
    : QObject(parent)
    , m_manager(BLUEZ_SERVICE_NAME, "/", QDBusConnection::systemBus())
{
    foreach (const QDBusObjectPath path, m_manager.adapters())
        m_adapters.append(new Adapter(BLUEZ_SERVICE_NAME, path.path(),
                                  QDBusConnection::systemBus()));

    qDebug() << m_adapters.count() << "adapter(s) found.";
}

WallClockSetter::~WallClockSetter()
{
    foreach (Adapter *adapter, m_adapters)
        delete adapter;
}

void WallClockSetter::setTime(const QString &h, const QString &m, const QString &s)
{
    QByteArray data;
    QDataStream ds(&data, QIODevice::WriteOnly);

    qDebug() << "setting time" << h << m << s;

    ds << QTime(h.toInt(), m.toInt(), s.toInt());

    foreach (Adapter *adapter, m_adapters)
        adapter->SetManufacturerData(COMPANY_ID, data);
}
