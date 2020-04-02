#include "compteur.h"

Compteur::Compteur(QObject *parent) : QObject(parent)
{
    fCompteur = 0;
    cptChanged();
}

QString Compteur::readCompteur(){
    return QString::number(fCompteur);
}

void Compteur::increment()
{
    fCompteur = fCompteur + 1000;
    cptChanged();
}

void Compteur::decrement()
{
    if (fCompteur>0)
        fCompteur--;
    cptChanged();
}
