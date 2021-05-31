#include "bits/stdc++.h"
using namespace std;


void wordklengthword2(vector<bool> &box,string ustr,int ssf,int ts,string asf){
	// if(idx == ){
		if(ssf == ts){
			cout << asf << endl;
			return;
			
		}

	for(int i=0;i<box.size();i++){
		if(box[i]==false){
			box[i]=true;
			wordklengthword2(box,ustr,ssf+1,ts,asf+ustr[i]);
			box[i]=false;
		}
	}
}


int main(){
	string s;
	int n;
	vector<char> v;
	cin >> s >> n;
	for(char ch:s){
		auto it=find(v.begin(),v.end(),ch);
		if(it==v.end()){
			v.push_back(ch);
		}
	}
	string ustr="";
	for(auto x:v){
		ustr+=x;
	}
	vector<bool> box(ustr.length(),false);
	wordklengthword2(box,ustr,0,n,"");
	return 0;

}