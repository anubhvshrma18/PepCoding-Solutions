#include "bits/stdc++.h"
using namespace std;


void combination(int idx,string ustr,int ssf,int ts,string asf){
	if(idx == ustr.length()){
		if(ssf == ts){
			cout << asf << endl;
		}
		return;
	}

	combination(idx+1,ustr,ssf+1,ts,asf+ustr[idx]);
	combination(idx+1,ustr,ssf,ts,asf);
}


int main(){
	string s;
	int n;
	set<char> un;
	cin >> s >> n;
	for(char ch:s){
		un.insert(ch);
	}
	string ustr="";
	for(auto x:un){
		ustr+=x;
	}
	// cout << ustr << endl;
	combination(0,ustr,0,n,"");
	return 0;

}