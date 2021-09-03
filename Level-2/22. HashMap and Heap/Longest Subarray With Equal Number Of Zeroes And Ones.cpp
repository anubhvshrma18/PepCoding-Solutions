#include "bits/stdc++.h"
using namespace std;

int solution(vector<int> &v){
    for(int i=0;i<v.size();i++){
        if(v[i]==0){
            v[i]=-1;
        }
    }
    
    
    
    unordered_map<int,int> mp;
    int ps=0;int ans=0;
    mp[0]=-1;
    for(int i=0;i<v.size();i++){
        ps+=v[i];

        if(mp.find(ps)!=mp.end()){
            ans =max(ans, i-mp[ps]);
        } else{
            mp[ps]=i;
        }
    }
    return ans;
}


int main(){
    int n;cin>> n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    cout << solution(v) << endl;

}