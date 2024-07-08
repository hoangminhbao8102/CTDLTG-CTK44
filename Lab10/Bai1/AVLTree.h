typedef int ElementType; /* Kiểu dữ liệu của nút */

struct AVLTN 
{
    ElementType data;
    int balfactor; // Chỉ số cân bằng
    AVLTN* lChild; // Con trái
    AVLTN* rChild; // Con phải
};

typedef AVLTN AVLTreeNode;
typedef AVLTreeNode* AVLTree;

// Function to create a new AVL tree node
AVLTreeNode* createNode(ElementType data) 
{
    AVLTreeNode* node = new AVLTreeNode();
    node->data = data;
    node->balfactor = 0;
    node->lChild = nullptr;
    node->rChild = nullptr;
    return node;
}

// Function to get the height of a node
int height(AVLTreeNode* node) 
{
    if (node == nullptr) return 0;
    return 1 + max(height(node->lChild), height(node->rChild));
}

// Function to update the balance factor of a node
void updateBalanceFactor(AVLTreeNode* node) 
{
    if (node != nullptr) 
    {
        node->balfactor = height(node->lChild) - height(node->rChild);
    }
}

// Right rotate
AVLTreeNode* rightRotate(AVLTreeNode* y) 
{
    AVLTreeNode* x = y->lChild;
    AVLTreeNode* T2 = x->rChild;

    // Perform rotation
    x->rChild = y;
    y->lChild = T2;

    // Update balance factors
    updateBalanceFactor(y);
    updateBalanceFactor(x);

    return x;
}

// Left rotate
AVLTreeNode* leftRotate(AVLTreeNode* x) 
{
    AVLTreeNode* y = x->rChild;
    AVLTreeNode* T2 = y->lChild;

    // Perform rotation
    y->lChild = x;
    x->rChild = T2;

    // Update balance factors
    updateBalanceFactor(x);
    updateBalanceFactor(y);

    return y;
}

// Insert a node into the AVL tree
AVLTreeNode* insert(AVLTreeNode* node, ElementType data) 
{
    if (node == nullptr) return createNode(data);

    if (data < node->data) 
    {
        node->lChild = insert(node->lChild, data);
    }
    else if (data > node->data) 
    {
        node->rChild = insert(node->rChild, data);
    }
    else 
    {
        // Duplicate data is not allowed
        return node;
    }

    // Update balance factor of this ancestor node
    updateBalanceFactor(node);

    // Get the balance factor of this ancestor node to check whether this node became unbalanced
    int balance = node->balfactor;

    // If this node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && data < node->lChild->data) 
    {
        return rightRotate(node);
    }

    // Right Right Case
    if (balance < -1 && data > node->rChild->data) 
    {
        return leftRotate(node);
    }

    // Left Right Case
    if (balance > 1 && data > node->lChild->data) 
    {
        node->lChild = leftRotate(node->lChild);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && data < node->rChild->data) 
    {
        node->rChild = rightRotate(node->rChild);
        return leftRotate(node);
    }

    return node;
}

// A utility function to print the preorder traversal of the tree.
void preOrder(AVLTreeNode* root) 
{
    if (root != nullptr) 
    {
        cout << root->data << " ";
        preOrder(root->lChild);
        preOrder(root->rChild);
    }
}