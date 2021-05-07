#include<bits/stdc++.h>
using namespace std;

struct Edge{
    int src;
    int nbr;
    int wt;
//    Edge(){
//
//    }
    Edge(int src,int nbr,int wt){
        this->src=src;
        this->nbr=nbr;
        this->wt=wt;
    }
};
stack<int> st;
void orderofcompilation(vector<vector<int>> &graph,int src,vector<bool> &vis){
    if(vis[src]){
        return;
    }
    vis[src]=true;
    for(int nr:graph[src]){
        if(!vis[nr]){
            orderofcompilation(graph,nr,vis);
        }
    }
    st.push(src);
}



int main(){
    int v,e;
    cin >> v >> e;
    vector<vector<int>> graph(v,vector<int>());
    for(int i=0;i<e;i++){
        int v1,v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
    }
    vector<bool> vis(v,false);
    for(int i=0;i<v;i++){
        orderofcompilation(graph,i,vis);
    }
    while(!st.empty()){
        cout << st.top() << endl;
        st.pop();
    }
    return 0;
}
