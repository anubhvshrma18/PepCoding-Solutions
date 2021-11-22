#include <bits/stdc++.h>
using namespace std;


// tabulation
int cs(int n){
    int dp[n+1];
    dp[0]=1;
    for(int i=1;i<=n;i++){
        if(i==1){
            dp[i]=1;
        }
        else if(i==2){
            dp[i]=2;
        }
        else{
            dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
        }
    }

    return dp[n];
}


// memoization
int cs(int n,vector<int> &v){
    // write your code here
    if(n==0){return 1;}
    if(n<0){return 0;}
    if(v[n]!=-1){ return v[n];}
    int csp=cs(n-1,v)+cs(n-2,v)+cs(n-3,v);
    return v[n]=csp;
}



int main(){
    int n;
    cin>>n;
    vector<int> v(n+1,-1);
    cout<<cs(n,v)<<endl;
}