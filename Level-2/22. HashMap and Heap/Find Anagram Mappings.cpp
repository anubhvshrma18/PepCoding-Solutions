#include<bits/stdc++.h>
using namespace std;

vector<int> findMapping(int a1[],int a2[],int n){
    unordered_map<int,vector<int>> map;
    for(int i=0;i<n;i++){
        map[a2[i]].push_back(i);
    }
    vector<int> ans(n);
    for(int i=0;i<n;i++){
        vector<int> v=map[a1[i]];
        ans[i]=v[0];
        map[a1[i]].erase(map[a1[i]].begin());
    }
    
    return ans;
}

int main(){
    int n;
    cin >> n;
    int a1[n],a2[n];
    for(int i=0;i<n;i++){
        cin >> a1[i];
    }
    for(int i=0;i<n;i++){
        cin >> a2[i];
    }
    
    vector<int> ans = findMapping(a1,a2,n);
    for(auto a:ans){
        cout << a << " ";
    }
}