#ifndef WALLCLOCKSETTER_H
#define WALLCLOCKSETTER_H

#include <QtCore/QObject>
#include "../../common/adapter.h"
#include "../../common/manager.h"

class WallClockSetter : public QObject
{
    Q_OBJECT
public:
    explicit WallClockSetter(QObject *parent = 0);
    virtual ~WallClockSetter();
    
public slots:
    void setTime(const QString &h, const QString &m, const QString &s);

private:
    org::bluez::Manager m_manager;
    QList<org::bluez::Adapter*> m_adapters;
};

#endif // WALLCLOCKSETTER_H
