#include <iostream>
#include <fstream>
#include <climits>
using namespace std;

int **memo;
struct Node
{
    int data;
    Node *next;
    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList
{
private:
    Node *head;
    Node *tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}
    ~LinkedList()
    {
        while (head != nullptr)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
    void insert(int value)
    {
        Node *newnode = new Node(value);
        if (head == nullptr)
        {
            head = newnode;
            tail = newnode;
            return;
        }
        tail->next = newnode;
        tail = tail->next;
    }
    void display()
    {
        Node *current = head;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};
void initializeMemo(int size, int attacks)
{
    memo = new int *[size];
    for (int i = 0; i < size; ++i)
    {

        memo[i] = new int[attacks];
        for (int k = 0; k < attacks; ++k)
        {
            memo[i][k] = -1;
        }
    }
}
void freeMemo(int size)
{
    for (int i = 0; i < size; ++i)
    {
        delete[] memo[i];
    }
    delete[] memo;
}
void freeDP(int **DP, int size)
{
    for (int i = 0; i < size; ++i)
    {
        delete[] memo[i];
    }
    delete[] memo;
}
void initialize(int *arr, int **DP, int cols)
{
    int i;
    int prevj = 0;
    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            DP[i][j] = 0;
        }
    }
    while (prevj < cols)
    {
        int j = prevj + 1;
        i = 0;
        while (j < cols)
        {
            DP[i][j] = DP[i][j - 1] + DP[i + 1][j] - DP[i + 1][j - 1] + arr[i] * arr[j];
            i++;
            j++;
        }
        prevj++;
    }
}

int BestStrategy(int **DP, int start, int end, int noofattacks)
{
    if (end - start <= noofattacks)
    {
        return 0;
    }
    if (noofattacks == 0)
    {
        return DP[start][end];
    }
    if (memo[start][noofattacks] != -1)
    {
        return memo[start][noofattacks];
    }
    int result = INT_MAX;
    for (int split = 0; split < end; ++split)
    {
        int right = BestStrategy(DP, split + 1, end, noofattacks - 1);
        int left = DP[start][split];
        result = min(result, left + right);
    }
    memo[start][noofattacks] = result;
    return result;
}

void FileHandling()
{
    LinkedList list;
    int numofattacks;
    ifstream infile("inputs.txt");
    int size;
    int **DP;
    while (infile >> size >> numofattacks)
    {
        if (numofattacks == 0)
        {
            break;
        }
        int *arr = new int[size];
        DP = new int *[size];
        for (int i = 0; i < size; i++)
        {
            DP[i] = new int[size];
            infile >> arr[i];
        }
        initialize(arr, DP, size);
        initializeMemo(size, numofattacks + 1);
        list.insert(BestStrategy(DP, 0, size - 1, numofattacks));
        freeMemo(size);
    }
    infile.close();
    list.display();
}

void Inputs()
{
    LinkedList list;
    int numofattacks;
    int size;
    while (true)
    {
        cout << "Enter number of depots: ";
        cin >> size;
        while (size < 0 || size > 1000)
        {
            cout << "Size is not valid (0-1000), kindly enter again: ";
            cin >> size;
        }
        cout << "Enter number of attacks : ";
        cin >> numofattacks;
        if (numofattacks == 0 && size == 0)
        {
            break;
        }
        while (numofattacks < 0 || numofattacks >= size)
        {
            cout << "NumOfAttacks not valid, kindly enter again: ";
            cin >> numofattacks;
        }
        int *arr = new int[size];
        int **DP = new int *[size];
        for (int i = 0; i < size; i++)
        {
            DP[i] = new int[size];
            cout << "Enter Depot " << i + 1 << " : ";
            cin >> arr[i];
        }
        initialize(arr, DP, size);
        initializeMemo(size, numofattacks + 1);
        list.insert(BestStrategy(DP, 0, size - 1, numofattacks));
        freeMemo(size);
    }
    list.display();
}

int main()
{
    cout << "1. File Handling" << endl
         << "2. Terminal based input " << endl
         << "Enter choice : ";
    int choice;
    cin >> choice;
    if (choice == 1)
    {
        FileHandling();
    }
    if (choice == 2)
    {
        Inputs();
    }
    return 0;
}