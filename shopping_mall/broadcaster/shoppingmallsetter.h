#ifndef SHOPPINGMALLSETTER_H
#define SHOPPINGMALLSETTER_H

#include <QObject>
#include "../../common/manager.h"
#include "../../common/adapter.h"

class ShoppingMallSetter : public QObject
{
    Q_OBJECT
public:
    explicit ShoppingMallSetter(QObject *parent = 0);
    virtual ~ShoppingMallSetter();
    
signals:
    
public slots:
    void setGeneralInfo(quint8 info_id);
    void setSpecialOffer(quint8 store, quint8 product, QString price);
    void setFoodCourt(quint8 restaurant, QString number);

private:
    org::bluez::Manager m_manager;
    QList<org::bluez::Adapter*> m_adapters;
};

#endif // SHOPPINGMALLSETTER_H
