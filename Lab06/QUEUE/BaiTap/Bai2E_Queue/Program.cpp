#include <iostream>
#include <fstream>
#include <conio.h>
#include <string.h>
#include <iomanip>
#include <sstream> // Thêm thư viện này để sử dụng stringstream

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
    CreatQueue(q); // Khởi tạo hàng đợi
    int choice;
    char filename[100];

    do {
        cout << "==================== MENU ====================\n";
        cout << "1. Load data from file\n";
        cout << "2. Display all documents\n";
        cout << "3. Exit\n";
        cout << "Enter your choice (1-3): ";
        cin >> choice;
        cin.ignore(); // Ignore the newline character left in the buffer

        switch (choice) {
        case 1:
            cout << "Enter file name: ";
            cin.getline(filename, sizeof(filename));
            TapTin_Queue(filename, q);
            break;
        case 2:
            cout << "Current Queue:\n";
            XuatQueue(q);
            break;
        case 3:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);
}