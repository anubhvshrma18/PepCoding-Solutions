#include<bits/stdc++.h>
using namespace std;
//memoization
int maxGoldMem(vector<vector<int>> &arr,int sr,int sc,vector<vector<int>> &dp){
	if(sr<0 || sr>=arr.size() || sc >= arr[0].size()){
		return 0;
	}
    if(dp[sr][sc]!=0){
        return dp[sr][sc];
    }
	int dU=maxGold(arr,sr-1,sc+1,dp);
	int dM=maxGold(arr,sr,sc+1,dp);
	int dD=maxGold(arr,sr+1,sc+1,dp);

	int mxGld=max(dU,max(dM,dD));
	int ans=mxGld+arr[sr][sc];
	dp[sr][sc]=ans;
	return ans; 
}

//tabulation
int maxGoldTab(vector<vector<int>> &arr,int sr,int sc,vector<vector<int>> &dp){
    int n=arr.size();
    int m=arr[0].size();
    
    for(int j=m-1;j>=0;j--){
        for(int i=0;i<n;i++){
            if(j==m-1){
                dp[i][j]=arr[i][j];
            }
            else if(i==n-1){
                dp[i][j]=max(dp[i-1][j+1],dp[i][j+1])+arr[i][j];
            }
            else if(i==0){
                dp[i][j]=arr[i][j]+max(dp[i][j+1],dp[i+1][j+1]);
            }
            else{
                dp[i][j]=arr[i][j]+max(dp[i-1][j+1],max(dp[i][j+1],dp[i+1][j+1]));
            }
        }
    }
    
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
    int ans=0;
    for(int i=0;i<n;i++){
        int mx=maxGoldTab(arr,i,0,dp);
    	ans=max(mx,ans);
    }
    cout << ans<< endl;
}