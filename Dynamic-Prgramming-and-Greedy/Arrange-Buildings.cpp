#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

//tabulation
ll countBinary0(ll n){
	ll dp[2][n+1];
	dp[0][0]=0;
	dp[1][0]=0;
	for(int j=1;j<n+1;j++){
		for(int i=0;i<2;i++){
		    if(j==1){
				dp[i][j]=1;
			}
			else if(i==0){
				dp[i][j]=dp[i+1][j-1];
			}
			else{
				dp[i][j]=dp[0][j-1]+dp[1][j-1];
			}
		}
	}
	return dp[0][n]+dp[1][n];
}



int main(){
	int n;
	cin >> n;
	long long ans =countBinary0(n);
	cout << ans*ans;
}