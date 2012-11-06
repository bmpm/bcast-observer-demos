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

public:
    explicit MallObserver(QObject *parent = 0);

    QString order() { return m_order; }
    int infoID() { return m_infoID; }

    void setRestID(int id) { m_restID = id; }

signals:
    void orderChanged();
    void infoIDChanged();

public slots:
    void ManufacturerReceived(const QString &address, ushort cid,
                              const QByteArray &value);
private:
    QString m_order;

    int m_restID;
    int m_infoID;

    void parseFoodCourt(QByteArray value);
    void parseGenInfo(QByteArray value);
};

#endif // MALLOBSERVER_H
