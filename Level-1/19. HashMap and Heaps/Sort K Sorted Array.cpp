#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	int k;
	cin >> k;
	priority_queue<int,vector<int>,greater<int>> p;
	for(int i=0;i<=k;i++){
		p.push(arr[i]);
	}
	for(int i=k+1;i<n;i++){
		cout << p.top() << endl;
		p.pop();
		p.push(arr[i]);
	}
	while(p.size()>0){
		cout << p.top()<< endl;
		p.pop();
	}

}