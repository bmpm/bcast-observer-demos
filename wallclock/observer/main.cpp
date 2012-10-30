#include <QtDeclarative>
#include <QtGui/QApplication>
#include "qmlapplicationviewer.h"
#include "wallclockobserver.h"
#include "../../common/types.h"

Q_DECL_EXPORT int main(int argc, char *argv[])
{
    QScopedPointer<QApplication> app(createApplication(argc, argv));

    WallClockObserver *obs = new WallClockObserver(QCoreApplication::instance());

    if (!QDBusConnection::systemBus().registerObject(WALLCLOCK_OBSERVER_PATH,
                                                     obs,
                                                     QDBusConnection::ExportAllSlots))
        qWarning() << "Error registering wallclock observer on D-Bus.";

    QmlApplicationViewer viewer;
    viewer.rootContext()->setContextProperty("observer", obs);
    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    viewer.setMainQmlFile(QLatin1String("qml/observer/main.qml"));
    viewer.showExpanded();

    return app->exec();
}
