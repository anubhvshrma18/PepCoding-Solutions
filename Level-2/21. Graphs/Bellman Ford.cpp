#include<bits/stdc++.h>
using namespace std;

struct Edge{
    int src;
    int nbr;
    int wt;
    Edge(int src,int nbr,int wt){
        this->src=src;
        this->nbr=nbr;
        this->wt=wt;
    }
};



void bellmanFord(vector<vector<Edge*>> &graph,int src){
    vector<Edge*> edges;
    for(int i=0;i<graph.size();i++){
        for(int j=0;j<graph[i].size();j++){
            if(i<graph[i][j]->nbr){
                edges.push_back(graph[i][j]);
            }
        }
    }
    
    vector<int> cost(graph.size(),INT_MAX);
    cost[src]=0;
    
    for(int itr=1;itr<=graph.size()-1;itr++){
        for(int e=0;e<edges.size();e++){
            Edge* ne = edges[e];
            int u=ne->src;
            int v=ne->nbr;
            int wt=ne->wt;
            
            if(cost[u]==INT_MAX){
                continue;
            }
            else if(cost[u]+wt<cost[v]){
                cost[v]=cost[u]+wt;   
            }
        }
    }
    
    for(int i=0;i<cost.size();i++){
        if(i==src){
            continue;
        }
        cout << cost[i] << " ";
    }
    cout << endl;
    
}

int main(){
	int v,e;
    cin >> v >> e;
    vector<vector<Edge*>> graph(v,vector<Edge*>());
    for(int i=0;i<e;i++){
        int v1,v2,wt;
        cin >> v1 >> v2 >> wt;
        Edge* e1=new Edge(v1-1,v2-1,wt);
        Edge* e2=new Edge(v2-1,v1-1,wt);

        graph[v1-1].push_back(e1);
        graph[v2-1].push_back(e2);
    }
    
    bellmanFord(graph,0);
}