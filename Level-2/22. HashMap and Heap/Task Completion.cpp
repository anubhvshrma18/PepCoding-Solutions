#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> v(m);
    for(int i=0;i<m;i++){
        cin >> v[i];
    }
    
    vector<int> s(n+1,0);
    for(int i=0;i<m;i++){
        s[v[i]]++;
    }
    
    vector<int> ans;
    for(int i=1;i<=n;i++){
        if(s[i]==0){
            ans.push_back(i);    
        }
    }
    
    
    for(int i=0;i<ans.size();i+=2){
        cout << ans[i] << " ";
    }
    cout << endl;
    for(int i=1;i<ans.size();i+=2){
        cout << ans[i] << " ";
    }
    cout << endl;
    
}