#ifndef MALLOBSERVER_H
#define MALLOBSERVER_H

#include <QObject>

#include "../../common/observer.h"

class MallObserver : public ObserverAdaptor
{
    Q_OBJECT

    Q_PROPERTY(QString order READ order NOTIFY orderChanged);
    Q_PROPERTY(int restID WRITE setRestID);
    Q_PROPERTY(int infoID READ infoID NOTIFY infoIDChanged);

    Q_PROPERTY(int product READ product NOTIFY offerChanged);
    Q_PROPERTY(int store READ store NOTIFY offerChanged);
    Q_PROPERTY(QString price READ price NOTIFY offerChanged);

public:
    explicit MallObserver(QObject *parent = 0);

    QString order() { return m_order; }
    int infoID() { return m_infoID; }

    void setRestID(int id) { m_restID = id; }

    int product() { return m_product; }
    int store() { return m_store; }
    QString price() { return m_price; }

signals:
    void orderChanged();
    void infoIDChanged();
    void offerChanged();

public slots:
    void ManufacturerReceived(const QString &address, ushort cid,
                              const QByteArray &value);
private:
    QString m_order;

    int m_restID;
    int m_infoID;

    int m_product;
    int m_store;
    QString m_price;

    void parseFoodCourt(QByteArray value);
    void parseGenInfo(QByteArray value);
    void parseSpecialOffer(QByteArray value);
};

#endif // MALLOBSERVER_H
