#include <bits/stdc++.h>
using namespace std;

int maxDistance(vector<vector<int>> &arr){
  queue<pair<int,int>> q;

  for(int i=0;i<arr.size();i++){
    for(int j=0;j<arr[0].size();j++){
      if(arr[i][j]==1){
        arr[i][j]=0;
        q.push({i,j});
      }
      else{
        arr[i][j]=-1;
      }
    }
  }
  int maxDist=-1;
  vector<vector<int>> dir{{-1,0},{0,1},{1,0},{0,-1}};
  while(!q.empty()){
    pair<int,int> p=q.front();
    q.pop();

    for(int i=0;i<4;i++){
      int ni=p.first + dir[i][0];
      int nj=p.second + dir[i][1];
      if(ni>=0 && ni<arr.size() &&nj>=0 &&nj<arr[0].size() &&arr[ni][nj]==-1){
        arr[ni][nj]=arr[p.first][p.second]+1;
        maxDist=max(arr[ni][nj],maxDist);
        q.push({ni,nj});
      }

    }
  }

  return maxDist;
}


int main(){
  int n;
  cin >> n;
  vector<vector<int>> arr(n,vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> arr[i][j];
    }
  }

  cout << maxDistance(arr) << endl;
  return 0;

}