#include<bits/stdc++.h>
using namespace std;
 

 int longBit(vector<int> &V) {
    vector<int> dp1(V.size());
    vector<int> dp2(V.size());
    int omax = 0;
    
    // lis
    for(int i=0;i<V.size();i++){
        int mx = 0;
        for(int j=0;j<i;j++){
            if(V[j] < V[i]){
                mx = max(mx,dp1[j]);
            }
        }
        
        dp1[i] = mx+1;
    }
    
    for(int i=V.size()-1;i>=0;i--){
        int mx = 0;
        for(int j=i+1;j<V.size();j++){
            if(V[j] < V[i]){
                mx = max(mx,dp2[j]);
            }
        }
        
        dp2[i] = mx+1;
        
    }
    
    
    for(int i=0;i<V.size();i++){
        int len = dp1[i]+dp2[i]-1;
        omax = max(omax,len);
    }
    
    return omax;
 }
 	 
 int main(int argc, char** argv){
     int n;
     cin>>n;
     vector<int> A(n);
     for (int i = 0; i < n; i++)
         cin >> A[i];
 	 cout<<longBit(A)<<endl;	 	 
 }