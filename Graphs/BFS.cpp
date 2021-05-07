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

void bfs(vector<vector<Edge*>> graph,int src){
    queue<pair<int,string>> q;
    vector<bool> x(graph.size(),false);
    q.push({src,""+ to_string(src)});
    while(q.size()>0){
        pair<int,string> p=q.front();
        q.pop();
        if(!x[p.first]){
            x[p.first]=true;
            cout << p.first << "@" << p.second << endl;
            for(Edge* edge:graph[p.first]){
                int nr=edge->nbr;
                if(!x[nr]){
                    q.push({nr,p.second+to_string(nr)});
                }
            }
        }
    }
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
    bfs(graph,src);
    return 0;
}