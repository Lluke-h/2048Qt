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
    bool notOver = true;
    board->Resize(size);
    fusionMatrix->Resize(size);
    board->Print();
   // initGame();
    //board->Print();
    //score = setScore(score, size);
    //scoreMax = setScoreMax(score, scoreMax);
    //cout << "========================= SCORE " << score << endl;
    //for (int i= 0; i < 6; i++){
     //   move(3, false);
      //  board->Print();
     //   score = setScore(score, size);
     //   scoreMax = setScoreMax(score, scoreMax);
     //   cout << "========================= SCORE " << score << endl;
     //   over = isGameOver(size);
    //}
    int c = 0;
    for(int i = 0; i<size; i++)
    {
        for (int j = 0; j<size; j++){
            c = ((rand()%2)+1)*2;
            board->Set(i,j,c);
            board->Print();

        }
    }
    notOver = isGameOver(size);
    cout << "END ?" << notOver << endl;



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
        || fusionMatrix->Get(row, col) ==1)                     //this cell results from a fusion
        movePossible = false;



    else if (board->Get(nextRow, nextCol) != 0) // if there is a fusion
        isFusion = true;

    return {movePossible, isFusion};
}

bool Game::move(int direction, bool trying) //trying is for gameOver
{
    int startRow = 0, startCol = 0, rowStep = 1, colStep = 1;
    int rowDir[] = {1, 0, -1, 0};
    int colDir[] = {0, 1, 0, -1};
    bool over = false;
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
                if (movePossible && !trying)
                {
                    board->Set(nextRow, nextCol,board->Get(nextRow, nextCol) + board->Get(i,j) );
                    board->Set(i,j,0);
                    somethingMoved = true; addTile = true;
                    if (isFusion)
                        fusionMatrix->Set(nextRow, nextCol, 1);
                }
                else if (trying && (movePossible || isFusion))
                    over = true;

             }


            }while(somethingMoved);


    if (addTile && !trying)
        addTileRandom();

    return over;
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

bool Game::isGameOver(int size){
    bool end = false;
    int c;
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            c = board->Get(i,j);
            if (c == 0)
                end = true; //if a space is empty : possibility to carry on
        }
    }
    if (!end) //if a move is possible
        end = move(0, true) || move(1, true) || move(2, true) || move(3, true);
    return end;
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
