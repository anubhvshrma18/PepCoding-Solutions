#include<bits/stdc++.h>
using namespace std;

void printtargetSumSubsets(int arr[],int n,int sum,int tar,string asf,int idx){
    if(sum>tar){
        return;
    }
    if(idx==n){
        if(sum==tar){
            cout << asf << "." << endl;
        }
        return;
    } 
    string x=to_string(arr[idx]);
    printtargetSumSubsets(arr,n,sum+arr[idx],tar,asf+x+", ",idx+1);
    printtargetSumSubsets(arr,n,sum,tar,asf,idx+1);
}
int main(){
    int n,tar;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    cin >> tar;
    printtargetSumSubsets(arr,n,0,tar,"",0);
}