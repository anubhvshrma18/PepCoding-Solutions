#include<bits/stdc++.h>
using namespace std;


void solve(vector<int> &v){
    map<int,vector<int>> map;
    int n = v.size();
    for(int i=0;i<n;i++){
        int val = v[i];
        
        if(map.find(val)==map.end()){
            map[val].push_back(1);
            map[val].push_back(i);
            map[val].push_back(i);
        }
        else{
            map[val][0]++;
            map[val][1] = min(map[val][1],i);
            map[val][2] = max(map[val][2],i);    
        }
        
    }
   
    int hf=0;
    for(auto m:map){
        if(m.second[0]>hf){
            hf=m.second[0];
        }
    }
    
    int st=-1,et=-1,len=INT_MAX;
    
    for(auto m:map){
        if(m.second[0]==hf){
            int ws = m.second[2]-m.second[1]+1;
            
            if(ws < len){
                len=ws;
                st = m.second[1];
                et = m.second[2];
            }
            else if(ws == len){
                if(st > m.second[0]){
                    len=ws;
                    st = m.second[1];
                    et = m.second[2];
                }
            }
        }
    }
    
    
    cout << v[st] << "\n" << st << "\n" << et << endl;
    
}


int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    
    solve(v);
}