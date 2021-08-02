#include <bits/stdc++.h>
using namespace std;


void dfs(vector<vector<int>> &grid,int r,int c,vector<vector<bool>> &vis){
  if(r<0 || c<0 || r==grid.size() || c==grid[0].size() || grid[r][c]=='1' || vis[r][c]==true){
    return;
  }
  vis[r][c]=true;
  dfs(grid,r-1,c,vis);
  dfs(grid,r,c+1,vis);
  dfs(grid,r+1,c,vis);
  dfs(grid,r,c-1,vis);
}

int countIslands(vector<vector<int>> grid){
  int cnt=0;
  int m=grid.size(),n=grid[0].size();
  vector<vector<bool>> vis(m,vector<bool>(n,false));
  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
      if(!vis[i][j] && grid[i][j]=='0'){
        dfs(grid,i,j,vis);
        cnt++;
      }
    }
  }
  return cnt;
}

int main(){
  int m,n;
  cin >> m >> n;
  vector<vector<int>> grid(m,vector<int> (n));
  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
      char ch;
      cin >> ch;
      grid[i][j]=(int)(ch);
    }
  }

  cout << countIslands(grid);
  return 0;

}