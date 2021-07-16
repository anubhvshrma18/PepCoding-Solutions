#include<bits/stdc++.h>
using namespace std;

int oneTrans(int arr[],int n){
	int lpsf=arr[0],mpsf=0;// lpsf->least price so far  mpsf->max profit so far
	return mpsf;
}

int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}

	cout << oneTrans(arr,n);
}