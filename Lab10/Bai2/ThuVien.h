struct AVLTreeNode 
{
    string data;
    int balfactor; // Chỉ số cân bằng
    AVLTreeNode* lChild; // Con trái
    AVLTreeNode* rChild; // Con phải
    AVLTreeNode* parent; // Con trỏ đến nút cha
};
typedef AVLTreeNode* AVLTree;

AVLTreeNode* createNewNode(const string& data, AVLTreeNode* parent = nullptr) 
{
    AVLTreeNode* newNode = new AVLTreeNode;
    newNode->data = data;
    newNode->balfactor = 0;
    newNode->lChild = nullptr;
    newNode->rChild = nullptr;
    newNode->parent = parent;
    return newNode;
}

// Hàm xoay sang trái
void rotateLeft(AVLTree& node) 
{
    AVLTree right = node->rChild;
    node->rChild = right->lChild;
    if (right->lChild != nullptr) 
    {
        right->lChild->parent = node;
    }
    right->parent = node->parent;
    if (node->parent == nullptr) 
    {
        node = right;
    }
    else if (node == node->parent->lChild) 
    {
        node->parent->lChild = right;
    }
    else 
    {
        node->parent->rChild = right;
    }
    right->lChild = node;
    node->parent = right;
}

// Hàm xoay sang phải
void rotateRight(AVLTree& node) 
{
    AVLTree left = node->lChild;
    node->lChild = left->rChild;
    if (left->rChild != nullptr) 
    {
        left->rChild->parent = node;
    }
    left->parent = node->parent;
    if (node->parent == nullptr) 
    {
        node = left;
    }
    else if (node == node->parent->rChild) 
    {
        node->parent->rChild = left;
    }
    else 
    {
        node->parent->lChild = left;
    }
    left->rChild = node;
    node->parent = left;
}

// Thêm các hàm cân bằng và chèn tại đây
void updateBalance(AVLTree node)
{
    if (node->balfactor < -1 || node->balfactor > 1) 
    {
        if (node->balfactor > 0) 
        {
            if (node->lChild->balfactor < 0) 
            {
                rotateLeft(node->lChild);
            }
            rotateRight(node);
        }
        else 
        {
            if (node->rChild->balfactor > 0) 
            {
                rotateRight(node->rChild);
            }
            rotateLeft(node);
        }
    }
}

void insert(AVLTree& tree, AVLTree node, const string& x) 
{
    if (tree == nullptr) 
    {
        tree = new AVLTreeNode;  // Tạo nút mới
        tree->data = x;          // Khởi tạo dữ liệu
        tree->balfactor = 0;     // Khởi tạo chỉ số cân bằng
        tree->lChild = nullptr;  // Không có con trái
        tree->rChild = nullptr;  // Không có con phải
        tree->parent = node;     // Khởi tạo con trỏ cha
    }
    else if (x < tree->data) 
    {
        insert(tree->lChild, tree, x);
        tree->balfactor--;
    }
    else if (x > tree->data) 
    {
        insert(tree->rChild, tree, x);
        tree->balfactor++;
    }

    updateBalance(tree);
}

void loadFromFileAndInsert(AVLTree& tree, const string& filename) 
{
    ifstream file(filename);
    string word;
    while (file >> word) 
    {
        insert(tree, nullptr, word);  // Sửa lại đây: thêm nullptr làm đối số thứ hai
    }
    file.close();
}

void printTree(AVLTree node, string indent = "", bool last = true) 
{
    // Hàm này sử dụng để in cây ra console theo dạng nhìn được (giản đơn)
    if (node != nullptr) {
        cout << indent;
        if (last) 
        {
            cout << "R----";
            indent += "   ";
        }
        else 
        {
            cout << "L----";
            indent += "|  ";
        }
        cout << node->data << " (BF: " << node->balfactor << ")" << endl;
        printTree(node->lChild, indent, false);
        printTree(node->rChild, indent, true);
    }
}

void freeTree(AVLTree node) 
{
    if (node != nullptr) 
    {
        freeTree(node->lChild);  // Giải phóng cây con trái
        freeTree(node->rChild);  // Giải phóng cây con phải
        delete node;             // Giải phóng nút hiện tại
    }
}
