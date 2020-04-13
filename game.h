#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QList>
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
    Q_INVOKABLE void initGame();
    Q_INVOKABLE void setSize(int newSize);
    Q_INVOKABLE void isGameOver();
    void updateScores();

    Q_PROPERTY(QString scoreQML READ readScore NOTIFY scoresChanged)
    Q_PROPERTY(QString scoreMaxQML READ readScoreMax NOTIFY scoresChanged)
    Q_PROPERTY(QList<QString> tileQML READ readTiles NOTIFY tilesChanged)
    Q_PROPERTY(QString gameOverQML READ readGameOver NOTIFY gameOverChanged)
    QList<QString> readTiles();
    QString readScore();
    QString readScoreMax();
    QString readGameOver();

//    void DisplayBoard();
//    bool isGameOver();
signals:
    void scoresChanged();
    void tilesChanged();
    void gameOverChanged();



private:
    tuple<bool, bool> isMovePossible(int row, int col, int nextRow, int nextCol);
    int size;
    int score;
    int scoreMax;
    int gameOver;
    Matrix * board = new Matrix(1);
    Matrix * fusionMatrix = new Matrix(1); // saves fusioned cells to prevent fusion of 3 cells in one move

};

#endif // GAME_H
