#include "bits/stdc++.h"
using namespace std;

bool IsQueenSafe(vector<vector<int>> &chess,int r,int c){
	// vertical 
	for(int i=0;i<chess.size();i++){
		if(chess[i][c]!=0 && i!=r){
			return false;
		}
	}

	// horizontal
	for(int i=0;i<chess.size();i++){
		if(chess[r][i]!=0 && i!=c){
			return false;
		}
	}
	// top left diagonal
	for(int i=r-1,j=c-1;i>=0 && j>=0;i--,j--){
		if(chess[i][j]!=0){
			return false;
		}
	}
	// top right diagonal
	for(int i=r-1,j=c+1;i>=0 && j<chess.size();i--,j++){
		if(chess[i][j]!=0){
			return false;
		}
	}

	// bottom left diagonal
	for(int i=r+1,j=c-1;i<chess.size() && j>=0;i++,j--){
		if(chess[i][j]!=0){
			return false;
		}
	}

	// bottom right diagonal
	for(int i=r+1,j=c+1;i<chess.size() && j<chess.size();i++,j++){
		if(chess[i][j]!=0){
			return false;
		}
	}
	return true;
}

void nqueens(int qpsf, int tq, vector<vector<int>> &chess) {
    if(qpsf>tq){
    	for (int i=0;i<chess.size();i++){
    		for(int j=0;j<chess.size();j++){
    			if(chess[i][j]!=0){
    				cout << "q" << chess[i][j] << "\t";
    			}
    			else{
    				cout << "-\t";
    			}
    		}
    		cout << endl;
    	}
    	cout << endl;
    	return;
    }


    for(int b = 0;b < chess.size()*chess.size();b++){
    	int i=b/chess.size();
    	int j=b%chess.size();
    	if(chess[i][j]==0 && IsQueenSafe(chess,i,j)){
    		chess[i][j]=qpsf+1;
    		nqueens(qpsf+1,tq,chess);
    		chess[i][j]=0;
    	}
    }
}


int main(){
	int n;
	cin >> n;
	vector<vector<int>> chess(n,vector<int>(n,0));
	nqueens(0,n,chess);
	return 0;

}