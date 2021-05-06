#include<bits/stdc++.h>
using namespace std;

void getislands(vector<vector<int>> &v,vector<vector<bool>> &vis,int r,int c){
    if(r<0 || c<0 || r>=v.size() || c>=v[0].size()|| v[r][c]==1 || vis[r][c]==true){
        return;
    }
    vis[r][c]=true;
    getcompo(v,vis,r-1,c);
    getcompo(v,vis,r,c+1);
    getcompo(v,vis,r+1,c);
    getcompo(v,vis,r,c-1);
}


int noofislands(vector<vector<int>> v){
    int n=v.size(),m=v[0].size(),count=0;
    vector<vector<bool>> vis(n,vector<bool>(m,false));
    for(int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            if(!vis[i][j] && v[i][j]==0){
                getislands(v,vis,i,j);
                count++;
            }
        }
    }

    return count;
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> v(n,vector<int>(m));
    for(int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            cin >> v[i][j];
        }
    }
    cout << noofislands(v) << endl;
    return 0;

}