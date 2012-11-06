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

void ShoppingMallSetter::setSpecialOffer(quint8 store, quint8 product, QString sprice)
{
    QByteArray data;
    QDataStream ds(&data, QIODevice::WriteOnly);
    quint8 msg_type = SPECIAL_OFFERS;
    bool ok;
    sprice.toFloat(&ok);
    quint32 price = 0;

    if (ok) {
        int pos = sprice.indexOf(",");
        if (pos < 0)
            pos = sprice.indexOf(".");

        if (pos < 0) {
            price = sprice.toInt(NULL) * 100;      /* "10" -> 1000 */
        } else {
            if (sprice.length() == pos + 1)        /* "10," -> "10,0" */
                sprice.append('0');

            if (sprice.length() == pos + 2)        /* "10,2" -> "10,20" */
                sprice.append('0');

            sprice[pos] = sprice[pos+1];           /* "10,20" -> "10220" */
            sprice[pos+1] = sprice[pos+2];         /* "10200" */
            sprice.remove(pos+2, sprice.length()); /* "1020" */
            price = sprice.toInt(NULL);            /* "1020" -> 1020 */
        }
    }

    qDebug() << "Store:" << store << ", Product:" << product << ", Price:" << price;

    ds << msg_type;
    ds << store;
    ds << product;
    ds << price;

    foreach (Adapter *adapter, m_adapters)
        adapter->SetManufacturerData(MALL_COMPANY_ID, data);
}
