#include <bits/stdc++.h>
using namespace std;

void diffTwoArray(int a1[], int a2[], int n1, int n2)
{
    int ans[n2];
    int i = n1 - 1;
    int j = n2 - 1;
    int k = n2 - 1;

    int borrow = 0;

    while (j >= 0)
    {
        int sub = (a2[j] + borrow);

        if (i >= 0)
        {
            sub = sub - a1[i];
        }

        int val = sub;

        if (sub < 0)
        {
            val = val + 10;
            borrow = -1;
        }
        else
        {
            borrow = 0;
        }

        ans[k] = val;

        i--;
        j--;
        k--;
    }

    int fnzi = -1; //first non zero index

    for (int i = 0; i < n2; i++)
    {
        if (ans[i] != 0)
        {
            fnzi = i;
            break;
        }
    }

    if (fnzi == -1)
    {
        cout << "0" << endl;
        return;
    }

    for (int i = fnzi; i < n2; i++)
    {
        cout << ans[i] << endl;
    }
}

int main()
{
    int n1, n2;
    cin >> n1;
    int arr1[n1];
    for (int i = 0; i < n1; i++)
    {
        cin >> arr1[i];
    }
    cin >> n2;
    int arr2[n2];
    for (int i = 0; i < n2; i++)
    {
        cin >> arr2[i];
    }

    diffTwoArray(arr1, arr2, n1, n2);
}