#include<bits/stdc++.h>
using namespace std;
typedef pair<int,pair<int,int>> pp;
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
class myComparator{
public:
    bool operator()(const pp &p1,const pp &p2){
        return p1.second.second>p2.second.second;
    }
};

void mst(vector<vector<Edge*>> graph){
    vector<bool> vis(graph.size(),false);
    priority_queue<pp,vector<pp>,myComparator> p;
    p.push(make_pair(0,make_pair(-1,0)));
    while(p.size()>0){
        int vtx=p.top().first;
        int pvtx=p.top().second.first;
        int wsf=p.top().second.second;
        p.pop();
        if(vis[vtx]==true){
            continue;
        }
        vis[vtx]=true;
        if(pvtx!=-1){
            cout << "[" << vtx <<"-" <<pvtx << "@" << wsf << "]" << endl;
        }
        for(Edge* edge:graph[vtx]){
            if(vis[edge->nbr]==false){
                p.push(make_pair(edge->nbr,make_pair(vtx,edge->wt)));
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
    mst(graph);
}