#include "bits/stdc++.h"
using namespace std;


int minSwaps(vector<int> &v){
    int n=v.size();
    vector<pair<int,int>> vec;
    for(int i=0;i<n;i++){
        vec.push_back({v[i],i});
    }
    
    sort(vec.begin(),vec.end());
    int minopr=0;
    
    vector<bool> vis(n);
    
    for(int i=0;i<n;i++){
        if(vis[i]==true || i==(vec[i]).second){
            continue;
        }
        
        int k=i,count=0;
        while(true){
            k = (vec[k]).second;
            if(vis[k]==true){
                break;
            }
            count++;
            vis[k]=true;
        }
        
        minopr+=(count-1);
    }
    
    return minopr;
}



int main(){
    int n;cin>> n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    cout << minSwaps(v) << endl;

}