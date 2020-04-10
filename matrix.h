#ifndef MATRIX_H
#define MATRIX_H


class Matrix
{
private:
    int fSize;
    int** fMatrix;
public:
    Matrix(int size);
    ~Matrix();
    void Set(int row, int col, int value);
    void Resize(int newTaille);
    void Print();
    int Get(int col ,int row);
    void InitMatrix(int value);



private:
    void AllocateMatrix();
    void DeleteMatrix();



};

#endif // MATRIX_H
