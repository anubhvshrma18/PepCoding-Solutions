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

// DFS travelling
void isallconnected(vector<vector<Edge*>> graph,int src,vector<bool> &x,string s,int osrc){
    if(s.size()==x.size()){
        int flg=0;
        for(Edge* edge:graph[osrc]){
            if(edge->nbr==src){
                flg=1;
                cout << s << "*" << endl;
                break;
            }
        }
        if(!flg){
            cout << s <<"." << endl;
        }
    }
    x[src]=true;
    for(Edge* edge:graph[src]){
        int nhr=edge->nbr;
        if(!x[nhr]) {
            isallconnected(graph,nhr,x,s+ to_string(nhr),osrc);
        }
    }
    x[src]=false;
}

void hamiltonian(vector<vector<Edge*>> graph,int src){
    vector<bool> x(graph.size(),false);
    isallconnected(graph,src,x,""+ to_string(src),src);
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
    int src;
    cin >> src;
    hamiltonian(graph,src);
    return 0;
}