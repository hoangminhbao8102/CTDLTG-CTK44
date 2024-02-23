#define MAX_N 10 

struct Point 
{
    int x, y;
    Point(int _x, int _y) : x(_x), y(_y) {}
};

bool isValidMove(int x, int y, int n, bool visited[MAX_N][MAX_N]);
int calculateMaxSumPath(int x, int y, int n, int board[MAX_N][MAX_N], bool visited[MAX_N][MAX_N]);
void printMaxSumPath(int n, int board[MAX_N][MAX_N]);

bool isValidMove(int x, int y, int n, bool visited[MAX_N][MAX_N]) 
{
    return (x >= 0 && y >= 0 && x < n && y < n && !visited[x][y]);
}

int calculateMaxSumPath(int x, int y, int n, int board[MAX_N][MAX_N], bool visited[MAX_N][MAX_N]) 
{
    static int dx[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
    static int dy[] = { 1, 2, 2, 1, -1, -2, -2, -1 };

    visited[x][y] = true;
    int maxSum = 0;

    for (int i = 0; i < 8; ++i) 
    {
        int newX = x + dx[i];
        int newY = y + dy[i];
        if (isValidMove(newX, newY, n, visited)) 
        {
            int currentSum = calculateMaxSumPath(newX, newY, n, board, visited);
            maxSum = max(maxSum, currentSum);
        }
    }

    visited[x][y] = false;
    return maxSum + board[x][y];
}

void printMaxSumPath(int n, int board[MAX_N][MAX_N]) 
{
    bool visited[MAX_N][MAX_N] = { false };
    int maxSum = 0;
    Point maxSumStart(0, 0);

    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < n; ++j) 
        {
            visited[i][j] = false;
            int currentSum = calculateMaxSumPath(i, j, n, board, visited);
            if (currentSum > maxSum) 
            {
                maxSum = currentSum;
                maxSumStart = Point(i, j);
            }
        }
    }

    cout << "Maximum sum path starts at (" << maxSumStart.x << ", " << maxSumStart.y << ") with sum: " << maxSum << endl;
}