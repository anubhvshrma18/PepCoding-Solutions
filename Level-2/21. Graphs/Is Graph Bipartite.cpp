#include <bits/stdc++.h>
using namespace std;

bool isBipartite(vector<vector<int>> &graph, int src, vector<int> &vis)
{
    queue<pair<int, int>> q;
    q.push({src, 1});
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();

        if (vis[p.first] != 0)
        {
            if (vis[p.first] != p.second)
            {
                return false;
            }
            continue;
        }

        vis[p.first] = p.second;

        for (int i : graph[p.first])
        {
            int color = (p.second == 2) ? 1 : 2;
            if (vis[i] == 0)
            {
                q.push({i, color});
            }
        }
    }
    return true;
}

bool isGraphBipartite(vector<vector<int>> &graph, int v)
{
    vector<int> vis(graph.size(), 0);
    for (int i = 0; i < graph.size(); i++)
    {
        if (vis[i] == 0)
        {
            if (isBipartite(graph, i, vis) == false)
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    int v, e;
    cin >> v >> e;
    vector<vector<int>> graph(v, vector<int>());
    for (int i = 0; i < e; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    if (isGraphBipartite(graph, v))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    return 0;
}