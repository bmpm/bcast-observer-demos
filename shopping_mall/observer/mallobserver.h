#ifndef MALLOBSERVER_H
#define MALLOBSERVER_H

#include <QObject>

#include "../../common/observer.h"

class MallObserver : public ObserverAdaptor
{
    Q_OBJECT

    Q_PROPERTY(QString order READ order NOTIFY orderChanged);
    Q_PROPERTY(int restID WRITE setRestID);

public:
    explicit MallObserver(QObject *parent = 0);

    QString order() { return m_order; }

    void setRestID(int id) { m_restID = id; }

signals:
    void orderChanged();

public slots:
    void ManufacturerReceived(const QString &address, ushort cid,
                              const QByteArray &value);
private:
    QString m_order;

    int m_restID;

    void parseFoodCourt(QByteArray value);
};

#endif // MALLOBSERVER_H
