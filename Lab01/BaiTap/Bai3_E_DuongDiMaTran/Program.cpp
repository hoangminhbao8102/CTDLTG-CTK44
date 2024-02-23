#include <iostream>

using namespace std;

#include "ThuVien.h"

void ChayChuongTrinh();

int main()
{
    ChayChuongTrinh();
    return 1;
}

void ChayChuongTrinh()
{
    int n = 3;
    int** matrix = new int* [n];
    for (int i = 0; i < n; ++i) 
    {
        matrix[i] = new int[n];
        for (int j = 0; j < n; ++j) 
        {
            matrix[i][j] = 0;
        }
    }

    setMatrix(matrix, n, 0, 0, 1);
    setMatrix(matrix, n, 0, 1, 2);
    setMatrix(matrix, n, 0, 2, 3);
    setMatrix(matrix, n, 1, 0, 4);
    setMatrix(matrix, n, 1, 1, 5);
    setMatrix(matrix, n, 1, 2, 6);
    setMatrix(matrix, n, 2, 0, 7);
    setMatrix(matrix, n, 2, 1, 8);
    setMatrix(matrix, n, 2, 2, 9);

    int** paths = new int* [n * n];
    for (int i = 0; i < n * n; ++i) 
    {
        paths[i] = new int[n * n];
        for (int j = 0; j < n * n; ++j) 
        {
            paths[i][j] = 0;
        }
    }

    int maxLength, maxWeight;
    findAllPaths(matrix, n, maxLength, maxWeight, paths);
    printPaths(paths, maxLength, maxWeight);

    for (int i = 0; i < n; ++i) 
    {
        delete[] matrix[i];
    }
    delete[] matrix;

    for (int i = 0; i < n * n; ++i) 
    {
        delete[] paths[i];
    }
    delete[] paths;
	system("PAUSE");
}