#include "bits/stdc++.h"
using namespace std;

int infiTranswithCooldown(int arr[],int n){
	int obsp=-arr[0],ossp=0,ocsp=0;
	for(int i=1;i<n;i++){
		int nbsp=0,nssp=0,ncsp=0;
		//buy
		if(ocsp-arr[i]>obsp) {
			nbsp=ocsp-arr[i];
		}
		else{
			nbsp=obsp;
		}


		// sell
		if(obsp+arr[i]>ossp) {
			nssp=obsp+arr[i];
		}
		else{
			nssp=ossp;
		}


		// cooldown
		if(ossp>ocsp) {
			ncsp=ossp;
		}
		else{
			ncsp=ocsp;
		}

		obsp=nbsp;
		ossp=nssp;
		ocsp=ncsp;

	}

	return ossp;
}


int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	cout << infiTranswithCooldown(arr,n);
}