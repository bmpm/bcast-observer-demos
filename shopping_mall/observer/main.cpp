#include <QtDeclarative>
#include <QtGui/QApplication>
#include "qmlapplicationviewer.h"


#include "mallobserver.h"
#include "../../common/types.h"

Q_DECL_EXPORT int main(int argc, char *argv[])
{
    QScopedPointer<QApplication> app(createApplication(argc, argv));

    MallObserver *obs = new MallObserver(QCoreApplication::instance());
    if (!QDBusConnection::systemBus().registerObject(FOODCOURT_OBSERVER_PATH,
                                                     obs,
                                                     QDBusConnection::ExportAllSlots))
        qWarning() << "Error registering shopping mall observer on D-Bus.";

    QmlApplicationViewer viewer;
    viewer.rootContext()->setContextProperty("observer", obs);
    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    viewer.setMainQmlFile(QLatin1String("qml/observer/main.qml"));
    viewer.showExpanded();

    return app->exec();
}
