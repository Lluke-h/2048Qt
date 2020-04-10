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
    board->Print();
    addTileRandom();
//    board->Set(3,1,2);
    board->Print();
//    updateGame();
}

//void Game::Move(int direction)
//{

//}

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
        cout << i << " " << j; ;
        c++;
        if (board->Get(i, j) == 0)
        {
            board->Set(i, j, 2);
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
