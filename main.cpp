#include <QApplication>
#include <QObject>
#include <QQmlComponent>
#include <QQmlApplicationEngine>
#include <QQuickWindow>
#include <QSurfaceFormat>

#include "board.h"

using namespace tile;

int main(int argc, char ** argv)
{

    QApplication app(argc, argv);

    qmlRegisterSingletonType<board>("com.ics.board", 1, 0, "board", board::getInstace);
    QQmlApplicationEngine engine;
    engine.load(QUrl("qrc:/main.qml"));
    return app.exec();
}
