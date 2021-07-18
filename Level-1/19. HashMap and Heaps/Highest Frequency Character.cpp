#include<bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin >> s;
	map<char,int> mp;
	for(char ch:s){
		mp[ch]++;
	}
	int mx=INT_MIN;
	char ch;
	for(auto m:mp){
		if(m.second>mx){
			mx=m.second;
			ch=m.first;
		}
	}
	cout << ch << endl;
}