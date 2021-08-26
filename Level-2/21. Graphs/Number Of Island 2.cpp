#include <bits/stdc++.h>
using namespace std;

vector<int> parent;
vector<int> r;


int find(int x) {
  if(parent[x]==x){
    return x;
  }
  int temp = find(parent[x]);
  parent[x]=temp;
  return temp;
}

vector<int> numIsland2(int m,int n,vector<vector<int>> &pos) {
  
  int cnt=0;
  r.resize(n*m);
  parent.resize(n*m);
  vector<int> vec;

  for(int i=0;i<n*m;i++){
    parent[i] = i;
    r[i] = 0;
  }

  vector<vector<int>> dir{{-1,0},{0,1},{1,0},{0,-1}};

  vector<vector<int>> grid(m,vector<int>(n,0));

  for(int i = 0; i < pos.size();i++){
    int u = pos[i][0];
    int v = pos[i][1];

    cnt++;

    grid[u][v]=1;

    for(vector<int> d:dir){

      int nx = u + d[0];
      int ny = v + d[1];

      if(nx < 0 || ny<0 || nx == m || ny==n || grid[nx][ny] == 0){
        continue;
      }

      int pbxn = u*n+v;
      int nbxn = nx*n+ny;

      int lp = find(pbxn);
      int ln = find(nbxn);

      if(lp!=ln){

        if(r[lp] < r[ln]){
          parent[lp] = ln;
          // cnt--;
        }
        else if(r[lp]>r[ln]) {
          parent[ln] = lp;
          // cnt--;
        }
        else{
          parent[lp]=ln;
          r[ln]++;
        }

        cnt--;

      }


    }

    vec.push_back(cnt);

  }



  return vec;
}

int main(){
  int m,n,q;
  cin >>m>>n>>q;
  vector<vector<int>> pos(q,vector<int>(2));
  for(int i=0;i<q;i++) {
    int a,b;cin >> a >> b;
    pos[i][0]=a;
    pos[i][1]=b;
  }
  vector<int> ans = numIsland2(m,n,pos);

  cout << "[";
  for(int i=0;i<ans.size();i++){
    if(i==ans.size()-1){
      cout << ans[i];
      break;
    }
    cout << ans[i] << ", ";
  }
  cout << "]" << endl;

}

