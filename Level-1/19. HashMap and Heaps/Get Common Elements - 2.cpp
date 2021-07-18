#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin >> n;
	int arr1[n];
	unordered_map<int,int> mp;
	//unordered_map<int,int> mp2;
	for(int i=0;i<n;i++){
		cin >> arr1[i];
		mp[arr1[i]]++;
	}
	cin >> m;
	int arr2[m];
	for(int i=0;i<m;i++){
		cin >> arr2[i];
		if(mp.find(arr2[i])!=mp.end() && mp[arr2[i]]!=0){
		    cout << arr2[i] << endl;
		    mp[arr2[i]]--;
		}
	}
	
}