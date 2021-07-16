#include <bits/stdc++.h>
using namespace std;

bool IsKnightSafe(vector<vector<bool>> &chess, int r,int c){
	if(r-1>=0 && c-2>=0 && chess[r-1][c-2]==true){
		return false;
	}
	else if(r-2>=0 && c-1>=0 && chess[r-2][c-1]==true){
		return false;
	}
	else if(r-2>=0 && c+1<chess.size() && chess[r-2][c+1]==true){
		return false;
	}
	else if(r-1>=0 && c+2 < chess.size() && chess[r-1][c+2]==true){
		return false;
	}

	return true;
}

void nknights(int kpsf, int tk, vector<vector<bool>> &chess, int lcno) {
        if (kpsf == tk) {
            for (int row = 0; row < chess.size(); row++) {
                for (int col = 0; col < chess.size(); col++) {
                   cout << (chess[row][col] ? "k\t" : "-\t");
                }
                cout << endl;
            }
	        cout << endl;
            return;
        }

        for (int i = lcno + 1; i < chess.size() * chess.size(); i++) {
            int row = i / chess.size();
            int col = i % chess.size();

            if (chess[row][col] == false && IsKnightSafe(chess, row, col)) {
                chess[row][col] = true;
                nknights(kpsf + 1, tk, chess, row * chess.size() + col);
                chess[row][col] = false;
            }
        }
    }


int main(){
	int n;
	cin >> n;
	vector<vector<bool>> chess(n,vector<bool>(n,false));
	nknights(0,n,chess,-1);  
	return 0;

}