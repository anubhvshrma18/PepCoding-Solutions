#include <bits/stdc++.h>
using namespace std;
//tabulation
int CSMTab(int *arr,int src,int n,int *dp){
    dp[n]=0;
    for(int i=n-1;i>=0;i--){
        int mn=INT_MAX;
        for(int j=1;j<=arr[i] && i+j<=n;j++){
            int ans=dp[i+j];
            if(ans<mn){
                mn=ans;
            }
        }
        if(mn==INT_MAX){
            dp[i]=mn;
        }else{
            int a=mn+1;
            dp[i]=a;   
        }
    }
    return dp[0];
    
}

//memoization
int CSMM(int *arr,int src,int n,int *dp){
    if(src==n){
        return 0;
    }
    if(dp[src]!=0){
        return dp[src];
    }
    int mn=INT_MAX;
    for(int i=1;i<=arr[src] && src+i<=n;i++){
        int ans=CSMM(arr,src+i,n,dp);
        if(ans<mn){
            mn=ans;
        }
    }
    if(mn==INT_MAX){
        dp[src]=mn;
        return dp[src];
    }
    int ans=mn+1;
    dp[src]=ans;
    return ans;
}
int main(){
	int n;
	cin >> n;
	int arr[n];
	int dp[n+1];
	for(int i=0;i<n;i++){
		cin >> arr[i];
	    dp[i]=0;
	}
	dp[n]=0;
	int ans=CSMTab(arr,0,n,dp);
	
    if(ans==INT_MAX){
        cout << "null";
    }
    else{
        cout << ans;
    }
	return 0;
}