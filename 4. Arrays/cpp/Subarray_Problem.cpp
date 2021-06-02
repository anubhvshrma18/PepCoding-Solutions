#include <iostream>
using namespace std;

void subarray(int *arr, int n)
{
    int str = 0;
    while (str < n)
    {
        int end = str;
        while (end < n)
        {
            for (int i = str; i <= end; i++)
            {
                cout << arr[i] << "\t";
            }
            cout << endl;
            end++;
        }
        str++;
    }
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    subarray(arr, n);
}