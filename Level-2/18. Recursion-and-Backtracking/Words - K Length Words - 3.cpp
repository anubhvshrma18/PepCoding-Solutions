#include "bits/stdc++.h"
using namespace std;

void wordklength3(int idx,int ssf,string s,map<char,int> &mp,int ts,vector<char> &get){
	if(idx == s.length()){
		if(ssf == ts){
			for(auto x:get){
				cout << x;
			}
			cout << endl;
		}
		return;
	}


	char ch=s[idx];
	int locs=mp[ch];

	for(int i=locs+1;i<get.size();i++){
		if(get[i]=='\0'){
		    get[i]=ch;
			mp[ch]=i;
			wordklength3(idx+1,ssf+1,s,mp,ts,get);
			mp[ch]=locs;
			get[i]='\0';
		}
	}
	if(locs==-1){
		wordklength3(idx+1,ssf,s,mp,ts,get);
	}
}


int main(){
	int n;
	string s;
	cin >> s >> n;
	map<char,int> mp;
	for(char ch:s){
		mp[ch]=-1;
	}
	vector<char> get(n,'\0');
	wordklength3(0,0,s,mp,n,get);
	
	
}