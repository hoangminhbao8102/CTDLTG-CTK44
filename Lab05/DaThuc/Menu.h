void XuatMenu();
int ChonMenu(int SoMenu);
void XuLyMenu(int menu, POLY& a, POLY& b);

void XuatMenu()
{
	cout << "\n================ He thong chuc nang ===============";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Nhap du lieu cho da thuc";
	cout << "\n2. Xem du lieu da thuc";
	cout << "\n3. Sap xep da thuc tang theo so mu";
	cout << "\n4. Rut gon mot da thuc";
	cout << "\n5. Tong 2 da thuc";
	cout << "\n6. Hieu 2 đa thuc";
	cout << "\n7. Nhan mot phan tu voi da thuc";
	cout << "\n8. Tich 2 da thuc";
	cout << "\n9. Tinh dao ham da thuc";
	cout << "\n10. Tinh tich phan ham da thuc";
	cout << "\n11. Tinh gia tri da thuc tai x";
	cout << "\n===================================================";
}

int ChonMenu(int SoMenu)
{
	int STT;
	for (;;)
	{
		system("CLS");
		XuatMenu();
		cout << "\nNhap mot so ( 0 <= so <= " << SoMenu << " ) de chon menu, stt = ";
		cin >> STT;
		if (0 <= STT && STT <= SoMenu)
		{
			break;
		}
	}
	return STT;
}

void XuLyMenu(int menu, POLY& a, POLY& b)
{
	POLY kq;
	DataType x;
	NODE* p;
	double x_val, val;
	switch (menu)
	{
	case 0:
		system("CLS");
		cout << "\n0. Thoat khoi chuong trinh\n";
		break;
	case 1:
		system("CLS");
		cout << "\n1. Nhap du lieu cho da thuc\n";
		File_Poly("A.txt", a);
		File_Poly("B.txt", b);
		break;
	case 2:
		system("CLS");
		cout << "\n2. Xem du lieu da thuc\n";
		cout << "\nDa thuc A:\n";
		Output_Poly(a);
		cout << "\nDa thuc B:\n";
		Output_Poly(b);
		break;
	case 3:
		system("CLS");
		cout << "\n3. Sap xep da thuc tang theo so mu\n";
		Sort_Expo(a);
		Sort_Expo(b);
		cout << "\nDa thuc sau khi sap xep:\n";
		Output_Poly(a);
		Output_Poly(b);
		break;
	case 4:
		system("CLS");
		cout << "\n4. Rut gon mot da thuc\n";
		Reduction(a);
		Reduction(b);
		cout << "\nDa thuc sau khi rut gon:\n";
		Output_Poly(a);
		Output_Poly(b);
		break;
	case 5:
		system("CLS");
		cout << "\n5. Tong 2 da thuc\n";
		kq = Add(a, b);
		cout << "\nTong cua hai da thuc:\n";
		Output_Poly(kq);
		break;
	case 6:
		system("CLS");
		cout << "\n6. Hieu 2 đa thuc\n";
		kq = Minus(a, b);
		cout << "\nHieu cua hai da thuc:\n";
		Output_Poly(kq);
		break;
	case 7:
		system("CLS");
		cout << "\n7. Nhan mot phan tu voi da thuc\n";
		cout << "\nNhap he so va so mu cua phan tu: ";
		cin >> x.coef >> x.expo;
		p = GetNode(x);
		kq = Mult_Node(a, p);
		cout << "\nKet qua cua phep nhan:\n";
		Output_Poly(kq);
		break;
	case 8:
		system("CLS");
		cout << "\n8. Tich 2 da thuc";
		kq = Mult_Poly(a, b);
		cout << "\nTich cua hai da thuc:\n";
		Output_Poly(kq);
		break;
	case 9:
		system("CLS");
		cout << "\n9. Tinh dao ham da thuc";
		kq = DeriveA(a);
		cout << "\nDao ham cua da thuc A:\n";
		Output_Poly(kq);
		break;
	case 10:
		system("CLS");
		cout << "\n10. Tinh tich phan ham da thuc";
		kq = IntegratePoly(a);
		cout << "\nTich phan cua da thuc A:\n";
		Output_Poly(kq);
		break;
	case 11:
		system("CLS");
		cout << "\n11. Tinh gia tri da thuc tai x";
		cout << "\nNhap gia tri x: ";
		cin >> x_val;
		val = ValueP(a, x_val);
		cout << "\nGia tri cua da thuc tai x = " << x_val << " la: " << val << "\n";
		break;
	}
}