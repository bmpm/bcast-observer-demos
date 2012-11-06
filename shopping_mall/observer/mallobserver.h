#ifndef MALLOBSERVER_H
#define MALLOBSERVER_H

#include <QObject>

class MallObserver : public QObject
{
    Q_OBJECT
public:
    explicit MallObserver(QObject *parent = 0);
    
signals:
    
public slots:
    
};

#endif // MALLOBSERVER_H
