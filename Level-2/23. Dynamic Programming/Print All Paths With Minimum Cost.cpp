#include<bits/stdc++.h>
using namespace std;

struct Pair{
    int i;
    int j;
    string s;
    Pair(int a,int b,string p){
        i=a;
        j=b;
        s=p;
    }
};


void printPath(vector<vector<int>>& dp){
    int n=dp.size(),m=dp[0].size();
    
    queue<Pair*> q;
    q.push(new Pair(0,0,""));
    
    while(q.size()>0){
        Pair* p = q.front();
        q.pop();
        
        if(p->i == n-1 && p->j == m-1){
            cout << p->s << endl;
            continue;
        }
        
        
        if(p->j==m-1){
            // dp[i][j]=dp[i+1][j]+mat[i][j];
            q.push(new Pair(p->i + 1, p->j , p->s +"V"));
        }
        else if(p->i==n-1){
            // dp[i][j]=dp[i][j+1]+mat[i][j];
            q.push(new Pair(p->i , p->j + 1 , p->s +"H"));
        }
        else{
            int val =min(dp[p->i + 1][p->j],dp[p->i][p->j + 1]);
            
            
            if(dp[p->i + 1][p->j] == val){
                q.push(new Pair(p->i + 1, p->j , p->s +"V"));
            }
            if(dp[p->i][p->j + 1] == val){
                q.push(new Pair(p->i , p->j + 1 , p->s +"H"));
            }
        }
    }
       
}

void minCost(vector<vector<int>> &mat){
    int n = mat.size(),m=mat[0].size();
    vector<vector<int>> dp(n,vector<int>(m));
    
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            if(i==n-1 && j==m-1){
                dp[i][j]=mat[i][j];
            }
            else if(i==n-1){
                dp[i][j]=dp[i][j+1]+mat[i][j];
            }
            else if(j==m-1){
                dp[i][j]=dp[i+1][j]+mat[i][j];
            }
            else{
                dp[i][j]=min(dp[i+1][j],dp[i][j+1])+mat[i][j];
            }
        }
    }
    cout << dp[0][0] << endl;
    printPath(dp);
}



int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> mat(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> mat[i][j];
        }
    }
    
    minCost(mat);
}