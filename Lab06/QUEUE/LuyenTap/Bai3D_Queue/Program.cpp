#include <iostream>
#include <fstream>
#include <conio.h>

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
    QUEUE q;
    CreatQueue(q);

    // Select file to read, can use "Test1.txt" or "Test2.txt", or even ask the user
    char filename[20];
    cout << "Enter file name (Test1.txt or Test2.txt): ";
    cin >> filename;

    // Load numbers from file into the queue
    TapTin_Queue(filename, q);

    // Output the original queue
    cout << "Original Queue: ";
    XuatQueue(q);

    // Sort the queue using the Radix sort algorithm
    Radix(q);

    // Output the sorted queue
    cout << "Sorted Queue: ";
    XuatQueue(q);
}