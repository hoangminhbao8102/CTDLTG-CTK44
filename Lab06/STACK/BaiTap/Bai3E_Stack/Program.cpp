#include <iostream>
#include <conio.h>

using namespace std;

#include "ThuVien.h"

void ChayChuongTrinh();

int main()
{
    ChayChuongTrinh();
    _getch();
    return 0;
}

void ChayChuongTrinh()
{
    char infix[MAX], postfix[MAX] = "";
    cout << "Enter an algebraic expression: ";
    cin.getline(infix, MAX);

    TrungTo_HauTo(infix, postfix);
    cout << "Postfix expression: " << postfix << endl;

    int result = Tinh_BT_HauTo(postfix);
    cout << "Result: " << result << endl;
}