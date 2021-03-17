#include<bits/stdc++.h>
using namespace std;

int CCC(int *arr,int n,int amt,int *dp){
    dp[0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<amt+1;j++){
            int left=j-arr[i];
            if(left>=0){
                dp[j]+=dp[left];
            }
        }
    }
    return dp[amt];
}
int main(){
    int n,amt;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    cin >> amt;
    int dp[amt+1];
    for(int i=0;i<=amt;i++){
        dp[i]=0;
    }
    cout << CCC(arr,n,amt,dp) << endl;
}