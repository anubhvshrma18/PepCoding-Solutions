#include <iostream>
#include <vector>
using namespace std;

// -----------------------------------------------------
// This is a functional problem. Only this function has to be written.
// This function takes as input 2D array
// It should return the required output
int minCost(vector<vector<int>> &arr)
{
    //Write your code here
    int n = arr.size();
    int dp[n][3];
    dp[0][0] = arr[0][0];
    dp[0][1] = arr[0][1];
    dp[0][2] = arr[0][2];
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (j == 0)
            {
                dp[i][j] = min(dp[i - 1][1], dp[i - 1][2]) + arr[i][j];
            }
            else if (j == 1)
            {
                dp[i][j] = min(dp[i - 1][0], dp[i - 1][2]) + arr[i][j];
            }
            else
            {
                dp[i][j] = min(dp[i - 1][0], dp[i - 1][1]) + arr[i][j];
            }
        }
    }
    return min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2]));
}

int main(int argc, char **argv)
{
    int n;
    cin >> n;
    vector<vector<int>> costs(n, vector<int>(3));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> costs[i][j];
        }
    }
    cout << minCost(costs) << endl;
}