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
vector<bool> x(1000,false);
bool allPaths(vector<vector<Edge*>> &graph,int src,int des){
    if(src==des){
        return true;
    }
    x[src]=true;
    for(Edge* edge :graph[src]){
        int nei=edge->nbr;
        if(!x[nei]) {
            if (allPaths(graph, nei, des)) {
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
    int src,des;
    cin >> src >> des;
    if(allPaths(graph,src,des)){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }
}