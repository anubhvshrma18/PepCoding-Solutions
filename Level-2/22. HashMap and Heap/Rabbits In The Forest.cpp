#include<bits/stdc++.h>
using namespace std;

int solution(vector<int> &v){
    unordered_map<int,int> map;
    for(int i:v){
        map[i]++;
    }
    int ans = 0;
    for(auto m:map){
        int val = m.second;
        int k =  m.first+1;
        
        ans += k*(int)ceil((val*1.0)/k);
    }
    
    return ans;
}


int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;++i){
        cin >> v[i];
    }
    
    cout << solution(v) << endl;
}