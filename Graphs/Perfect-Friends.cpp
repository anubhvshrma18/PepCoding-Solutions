#include<bits/stdc++.h>
using namespace std;

void getall(vector<vector<int>> graph,int src,vector<int> &v,vector<bool> &x){
   x[src]=true;
   v.push_back(src);
   for(int y:graph[src]){
       if(!x[y]) {
           getall(graph,y,v,x);
       }
   }
}
int perfectfriends(vector<vector<int>> &graph){
    vector<bool> vis(graph.size(),false);
    vector<int> vec;
    for(int i=0;i<graph.size();i++){
        vector<int> v;
        getall(graph,i,v,vis);
        vec.push_back(v.size());

    }
    int count=0;
    for(int i=0;i<vec.size();i++){
        for(int j=i+1;j<vec.size();j++){
            count+=vec[i]*vec[j];
        }
    }
    return count;
}

int main(){
	int v,e;
    cin >> v >> e;
    vector<vector<int>> graph(v,vector<int>());
    for(int i=0;i<e;i++){
        int v1,v2;
        cin >> v1 >> v2;

        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    cout << perfectfriends(graph) << endl;
    return 0;
}