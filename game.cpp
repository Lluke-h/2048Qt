#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <iomanip>
#include <QQuickView>
#include <QObject>
#include<QString>
#include <QQmlContext>
#include <QQmlEngine>
#include <QQmlComponent>
#include <QList>


#include "game.h"

using namespace std;


//It launches the first grid
Game::Game(QObject *parent) : QObject(parent)
{
    score = 0;
    scoreMax = 0;
    gameOver = 1;
    setSize(4);

}


//This function says if a movement is possible or not, if a place is empty or full with another cipher or full with the same cipher, and if this one results from a fusion or not at this movement
tuple<bool, bool> Game::isMovePossible(int row, int col, int nextRow, int nextCol)
{
    bool movePossible = true;
    bool isFusion = false;
    if (nextRow<0 || nextRow>=size || nextCol<0 || nextCol>=size // index in range - if the place is at the grid border
        || (board->Get(row, col) != board->Get(nextRow, nextCol) // or if the next place is full of another number
            && board->Get(nextRow, nextCol) != 0)                // The move is legal
        || board->Get(row, col) == 0                             // The cell to move is not empty
        || fusionMatrix->Get(nextRow, nextCol) == 1              // next cell has already been fused this move
        || fusionMatrix->Get(row, col) ==1)                      //this cell results from a fusion
        movePossible = false;

    else if (board->Get(nextRow, nextCol) != 0) // if there is a fusion
        isFusion = true;

    return {movePossible, isFusion};
}


//Function that acts the movement chosen by the player
void Game::move(int direction)
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
        somethingMoved = false;
        for (int i = startRow; i>=0 && i<size; i += rowStep)
            for (int j = startCol; j>=0 && j<size; j+= colStep)
            {
                int nextRow = i + rowDir[direction], nextCol = j + colDir[direction];
                auto [movePossible, isFusion] = isMovePossible(i, j, nextRow, nextCol); //if the move is possible or at least, there is a fusion
                if (movePossible)
                {
                    board->Set(nextRow, nextCol,board->Get(nextRow, nextCol) + board->Get(i,j) );
                    board->Set(i,j,0);
                    somethingMoved = true;
                    addTile = true;
                    if (isFusion)
                        fusionMatrix->Set(nextRow, nextCol, 1);
                }
             }
            }while(somethingMoved); //we only act the movement if a changement in the grid is possible

    if (addTile)
        addTileRandom();

    board->Print(); //console
    isGameOver();
    cout << "Game Over ? : "<<gameOver<<" ";
    updateScores(); //slots for our interface
    tilesChanged();
    gameOverChanged();
}


//Function which initializes the grid (after a retry or a set size, or for the first) play
void Game::initGame(){
    board->Resize(size); //grids size updated: 3 to 7 are possible in our interface. New grid, empty of tiles.
    fusionMatrix->Resize(size);
    tilesChanged(); //slot to adapt our interface
    board->Print();
    addTileRandom(); //first, we begin with two single tiles
    board->Print();
    addTileRandom();
    cout << "tile added" << endl;
    board->Print();
    score = 0;
    gameOver = 0;
    updateScores(); //slot for our interface
    tilesChanged();
    gameOverChanged();

}


//Function which updates size of the grid
void Game::setSize(int newSize){
    size = newSize;
    sizeChanged();
    initGame();
}


//Function which adds a tile, randomly in an empty space
void Game::addTileRandom()
{
    srand(time(NULL));
    bool notAdded = true;
    int i = 0, j = 0;
    int c = 0;
    int ok = 0;
    int emptySpaces = 0;
    for (i = 0; i<size; i++){  //we count empty spaces on the grid
        for (j = 0; j<size; j++){
            if (board->Get(i,j) == 0)
                emptySpaces++;
        }
    }
    i = 0, j = 0;
    cout << "\n ADD TILE RANDOM \n" << endl;
    int n = rand()%emptySpaces; //we choose an epmty space
    int val = 2 + (rand()%10>7)*2; //adds mostyl twos, one in five chance of adding four
    cout << emptySpaces << "   " << n << "    " << val << endl;
    for (i = 0; i<size; i++){
        for (j = 0; j<size; j++){
            if (board->Get(i,j) == 0){
                if (n == 0){
                    board->Set(i,j,val); //we find the empty space we have chosen and we set it
                    ok = 1;
                    break;
                }
                else
                    n--;
            }
        }
        if (ok)
            break;
    }
    cout << n << endl;
    //cout << board->Get(i,j) << endl ;



   // while (notAdded && c<100) //we consider
    //{
      //  int i = rand() % size ;
        //int j = rand()% size ;
        //int n = 2 + (rand()%10>7)*2; // adds mostly twos, one in five chance of adding a four
        //c++;
        //if (board->Get(i, j) == 0)
        //{
            //board->Set(i, j, n);
            //notAdded = false;
        //}
    //}
}



//Function that looks for a possible movement or fusion after a movement and says if the game is over or not
void Game::isGameOver(){
    gameOver = 1;
    int c, i=0, j=0;
    while(i<size && gameOver)
    {
        j = 0;
        while(j<size && gameOver)
        {
            c = board->Get(i,j);
            if (c==0){
                gameOver = 0;
            }

            else if ((i!=size-1 && board->Get(i+1,j)==c)
                     ||(j!=size-1 && board->Get(i,j+1)==c)){
                    gameOver = 0;
                }
        j ++;
        }
    i++;
    }
    gameOverChanged();
}












// ----------------------------- Score Handling -----------------------------------


//Function that update scoreMax
void Game::updateScores()
{
    countScore(); // update the current score
    if (score > scoreMax)
        scoreMax = score;

    scoresChanged(); // update score in the QML
}


//It counts values of tiles that results from a fusion for the last movement
void Game::countScore(){
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
}


//Slots
QString Game::readScore(){
    return QString::number(score);
}
QString Game::readScoreMax(){
    return QString::number(scoreMax);
}
QString Game::readGameOver(){
    return QString::number(gameOver);
}

QString Game::readSize(){
    return QString::number(size);
}

QList<QString> Game::readTiles(){
    QList<QString> gameTiles;
    for (int i= 0; i<size; i++){
        for (int j = 0; j<size; j++){
            gameTiles.push_back(QString::number(board->Get(i,j)));
            if(board->Get(i,j) == 0) //it pushes back opacity of the tile in the grid (if there is an empty space, represented by a 0, opacity is at 0)
                gameTiles.push_back(QString::number(0));
            else
                gameTiles.push_back(QString::number(1));
        }
    }
    return gameTiles;
}

// ---------------------------------------------------------------------------------




