#include "bits/stdc++.h"
using namespace std;

void permutationsII(int cb,int tb,vector<bool> &nba,int ssf,int ts,string asf) {
	if(cb>tb){
		if(ssf==ts){
			cout << asf << endl;
		}
		return;
	}
	for(int i=0;i<nba.size();i++){
		if(nba[i]==false){
			nba[i]=true;
			permutationsII(cb+1,tb,nba,ssf+1,ts,asf+to_string(i+1));
			nba[i]=false;
		}
	}
	permutationsII(cb+1,tb,nba,ssf,ts,asf+to_string(0));

}


int main(){
	int nboxes , ritems;
	cin >> nboxes >> ritems;
	vector<bool> nba(ritems,false);
	permutationsII(1,nboxes,nba,0, ritems,"");
	return 0;
}