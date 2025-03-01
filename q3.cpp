#include <iostream>
using namespace std;
int findmax(int a[], int start, int end)
{
    int m = a[start];
    for (int i = start + 1; i <= end; i++)
    {
        if (a[i] > m)
        {
            m = a[i];
        }
    }
    return m;
}
int firstMissingPos(int A[], int start, int end)
{
    int nm = findmax(A, start, end) + 2;
    bool present[nm] = {false};
    for (int i = start; i <= end; i++)
    {
        present[A[i]] = true;
    }
    int min = 0;
    while (present[min])
        min++;
    return min;
}

void makesegments(int arr[], int size)
{
    int MNPN = firstMissingPos(arr, 0, size - 1);
    int maxsize = findmax(arr, 0, size - 1) + 2;
    bool present[maxsize] = {false};
    int right = MNPN;
    int left = 0;
    int i = 0;
    bool check = false;
    for (; i < size; i++)
    {
        if (present[arr[i]] == 0)
        {
            present[arr[i]] = true;
            left++;
            if (arr[i] > MNPN)
            {
                right++;
            }
        }
        if (left == right)
        {
            check = true;
            break;
        }
    }
    if (check)
    {
        if (i == size - 1)
        {
            if (firstMissingPos(arr, 0, i - 1) == firstMissingPos(arr, i, size - 1))
            {
                cout << "Segments created succesfully MNPN = " << MNPN << endl;
                cout << "Segment 1 : " << 1 << " - " << i << endl;
                cout << "Segment 2 : " << size << " - " << size << endl;
                return;
            }
        }
        else
        {
            if (firstMissingPos(arr, 0, i) == firstMissingPos(arr, i + 1, size - 1))
            {
                cout << "Segments created succesfully MNPN = " << MNPN << endl;
                cout << "Segment 1 : " << 1 << " - " << i + 1 << endl;
                cout << "Segment 2 : " << i + 2 << " - " << size << endl;
                return;
            }
        }
    }
    cout << "No segments created -1" << endl;
}
int main()
{
    cout << "Enter size of array : ";
    int s;
    cin >> s;
    while (s <= 0)
    {
        cout << "Enter Valid Size(1 - N) : ";
        cin >> s;
    }
    int arr[s];
    for (int i = 0; i < s; i++)
    {
        cout << "Enter element " << i + 1 << " : ";
        cin >> arr[i];
    }
    makesegments(arr, s);
}