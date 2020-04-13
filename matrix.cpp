#include "matrix.h"
#include <iostream>
#include <iomanip>
#include <cassert>

using namespace std;

Matrix::Matrix(int size)
{
    if (size > 1)
        fSize = size;
    else
        fSize = 4;

    AllocateMatrix();
    InitMatrix(0);
}

Matrix::~Matrix()
{
    DeleteMatrix();
}

void Matrix::DeleteMatrix()
{
    for (int i = 0; i < fSize; i++)
        delete [] fMatrix[i];
    delete [] fMatrix;
}

void Matrix::AllocateMatrix()
{
    fMatrix = new int* [fSize];
    for (int i = 0; i < fSize; i++)
        fMatrix[i] = new int[fSize];
}

void Matrix::InitMatrix(int value)
{
    for (int i = 0; i < fSize; i++)
        for (int j = 0; j < fSize; j++)
            fMatrix[i][j] = value;
}

void Matrix::Set(int x, int y, int val)
{
    assert(x >= 0 && x < fSize);
    assert(y >= 0 && y < fSize);

    fMatrix[x][y] = val;
}

void Matrix::Resize(int newSize)
{
    DeleteMatrix();

    if (newSize > 1)
        fSize = newSize;
    else
        fSize = 4;
    AllocateMatrix();
    InitMatrix(0);

}

void Matrix::Print()
{
    cout << endl;
    for (int i = 0; i < fSize; i++)
    {
        for (int j = 0; j < fSize; j++)
        {
            cout << setw(3) << fMatrix[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

int Matrix::Get(int row, int col)
{
    assert(col >= 0 && col < fSize);
    assert(row >= 0 && row < fSize);

    return fMatrix[row][col];
}

