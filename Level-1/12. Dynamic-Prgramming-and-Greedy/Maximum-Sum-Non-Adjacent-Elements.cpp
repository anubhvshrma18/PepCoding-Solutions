#include <bits/stdc++.h>
using namespace std;

int maxSum(int *arr, int n)
{
    int in = 0, ex = 0;
    for (int i = 0; i < n; i++)
    {
        int ni = ex + arr[i];
        int ne = max(in, ex);

        in = ni;
        ex = ne;
    }
    return max(in, ex);
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
    cout << maxSum(arr, n);
}