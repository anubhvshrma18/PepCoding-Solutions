#include<bits/stdc++.h>
using namespace std;
 
 int findLongestChain(vector<vector<int>> &v){
     //write your code here
     int n = v.size();
        
        // if(n==1) return 1;
        sort(v.begin(),v.end(),[&](const auto&a ,const auto &b){
           return a[1] < b[1]; 
        });




        // sort(v.begin(), v.end(), cmp);
        int cnt = 0;
        for (int i = 0, j = 0; j < v.size(); j++) {
            if (j == 0 || v[i][1] < v[j][0]) {
                cnt++;
                i = j;
            }
        }
        return cnt;
 }
 
 int main(int argc, char** argv){
     int n;
     cin>>n;
 
     vector<vector<int> > pairs(n, vector<int> (2));
     for (int i = 0; i < pairs.size(); i++) {
         cin>>pairs[i][0];
         cin>>pairs[i][1];
     }
     cout<<findLongestChain(pairs)<<endl;
 }