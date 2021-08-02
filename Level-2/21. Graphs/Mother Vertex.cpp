#include <bits/stdc++.h>
using namespace std;


void dfs_(vector<vector<int>> &graph,int src,vector<bool> &vis){
  vis[src]=true;
  for(int i:graph[src]){
    if(!vis[i]){
      dfs_(graph,i,vis);
    }
  }
}



void dfs(vector<vector<int>> &graph,int src,vector<bool> &vis,stack<int>&st){
  vis[src]=true;
  for(int i:graph[src]){
    if(!vis[i]){
      dfs(graph,i,vis,st);
    }
  }
  st.push(src);
}


int findMotherVertex(int n, vector<vector<int>> &graph){
  stack<int> st;
  vector<bool> vis(n+1,false);
  for(int i=0;i<n;i++){
    if(!vis[i]){
      dfs(graph,i,vis,st);
    }
  }

  vector<bool> nvis(n+1,false);
  vis=nvis;
  int node=st.top();
  dfs_(graph,node,vis);

  for(int i=0;i<n;i++){
    if(vis[i]==false){
      return -1;
    }
  }
  return node+1;
}



int main(){
  int n,m;
  cin >> n >> m;
  vector<vector<int>> graph(n,vector<int>(m));
  for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    graph[u-1].push_back(v-1);
  }
  cout << findMotherVertex(n, graph) << endl;
  return 0; 
}