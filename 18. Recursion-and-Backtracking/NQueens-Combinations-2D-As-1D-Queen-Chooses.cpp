#include "bits/stdc++.h"
using namespace std;
// qpsf->queen placed so far
// tq->total queen
// asf->ans so far

bool IsQueenSafe(vector<vector<bool>> &chess,int row,int col){
	// vertical
	for(int i=row-1;i>=0;i--){
		if(chess[i][col]==true){
			return false;
		}
	}

	//horizontal

	for(int i=col-1;i>=0;i--){
		if(chess[row][i]==true){
			return false;
		}
	}

	// top left diagonal

	for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
		if(chess[i][j]==true){
			return false;
		}
	}

	// top right diagonal

	for(int i=row-1,j=col+1;i>=0 && j<chess.size();i--,j++){
		if(chess[i][j]==true){
			return false;
		}
	}

	return true;
}

void nqueens(int qpsf, int tq, vector<vector<bool>> &chess, int lcno) {
    if (qpsf == tq) {
        for (int row = 0; row < chess.size(); row++) {
            for (int col = 0; col < chess.size(); col++) {
              // cout << (chess[row][col]? "q	" : "-	");
            	if(chess[row][col]){
            		cout << "q	";
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

    for (int i = lcno + 1; i < chess.size() * chess.size(); i++) {
        int row = i / chess.size();
        int col = i % chess.size();

        if (chess[row][col] == false && IsQueenSafe(chess, row, col)) {
            chess[row][col] = true;
            nqueens(qpsf + 1, tq, chess, row * chess.size() + col);
            chess[row][col] = false;
        }
    }
}




int main(){
	int n;
	cin >> n;
	vector<vector<bool>> queens(n,vector<bool>(n,false));
	nqueens(0,n,queens,-1);
	return 0;

}