#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "datalistmodel.h"
#include "datalistproxymodel.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    DataListModel model;
    model.append( ModelData("wolf.jpg", "Medium") );
    model.append( ModelData("polarbear.jpg", "Large") );
    model.append( ModelData("quoll.jpg", "Small") );

    DataListProxyModel proxyModel;
    proxyModel.setSourceModel(&model);

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("myModel", &proxyModel);
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
