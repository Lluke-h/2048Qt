#ifndef GAME_H
#define GAME_H

#include <QObject>
#include<matrix.h>

class Game : public QObject
{
    Q_OBJECT
public:
    explicit Game(QObject *parent = nullptr);

//    void startGame(int valeur);
//    void setTile(int x, int y, int value);
    Q_INVOKABLE void addTileRandom();
//    Q_INVOKABLE void Move(int direction);
//    bool isGameOver();
signals:
//    void updateGame();
//    void updateScore();
//    void updateMaxScore();

private:

    int size;
    int score;
    int scoreMax;
    Matrix * board = new Matrix(3);

};

#endif // GAME_H
