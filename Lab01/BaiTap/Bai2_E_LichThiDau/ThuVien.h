void TaoLichThiDau(int n, int*** lichThiDau);

void TaoLichThiDau(int n, int*** lichThiDau) 
{
    int numMatches = n * (n - 1);
    *lichThiDau = new int* [numMatches];

    for (int i = 0; i < numMatches; ++i) 
    {
        (*lichThiDau)[i] = new int[2];
    }

    int index = 0;
    if (n == 2) 
    {
        (*lichThiDau)[index][0] = 1;
        (*lichThiDau)[index][1] = 2;
        index++;
    }
    else 
    {
        int** lichNuaDau;
        TaoLichThiDau(n / 2, &lichNuaDau);

        for (int i = 0; i < n / 2; ++i) 
        {
            (*lichThiDau)[index][0] = lichNuaDau[i][0];
            (*lichThiDau)[index][1] = lichNuaDau[i][1] + n / 2;
            index++;
        }

        for (int i = 1; i <= n / 2; ++i) 
        {
            for (int j = 0; j < n / 2; ++j) 
            {
                int doiNguoc = (lichNuaDau[j][1] + n / 2 - 1) % (n - 1) + 1;
                if (i != 1 || lichNuaDau[j][0] + lichNuaDau[j][1] != n) 
                {
                    (*lichThiDau)[index][0] = lichNuaDau[j][0] + i;
                    (*lichThiDau)[index][1] = doiNguoc;
                    index++;
                }
            }
        }

        for (int i = 0; i < n / 2; ++i) 
        {
            delete[] lichNuaDau[i];
        }
        delete[] lichNuaDau;
    }
}