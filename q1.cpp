#include <iostream>
using namespace std;
int dp[201][201];
int calculateStructures(int n)
{
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= n; ++j)
        {
            if (i == 0)
            {
                dp[i][j] = 1;
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (j <= i)
            {
                dp[i][j] = dp[i][j - 1] + dp[i - j][j - 1];
            }
            else
            {
                dp[i][j] = dp[i][j - 1];
            }
        }
    }

    return dp[n][n - 1];
}
int main()
{
    int n;
    cout << endl;
    cout << "Enter the total number of blocks (n): ";
    cin >> n;
    while (n < 3 || n > 200)
    {
        cout << endl
             << "Size must be between 3 and 200, Re-Enter Size: ";
        cin >> n;
    }
    int numberOfStructures = calculateStructures(n);
    cout << endl
         << "-----Calculating Structures-----" << endl
         << endl;
    cout << "The number of structures that can be built from " << n << " blocks is: ";
    cout << numberOfStructures << endl
         << endl;

    return 0;
}