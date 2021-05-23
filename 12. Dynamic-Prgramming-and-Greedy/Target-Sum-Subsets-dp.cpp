#include<bits/stdc++.h>
using namespace std;

//tabulation
bool targetSumSubset(int *arr,int n,int tar,int sum){
    int dp[n+1][tar+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=tar;j++){
            if(j==0){
                dp[i][j]=true;
            }
            else if(i==0){
                dp[i][j]=false;
            }
            else{
                bool a=dp[i-1][j];
                bool b=false;
                if(j>=arr[i-1]){
                    b=dp[i-1][j-arr[i-1]];
                }
                dp[i][j]=a || b;
            }
        }
    }
    return dp[n][tar];
    
}

int main(){
    int n,tar;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    cin >> tar;
    
    if(targetSumSubset(arr,n,tar,0)){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }
}