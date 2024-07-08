void XuatMenu();
int ChonMenu(int SoMenu);
void XuLyMenu(int menu, AVLTree& root);

void XuatMenu()
{
	cout << "\n========HE THONG MENU======";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Tao cay can bang (AVL).";
	cout << "\n2. Duyet cay theo thu tu NLR (PreOder) , LNR (Inorder), LRN (PosOder) dang de quy.";
	cout << "\n3. Tim nut tren cay chua gia tri key cho truoc (dang de quy).";
	cout << "\n4. Phep quay don Left-Left. Su dung khi cay con ben trai lech trai hoac can bang.";
	cout << "\n5. Phep quay don Right-Right. Su dung khi cay con ben phai lech phai hoac can bang.";
	cout << "\n6. Phep quay kep Left-Right. Su dung khi cay con ben trai lech phai.";
	cout << "\n7. Phep quay kep Right-Left. Su dung khi cay con ben phai lech trai.";
	cout << "\n8. Can bang lai cay khi cay lech trai.";
	cout << "\n9. Can bang lai cay khi cay lech phai.";
	cout << "\n10. Them mot phan tu moi vao cay";
	cout << "\n11. Tim nut trai nhat cua cay con ben phai Q de thay the cho P.";
	cout << "\n12. Xoa mot nut ra khoi cay.";
	cout << "\n13. Xay dung cay AVL tu mot tap du lieu cho truoc.";
	cout << "\n14. Xuat he so can bang và du lieu chua trong cac nut cua cay theo thu tu NLR.";
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
void XuLyMenu(int menu, AVLTree& root)
{
	int key;
	vector<ElementType> data;
	ElementType value;
	AVLTreeNode* node;
	//=========================
	switch (menu)
	{
	case 0:
		system("CLS");
		cout << "\0. Thoat khoi chuong trinh\n";
		break;
	case 1:
		system("CLS");
		cout << "\n1. Tao cay can bang (AVL).\n";
		// Assume we read a series of values to insert into the AVL tree
		data = { 20, 10, 30, 5, 15, 25, 35 }; // Example data
		root = buildAVLTree(data);
		cout << "Cay AVL da duoc tao thanh cong.\n";
		break;
	case 2:
		system("CLS");
		cout << "\n2. Duyet cay theo thu tu NLR (PreOder) , LNR (Inorder), LRN (PosOder) dang de quy.\n";
		cout << "Duyet cay theo thu tu NLR (PreOrder): ";
		preOrder(root);
		cout << "\nDuyet cay theo thu tu LNR (InOrder): ";
		inOrder(root);
		cout << "\nDuyet cay theo thu tu LRN (PostOrder): ";
		postOrder(root);
		cout << endl;
		break;
	case 3:
		system("CLS");
		cout << "\n3. Tim nut tren cay chua gia tri key cho truoc (dang de quy).\n";
		cout << "Nhap gia tri can tim: ";
		cin >> key;
		node = findNode(root, key);
		if (node != nullptr) 
		{
			cout << "Tim thay nut voi gia tri: " << node->data << endl;
		}
		else 
		{
			cout << "Khong tim thay nut voi gia tri: " << key << endl;
		}
		break;
	case 4:
		system("CLS");
		cout << "\n4. Phep quay don Left-Left. Su dung khi cay con ben trai lech trai hoac can bang.\n";
		// Example rotation for demonstration
		root = rightRotate(root);
		cout << "Da thuc hien phep quay don Left-Left.\n";
		break;
	case 5:
		system("CLS");
		cout << "\n5. Phep quay don Right-Right. Su dung khi cay con ben phai lech phai hoac can bang.\n";
		// Example rotation for demonstration
		root = leftRotate(root);
		cout << "Da thuc hien phep quay don Right-Right.\n";
		break;
	case 6:
		system("CLS");
		cout << "\n6. Phep quay kep Left-Right. Su dung khi cay con ben trai lech phai.\n";
		// Example rotation for demonstration
		root = leftRightRotate(root);
		cout << "Da thuc hien phep quay kep Left-Right.\n";
		break;
	case 7:
		system("CLS");
		cout << "\n7. Phep quay kep Right-Left. Su dung khi cay con ben phai lech trai.\n";
		// Example rotation for demonstration
		root = rightLeftRotate(root);
		cout << "Da thuc hien phep quay kep Right-Left.\n";
		break;
	case 8:
		system("CLS");
		cout << "\n8. Can bang lai cay khi cay lech trai.\n";
		root = balanceLeft(root);
		cout << "Da can bang lai cay khi cay lech trai.\n";
		break;
	case 9:
		system("CLS");
		cout << "\n9. Can bang lai cay khi cay lech phai.\n";
		root = balanceRight(root);
		cout << "Da can bang lai cay khi cay lech phai.\n";
		break;
	case 10:
		system("CLS");
		cout << "\n10. Them mot phan tu moi vao cay\n";
		cout << "Nhap gia tri can them: ";
		cin >> value;
		root = insert(root, value);
		cout << "Da them gia tri " << value << " vao cay.\n";
		break;
	case 11:
		system("CLS");
		cout << "\n11. Tim nut trai nhat cua cay con ben phai Q de thay the cho P.\n";
		if (root != nullptr && root->rChild != nullptr) 
		{
			node = minValueNode(root->rChild);
			if (node != nullptr) 
			{
				cout << "Nut trai nhat cua cay con ben phai la: " << node->data << endl;
			}
			else 
			{
				cout << "Khong co nut con ben phai.\n";
			}
		}
		else 
		{
			cout << "Cay khong co nut con ben phai.\n";
		}
		break;
	case 12:
		system("CLS");
		cout << "\n12. Xoa mot nut ra khoi cay.\n";
		cout << "Nhap gia tri can xoa: ";
		cin >> key;
		root = deleteNode(root, key);
		cout << "Da xoa gia tri " << key << " ra khoi cay.\n";
		break;
	case 13:
		system("CLS");
		cout << "\n13. Xay dung cay AVL tu mot tap du lieu cho truoc.\n";
		data = { 50, 30, 70, 20, 40, 60, 80 }; // Example data
		root = buildAVLTree(data);
		cout << "Cay AVL da duoc tao thanh cong tu du lieu cho truoc.\n";
		break;
	case 14:
		system("CLS");
		cout << "\n14. Xuat he so can bang và du lieu chua trong cac nut cua cay theo thu tu NLR..\n";
		printBalanceFactors(root);
		break;
	}
}