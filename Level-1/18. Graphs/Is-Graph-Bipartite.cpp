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
bool isComponentsBipartite(vector<vector<Edge*>> &graph,int src,vector<int> &vis){
    
    queue<pair<int,int>> q;
    q.push({src,1});

    while(q.size()>0){
        //remove
        pair<int,int> p=q.front();
        q.pop();

        //mark
        if(vis[p.first]!=0){
            if(vis[p.first]!=p.second){
                return false;
            }
            continue;
        }
        vis[p.first]=p.second;

        //add neighbour
        for(Edge* edge:graph[p.first]){
            int nbrset=(p.second==1)?2:1;
            if(vis[edge->nbr]==0){
                q.push({edge->nbr,nbrset});
            }
        }

    }
    return true;
}

bool isbipartite(vector<vector<Edge*>> &graph){
    vector<int> vis(graph.size(),0);

    for (int i = 0; i < graph.size();i++){
        if(vis[i]==0){
            if(!isComponentsBipartite(graph,i,vis)){
                return false;
            }
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
    if(isbipartite(graph)){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }
    return 0;
}