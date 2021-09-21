#include<bits/stdc++.h>
using namespace std;

bool canReorderDoubled(vector<int>& arr) {
    sort(arr.begin(),arr.end());
    unordered_map<int,int> map;
    for(int a:arr) map[a]++;
    
    for(int a:arr){
        if(map[a]==0) 
            continue;
        if(a < 0 && abs(a)%2 == 1) 
            return false;
        int next_val =  a < 0 ? a/2 : a*2;
        if(map[next_val]==0) return false;
        map[a]--,map[next_val]--;
        
    }
    return true;
}


int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    
    if(canReorderDoubled(arr)){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }
}