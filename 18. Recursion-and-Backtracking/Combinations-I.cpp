#include "bits/stdc++.h"
using namespace std;

void combinations(int cb,int tb,int ssf,int ts,string asf) {
	if(cb>tb){
		if(ssf==ts){
			cout << asf << endl;
		}
		return;
	}
	combinations(cb+1,tb,ssf+1,ts,asf+"i");
	combinations(cb+1,tb,ssf,ts,asf+"-");

}


int main(){
	int nboxes , ritems;
	cin >> nboxes >> ritems;
	combinations(1,nboxes,0, ritems,"");
	return 0;
}