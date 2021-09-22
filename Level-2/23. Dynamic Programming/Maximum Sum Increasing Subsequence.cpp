#include<bits/stdc++.h>
 #include<vector>
 using namespace std;
 
 // This is a functional problem. You have to complete this function.
 // It takes as input an integer array. It should return the required sum.
 int maxSum(vector<int> &V) {
     // write your code here.
    vector<int> dp(V.size());
    int omax = INT_MIN;
    
    for(int i=0;i<V.size();i++){
        int mx = INT_MIN;
        for(int j=0;j<V.size();j++){
            if(V[j] < V[i]){
                mx = max(mx,dp[j]);
            }
        }
        
        dp[i] = (mx==INT_MIN)?V[i]:(mx+V[i]);
        omax = max(omax , dp[i]);
    }
    
    return omax;
 }
 	 
 int main(int argc, char** argv){
     int n;
     cin>>n;
     vector<int> A(n);
     for (int i = 0; i < n; i++)
         cin>>A[i];
 	 cout<<maxSum(A)<<endl;	 	 
 }