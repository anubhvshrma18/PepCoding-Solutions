#include <bits/stdc++.h>
using namespace std;

int cnt = 1;
//rssf->remaining set so far
void solution(int id, int n, int k, int rssf, vector<vector<int>> &v)
{
    if (id > n)
    { //printing
        if (rssf == k)
        {
            cout << cnt << ". ";
            for (int i = 0; i < v.size(); i++)
            {
                cout << "[";
                for (int j = 0; j < v[i].size(); j++)
                {
                    if (j == v[i].size() - 1)
                    {
                        cout << v[i][j];
                        break;
                    }
                    cout << v[i][j] << ", ";
                }
                cout << "] ";
            }
            cout << endl;
            cnt++;
        }
        return;
    }

    for (int i = 0; i < k; i++)
    {
        // non empty subset addition
        if (v[i].size() > 0)
        {
            v[i].push_back(id);
            solution(id + 1, n, k, rssf, v);
            v[i].pop_back();
        }
        // empty subset addition
        else
        {
            v[i].push_back(id);
            solution(id + 1, n, k, rssf + 1, v);
            v[i].pop_back();
            break;
        }
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> v(k, vector<int>());
    solution(1, n, k, 0, v);
    return 0;
}