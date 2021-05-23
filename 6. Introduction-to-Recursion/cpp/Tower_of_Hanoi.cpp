#include "bits/stdc++.h"
using namespace std;

void toh(int n,int t1id, int t2id, int t3id){
	if (n == 0) {
		return;
	}
	toh(n - 1, t1id, t3id, t2id);
	// toh(1,t1id,t2id,t3id);
	cout << n << "[" << t1id << " -> " << t2id << "]" << endl;
	toh(n - 1, t3id, t2id, t1id);
}

int main(){
	int n,t1,t2,t3;
	cin >> n >> t1 >> t2 >> t3;
	toh(n,t1,t2,t3);
}
