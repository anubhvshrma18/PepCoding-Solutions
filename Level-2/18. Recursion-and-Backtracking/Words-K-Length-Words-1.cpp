#include "bits/stdc++.h"
using namespace std;


// need to print all the permutations
void wordklengthword1(int idx,vector<bool> &box,string ustr,int ssf,int ts,vector<char> &ans){
	if(idx==ustr.length()){
		if(ssf==ts){
			for(auto x:ans){
				cout << x <<  " ";
			}
			cout << endl;
			
		}
		return;
	}		

	// include call
	for(int i=0;i<ts;i++){
		if(box[i]==false){
			box[i]=true;
			ans[i]=ustr[idx];
			wordklengthword1(idx+1,box,ustr,ssf+1,ts,ans);
			ans[i]='\0';
			box[i]=false;
		}
	}
	// not include call
	wordklengthword1(idx+1,box,ustr,ssf,ts,ans);
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
	vector<bool> box(n,false);
	vector<char> vec(n);
	wordklengthword1(0,box,ustr,0,n,vec);
	return 0;

}