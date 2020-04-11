#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <iomanip>

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
    board->Set(3,0,2);

    board->Set(3,1,2);
    board->Set(3,2,4);
    board->Set(3,3,4);
    board->Print();
    Move(3);
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
        || fusionMatrix->Get(nextRow, nextCol) == 1)             // next cell has already been fused this move
                   movePossible = false;

    else if (board->Get(nextRow, nextCol) != 0) // if there is a fusion
    {
        isFusion = true;
    }
    return {movePossible, isFusion};
}

void Game::Move(int direction)
{
    int startRow = 0, startCol = 0, rowStep = 1, colStep = 1;
    int rowDir[] = {1, 0, -1, 0};
    int colDir[] = {0, 1, 0, -1};
    fusionMatrix->InitMatrix(0);

    bool somethingMoved;

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
        cout << "LLLLLLLLLLLLLLOOOOOOOOOOOOOOOOOOOOOOP";
        somethingMoved = false;
        for (int i = startRow; i>=0 && i<size; i += rowStep)
            for (int j = startCol; j>=0 && j<size; j+= colStep)
            {
                int nextRow = i + rowDir[direction], nextCol = j + colDir[direction];
                auto [movePossible, isFusion] = isMovePossible(i, j, nextRow, nextCol);
                cout << "ZZZZZZZZZZZ " << isFusion;
                if (movePossible)
                {
                    board->Set(nextRow, nextCol,board->Get(nextRow, nextCol) + board->Get(i,j) );
                    board->Set(i,j,0);
                    board->Print();
                    somethingMoved = true;
                    if (isFusion)
                    {
                        fusionMatrix->Set(nextRow, nextCol, 1);
                        fusionMatrix->Print();
                    }
                }

                }


            }while(somethingMoved);
}



//void Game::updateGame()
//{

//}

void Game::addTileRandom()
{
    srand(time(NULL));
    bool notAdded = true;
    int c = 0;
    while (notAdded && c<10)
    {
        int i = rand() % size ;
        int j = rand()% size ;
        int n = (rand()%2+1)*2;
        cout << i << " " << j; ;
        c++;
        if (board->Get(i, j) == 0)
        {
            board->Set(i, j, n);
            cout << "added";
            notAdded = false;
        }
    }







}

//void Game::setTile(int x, int y, int value)
//{

//}

//bool Game::isGameOver()
//{
//    return false;
//}
