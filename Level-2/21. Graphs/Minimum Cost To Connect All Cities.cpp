#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pp;

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
        return p1.second > p2.second;
    }
};

int prims(vector<vector<Edge*>> &graph){
  int cost=0;
  priority_queue<pp,vector<pp>,myComparator> pq;
  pq.push({0,0});

  vector<bool> vis(graph.size(),false);

  while(pq.size()>0){
    int vtx=pq.top().first;
    int wei = pq.top().second;
    pq.pop();

    if(vis[vtx]==true){
      continue;
    }  
    vis[vtx]=true;
    cost+=wei;

    for(Edge* edge:graph[vtx]){
      int nr= edge->nbr;
      int w = edge->wt;
      if(!vis[nr]){
        pq.push({nr,w});
      }
    }
  }

  return cost;
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
  int cost=prims(graph);
  cout << cost << endl;
  return 0;

}