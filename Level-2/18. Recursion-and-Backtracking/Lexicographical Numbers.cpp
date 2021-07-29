#include "bits/stdc++.h"
using namespace std;

void family_print(int num, int n)
{
    if (num > n)
    {
        return;
    }

    cout << num << endl;
    for (int i = 0; i <= 9; i++)
    {
        family_print(num * 10 + i, n);
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= 9; i++)
    {
        family_print(i, n);
    }
}