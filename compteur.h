#ifndef COMPTEUR_H
#define COMPTEUR_H

#include <QObject>

class Compteur : public QObject
{
    Q_OBJECT
public:
    explicit Compteur(QObject *parent = nullptr);

    Q_PROPERTY(QString cptQML READ readCompteur NOTIFY cptChanged)

    QString readCompteur();

    Q_INVOKABLE void increment();
    Q_INVOKABLE void decrement();

signals:
    void cptChanged();

public slots:

private:
    int fCompteur;
};

#endif // COMPTEUR_H
