#include "bits/stdc++.h"
using namespace std;

void wordkselection(int cs,string ustr,map<char,int> &mp,int ts,string asf){
	if(ustr.length()==cs){
		if(asf.length()==ts){
			cout << asf << endl;	
		}
		
		return;
	}

	char ch=ustr[cs];
	int freq=mp[ch];
	
	for(int i=freq;i>=0;i--){
		string ans="";
		for(int j=0;j<i;j++)
			ans+=ch;
		wordkselection(cs+1,ustr,mp,ts,asf+ans);
	}
	
}


int main(){
	int n;
	string s;
	cin >> s >> n;
	map<char,int> mp;
	string ustr="";
	for(char ch:s){
		if(mp[ch]==0){
			ustr+=ch;
		}
		mp[ch]++;
	}

	wordkselection(0,ustr,mp,n,"");


}