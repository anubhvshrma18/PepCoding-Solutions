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
int spathwt=INT_MAX;
int lpathwt=INT_MIN;
int cpathwt=INT_MAX;
int fpathwt=INT_MIN;
string spath="";
string cpath="";
string lpath="";
string fpath="";
void multisolver(vector<vector<Edge*>> &graph,int src,int des,vector<bool> &x,int criteria,int k,string s,int wsf){
    if(src==des){
        if(wsf<spathwt){
            spath=s;
            spathwt=wsf;
        }
        if(wsf>lpathwt){
            lpath=s;
            lpathwt=wsf;
        }
        if(wsf>criteria && cpathwt>wsf){
            cpathwt=wsf;
            cpath=s;
        }
        if(wsf<criteria && fpathwt<wsf){
            fpathwt=wsf;
            fpath=s;
        }
        return;
    }

    x[src]=true;
    for(Edge* edge:graph[src]){
        int nb=edge->nbr;
        if(!x[nb]) {
            multisolver(graph, nb, des, x, criteria, k, s + to_string(nb), wsf + edge->wt);
        }
    }
    x[src]= false;
}

void kthlargest(vector<vector<Edge*>> graph,int src,int des,vector<bool>& y,int k){
    int val=INT_MAX;
    for(int i=0;i<k;i++) {
        fpath = "";
        fpathwt = INT_MIN;
        multisolver(graph, src, des, y, val, k, to_string(src) +fpath, 0);
        val = fpathwt;
    }
    string q=fpath;
    int ans=val;
    cout << k << "th largest path = " << q << "@" << ans;
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
    int src,des,criteria,k;
    cin >> src >> des >> criteria >> k;
    vector<bool> x(v,false);
    string s="";
    multisolver(graph,src,des,x,criteria,k,s+to_string(src),0);
    cout<<"Smallest Path = "<< spath << "@" << spathwt << endl;
    cout<<"Largest Path = " << lpath << "@" << lpathwt << endl;
    cout<<"Just Larger Path than "<<criteria <<" = " <<cpath <<"@"<<cpathwt << endl;
    cout<<"Just Smaller Path than " << criteria <<" = " << fpath << "@" << fpathwt << endl;
    vector<bool> y(v,false);
    kthlargest(graph,src,des,y,k);
    return 0;
}