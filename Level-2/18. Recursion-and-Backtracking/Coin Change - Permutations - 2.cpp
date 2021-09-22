#include "bits/stdc++.h"
using namespace std;

void coinchangePermutation(int idx,int *arr,int n,int sum,int ssf,string asf){
	if(ssf > sum) {
		return;
	}
	if(ssf == sum){
		cout << asf << "."<< endl;
		return;
	}

	for(int i=0;i<n;i++){
		// if(arr[i]!=0){
			int cn=arr[i];
		// 	arr[i]=0;
			coinchangePermutation(i,arr,n,sum,ssf+cn,asf+to_string(cn)+"-");
		// 	arr[i]=cn;
		// }
	}
}


int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	int sum;
	cin>> sum;
	coinchangePermutation(0,arr,n,sum,0,"");
}