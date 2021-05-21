#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin >> n;
	int arr1[n];
	vector<int> gl;
	map<int,int> mp;
	for(int i=0;i<n;i++){
		cin >> arr1[i];
		mp[arr1[i]]++;
	}
	int cnt=0,temp=(*mp.begin()).first;
	vector<int> v;
	for(auto x:mp){
		if(x.first==temp){
			cnt++;
			temp++;
			v.push_back(x.first);
			
		}
		else{
			
			cnt=1;
			temp=x.first+1;
			v.clear();
			v.push_back(x.first);
		}
		if(cnt>gl.size()){
			gl=v;
		}
	}
	
	for(auto y:gl){
		cout << y << endl;
	}
}
