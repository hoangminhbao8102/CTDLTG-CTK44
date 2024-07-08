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
	return 1;
}
void ChayChuongTrinh() {
    AVLTree root = nullptr;  // Khởi tạo cây AVL
    string filename = "data.txt";  // Tên file chứa dữ liệu

    loadFromFileAndInsert(root, filename);  // Tải dữ liệu từ file và chèn vào cây

    cout << "Cay AVL sau khi chen du lieu tu file:" << endl;
    printTree(root);  // In cây AVL

    // Giải phóng bộ nhớ của cây AVL
    freeTree(root);
    root = nullptr; // Đặt lại con trỏ gốc để tránh sử dụng giá trị rác

    // Thêm bất kỳ thao tác nào khác bạn muốn thực hiện trên cây
}
