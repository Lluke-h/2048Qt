#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include "compteur.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    Compteur aCompteur;
    engine.rootContext()->setContextProperty("vueObjetCpt", &aCompteur);

    const QUrl mainQml(QStringLiteral("qrc:/main.qml"));
    engine.load(mainQml);

    return app.exec();
}
