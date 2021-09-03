#include "bits/stdc++.h"
using namespace std;

int isNegativeWeightCycle(int n,vector<vector<int>>edges){
	    // Code here
    vector<int> count(n,INT_MAX);
    count[0]=0;
    
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        int wt=edges[i][2];
        
        if(count[u]==INT_MAX){
            continue;
        }
        else if(count[u]+wt<count[v]){
            count[v]=count[u]+wt;
        }
    }
    
    
    
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        int wt=edges[i][2];
        
        if(count[u]==INT_MAX){
            continue;
        }
        else if(count[u]+wt<count[v]){
            return 1;
        }
    }
    return 0;
}


int main(){
    int v,e;
    cin >> v >> e;
    vector<vector<int>> graph(e,vector<int>());
    for(int i=0;i<e;i++){
        int u,v,wt;
        cin >> u>>v >>wt;
        graph[i].push_back(u);
        graph[i].push_back(v);
        graph[i].push_back(wt);
    }
    int ans = isNegativeWeightCycle(v,graph);
    cout << ans << endl;

}