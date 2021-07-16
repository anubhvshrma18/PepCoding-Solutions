#include "bits/stdc++.h"
using namespace std;

void queenpermutationnqueen(vector<vector<int>> &chess,int qpsf,int tq){
	if(qpsf>tq){
		for(int i=0;i<tq;i++){
			for(int j=0;j<tq;j++){
				if(chess[i][j]!=0){
					cout << "q" << chess[i][j] << "	";
				}
				else{
					cout << "-	";
				}
			}
			cout << endl;
		}
		cout << endl;
		return;
	}

	for(int i=0;i<tq;i++){
		for(int j=0;j<tq;j++){
			if(chess[i][j]==0){
				chess[i][j]=qpsf;
				queenpermutationqueen(chess,qpsf+1,tq);
				chess[i][j]=0;
			}
		}
	}
}

int main(){
	int n;
	cin >> n;
	vector<vector<int>> chess(n,vector<int>(n,0));
	queenpermutationqueen(chess,1,n);
	return 0;

}