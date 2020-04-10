#ifndef GAME_H
#define GAME_H

#include <QObject>
#include<matrix.h>

using namespace std;

class Game : public QObject
{
    Q_OBJECT
public:
    explicit Game(QObject *parent = nullptr);

//    void startGame(int valeur);
//    void setTile(int x, int y, int value);
    Q_INVOKABLE void addTileRandom();
    Q_INVOKABLE void Move(int direction);
//    bool isGameOver();
signals:
//    void updateGame();
//    void updateScore();
//    void updateMaxScore();

private:
    tuple<bool, bool> isMovePossible(int row, int col, int nextRow, int nextCol);
    int size;
    int score;
    int scoreMax;
    Matrix * board = new Matrix(1);
    Matrix * fusionMatrix = new Matrix(1); // saves fusioned cells to prevent fusion of 3 cells in one move

};

#endif // GAME_H
