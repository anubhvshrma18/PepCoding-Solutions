#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
  queue<pair<int,int>> q;
  for(int i=0;i<mat.size();i++){
      for(int j=0;j<mat[0].size();j++){
          if(mat[i][j]==0){
              q.push({i,j});
          }
          else{
              mat[i][j]=-1;
          }
      }
  }
  
  
  vector<vector<int>> dir{{-1,0},{0,1},{1,0},{0,-1}};
  
  while(!q.empty()){
      pair<int,int> p=q.front();
      q.pop();
      
      for(int i=0;i<4;i++){
          int ni=p.first+dir[i][0];
          int nj=p.second+dir[i][1];
          if(ni>=0 && ni<mat.size() && nj>=0 && nj<mat[0].size() && mat[ni][nj]==-1){
              mat[ni][nj]=mat[p.first][p.second]+1;
              q.push({ni,nj});
          }
      }
  }
  
  return mat;
}



int main(){
  int n,m;
  cin >> n >> m;
  vector<vector<int>> grid(n,vector<int>(m));
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin >> grid[i][j];
    }
  }
  
  vector<vector<int>> ans=updateMatrix(grid);

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }


  return 0;

}