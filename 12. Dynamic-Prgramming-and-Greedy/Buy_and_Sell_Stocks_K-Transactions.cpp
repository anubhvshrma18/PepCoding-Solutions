// K Transactions

#include <bits/stdc++.h>
using namespace std;

int kTrans(int *arr, int n,int k){
	if(k>n){return 0;}
	int dp[k+1][n];
	for(int i=0;i<=k;i++){
		int mx=INT_MIN;
		for(int j=0;j<n;j++){
			if(i==0||j==0){
				dp[i][j]=0;
			}
			else{
				mx=max(mx,dp[i-1][j-1]-arr[j-1]);
				dp[i][j]=max(mx+arr[j],dp[i][j-1]);
			}
		}
	}
	return dp[k][n-1];
}
int main(){
	int n,k;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	cin >> k;
	cout << kTrans(arr,n,k);
	return 0;
}
