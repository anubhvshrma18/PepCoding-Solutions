#include "bits/stdc++.h"
using namespace std;

int solution(vector<int> &v){
    unordered_map<string,int> map;
    int n=v.size();
    int ans=0,c0=0,c1=0,c2=0;
    string st = to_string(c1-c0)+"@"+to_string(c2-c1);
    map[st]=-1;   
    for(int i=0;i<n;i++){
        if(v[i]==0){
            c0++;
        } else if(v[i]==1){
            c1++;
        } else{
            c2++;
        }


        string state = to_string(c1-c0)+"@"+to_string(c2-c1);
        if(map.find(state)!=map.end()){
            ans = max(ans , i - map[state]);
            
        } else{
            map[state]=i;
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
    cout << solution(arr) << endl;
}