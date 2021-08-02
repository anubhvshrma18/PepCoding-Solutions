#include <bits/stdc++.h>
using namespace std;

int cnt=1;
//rssf->remaining set so far
void solution(int id,vector<int> &arr,vector<int> &subsetsum,int k,int rssf,vector<vector<int>> &v){
  if(id==arr.size()){
    if(rssf==k){
      // validity check
      for(int i=0;i<k-1;i++){
        // not valid return
        if(subsetsum[i]!=subsetsum[i+1]){
          return;
        }
      }

      // if we dont return frrom above then all the subset are valid , we simply print all the subsets
      for(int i=0;i<v.size();i++){
          cout << "[";
          for(int j=0;j<v[i].size();j++){
            if(j==v[i].size()-1){
              cout << v[i][j];
              break;
            }
            cout << v[i][j] << ", ";
          }
          cout << "] ";
      }
      cout << endl;
    }
    return;
  }

  int val=arr[id];
  for(int i=0;i<k;i++){
    if(v[i].size()>0){
      v[i].push_back(val);
      subsetsum[i]+=val;
      solution(id+1,arr,subsetsum,k,rssf,v);
      v[i].pop_back();
      subsetsum[i]-=val;
    } else {
      v[i].push_back(val);
      subsetsum[i]+=val;
      solution(id+1,arr,subsetsum,k,rssf+1,v);
      v[i].pop_back();
      subsetsum[i]-=val;
      break;
    }
  }


}


int main(){
  int n,k;
  cin>>n;
  vector<int> arr(n);
  for(auto &x:arr){
    cin>>x;
  }
  cin>>k;
  vector<vector<int>> v(k,vector<int>());
  vector<int> subsetsum(k,0);
  solution(0,arr,subsetsum,k,0,v);
  return 0;
}