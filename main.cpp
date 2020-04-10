#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include "compteur.h"
#include "game.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    Compteur aCompteur;
    Game game;


    engine.rootContext()->setContextProperty("vueObjetCpt", &aCompteur);
//    engine.rootContext()->setContextProperty("game", &game);

    const QUrl mainQml(QStringLiteral("qrc:/main.qml"));
    engine.load(mainQml);

    return app.exec();
}
