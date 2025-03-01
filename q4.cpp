#include <iostream>
using namespace std;
int MaxPower(int **Arr, int rows, int cols)
{
    if (rows == 1)
    {
        int max = 0;
        for (int i = 0; i < cols; i++)
        {
            if (Arr[0][i] > max)
            {
                max = Arr[0][i];
            }
        }
        return max;
    }
    int SumArr[rows][cols] = {0};
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            SumArr[i][j] = 0;
        }
    }
    for (int i = 0; i < rows; i++)
    {
        SumArr[i][0] = Arr[i][0];
    }
    for (int i = 0; i < cols; i++)
    {
        int max[2] = {0};
        int indexes[2] = {0};
        for (int j = 0; j < rows; j++)
        {
            if (SumArr[j][i] > max[0])
            {
                max[0] = SumArr[j][i];
                indexes[0] = j;
            }
        }
        for (int j = 0; j < rows; j++)
        {
            if (SumArr[j][i] > max[1] && j != indexes[0])
            {
                max[1] = SumArr[j][i];
                indexes[1] = j;
            }
        }
        for (int k = i + 1; k < cols && k < i + 3; k++)
        {
            for (int l = 0; l < rows; l++)
            {
                if (l != indexes[0])
                {
                    if (max[0] + Arr[l][k] > SumArr[l][k])
                    {
                        SumArr[l][k] = max[0] + Arr[l][k];
                    }
                }
            }
        }
        for (int k = i + 1; k < cols && k < i + 3; k++)
        {
            for (int l = 0; l < rows; l++)
            {
                if (l != indexes[1])
                {
                    if (max[1] + Arr[l][k] > SumArr[l][k])
                    {
                        SumArr[l][k] = max[1] + Arr[l][k];
                    }
                }
            }
        }
    }
    int max = 0;
    for (int i = 0; i < rows; i++)
    {
        if (SumArr[i][cols - 1] > max)
        {
            max = SumArr[i][cols - 1];
        }
    }
    return max;
}
int main()
{
    int M, N;
    cout << "Enter rows(M) : ";
    cin >> M;
    while (M <= 0)
    {
        cout << "Rows can't be less than 0. Enter again: ";
        cin >> M;
    }
    cout << "Enter columns(N) : ";
    cin >> N;
    while (N <= 0)
    {
        cout << "Columns can't be less than 0. Enter again : ";
        cin >> N;
    }
    int **Arr = new int *[M];
    for (int i = 0; i < M; i++)
    {
        Arr[i] = new int[N];
        for (int j = 0; j < N; j++)
        {
            cout << "Arr[" + to_string(i) + "][" + to_string(j) + "] : ";
            cin >> Arr[i][j];
        }
    }
    cout << endl;
    cout << "Maximum Power: " << MaxPower(Arr, M, N);
    cout << endl
         << endl;
    for (int i = 0; i < M; i++)
    {
        delete[] Arr[i];
    }
    delete[] Arr;
    return 0;
}