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

void allPaths(vector<vector<Edge*>> &graph,int src,int des,string s,vector<bool> &x){
    if(src==des){
        cout << s << endl;
        return;
    }
    x[src]=true;
//    s+= to_string(src);
    for(Edge* edge :graph[src]){
        int nei=edge->nbr;
        if(!x[nei]) {
            allPaths(graph, nei, des,s+to_string(nei),x);
        }
    }
    x[src]=false;
}

void getallconnected(vector<vector<Edge*>> graph,int src,vector<int> &l,vector<bool> &x){

    x[src]=true;
    l.push_back(src);
    for(Edge* edge:graph[src]){
        int nhr=edge->nbr;
        if(!x[nhr]) {
            getallconnected(graph,nhr,l,x);
        }
    }
}

void getAllConnectedComponents(vector<vector<Edge*>> graph,vector<vector<int>> &ans){
    vector<bool> x(graph.size(),false);
    for(int i=0;i<graph.size();i++){
        if(!x[i]){
            vector<int> l;
            getallconnected(graph,i,l,x);
            ans.push_back(l);
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
    vector<vector<int>> ans;
    getAllConnectedComponents(graph,ans);
    cout << "[";
    int i=0;
    for(auto z:ans){
        if(i==ans.size()-1){
            cout << "[";
            int j=0;
            for(auto m:z){
                if(j==z.size()-1){
                    cout << m;
                    break;
                }
                cout << m << ", ";
                j++;
            }
            cout << "]";
            break;
        }
        cout << "[";
        int j=0;
        for(auto m:z){
            if(j==z.size()-1){
                cout << m;
                break;
            }
            cout << m << ", ";
            j++;
        }
        cout << "], ";
        i++;
    }
    cout << "]";
    return 0;
}