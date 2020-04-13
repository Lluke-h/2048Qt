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
    Q_INVOKABLE void move(int direction);
    Q_INVOKABLE void countScore();
    Q_INVOKABLE void initGame(int size);
    Q_INVOKABLE bool isGameOver();
    void updateScores();

    Q_PROPERTY(QString scoreQML READ readScore NOTIFY scoresChanged)
    Q_PROPERTY(QString scoreMaxQML READ readScoreMax NOTIFY scoresChanged)
    QString readScore();
    QString readScoreMax();

//    void DisplayBoard();
//    bool isGameOver();
signals:
    void scoresChanged();



private:
    tuple<bool, bool> isMovePossible(int row, int col, int nextRow, int nextCol);
    int size;
    int score;
    int scoreMax;
    Matrix * board = new Matrix(1);
    Matrix * fusionMatrix = new Matrix(1); // saves fusioned cells to prevent fusion of 3 cells in one move

};

#endif // GAME_H
