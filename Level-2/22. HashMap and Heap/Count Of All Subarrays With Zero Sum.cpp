#include "bits/stdc++.h"
using namespace std;

int solution(vector<int> &v){
    unordered_map<int,int> mp;
    int ps=0;int ans=0;
    mp[0]=1;
    for(int i=0;i<v.size();i++){
        ps+=v[i];

        if(mp.find(ps)!=mp.end()){
            ans += mp[ps];
            mp[ps]++;
        } else{
            mp[ps]=1;
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
    // int k;cin>>k;
    cout << solution(v) << endl;

}