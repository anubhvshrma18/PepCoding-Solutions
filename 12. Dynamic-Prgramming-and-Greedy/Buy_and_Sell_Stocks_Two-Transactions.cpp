#include "bits/stdc++.h"
using namespace std;

int bssTwoTrans(int arr[],int n){
  //forward travel
  int ans1[n];
  ans1[0] = 0;
  int lpsf = arr[0];
  int mxpsf = 0;
  for(int i = 1;i < n; i++){
    if(arr[i] < lpsf){
      lpsf = arr[i];
    }

    if(arr[i] - lpsf > ans1[i-1]){
      ans1[i] = arr[i] - lpsf;
    }
    else{
      ans1[i] = ans1[i-1];
    }
  }

  // backward travel
  int ans2[n];
  ans2[n-1] = 0;
  int msf = arr[n-1] , mpsf = 0;
  for(int i = n-2; i >= 0; i--) {
    if(msf < arr[i]) {
      msf = arr[i];
    }

    if(msf - arr[i] > ans2[i+1]){
      ans2[i] = msf-arr[i];
    }
    else{
      ans2[i] = ans2[i+1];
    }
  }

  // calculating max profit
  int val = INT_MIN;
  for(int i = 0; i < n; i++){
    if(ans1[i] + ans2[i] > val)
      val = ans1[i] + ans2[i];
  }
  return val;
}
int main()
{
  iint n;
  cin >> n;
  int arr[n];
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  cout << bssTwoTrans(arr,n);
  return 0;
}