#include "bits/stdc++.h"
using namespace std;

bool solution(vector<int> &v,int k){
    unordered_map<int,int> mp;
    for(int i=0;i<v.size();i++){
        int rem = v[i]%k;
        if(mp.find(rem)==mp.end()){
            mp[rem]=1;
        }
        else{
            mp[rem]++;
        }
    }


    for(auto m:mp){
        int freq=m.second;

        if(m.first==0) {
            if(freq%2!=0){
                return false;
            }
        }
        else if(k%2==0 && m.first==k/2) {
            if(freq%2!=0){
                return false;
            }
        }
        else {
            int left = k-m.first;
            if(mp.find(left)==mp.end() || mp[left]!=freq){
                return false;
            }
        }
    }
    return true;
}


int main(){
    int n;cin>> n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    int k;cin>>k;
    if(solution(v,k)){
        cout << "true" << endl;
    } else{
        cout << "false" << endl;
    }

}