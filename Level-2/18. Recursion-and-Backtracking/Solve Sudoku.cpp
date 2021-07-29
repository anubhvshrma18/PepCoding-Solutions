#include "bits/stdc++.h"
using namespace std;

void display(vector<vector<int>> &board){
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cout << board[i][j]<<" ";
		}
		cout << endl;
	}
}

bool isItSafe(vector<vector<int>> &v,int r,int c,int val){
	// row
	for(int i=0;i<9;i++){
		if(v[i][c]==val){
			return false;
		}
	}

	// column
	for(int j=0;j<9;j++){
		if(v[r][j]==val){
			return false;
		}
	}

	// submatrix
	int sbrn=r/3,sbcn=c/3;
	int x=sbrn*3,y=sbcn*3;
	for(int i=x;i<x+3;i++){
		for(int j=y;j<y+3;j++){
			if(v[i][j]==val){
				return false;
			}
		}
	}

	return true;

}


void solveSudoku(vector<vector<int>> &v,int r,int c){
	if(c==9){
		r++;
		c=0;
	}

	if(r==9){
		display(v);
		return;
	}

	if(v[r][c]==0){
		for(int i=1;i<=9;i++){
			if(isItSafe(v,r,c,i)){
				v[r][c]=i;
				solveSudoku(v,r,c+1);
				v[r][c]=0;
			}
		}
	}
	else{
		solveSudoku(v,r,c+1);
	}

}

int main(){
	int n=9;
	vector<vector<int>> v(n,vector<int>(n));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>v[i][j];
		}
	}

	solveSudoku(v,0,0);
	
}