#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#include "ThuVien.h"
void ChayChuongTrinh();
int main()
{
	ChayChuongTrinh();
	return 0;
}
void ChayChuongTrinh()
{
    AVLTree root = nullptr;
    int choice;
    string key, meaning;

    while (true) {
        cout << "\nMenu Chuong Trinh Tu Dien Anh-Viet:" << endl;
        cout << "1. Them tu moi" << endl;
        cout << "2. Tim kiem tu" << endl;
        cout << "3. Thoat" << endl;
        cout << "Nhap lua chon cua ban (1-3): ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Nhap tu tieng Anh: ";
            cin >> key;
            cin.ignore(); // Xóa bộ nhớ đệm
            cout << "Nhap nghia tieng Viet: ";
            getline(cin, meaning); // Cho phép nhập nghĩa có khoảng trắng
            insert(root, key, meaning);
            cout << "Da them tu \"" << key << "\" vao tu dien." << endl;
            break;
        case 2:
            cout << "Nhap tu tieng Anh can tim: ";
            cin >> key;
            cout << "Nghia cua tu \"" << key << "\": " << find(root, key) << endl;
            break;
        case 3:
            cout << "Thoat chuong trinh." << endl;
            return;
        default:
            cout << "Lua chon khong hop le. Vui long nhap lai." << endl;
        }
    }
}