#include<bits/stdc++.h>
using namespace std;

int CCP(int *arr,int n,int amt,int *dp){
    dp[0]=1;
    for(int i=1;i<amt+1;i++){
        for(int j=0;j<n;j++){
            int t=i-arr[j];
            if(t>=0){
                dp[i]+=dp[t];

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
    for(int i=0;i<amt+1;i++){
        dp[i]=0;
    }
    cout << CCP(arr,n,amt,dp) << endl;
}