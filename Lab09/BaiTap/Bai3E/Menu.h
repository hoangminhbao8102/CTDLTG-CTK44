void XuatMenu();
int ChonMenu(int SoMenu);
void XuLyMenu(int menu, BSTree& root);

void XuatMenu()
{
	cout << "\n========HE THONG MENU======";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Nhap vao mot bieu thuc so hoc don gian. Bieu dien bieu thuc so hoc len cay nhi phan. Kiem tra cu phap cua bieu thuc";
	cout << "\n2. Xuat ra bieu thuc so hoc do duoi dang: tien to, trung to, hau to";
	cout << "\n3. Tinh gia tri cua bieu thuc";
	cout << "\n===========================";
}
int ChonMenu(int SoMenu)
{
	int stt;
	for (;;)
	{
		system("CLS");
		XuatMenu();
		cout << "\nNhap 1 so trong khoang [0,...," << SoMenu << "] de chon menu, stt = ";
		cin >> stt;
		if (0 <= stt && stt <= SoMenu)
			break;
	}
	return stt;
}
void XuLyMenu(int menu, BSTree& root)
{
    //=========================
    switch (menu)
    {
    case 0:
        system("CLS");
        cout << "0. Thoat khoi chuong trinh\n";
        break;
    case 1:
        system("CLS");
        cout << "\n1. Nhap vao mot bieu thuc so hoc don gian. Bieu dien bieu thuc so hoc len cay nhi phan. Kiem tra cu phap cua bieu thuc\n";
        root = InputExpression();
        break;
    case 2:
        system("CLS");
        cout << "\n2. Xuat ra bieu thuc so hoc do duoi dang: tien to, trung to, hau to\n";
        if (root) {
            cout << "Tien to: ";
            PrintPrefix(root);
            cout << endl;

            cout << "Trung to: ";
            PrintInfix(root);
            cout << endl;

            cout << "Hau to: ";
            PrintPostfix(root);
            cout << endl;
        }
        else {
            cout << "Cay chua duoc tao!\n";
        }
        break;
    case 3:
        system("CLS");
        cout << "\n3. Tinh gia tri cua bieu thuc\n";
        if (root) {
            cout << "Gia tri cua bieu thuc: " << Evaluate(root) << endl;
        }
        else {
            cout << "Cay chua duoc tao!\n";
        }
        break;
    default:
        cout << "Lua chon khong hop le!\n";
        break;
    }
}