#include "bits/stdc++.h"
using namespace std;

void generateWords(int cs,int ts,map<char,int> &mp,string asf){
	if(cs>ts){
		cout << asf << endl;
	}

	for(auto x:mp){
		if(x.second>0){
			mp[x.first]--;
			generateWords(cs+1,ts,mp,asf+x.first);
			mp[x.first]++;
		}
	}

}

int main(){
	string s;
	cin >> s;
	map<char,int> mp;
	for(int i=0;i<s.length();i++){
		mp[s[i]]++;
	}
	generateWords(1,s.length(),mp,"");
	return 0;

}