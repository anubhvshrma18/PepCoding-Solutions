#include<bits/stdc++.h>
using namespace std;

// O(n^2)
int LIS(vector<int> &V){
    vector<int> dp(V.size());
    int omax = 0;
    
    for(int i=0;i<V.size();i++){
        int mx = 0;
        for(int j=0;j<V.size();j++){
            if(V[j] < V[i]){
                mx = max(mx,dp[j]);
            }
        }
        
        dp[i] = mx+1;
        omax = max(omax , dp[i]);
    }
    
    return omax;
}



int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    
    cout << LIS(v) << endl;
}