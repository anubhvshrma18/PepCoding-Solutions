#include "bits/stdc++.h"
using namespace std;

int solution(vector<int> &v,int k){
    unordered_map<int,int> map;

    int ps=0;int ans=0;
    map[0]=1;
    for(int i=0;i<v.size();i++){

        ps+=v[i];

        int rem = ps%k;
        if(rem < 0){
            rem = rem + k;
        }

        if(map.find(rem)!=map.end()){
            ans+=map[rem];
            map[rem]++;

        } else{
            map[rem]=1;
        }


    }
    return ans;
}


int main(){
    int n;cin>> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int k;cin >> k;
    cout << solution(arr,k) << endl;
}