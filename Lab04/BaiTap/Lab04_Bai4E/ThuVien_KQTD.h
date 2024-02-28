#define MAX 100
#define NGANGDOI '='
#define NGANGDON '-'

void XuatNgangDoi();
void XuatTieuDe_LTD();
void XuatLTD_1TD(DataType_TD p);
void Xuat_LTD_Vong_j(LIST_KQTD l, int vong);
void Xuat_LTD_DenVong_j(LIST_KQTD l, int vong);
void XuatTieuDe_KQTD();
void XuatKQ_1TD(DataType_TD p);
void Xuat_KQTD_Vong_j(LIST_KQTD l, int vong);
void Xuat_KQTD_DenVong_j(LIST_KQTD l, int vong);
int VongTD_MoiNhat(LIST_KQTD l);

void XuatNgangDoi()
{
	int i;
	cout << ':';
	for (i = 1; i < 59; i++)
		cout << NGANGDOI;
	cout << ':';
}

void XuatTieuDe_LTD()
{
	XuatNgangDoi();
	cout << endl;
	cout << setiosflags(ios::left)
		<< ": "
		<< setw(4) << "Vong"
		<< ": "
		<< setw(9) << "Ngay"
		<< ": "
		<< setw(6) << "Gio"
		<< ": "
		<< setw(15) << "Chu Nha"
		<< ": "
		<< setw(15) << "Doi Khach"
		<< ":";
	cout << endl;
	XuatNgangDoi();
}

void XuatLTD_1TD(DataType_TD p)
{
	cout << setiosflags(ios::left)
		<< ": "
		<< setw(4) << p.Vong
		<< ": "
		<< setw(9) << p.Ngay
		<< ": "
		<< setw(6) << p.Gio
		<< ": "
		<< setw(15) << p.ChuNha
		<< ": "
		<< setw(15) << p.DoiKhach
		<< ':';
}

void Xuat_LTD_Vong_j(LIST_KQTD l, int vong)
{
	int k, dem = 0;
	cout << "\n Lich thi dau vong " << vong;
	cout << endl;
	XuatTieuDe_LTD();
	NODE_TD* p;
	for (p = l.pHead; p != NULL; p = p->pNext)
	{
		if (p->KQTD.Vong == vong)
		{
			cout << endl;
			XuatLTD_1TD(p->KQTD);
			dem++;
			if (dem == 10)
				break;
			if (p->pNext == NULL)
				break;
			if (_strcmpi(p->KQTD.Ngay, p->pNext->KQTD.Ngay) != 0)
			{
				cout << endl;
				cout << ':';
				for (k = 1; k < 59; k++)
					cout << NGANGDON;
				cout << ':';
			}
		}
	}
	cout << endl;
	XuatNgangDoi();
}

void Xuat_LTD_DenVong_j(LIST_KQTD l, int vong)
{
	int j;
	cout << endl;
	system("CLS");
	for (j = 1; j <= vong; j++)
	{
		Xuat_LTD_Vong_j(l, j);
		cout << endl;
		system("PAUSE");
	}
}

void XuatTieuDe_KQTD()
{
	int i;
	cout << ':';
	for (i = 1; i < 70; i++)
		cout << NGANGDOI;
	cout << ':';
	cout << endl;
	cout << setiosflags(ios::left)
		<< ':'
		<< setw(4) << "Vong"
		<< ':'
		<< setw(9) << "Ngay"
		<< ':'
		<< setw(6) << "Gio"
		<< ':'
		<< setw(15) << "Chu Nha"
		<< ':'
		<< setw(15) << " Ty So "
		<< ':'
		<< setw(15) << "Doi Khach"
		<< ':';
	cout << endl;
	cout << ':';
	for (i = 1; i < 70; i++)
		cout << NGANGDOI;
	cout << ':';
}

void XuatKQ_1TD(DataType_TD p)
{
	cout << setiosflags(ios::left)
		<< ':'
		<< setw(4) << p.Vong
		<< ':'
		<< setw(9) << p.Ngay
		<< ':'
		<< setw(6) << p.Gio
		<< ':'
		<< setw(15) << p.ChuNha
		<< ':'
		<< setw(7) << p.BanThangChu
		<< ':'
		<< setw(7) << p.BanThangKhach
		<< ':'
		<< setw(15) << p.DoiKhach
		<< ':';
}

void Xuat_KQTD_Vong_j(LIST_KQTD l, int vong)
{
	NODE_TD* p;
	int k;
	int dem = 0;
	cout << "\n Ket qua cac tran dau vong " << vong;
	cout << endl;
	XuatTieuDe_KQTD();
	for (p = l.pHead; p != NULL; p = p->pNext)
	{
		if (p->KQTD.Vong == vong)
		{
			cout << endl;
			XuatKQ_1TD(p->KQTD);
			dem++;
			if (dem == 10)
				break;
			if (p->pNext == NULL)
				break;
			if (_strcmpi(p->KQTD.Ngay, p->pNext->KQTD.Ngay) != 0)
			{
				cout << endl;
				cout << ':';
				for (k = 1; k < 70; k++)
					cout << NGANGDON;
				cout << ':';
			}
		}
	}
	cout << endl;
	cout << ':';
	for (k = 1; k < 70; k++)
		cout << NGANGDOI;
	cout << ':';
}

void Xuat_KQTD_DenVong_j(LIST_KQTD l, int vong)
{
	int j;
	cout << "\nKet qua cac tran dau den vong " << vong << " :";
	cout << endl;
	for (j = 1; j <= vong; j++)
	{
		Xuat_KQTD_Vong_j(l, j);
		cout << endl;
		system("PAUSE");
	}
}

int VongTD_MoiNhat(LIST_KQTD l)
{
	int vong = 38;
	NODE_TD* p;
	for (p = l.pHead; p != NULL; p = p->pNext)
		if (p->KQTD.BanThangChu == -1)
		{
			vong = p->KQTD.Vong - 1;
			break;
		}
	return vong;
}