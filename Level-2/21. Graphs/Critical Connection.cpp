#include "bits/stdc++.h"
using namespace std;

vector<int> par;
vector<int> disc;
vector<int> low;
// vector<bool> apoint;
int t;
    
void ap(int src,vector<vector<int>> &graph,vector<bool> &vis,vector<vector<int>> &ans){
    vis[src]=true;

    disc[src]=low[src]=t;
    t++;

    for(int vtx:graph[src]){

        if(par[src] == vtx){

        }

        else if(vis[vtx]==true){
            low[src] = min(low[src],disc[vtx]);
        }
        else if(vis[vtx]==false){
            // par[vtx]=src;
            par[vtx]=src;
            ap(vtx,graph,vis,ans);
            low[src]=min(low[src],low[vtx]);


            if(disc[src] < low[vtx]){
                vector<int> bridge{src,vtx};
                ans.push_back(bridge);
            }

        }

    }
}


vector<vector<int>> criticalConnections(vector<vector<int>>& graph) {
    vector<vector<int>> ans;
    int n=graph.size();
    vector<bool> vis(n,false);
    par.resize(n);
    disc.resize(n);
    low.resize(n);
    t=0;
    par[0]=-1;
    ap(0,graph,vis,ans);
    
    return ans;
    
}


int main(){
    int v,e;cin>>v>>e;
    vector<vector<int>> graph(v,vector<int>());
    for(int i=0;i<e;i++){
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<vector<int>> ans = criticalConnections(graph);
    cout << '[';
    for(int k=0;k<ans.size();k++){
        if(k==ans.size()-1){
            cout << "[" << ans[k][0] << ", " << ans[k][1] << "]";
        } else{
            cout << "[" << ans[k][0] << ", " << ans[k][1] << "], ";
        }
    }
    cout << ']' << endl;
}