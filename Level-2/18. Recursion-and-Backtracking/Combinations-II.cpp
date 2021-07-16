#include "bits/stdc++.h"
using namespace std;

void combinationsII(int cb,int tb,vector<bool> &nba,int ts) {
	if(cb>tb){
		for(int i=0;i<nba.size();i++){
			if(nba[i]==true){
				cout << "i";
			}
			else{
				cout << "-";
			}
		}
		cout << "\n";
		return;
	}
	for(int i=ts+1;i<nba.size();i++){
		if(nba[i]==false){
			nba[i]=true;
			combinationsII(cb+1,tb,nba,i);	
			nba[i]=false;
		}
	}
	
}


int main(){
	int nboxes , ritems;
	cin >> nboxes >> ritems;
	vector<bool> nba(nboxes,false);
	combinationsII(1,ritems,nba,-1);
	return 0;
}