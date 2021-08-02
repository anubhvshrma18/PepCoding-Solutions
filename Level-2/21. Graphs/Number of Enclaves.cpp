#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &grid,int r,int c){
  if(r<0 || c<0 || r==grid.size() || c==grid[0].size() || grid[r][c]==0){
    return;
  }
  grid[r][c]=0;
  dfs(grid,r-1,c);
  dfs(grid,r,c+1);
  dfs(grid,r+1,c);
  dfs(grid,r,c-1);
}

int countEnclaves(vector<vector<int>> grid){
  int m=grid.size(),n=grid[0].size();
  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
      if(i==0 || j==0 || i==m-1 || j==n-1){
        if(grid[i][j]==1){
          dfs(grid,i,j);
        }
      }
    }
  }

  int cnt=0;
  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
      if(grid[i][j]==1){
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
      cin >> grid[i][j];
    }
  }

  cout << countEnclaves(grid);
  return 0;

}