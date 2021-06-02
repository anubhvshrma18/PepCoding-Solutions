#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int data;
    cin >> data;

    for (int i = 0; i < n; i++)
    {
        if (data == arr[i])
        {
            cout << arr[i] << endl;
        }
        else if (arr[i] < data && arr[i + 1] > data && i < n - 1)
        {
            cout << arr[i + 1] << endl;
            cout << arr[i] << endl;
        }
    }
}