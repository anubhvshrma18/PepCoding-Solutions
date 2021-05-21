#include <bits/stdc++.h>
using namespace std;

// memoization
int csvjmem(int src,int n,int *jumps,int *dp){
    if(src==n){
        return 1;
    }
    if(dp[src]!=-1){
        return dp[src];
    }
    int ans=0;
    for(int i=1;i<=jumps[src];i++){
        ans+=csvjmem(src+i,n,jumps,dp);
    }
    dp[src]=ans;
    return ans;
}

//tabular method
int cstab(int *arr,int src, int n,int *a){
    a[n]=1;
    for(int i=n-1;i>=0;i--){
        int ans=0;
        for(int j=1;j<=arr[i] && i+j<=n;j++){
            ans+=a[i+j];
        }
        a[i]=ans;
    }
    return a[0];
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0 ; i < n ;i++){
        cin>>arr[i];
    }
    int a[n+1];
    cout<< cstab(arr,0,n,a) << endl;
}