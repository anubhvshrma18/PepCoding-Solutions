#include <bits/stdc++.h>
using namespace std;

int helper(unordered_map<int,vector<int>> &mp,vector<vector<int>> &arr,int src,int des){
  unordered_set<int> bS;
  unordered_set<int> bN;
  queue<int> q;


  q.push(src);
  
  int lev=0;
  while(!q.empty()){
    int size = q.size();
    while(size--){
      int bus_stop = q.front();
      q.pop();


      if(bus_stop == des){
        return lev;
      }

      if(bS.count(bus_stop)==1){
        continue;
      }

      bS.insert(bus_stop);
      for(int bus : mp[bus_stop]){
        if(bN.count(bus)==0){
          bN.insert(bus);
          for(int bs:arr[bus]){
            if(bS.count(bs)==0){
              q.push(bs);
            }
          }
        }
      }
    }
    lev++;

  }


  return -1;

}

int numBusestoDestination(vector<vector<int>> &arr,int src,int des){
  
  unordered_map<int,vector<int>> mp;
  for(int i=0;i<arr.size();i++){
    for(int j=0;j<arr[i].size();j++){
      int bus_stop = arr[i][j];
      mp[bus_stop].push_back(i);
    }
  }

  return helper(mp,arr,src,des);

}


int main(){
  int n,m;
  cin >> n >> m;
  vector<vector<int>> arr(n,vector<int>(m));
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      char ch;cin>>ch;
      arr[i][j]=(int)(ch);
    }
  }

  char ch1,ch2;
  cin >> ch1 >> ch2;
  int src,des;
  src=ch1,des=ch2;
  cout << numBusestoDestination(arr,src,des) << endl;
  return 0;

}