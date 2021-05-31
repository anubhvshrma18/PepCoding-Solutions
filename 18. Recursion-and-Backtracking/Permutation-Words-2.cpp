#include "bits/stdc++.h"
using namespace std;

void generateWords(int cc,string s,vector<char> &spots,map<char,int> &mp){
	if(cc==s.length()){
		for(auto ch:spots){
			cout << ch;
		}
		cout << endl;
		return;

	}
	
	char ch=s[cc];
	int loch=mp[ch];// last occurence of characte
	for(int i=loch+1;i<s.length();i++){
		if(spots[i]=='.'){


		}
	}