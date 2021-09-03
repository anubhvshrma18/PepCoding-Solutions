#include "bits/stdc++.h"
using namespace std;

int solution(int nums[],int n,int k){
    int i=-1,j=-1,c0=0,ans=0;
    // unordered_map<char,int> mp;
    
    while(i < n-1){
        //acquire
        while(i <  n-1){
            i++;
            if(nums[i]==0){
                c0++;
            }
            
            if(c0 <= k){
                ans=max(ans,i-j);
            }
            else{
                break;
            }
        }
        
        // release
        while(j<i && c0 > k){
            j++;
            if(nums[j]==0){
                c0--;
            }
        }
    }
    
    return ans;
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int k;cin>>k;
    cout << solution(arr,n,k) << endl;
}