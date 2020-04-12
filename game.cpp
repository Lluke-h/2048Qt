#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <iomanip>
#include <QQuickView>
#include <QObject>
#include<QString>
#include <QQmlContext>
#include <QQmlEngine>
#include <QQmlComponent>


#include "game.h"

using namespace std;



Game::Game(QObject *parent) : QObject(parent)
{
    size = 4;
    score = 0;
    scoreMax = 0;
    board->Resize(size);
    fusionMatrix->Resize(size);
    board->Print();
    initGame();
    board->Print();
    score = setScore(score, size);
    scoreMax = setScoreMax(score, scoreMax);
    cout << "========================= SCORE " << score << endl;
    for (int i= 0; i < 6; i++){
        move(3);
        board->Print();
        score = setScore(score, size);
        scoreMax = setScoreMax(score, scoreMax);
        cout << "========================= SCORE " << score << endl;
    }


//    DisplayBoard();
//    updateGame();
}


tuple<bool, bool> Game::isMovePossible(int row, int col, int nextRow, int nextCol)
{
    bool movePossible = true;
    bool isFusion = false;
    if (nextRow<0 || nextRow>=size || nextCol<0 || nextCol>=size // index in range
        || (board->Get(row, col) != board->Get(nextRow, nextCol)
            && board->Get(nextRow, nextCol) != 0)                // The move is legal
        || board->Get(row, col) == 0                             // The cell to move is not empty
        || fusionMatrix->Get(nextRow, nextCol) == 1             // next cell has already been fused this move
        || fusionMatrix->Get(row, col) ==1)
    {
        movePossible = false;
    }


    else if (board->Get(nextRow, nextCol) != 0) // if there is a fusion
    {
        isFusion = true;
    }
    return {movePossible, isFusion};
}

void Game::move(int direction)
{
    int startRow = 0, startCol = 0, rowStep = 1, colStep = 1;
    int rowDir[] = {1, 0, -1, 0};
    int colDir[] = {0, 1, 0, -1};
    fusionMatrix->InitMatrix(0);

    bool somethingMoved, addTile = false;

    if (direction == 0)
    {
        startRow = size -1;
        rowStep = -1;
    }

    if (direction == 1)
    {
        startCol = size -1;
        colStep = -1;
    }
    do{
        cout << "LLLLLLLLLLLLLLOOOOOOOOOOOOOOOOOOOOOOP" << endl;
        somethingMoved = false;
        for (int i = startRow; i>=0 && i<size; i += rowStep)
            for (int j = startCol; j>=0 && j<size; j+= colStep)
            {
                int nextRow = i + rowDir[direction], nextCol = j + colDir[direction];
                auto [movePossible, isFusion] = isMovePossible(i, j, nextRow, nextCol);
                if (movePossible)
                {
                    board->Set(nextRow, nextCol,board->Get(nextRow, nextCol) + board->Get(i,j) );
                    board->Set(i,j,0);
                    somethingMoved = true; addTile = true;
                    if (isFusion)
                    {
                        fusionMatrix->Set(nextRow, nextCol, 1);                       
                    }
                }

                }


            }while(somethingMoved);


    if (addTile)
        addTileRandom();

}



//void Game::updateGame(int size, int score, int scoreM)
//{

//}

void Game::initGame(){
    addTileRandom();
    addTileRandom();
}

void Game::addTileRandom()
{
    srand(time(NULL));
    bool notAdded = true;
    int c = 0;
    while (notAdded && c<10)
    {
        int i = rand() % size ;
        int j = rand()% size ;
        int n = 2 + (rand()%10>7)*2; // adds mostly twos, one in five chance of adding a four
        c++;
        if (board->Get(i, j) == 0)
        {
            board->Set(i, j, n);
            notAdded = false;
        }
    }




}

int Game::countTiles(int size)
{
    int tot = 0;
    for(int i = 0; i<size; i++){
        for (int j = 0; j<size; j++){
            tot += (board->Get(i,j));
            //cout << "On get" << tot << endl;
        }
    }

    return tot;
}

int Game::setScore(int score, int size){
    int tot = 0;
    int c;
    for(int i = 0; i<size; i++){
        for (int j = 0; j<size; j++){
            c = (fusionMatrix->Get(i,j));
            if (c == 1)
                tot += board->Get(i,j);
        }
    }
    score += tot;

    return score;
}

int Game::setScoreMax(int score, int scoreMax){
    if (score > scoreMax)
        return score;
    else
        return scoreMax;
}
//void Game::setTile(int x, int y, int value)
//{

//}

//bool Game::isGameOver()
//{
//    return false;
//}

//void Game::DisplayBoard()
//{
//    QQmlEngine engine;
//    QQmlComponent tile(&engine,QUrl::fromLocalFile("Tile.qml"));
//    QObject *myTile = tile.create();
//    QObject *window = object->findChild<QObject*>("window");
//    if (rect)
//        rect->setProperty("color", "red");
//}
