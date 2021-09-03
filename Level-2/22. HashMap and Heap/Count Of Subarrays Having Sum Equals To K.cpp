#include<bits/stdc++.h>
 using namespace std;
 
 // Function to display an array.
 void display(vector<int> &arr) {
     for (int i = 0; i < arr.size(); i++) {
         cout<<arr[i]<<" ";
     }
     cout<<endl;
 }
 
//   This is a functional problem. You have to complete this function.
//   It takes as input an array and K.
//   It should return the length of maximum subarray whose sum is K. If no such subarray, return 0.
 int maxLenSubarray(vector<int> &v, int k) {
     // write your code here.
     
     unordered_map<int,int> map;

    int ps=0;int ans=0;
    map[0]=1;
    for(int i=0;i<v.size();i++){

        ps+=v[i];

        if(map.find(ps-k)!=map.end()){
            ans += map[ps-k];
        }
        
        if(map.find(ps)==map.end()){
            map[ps]=1;
        }
        else{
            map[ps]++;
        }
        
    }
    return ans;
     
 }
 
 int main(int argc, char** argv){
     int n;
     cin>>n;
     vector<int> arr;
     for (int j = 0; j < n; j++) {
         int val;
         cin>>val;
         arr.push_back(val);
     }
     int K;
     cin>>K;
     cout<<maxLenSubarray(arr, K);
 }