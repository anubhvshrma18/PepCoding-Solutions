#include <bits/stdc++.h>
using namespace std;
//tabulation
int minCostTab(vector<vector<int>> &arr,int sr,int sc,vector<vector<int>> &dp){
	int n=arr.size();
	int m=arr[0].size();
	
	for(int i=n-1;i>=0;i--){
		for(int j=m-1;j>=0;j--){
			if(i==n-1 && j==m-1){
				dp[i][j]=arr[i][j];
			}
			else if(i==n-1){
				dp[i][j]=dp[i][j+1]+arr[i][j];
			}
			else if(j==m-1){
				dp[i][j]=dp[i+1][j]+arr[i][j];	
			}
			else{
				dp[i][j]=min(dp[i][j+1],dp[i+1][j])+arr[i][j];
			}
		}
	}
	return dp[0][0];
}

//memoization
int minCostMem(vector<vector<int>> &arr,int sr,int sc,vector<vector<int>> &dp){
	if(sr==arr.size()-1 && sc==arr[0].size()-1){
		return arr[sr][sc];
	}
	if(sr>=arr.size() || sc>=arr[0].size()){
		return INT_MAX;
	}
	if(dp[sr][sc]!=0){
		return dp[sr][sc];
	}
	int ncost=min(minCostMem(arr,sr,sc+1,dp),minCostMem(arr,sr+1,sc,dp));
	dp[sr][sc]=ncost+ arr[sr][sc];
	return dp[sr][sc];
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> arr(n,vector<int> (m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
        	cin >> arr[i][j];
        }
    }
    vector<vector<int>> dp(n,vector<int> (m,0));
    cout << minCostTab(arr,0,0,dp);
}