struct Point 
{
    int x, y;
    Point(int _x, int _y) : x(_x), y(_y) {}
};

void setMatrix(int** matrix, int size, int x, int y, int value);
int getMatrix(int** matrix, int size, int x, int y);
bool isValid(int size, int x, int y);
void findAllPathsUtil(int** matrix, int size, int x, int y, bool* visited, int* path, int& pathIndex, int** paths, int& maxLength, int& maxWeight);
void findAllPaths(int** matrix, int size, int& maxLength, int& maxWeight, int** paths);
void printPaths(int** paths, int maxLength, int maxWeight);

void setMatrix(int** matrix, int size, int x, int y, int value) 
{
    matrix[x][y] = value;
}

int getMatrix(int** matrix, int size, int x, int y) 
{
    return matrix[x][y];
}

bool isValid(int size, int x, int y) 
{
    return x >= 0 && x < size && y >= 0 && y < size;
}

void findAllPathsUtil(int** matrix, int size, int x, int y, bool* visited, int* path, int& pathIndex, int** paths, int& maxLength, int& maxWeight) 
{
    visited[x * size + y] = true;
    path[pathIndex] = matrix[x][y];
    pathIndex++;

    if (x == size - 1 && y == size - 1) 
    {
        int weight = 0;
        for (int i = 0; i < pathIndex; i++) 
        {
            weight += path[i];
        }
        if (pathIndex >= maxLength) 
        {
            maxLength = pathIndex;
            maxWeight = weight;
            for (int i = 0; i < pathIndex; i++) 
            {
                paths[maxLength][i] = path[i];
            }
        }
    }
    else 
    {
        if (isValid(size, x - 1, y) && !visited[(x - 1) * size + y]) 
        {
            findAllPathsUtil(matrix, size, x - 1, y, visited, path, pathIndex, paths, maxLength, maxWeight);
        }
        if (isValid(size, x + 1, y) && !visited[(x + 1) * size + y]) 
        {
            findAllPathsUtil(matrix, size, x + 1, y, visited, path, pathIndex, paths, maxLength, maxWeight);
        }
        if (isValid(size, x, y - 1) && !visited[x * size + (y - 1)]) 
        {
            findAllPathsUtil(matrix, size, x, y - 1, visited, path, pathIndex, paths, maxLength, maxWeight);
        }
        if (isValid(size, x, y + 1) && !visited[x * size + (y + 1)]) 
        {
            findAllPathsUtil(matrix, size, x, y + 1, visited, path, pathIndex, paths, maxLength, maxWeight);
        }
    }

    pathIndex--;
    visited[x * size + y] = false;
}

void findAllPaths(int** matrix, int size, int& maxLength, int& maxWeight, int** paths) 
{
    bool* visited = new bool[size * size];
    int* path = new int[size * size];
    int pathIndex = 0;
    maxLength = 0;
    maxWeight = 0;

    for (int i = 0; i < size * size; i++) 
    {
        visited[i] = false;
    }

    findAllPathsUtil(matrix, size, 0, 0, visited, path, pathIndex, paths, maxLength, maxWeight);

    delete[] visited;
    delete[] path;
}

void printPaths(int** paths, int maxLength, int maxWeight) 
{
    cout << "Paths with maximum length " << maxLength << " and maximum weight " << maxWeight << " are:\n";
    for (int i = 0; i < maxLength; i++) 
    {
        cout << "Path: ";
        for (int j = 0; j < maxLength; j++) 
        {
            if (paths[i][j] != 0) 
            {
                cout << paths[i][j] << " ";
            }
        }
        cout << "\n";
    }
}