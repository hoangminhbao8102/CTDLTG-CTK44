//DN du liệu va Cac thao tac co ban tren BT vơi kieu du lieu cua thanh phan du lieu cua nut la int
//Dinh nghia Cau truc du lieu :BT
typedef int Data; //Kieu du lieu cua thanh phan du lieu cua cac nut trong cay la int
//Kieu cac nut cua cay : BNode
struct BNode
{
	Data key;
	BNode* left; //Chua dia chi cay con trai
	BNode* right; //Chua dia chi cay con phai
};
//Kieu CTDL Cay nhi phan tim kiem : kieu con tro tro den cac nut kieu BNode
typedef BNode* BTree;
//==================================
//Khai bao nguyen mau cac ham
//Cac ham he thong
void CreateBT(BTree& root); //Tao cay BT rong
BNode* CreateNode(Data x);
//Chen theo yeu cau : so nut cay phai >= cau trai nhieu nhat la 1 
int InsertNode(BTree& root, Data x); //Chen x vao cay BT
//Nhap, xuat (duyet va in)
int File_BT(BTree& root, char* filename); //Tao cay BST tu file
void PreOrder(BTree root);//NLR
void InOrder(BTree root); //LNR
void PosOrder(BTree root); //LRN
int DemSoNut(BTree root);
//==================================
//Dinh nghia ham
//Tao nut voi x cho truoc
BNode* CreateNode(Data x)
{
	BNode* p = new BNode;
	if (p != NULL)
	{
		p->key = x;
		p->left = NULL;
		p->right = NULL;
	}
	return p;
}
//----------------------------------
//Khoi tao cay BST rong
void CreateBT(BTree& root)
{
	root = NULL;
}
//----------------------------------
//Them x vao cay BST
int InsertNode(BTree& root, Data x)
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
//----------------------------------
//Tao cay BST tu file
int File_BT(BTree& root, char* filename)
{
	ifstream in(filename);
	if (!in)
		return 0;
	Data x;
	int kq;
	CreateBT(root);
	while (!in.eof())
	{
		in >> x;
		kq = InsertNode(root, x);
		if (kq == 0 || kq == -1)
			return 0;
	}
	in.close();
	return 1;
}
//----------------------------------
//Xuat cay theo thu tu truoc : NLR
void PreOrder(BTree root)
{
	if (root != NULL)
	{
		cout << root->key << '\t';
		PreOrder(root->left);
		PreOrder(root->right);
	}
}
//Xuat cay theo thu tu giua : LNR
void InOrder(BTree root)
{
	if (root != NULL)
	{
		InOrder(root->left);
		cout << root->key << '\t';
		InOrder(root->right);
	}
}
//Xuat cay theo thu tu sau : LRN
void PosOrder(BTree root)
{
	if (root != NULL)
	{
		PosOrder(root->left);
		PosOrder(root->right);
		cout << root->key << '\t';
	}
}
//----------------------------------
//Dem so nut
int DemSoNut(BTree root)
{
	if (root == NULL)
		return 0;
	return 1 + DemSoNut(root->left) + DemSoNut(root->right);
}