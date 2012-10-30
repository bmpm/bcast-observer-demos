#ifndef WALLCLOCKOBSERVER_H
#define WALLCLOCKOBSERVER_H

#include <QtCore/QObject>
#include "../../common/observer.h"

class WallClockObserver : public ObserverAdaptor
{
    Q_OBJECT

    Q_PROPERTY(QString hour READ hour NOTIFY timeChanged);
    Q_PROPERTY(QString minute READ minute NOTIFY timeChanged);
    Q_PROPERTY(QString second READ second NOTIFY timeChanged);
public:
    explicit WallClockObserver(QObject *parent = 0);

    QString hour() { return m_hour; }
    QString minute() { return m_minute; }
    QString second() { return m_second; }

signals:
    void timeChanged();

public slots:
    void ManufacturerReceived(const QString &address, ushort cid,
                              const QByteArray &value);

private:
    QString m_hour;
    QString m_minute;
    QString m_second;
};

#endif // WALLCLOCKOBSERVER_H
