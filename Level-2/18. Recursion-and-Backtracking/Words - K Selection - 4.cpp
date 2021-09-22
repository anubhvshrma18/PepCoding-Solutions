#include "bits/stdc++.h"
using namespace std;

void wordkselection4(int cs,int idx,string ustr,map<char,int> &mp,int ts,string asf){
	if(cs==ts){
		// if(asf.length()==ts){
			cout << asf << endl;
		// }
		return;
	}
	
	for(int i=idx;i<ustr.length();i++){
		int freq=mp[ustr[i]];
		if(freq>0){
			mp[ustr[i]]--;
			wordkselection4(cs+1,i,ustr,mp,ts,asf+ustr[i]);
			mp[ustr[i]]++;
		}
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

	wordkselection4(0,0,ustr,mp,n,"");


}