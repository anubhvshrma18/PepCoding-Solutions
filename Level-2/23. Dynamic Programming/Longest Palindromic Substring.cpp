#include<bits/stdc++.h>
using namespace std;
int countSubstrings(string s) {
    int n=s.length();
    int si=-1,sj=-1;
    vector<vector<bool>> dp(n,vector<bool>(n,false));
    for(int d=0;d<n;d++){
        for(int i=0,j=d;j<n;i++,j++){
            if(d==0){
                dp[i][j]=true;
            }
            else if(d == 1){
                if(s[i]==s[j]) dp[i][j]=true;
            }
            else{
                dp[i][j] = (s[i]==s[j] && dp[i+1][j-1]);
            }
            
            if(dp[i][j]==true){
                si = i;
                sj = j;
            }
        }
    }
    
    return sj-si+1;
}
int main(){
    string s;
    cin >> s;
    cout << countSubstrings(s) << endl;
}