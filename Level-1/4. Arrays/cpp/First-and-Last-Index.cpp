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
    int d;
    cin >> d;

    int count = 0, str = -1, end = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == d)
        {
            str = i;
            for (int j = i + 1; j < n; j++)
            {
                if (arr[j] == d)
                {
                    count++;
                }
                else
                {
                    break;
                }
            }
            end = str + count;
            break;
        }
    }
    cout << str << endl
         << end << endl;
    // write your code here
}