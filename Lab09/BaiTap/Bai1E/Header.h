//Dinh nghia Cau truc du lieu : BST
typedef int KeyType; //Kieu du lieu cua thanh phan du lieu cua cac nut trong cay la int
//Kieu cac nut cua cay BST: BSNode
struct BSNode
{
	KeyType key;
	BSNode* left; //Chua dia chi cay con trai
	BSNode* right; //Chua dia chi cay con phai
};
//Kieu CTDL Cay nhi phan tim kiem : kieu con tro tro den cac nut kieu BSNode
typedef BSNode* BSTree;
//==================================
//Khai bao nguyen mau cac ham
//Cac ham he thong
void CreateBST(BSTree& root); //Tao cay BST rong
BSNode* CreateNode(KeyType x);
//Chen
int InsertNode(BSTree& root, KeyType x); //Chen x vao cay BST
//Nhap, xuat (duyet va in)
int File_BST(BSTree& root, char* filename); //Tao cay BST tu file
void PreOrder(BSTree root);//NLR
void InOrder(BSTree root); //LNR
void PosOrder(BSTree root); //LRN
//==================================
//Dinh nghia ham
//Tao nut voi x cho truoc
BSNode* CreateNode(KeyType x)
{
	BSNode* p = new BSNode;
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
void CreateBST(BSTree& root)
{
	root = NULL;
}
//----------------------------------
//Them x vao cay BST
int InsertNode(BSTree& root, KeyType x)
{
	//Cay khac rong
	if (root != NULL)
	{
		if (root->key == x)
			return 0; // x da co san
		if (root->key > x)
			return InsertNode(root->left, x);
		else
			return InsertNode(root->right, x);
	}//root == NULL
	root = CreateNode(x);
	if (root == NULL)
		return -1;
	return 1;
}
//----------------------------------
//1. Tạo cây nhị phân cân đối (tại mỗi nút, số con trái và số con phải lệc nhau không quá 1)
int File_BST(BSTree& root, char* filename)
{
	ifstream in(filename);
	if (!in)
		return 0;
	KeyType x;
	int kq;
	CreateBST(root);
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
// 2. Xuất các phần tử trên cây theo thứ tự đầu (NLR), giữa (LNR), cuối (LRN).
// Xuat cay theo thu tu truoc : NLR
void PreOrder(BSTree root)
{
	if (root != NULL)
	{
		cout << root->key << '\t';
		PreOrder(root->left);
		PreOrder(root->right);
	}
}
//Xuat cay theo thu tu giua : LNR
void InOrder(BSTree root)
{
	if (root != NULL)
	{
		InOrder(root->left);
		cout << root->key << '\t';
		InOrder(root->right);
	}
}
//Xuat cay theo thu tu sau : LRN
void PosOrder(BSTree root)
{
	if (root != NULL)
	{
		PosOrder(root->left);
		PosOrder(root->right);
		cout << root->key << '\t';
	}
}
//----------------------------------