#include "bits/stdc++.h"
using namespace std;


void combination(vector<bool> &box,int idx,string ustr,int ssf,int ts,string asf){
	// if(idx == ){
		if(ssf == ts){
			cout << asf << endl;
			return;
			
		}

	for(int i=idx+1;i<box.size();i++){
		if(box[i]==false){
			box[i]=true;
			combination(box,i,ustr,ssf+1,ts,asf+ustr[i]);
			box[i]=false;
		}
	}
}


int main(){
	string s;
	int n;
	vector<char> v; // vector is used instead of unordered and set because in some cases the order in which string is given has to be maintained which is lost in both set and unordered set
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
	combination(box,-1,ustr,0,n,"");
	return 0;

}