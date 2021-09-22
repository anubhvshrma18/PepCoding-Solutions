#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
int ans;

void solve(vector<int> &v,int idx,vector<int> &s1,vector<int> &s2 ,int sos1,int sos2){
    if(idx == v.size()){
        if(abs(sos1-sos2) < ans){
            ans = abs(sos1-sos2);
            g[0]=s1,g[1]=s2;
        }
        
        return;
    }
    
    if(s1.size() < (v.size() + 1)/2){
        s1.push_back(v[idx]);
        solve(v,idx+1,s1,s2,sos1+v[idx],sos2);
        s1.pop_back();
    }
    
    if(s2.size() < (v.size() + 1)/2){
        s2.push_back(v[idx]);
        solve(v,idx+1,s1,s2,sos1,sos2+v[idx]);
        s2.pop_back();
    }
}


void tow(vector<int>&v){
    g.resize(2);
    ans=INT_MAX;
    vector<int> temp1,temp2;
    solve(v,0,temp1,temp2,0,0);
    
    int i,j;
    cout << "[";
    for(i=0;i<g[0].size()-1;i++){
        cout << g[0][i] << ", ";
    }
    cout << g[0][i] << "] ";
    cout << "[";
    for(j=0;j<g[1].size()-1;j++){
        cout << g[1][j] << ", ";
    }
    cout << g[1][j] << "]" << endl;
    
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    
    tow(v);
}