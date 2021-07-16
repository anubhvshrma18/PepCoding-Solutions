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
			spots[i]=ch;
			mp[ch]=i;
			generateWords(cc+1,s,spots,mp);
			spots[i]='.';
			mp[ch]=loch;
		}
	}
}
int main(){
	string s;
	cin >> s;
	map<char,int> mp;
	for(auto ch:s){
		mp[ch]=-1;
	}
	vector<char> a(s.length());
	generateWords(0,s,a,mp);
	return 0;

}