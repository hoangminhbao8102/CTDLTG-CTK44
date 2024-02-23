const int N = 8;
int board[N];

bool KiemTraViTriAnToan(int row, int col);
void InBoard();
void GiaiBaiToan8HauUtil(int col);
void GiaiBaiToan8Hau();

bool KiemTraViTriAnToan(int row, int col) 
{
    for (int i = 0; i < col; ++i) 
    {
        if (board[i] == row || abs(board[i] - row) == abs(i - col))
            return false;
    }
    return true;
}

void InBoard() 
{
    for (int i = 0; i < N; ++i) 
    {
        for (int j = 0; j < N; ++j) 
        {
            if (board[j] == i)
            {
                cout << " 1 ";
            }
            else
            {
                cout << " 0 ";
            } 
        }
        cout << endl;
    }
    cout << endl;
}

void GiaiBaiToan8HauUtil(int col) 
{
    if (col == N) 
    { 
        InBoard(); 
        return;
    }

    for (int i = 0; i < N; ++i) 
    { 
        if (KiemTraViTriAnToan(i, col)) 
        {
            board[col] = i;
            GiaiBaiToan8HauUtil(col + 1);
        }
    }
}

void GiaiBaiToan8Hau() 
{
    GiaiBaiToan8HauUtil(0);
}