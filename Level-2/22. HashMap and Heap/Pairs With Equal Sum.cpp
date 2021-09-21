#include<bits/stdc++.h>
using namespace std;

bool solve(vector<int> &v){
    map<int,int> map;
    int n=v.size();
    for(int i=0;i<n;i++){
        
        for(int j=i+1;j<n;j++){
            int val = v[i]+v[j];
            
            if(map.find(val)!=map.end()){
                return true;
            }
            map[val]++;
        }
    }
    
    return false;
    
    
    
}



int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    
    if(solve(v)){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }
}