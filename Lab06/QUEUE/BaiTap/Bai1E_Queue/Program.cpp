#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>

using namespace std;

#include "ThuVien.h"

void ChayChuongTrinh();

int main()
{
    ChayChuongTrinh();
    _getch();
    return 1;
}

void ChayChuongTrinh()
{
    QUEUE buffer;
    CreatQueue(buffer);
    char filename[] = "input.txt"; // Đổi tên tập tin theo yêu cầu

    ifstream inFile(filename);
    if (!inFile)
    {
        cout << "Cannot open file!" << endl;
    }

    string line;
    const int bufferSize = 10; // Giới hạn kích thước buffer

    while (getline(inFile, line))
    {
        EnQueue(buffer, line);
        if (isBufferFull(buffer, bufferSize))
        {
            PrintBuffer(buffer);
        }
    }

    // In phần còn lại của buffer nếu có
    PrintBuffer(buffer);

    inFile.close();
}