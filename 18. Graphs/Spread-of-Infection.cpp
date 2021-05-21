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
void spreadinfection(vector<vector<Edge*>> graph,int src,int tme){
    vector<bool> vis(graph.size(),false);
    queue<pair<int,int>> q;
    q.push({src,1});
    int cnt=0;
    while(q.size()>0){
        int tp=q.front().first;
        int t=q.front().second;
        q.pop();
        if(t>tme){
            break;
        }
        if(vis[tp]==true){
            continue;
        }
        vis[tp]=true;
        cnt++;
        
        for(Edge* edge:graph[tp]){
            if(!vis[edge->nbr]){
                q.push({edge->nbr,t+1});
                
            }
        }
    }
    
    cout << cnt << endl;
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
    int src,tme;
    cin >> src >> tme;
    spreadinfection(graph,src,tme);
}