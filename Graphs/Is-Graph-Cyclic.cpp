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

//BFS wala
bool isComponentCyclic(vector<vector<Edge*>> &graph,int src,vector<bool> &vis){
    queue<int> q;
    q.push(src);
    while(q.size()>0){
        int t=q.front();
        q.pop();
        if(vis[t]){
            return true;
        }
        vis[t]=true;
        for(Edge* edge:graph[src]){
            if(!vis[edge->nbr]){
                q.push(edge->nbr);
            }
        }
    }

    return false;
}

bool isGraphCyclic(vector<vector<Edge*>> &graph){
    vector<bool> vis(graph.size(),false);
    for(int v=0;v<graph.size();v++){
        if(!vis[v]){
            if(isComponentCyclic(graph,v,vis)){
                return true;
            }
        }
    }
    return false;
}

int main(){
    int v,e;
    cin >> v >> e;
    vector<vector<Edge*>> graph(v,vector<Edge*>());
    for(int i=0;i<e;i++){
        int v1,v2,wt;
        cin >> v1 >> v2 >> wt;
        Edge* e1=new Edge(v1,v2,wt);
        Edge* e2=new Edge(v2,v1,wt);

        graph[v1].push_back(e1);
        graph[v2].push_back(e2);
    }
    if(isGraphCyclic(graph)){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }
    return 0;
}