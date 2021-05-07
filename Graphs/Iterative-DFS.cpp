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
void iterDFS(vector<vector<Edge*>> &graph,int src){
    vector<bool> vis(graph.size(),false);
    stack<pair<int,string>> st;
    st.push({src,to_string(src)+""});
    while(st.size()>0){
        pair<int,string> p=st.top();
        st.pop();
        if(vis[p.first]){
            continue;
        }
        vis[p.first]=true;
        cout<< p.first << "@" << p.second <<"\n";
        for(Edge* edge:graph[p.first]){
            if(!vis[edge->nbr]){
                st.push({edge->nbr,p.second+to_string(edge->nbr)});
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
    iterDFS(graph,src);
    return 0;
}
