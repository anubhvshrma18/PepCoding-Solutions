#include<bits/stdc++.h>
using namespace std;

vector<int> parentA;
vector<int> rankA;
vector<int> parentB;
vector<int> rankB;

int find(vector<int> &p,int x){
    if(p[x] == x){
        return x;
    }
    int temp = find(p,p[x]);
    p[x]=temp; // path compression
    return temp;
}
bool merge(vector<int> &pa , vector<int> &ra,int u,int v){
    int lx = find(pa,u);
    int ly = find(pa,v);
    if(lx != ly) {
        //merging is required
        if(ra[lx] < ra[ly]) {
            pa[lx] = ly;
        }
        else if(ra[lx] > ra[ly]) {
            pa[ly] = lx;
        }
        else {
            pa[lx] = ly;
            ra[ly]++;
        }
        return true;
    }
    else {
        //merging is not required
        return false;
    }
    
}
    
    


int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
    parentA.resize(n+1);
    parentB.resize(n+1);
    
    rankA.resize(n+1);
    rankB.resize(n+1);
    
    for(int i=1;i<=n;i++){
        parentA[i]=i;
        parentB[i]=i;
        rankA[i]=0;
        rankB[i]=0;
    }
        
    int remc=0,ca=1,cb=1;
    for(int i=0;i<edges.size();i++){
        int type = edges[i][0],u = edges[i][1],v=edges[i][2];
        // both alice and bob
        if(type==3){
            
            bool ma = merge(parentA,rankA,u,v);
            bool mb = merge(parentB,rankB,u,v);
            if(ma == true && mb == true) {
                ca++;
                cb++;
            }
            else if(ma == false && mb == false) {
                remc++;
            }
        }
    }
        
    for(int i=0;i<edges.size();i++){
        int type = edges[i][0],u = edges[i][1],v=edges[i][2];
        // for alice
        if(type==1){
            bool ma = merge(parentA,rankA,u,v);
            
            if(ma == true) {
                ca++;
            }
            else {
                remc++;
            }
            
        }
    }
        
    for(int i=0;i<edges.size();i++){
        int type = edges[i][0],u = edges[i][1],v=edges[i][2];
        // for bob
        if(type==2){
            bool mb = merge(parentB,rankB,u,v);
            
            if(mb == true) {
                cb++;
            }
            else {
                remc++;
            }
        }
    }
    

    // if all the nodes can be easily travelled by both the return min nodes to be removed   
    if(ca == n && cb == n){
        return remc;
    }
    
    // if either of them cant fully traverse all points return -1
       
    return -1;
}


int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> v(m);
    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        v[i] = {a,b,c};
    }
    
    cout << maxNumEdgesToRemove(n,v) << endl;
}
    
    