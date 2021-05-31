#include "bits/stdc++.h"
using namespace std;

vector<bool> colB;
vector<bool> regDB;
vector<bool> revDB;

void nqueensbnb(int r,vector<vector<bool>> chess,string asf){
	if(r==chess.size()){
		cout << asf << "." << endl;
		return;
	}

	for(int c=0;c<chess.size();c++){
		int col=c;
		int rd=r+c;
		int revd=r-c+chess.size()-1;
		if(!chess[r][c] && !colB[c] && !regDB[rd] && !revDB[revd]){
			chess[r][c]=true;
			colB[c]=true;
			regDB[rd]=true;
			revDB[revd]=true;
			nqueensbnb(r+1,chess,asf+to_string(r)+"-"+to_string(c)+", ");
			chess[r][c]=false;
			colB[c]=false;
			regDB[rd]=false;
			revDB[revd]=false;

		}
	}
}

int main(){
	int n;
	cin >> n;
	vector<vector<bool>> chess(n,vector<bool>(n,0));
	colB.clear();regDB.clear();revDB.clear();
	colB.resize(n,false);
	regDB.resize((2*n)-1,false);
	revDB.resize((2*n)-1,false);
	nqueensbnb(0,chess,"");
	return 0;

}