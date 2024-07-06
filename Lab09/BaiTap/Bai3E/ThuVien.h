typedef char KeyType;

struct BSNode 
{
    KeyType key;
    BSNode* left;
    BSNode* right;
};

typedef BSNode* BSTree;

struct NODE 
{
    BSTree info;
    NODE* pNext;
};

struct Stack 
{
    NODE* pHead;
    NODE* pTail;
};

void InitStack(Stack& s) 
{
    s.pHead = nullptr;
    s.pTail = nullptr;
}

bool IsEmpty(Stack s) 
{
    return s.pHead == nullptr;
}

void Push(Stack& s, BSTree x) 
{
    NODE* p = new NODE;
    p->info = x;
    p->pNext = nullptr;
    if (IsEmpty(s)) 
    {
        s.pHead = s.pTail = p;
    }
    else 
    {
        p->pNext = s.pHead;
        s.pHead = p;
    }
}

void Pop(Stack& s) 
{
    if (IsEmpty(s)) return;
    NODE* p = s.pHead;
    s.pHead = s.pHead->pNext;
    delete p;
    if (s.pHead == nullptr) 
    {
        s.pTail = nullptr;
    }
}

BSTree Top(Stack s) 
{
    if (IsEmpty(s)) return nullptr;
    return s.pHead->info;
}

bool IsDigit(char c) 
{
    return c >= '0' && c <= '9';
}

bool IsOperator(char c) 
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

BSNode* CreateNode(KeyType key) 
{
    BSNode* newNode = new BSNode;
    newNode->key = key;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

BSTree ConstructTree(const string& postfix) 
{
    Stack st;
    InitStack(st);
    for (char ch : postfix) 
    {
        if (!IsOperator(ch)) 
        {
            Push(st, CreateNode(ch));
        }
        else 
        {
            BSNode* t = CreateNode(ch);
            t->right = Top(st); Pop(st);
            t->left = Top(st); Pop(st);
            Push(st, t);
        }
    }
    return Top(st);
}

bool IsValidExpression(const string& expr) 
{
    int balance = 0;
    for (char ch : expr) 
    {
        if (IsDigit(ch) || IsOperator(ch)) 
        {
            if (IsOperator(ch))
            {
                if (balance < 2) return false;
                balance--;
            }
            else 
            {
                balance++;
            }
        }
        else
        {
            return false;
        }
    }
    return balance == 1;
}

int Precedence(char op) 
{
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

string InfixToPostfix(const string& infix) 
{
    Stack st;
    InitStack(st);
    string postfix;
    for (char ch : infix) 
    {
        if (IsDigit(ch)) 
        {
            postfix += ch;
        }
        else if (ch == '(') 
        {
            Push(st, CreateNode(ch));
        }
        else if (ch == ')') 
        {
            while (!IsEmpty(st) && Top(st)->key != '(') 
            {
                postfix += Top(st)->key; Pop(st);
            }
            Pop(st); // Remove '(' from stack
        }
        else 
        {
            while (!IsEmpty(st) && Precedence(Top(st)->key) >= Precedence(ch))
            {
                postfix += Top(st)->key; Pop(st);
            }
            Push(st, CreateNode(ch));
        }
    }
    while (!IsEmpty(st)) 
    {
        postfix += Top(st)->key; Pop(st);
    }
    return postfix;
}

BSTree InputExpression()
{
    string expr;
    cout << "Nhap bieu thuc so hoc: ";
    cin >> expr;

    if (!IsValidExpression(expr))
    {
        cerr << "Bieu thuc khong hop le!" << endl;
        return nullptr;
    }

    string postfix = InfixToPostfix(expr);
    return ConstructTree(postfix);
}

void PrintPrefix(BSTree root) 
{
    if (root) 
    {
        cout << root->key << ' ';
        PrintPrefix(root->left);
        PrintPrefix(root->right);
    }
}

void PrintInfix(BSTree root) 
{
    if (root) 
    {
        PrintInfix(root->left);
        cout << root->key << ' ';
        PrintInfix(root->right);
    }
}

void PrintPostfix(BSTree root) 
{
    if (root) 
    {
        PrintPostfix(root->left);
        PrintPostfix(root->right);
        cout << root->key << ' ';
    }
}

int Evaluate(BSTree root) 
{
    if (!root) return 0;

    if (!IsOperator(root->key)) return root->key - '0';

    int leftVal = Evaluate(root->left);
    int rightVal = Evaluate(root->right);

    switch (root->key) 
    {
    case '+': return leftVal + rightVal;
    case '-': return leftVal - rightVal;
    case '*': return leftVal * rightVal;
    case '/': return leftVal / rightVal;
    }
    return 0;
}