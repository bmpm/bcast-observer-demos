#include "shoppingmallsetter.h"
#include "../../common/types.h"

#include <QDBusConnection>
#include <QDebug>

using namespace org::bluez;

ShoppingMallSetter::ShoppingMallSetter(QObject *parent)
    : QObject(parent)
    , m_manager(BLUEZ_SERVICE_NAME, "/", QDBusConnection::systemBus())
{
    foreach (const QDBusObjectPath path, m_manager.adapters())
        m_adapters.append(new Adapter(BLUEZ_SERVICE_NAME, path.path(),
                                  QDBusConnection::systemBus()));

    qDebug() << m_adapters.count() << "adapter(s) found.";
}

ShoppingMallSetter::~ShoppingMallSetter()
{
    foreach (Adapter *adapter, m_adapters)
        delete adapter;
}

void ShoppingMallSetter::setGeneralInfo(quint8 info_id)
{
    QByteArray data;
    QDataStream ds(&data, QIODevice::WriteOnly);
    quint8 msg_type = GEN_INFO;

    qDebug() << "setGeneralInfo:" << info_id;

    ds << msg_type;
    ds << info_id;

    foreach (Adapter *adapter, m_adapters)
        adapter->SetManufacturerData(MALL_COMPANY_ID, data);
}
