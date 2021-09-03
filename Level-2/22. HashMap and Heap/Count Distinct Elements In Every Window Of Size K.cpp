#include "bits/stdc++.h"
using namespace std;

vector<int> solution(vector<int> &v,int k){
    unordered_map<int,int> mp;
    vector<int> ans;
    for(int i=0;i<v.size();i++){
        if(i<k-1){
            mp[v[i]]++;
        }
        else if(i==k-1){
            mp[v[i]]++;
            ans.push_back(mp.size());
        }
        else{
            if(mp[v[i-k]]==1){
                mp.erase(v[i-k]);
            } else{
                mp[v[i-k]]--;
            }
            mp[v[i]]++;
            ans.push_back(mp.size());

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
    int k;cin>>k;
    vector<int> ans = solution(v,k);
    for(auto a:ans){
        cout << a << " ";
    }

}