#include <bits/stdc++.h>
using namespace std;

vector<int> par;
vector<int> disc;
vector<int> low;
vector<bool> apoint;
int t;

int dfsc = 0;

void ap(int src, vector<vector<int>> &graph, vector<bool> &vis)
{
    vis[src] = true;

    disc[src] = low[src] = t;
    t++;

    for (int vtx : graph[src])
    {

        if (par[src] == vtx)
        {
        }

        else if (vis[vtx] == true)
        {
            low[src] = min(low[src], disc[vtx]);
        }
        else if (vis[vtx] == false)
        {
            // par[vtx]=src;
            par[vtx] = src;
            ap(vtx, graph, vis);
            low[src] = min(low[src], low[vtx]);

            if (par[src] == -1)
            {
                dfsc++;

                if (dfsc >= 2)
                {
                    apoint[src] = true;
                }
            }

            else if (disc[src] <= low[vtx])
            {
                apoint[src] = true;
            }
        }
    }
}

int main()
{
    int v, e;
    cin >> v >> e;
    vector<vector<int>> graph(v, vector<int>());
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
    }

    par.resize(v);
    disc.resize(v);
    low.resize(v);
    apoint.resize(v, false);
    vector<bool> vis(v, false);
    t = 0;
    par[0] = -1;
    ap(0, graph, vis);

    int count = 0;

    for (int i = 0; i < apoint.size(); i++)
    {
        if (apoint[i] == true)
            count++;
    }

    cout << count << endl;
}
