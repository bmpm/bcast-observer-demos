#include "../../common/adapter.h"
#include "../../common/manager.h"
#include "../../common/types.h"

#include "mallobserver.h"

using namespace org::bluez;

MallObserver::MallObserver(QObject *parent) :
    ObserverAdaptor(parent), m_order("XXXX"), m_restID(0), m_infoID(-1),
    m_product(0), m_store(0), m_price(-1)
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

    /* For all events, remove first octet. It represents only the info type
       and does not be parsed */
    QByteArray newValue = value.right(value.size() - 1);

    switch (value[0]) {
    case GEN_INFO:
        qDebug() << "General Information";
        parseGenInfo(newValue);
        break;
    case SPECIAL_OFFERS:
        qDebug() << "Special Offers";
        parseSpecialOffer(newValue);
        break;
    case FOOD_COURT:
        qDebug() << "Food Court";
        parseFoodCourt(newValue);
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

    if (m_restID == id) {
        m_order = QString::number(order);
        emit orderChanged();
    }
}

void MallObserver::parseGenInfo(QByteArray value)
{
    /* Data format: Info ID (1 octet) */

    bool ok;

    m_infoID = value.toHex().toLong(&ok, 16);
    qDebug() << "Info ID:" << m_infoID;

    emit infoIDChanged();
}

void MallObserver::parseSpecialOffer(QByteArray value)
{
    /* Data format: Store ID (1 octet)
                    Product ID (1 octet)
                    Price (2 octets) */

    int size = value.size() - 2;
    bool ok;

    m_store = value.at(0);
    m_product = value.at(1);

    m_price =  value.right(size).toHex().toLong(&ok, 16);
    m_price /= 100;
    qDebug() << "Store ID:" << m_store << "Product ID:" << m_product << "Price:" << m_price;

    emit offerChanged();
}
