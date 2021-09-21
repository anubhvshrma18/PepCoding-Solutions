#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&v){
    set<int> st;
    for(auto a:v){
        st.insert(a);
    }
    int k = st.size();
    
    int i=-1,j=-1;
    map<int,int> map;
    int ans =0;
    int n = v.size();
    
    while(i<n-1){
        // acquire
        while(i<n-1){
            i++;
            map[v[i]]++;
            
            if(map.size()==k){
                ans+=(n-i);
                break;
            }
            
        }
        
        
        while(j < i && map.size()==k){
            j++;
            if(map[v[j]]==1){
                map.erase(v[j]);
            }
            else{
                map[v[j]]--;
                ans+=(n-i);
            }
        }
    }
    
    return ans;
}



int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    
    cout << solve(v) << endl;
}