#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &graph, int src, stack<int> &st, vector<bool> &vis)
{
    vis[src] = true;
    for (int vtx : graph[src])
    {
        if (vis[vtx] == false)
        {
            dfs(graph, vtx, st, vis);
        }
    }

    st.push(src);
}

void dfs_(vector<vector<int>> &graph, int src, vector<bool> &vis)
{
    vis[src] = true;
    for (int vtx : graph[src])
    {
        if (vis[vtx] == false)
        {
            dfs_(graph, vtx, vis);
        }
    }
}

int stronglyConnectedComponents(vector<vector<int>> &graph)
{
    int v = graph.size();
    vector<bool> vis(v, false);
    stack<int> st;

    // store all the nodes
    for (int i = 0; i < v; i++)
    {
        if (vis[i] == false)
        {
            dfs(graph, i, st, vis);
        }
    }

    // reverse all the edges
    vector<vector<int>> revgraph(v, vector<int>());

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < graph[i].size(); j++)
        {
            int src = i;
            int nbr = graph[i][j];

            revgraph[nbr].push_back(src);
        }
    }

    // count the scc(dfs) using stack
    int scc = 0;
    vector<bool> nvis(v, false);

    while (st.size() > 0)
    {
        int top = st.top();
        st.pop();
        if (nvis[top] == false)
        {
            dfs_(revgraph, top, nvis);
            scc++;
        }
    }

    return scc;
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
    }
    int scc = stronglyConnectedComponents(graph);
    cout << scc << endl;
}