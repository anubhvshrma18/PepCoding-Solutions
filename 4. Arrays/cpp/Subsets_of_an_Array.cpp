#include <bits/stdc++.h>
using namespace std;

int *decToBinary(int n, int len)
{
    int *arr = new int[len];
    int i = len - 1;
    while (n > 0)
    {
        int rem = n % 2;
        arr[i] = rem;
        n = n / 2;
        i--;
    }
    return arr;
}

void printSubsets(int *arr, int n)
{
    int ts = (int)pow(2, n);
    for (int d = 0; d < ts; d++)
    {
        int *subset = decToBinary(d, n);
        for (int i = 0; i < n; i++)
        {
            if (subset[i] == 0)
            {
                cout << "-\t";
            }
            else if (subset[i] == 1)
            {
                cout << arr[i] << "\t";
            }
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    printSubsets(arr, n);
}