#include <QtGui/QApplication>
#include <QtDeclarative>
#include "qmlapplicationviewer.h"
#include "wallclocksetter.h"

Q_DECL_EXPORT int main(int argc, char *argv[])
{
    QScopedPointer<QApplication> app(createApplication(argc, argv));

    qmlRegisterType<WallClockSetter>("com.indt.components", 1, 0, "WallClockSetter");

    QmlApplicationViewer viewer;
    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    viewer.setMainQmlFile(QLatin1String("qml/broadcaster/main.qml"));
    viewer.showExpanded();

    return app->exec();
}
