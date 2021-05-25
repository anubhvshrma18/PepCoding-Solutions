// Permutations-I
#include "bits/stdc++.h"
using namespace std;

void permutations(vector<int> &nba,int ci,int ti) {
	// base case when current item is greater than total items
	if(ci>ti){
		// print the array and return
		for(auto x:nba){
			cout << x << "";
		}
		cout << endl;
		return;
	}
	for(int i=0;i<nba.size();i++){
		// if the box is empty then you can place the item only
		if(nba[i]==0){
			// place the item in that box
			nba[i]=ci;

			// call for other vacant boxes
			permutations(nba,ci+1,ti);
			// unmark the item from that box so that you can place other items
			nba[i]=0;	
		}
	}
}


int main(){
	int nboxes , ritems;
	cin >> nboxes >> ritems;
	vector<int> nba(nboxes,0);

	permutations(nba ,1 , ritems);
	return 0;
}