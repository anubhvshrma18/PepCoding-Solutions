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
void isallconnected(vector<vector<Edge*>> graph,int src,vector<bool> &x){
    x[src]=true;
    for(Edge* edge:graph[src]){
        int nhr=edge->nbr;
        if(!x[nhr]) {
            isallconnected(graph,nhr,x);
        }
    }
}

bool isConnected(vector<vector<Edge*>> graph){
    vector<bool> x(graph.size(),false);
    isallconnected(graph,0,x);
    for(auto a:x){
        if(a==false){
            return false;
        }
    }
    return true;
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
    if(isConnected(graph)){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }

    return 0;
}