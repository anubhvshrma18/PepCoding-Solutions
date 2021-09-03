#include <bits/stdc++.h>
using namespace std;

vector<int> parent;
vector<int> r;

int find(int x){
    if(parent[x] == x){
        return x;
    }

    int temp = find(parent[x]);
    parent[x]=temp;
    return temp;
}
int dsu(vector<vector<int>> &pos,int e1){
  int n = pos.size();
  r.resize(n+1);
  parent.resize(n+1);

  for(int i=1;i<=n;i++){
      r[i]=0;
      parent[i]=i;
  }


  for(int i=0;i<pos.size();i++){
      if(i==e1){
          continue;
      }
      int u=pos[i][0];
      int v=pos[i][1];

      int lu = find(u);
      int lv = find(v);

      if(lu != lv){
          if(r[lu] < r[lv]){
              parent[lu] = lv;
          }
          else if(r[lu] > r [lv]){
              parent[lv]=lu;
          }
          else{
              parent[lu] = lv;
              r[lv]++;
          }
      }
      else{
          return i;
      }
  }
  return -1;
}


vector<int> redundantConnection2(vector<vector<int>> &edges) {
  int n=edges.size();
  vector<int> inD(n+1,-1);
  int e1=-1,e2=-1;
  for(int i=0;i<n;i++){
    int u=edges[i][0],v=edges[i][1];
      
      if(inD[v]==-1){
          
      }
      else{
          e1 = inD[v];
          e2=i;
      }
      inD[v]=i;
    
  }
    
    int ei = dsu(edges,e2);
    if(e1==-1 && e2==-1){
        return edges[ei];
    }
    else if(ei==-1){
        return edges[e2];
    }
    else {
        return edges[e1];
    }



}

int main(){
  int n;
  cin >> n;
  vector<vector<int>> pos(n,vector<int>(2));
  for(int i=0;i<n;i++){
      int a,b;
      cin >> a >> b;
      pos[i][0]=a;
      pos[i][1]=b;
  }
  
  vector<int> ans = redundantConnection2(pos);
  cout << ans[0] << " " << ans[1] << endl;
  return 0;

}