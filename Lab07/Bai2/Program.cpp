//Cac thu vien
#include <iostream>
#include <fstream>
#include <conio.h>
#include <iomanip>
using namespace std;
#include "Header.h"
#include "ThuVien.h"
void ChayChuongTrinh();
//============================================
int main()
{
	ChayChuongTrinh();
    _getch();
	return 0;
}

void ChayChuongTrinh()
{
    LLIST l;
    const char* filename = "Test.txt"; // Giả sử tên file chứa dữ liệu đầu vào là "Test.txt"

    // Khởi tạo danh sách rỗng
    CreatLLIST(l);

    // Đọc dữ liệu từ file vào danh sách
    if (File_LLIST(filename, l) == 0) {
        cout << "Khong the doc file hoac file khong ton tai.\n";
        return;
    }

    // In danh sách hiện tại ra màn hình để kiểm tra
    cout << "Danh sach hien tai:\n";
    Output_Llist(l);

    // Thực hiện bài toán Josephus
    cout << "\nBai toan Josephus:\n";
    CryForHelp(l);

    // Gọi hàm xử lý bài toán Josephus
    // Bài toán sẽ được xử lý trong CryForHelp, hàm này sẽ in ra quá trình loại bỏ và người cuối cùng
}
