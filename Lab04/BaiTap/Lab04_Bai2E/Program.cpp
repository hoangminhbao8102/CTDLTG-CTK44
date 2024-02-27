#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>
#include <math.h>
#include <conio.h>

using namespace std;

#include "ThuVien.h"

void ChayChuongTrinh();
int XuatFileEmployeeList(const char* filename, EmployeeList list);

int main()
{
    ChayChuongTrinh();
    return 1;
}

void ChayChuongTrinh()
{
    // Khởi tạo danh sách nhân viên và bảng chấm công
    EmployeeList employees;
    InitializeEmployeeList(employees);

    // Đọc dữ liệu từ file và tạo danh sách nhân viên và bảng chấm công
    if (XuatFileEmployeeList("LLNV.txt", employees) && XuatFileEmployeeList("ChamCong.txt", employees))
    {
        // Tính toán lương và sắp xếp nhân viên theo lương
        CalculateTotalSalary(employees);
        SortByTotalSalary(employees);

        // Hiển thị danh sách nhân viên và lương thực lĩnh
        DisplayEmployeeList(employees);
    }
    else
    {
        cout << "\nLoi mo tap tin";
    }
    _getch();
}

int XuatFileEmployeeList(const char* filename, EmployeeList list) 
{
    ofstream outFile(filename);
    if (!outFile.is_open()) 
    {
        cout << "Khong the mo file de ghi." << endl;
        return;
    }

    NODE_EMPLOYEE* current = list.pHead;
    while (current != nullptr) 
    {
        outFile << current->info.ID << " " << current->info.FullName << " " << current->info.Address << " " << current->info.EducationLevel << " " << current->info.BaseSalary << " ";
        outFile << current->attendance.PaidLeaveDays << " " << current->attendance.UnpaidLeaveDays << " " << current->attendance.OvertimeDays << endl;
        current = current->pNext;
    }

    outFile.close();
}