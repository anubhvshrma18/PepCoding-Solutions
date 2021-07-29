#include "bits/stdc++.h"
using namespace std;

int jc(int n, int k)
{
    if (n == 1)
    {
        return 0;
    }
    int ans = jc(n - 1, k);
    return (ans + k) % n;
}

int main()
{
    int n, k;
    cin >> n >> k;
    cout << jc(n, k) << endl;
}