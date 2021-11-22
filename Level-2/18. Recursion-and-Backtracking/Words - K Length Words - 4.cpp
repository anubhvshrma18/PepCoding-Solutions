#include "bits/stdc++.h"
using namespace std;


void wordklength4(string ustr,map<char,int> &mp,int idx,int ts,string asf){
	if(idx==ts){
		cout << asf << endl;
		return;
	}

	for(int i=0;i<ustr.length();i++){
		char ch=ustr[i];
		if(mp[ch]>0){
			mp[ch]--;
			wordklength4(ustr,mp,idx+1,ts,asf+ch);
			mp[ch]++;
		}
	}

}

int main(){
	int n;
	string s;
	cin >> s >> n;
	string ustr="";
	map<char,int> mp;
	for(char ch:s){
		if(mp[ch]>0){
			mp[ch]++;
		}
		else{
			ustr+=ch;
			mp[ch]++;
		}
	}

	wordklength4(ustr,mp,0,n,"");

}