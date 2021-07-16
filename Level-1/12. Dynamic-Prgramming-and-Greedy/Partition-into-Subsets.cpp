#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll partitionintoSubsets(ll n, ll k)
{
    ll dp[n + 1][k + 1];
    for (ll i = 0; i <= n; i++)
    {
        for (ll j = 0; j <= k; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (i == j || j == 1)
            {
                dp[i][j] = 1;
            }
            else if (i < j)
            {
                dp[i][j] = 0;
            }
            else
            {
                dp[i][j] = dp[i - 1][j] * j + dp[i - 1][j - 1];
            }
        }
    }
    return dp[n][k];
}

int main()
{
    ll n, k;
    cin >> n >> k;
    cout << partitionintoSubsets(n, k);
}