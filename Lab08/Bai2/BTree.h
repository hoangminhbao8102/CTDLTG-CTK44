//Thu vien dinh nghia B tree, cac thao tac he thong, nhap, xuat
#define MAXCOT 73
//Dinh nghia kieu thanh phan du lieu cua nut
struct HocVien
{
	char MaHV[8];
	char HoHV[10];
	char TenLot[10];
	char Ten[10];
	char Lop[6];
	int NamSinh;
	double DTB;
	int TichLuy;
};
//Kieu cac nut
struct BNode
{
	HocVien info;
	BNode* left;
	BNode* right;
};
//Kieu BTree
typedef BNode* BTree;
//----------------------------------
BNode* CreateNode(HocVien x);
void CreateBT(BTree& root);
int InsertNode(BTree& root, HocVien x);
int InsertNode1(BTree& root, HocVien x); //lam cay suy bien
int File_BT(BTree& root, char* filename);
void TieuDe();
void Xuat_HV(HocVien p);
int DemSoNut(BTree root);
//============================================
//Cai dat cac ham he thong
//Tao nut moi voi x cho truoc
BNode* CreateNode(HocVien x)
{
	BNode* p = new BNode;
	if (p != NULL)
	{
		p->info = x;
		p->left = NULL;
		p->right = NULL;
	}
	return p;
}
//----------------------------------
//Khoi tao cay BTree rong
void CreateBT(BTree& root)
{
	root = NULL;
}
//----------------------------------
//Them x vao cay BT
int InsertNode(BTree& root, HocVien x)
{
	//Cay khac rong
	if (root != NULL)
	{
		if (DemSoNut(root->left) > DemSoNut(root->right))
			return InsertNode(root->right, x);
		return InsertNode(root->left, x);
	}//root == NULL
	root = CreateNode(x);
	if (root == NULL)
		return 0;
	return 1; //thanh cong
}
//Them x vao cay BT: Suy bien
int InsertNode1(BTree& root, HocVien x)
{
	//Cay khac rong
	if (root != NULL)
	{
		return InsertNode(root->left, x);
		return InsertNode(root->right, x);
	}//root == NULL
	root = CreateNode(x);
	if (root == NULL)
		return 0;
	return 1; //thanh cong
}
//Dem so nut : So luong hoc vien trong danh sach
int DemSoNut(BTree root)
{
	if (root == NULL)
		return 0;
	return 1 + DemSoNut(root->left) + DemSoNut(root->right);
}
//============================================
//Cai dat cac ham nhap, xuat
//Tao BTree tu file - cai dat danh sach hoc vien bang cay nhi phan
int File_BT(BTree& root, char* filename)
{
	ifstream in(filename);
	if (!in)
		return 0;
	int kq;
	CreateBT(root);
	HocVien x;
	while (!in.eof())
	{
		in >> x.MaHV;
		in >> x.HoHV;
		in >> x.TenLot;
		in >> x.Ten;
		in >> x.Lop;
		in >> x.NamSinh;
		in >> x.DTB;
		in >> x.TichLuy;
		kq = InsertNode(root, x);
		if (kq == 0)
			return 0;
	}
	in.close();
	return 1;
}
//----------------------------------
//Xuat tieu de
void TieuDe()
{
	int i;
	cout << endl;
	cout << ":";
	for (i = 1; i <= MAXCOT; i++)
		cout << "=";
	cout << ":";
	cout << endl;
	cout << setiosflags(ios::left);
	cout << ':'
		<< setw(8) << "MaHV"
		<< ':'
		<< setw(10) << "Ho"
		<< setw(10) << "Tenlot"
		<< setw(10) << "Ten"
		<< ':'
		<< setw(8) << "Lop"
		<< ':'
		<< setw(6) << "NS"
		<< ':'
		<< setw(6) << "DTB"
		<< ':'
		<< setw(10) << "TichLuy"
		<< ':';
	cout << "\n";
	cout << ":";
	for (i = 1; i <= MAXCOT; i++)
		cout << "=";
	cout << ":";
}
//----------------------------------
//Xuat 1 hoc vien
void Xuat_HV(HocVien p)
{
	cout << endl;
	cout << setiosflags(ios::left)
		<< ':'
		<< setw(8) << p.MaHV
		<< ':'
		<< setw(10) << p.HoHV
		<< setw(10) << p.TenLot
		<< setw(10) << p.Ten
		<< ':'
		<< setw(8) << p.Lop
		<< ':'
		<< setw(6) << p.NamSinh
		<< ':'
		<< setw(6) << setprecision(2) << p.DTB << ':'
		<< setw(10) << p.TichLuy
		<< ':';
}
//============================================
//Cai dat cac ham duyet cay
//Duyet va Xuat cay theo thu tu truoc : NLR
void PreOrder(BTree root)
{
	if (root != NULL)
	{
		Xuat_HV(root->info);
		PreOrder(root->left);
		PreOrder(root->right);
	}
}
//----------------------------------
//Duyet va Xuat cay theo thu tu giua : LNR
void InOrder(BTree root)
{
	if (root != NULL)
	{
		InOrder(root->left);
		Xuat_HV(root->info);
		InOrder(root->right);
	}
}
//----------------------------------
//Duyet va Xuat cay theo thu tu sau : LRN
void PosOrder(BTree root)
{
	if (root != NULL)
	{
		PosOrder(root->left);
		PosOrder(root->right);
		Xuat_HV(root->info);
	}
}
//----------------------------------