#include "bits/stdc++.h"
using namespace std;

void coinchangeCombination(int idx,int *arr,int n,int sum,int ssf,string asf){
 if(ssf == sum){
 	cout << asf << "." << endl;
 	return;
 }

 for(int i=idx+1;i<n;i++){
 	coinchangeCombination(i,arr,n,sum,ssf+arr[i],asf+to_string(arr[i])+"-");
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
	coinchangeCombination(-1,arr,n,sum,0,"");
}