#include<bits/stdc++.h>
using namespace std;

//function to check if the position of the queen is safe i.e no queen in on its diagonal , column, and row
bool isQueenSafe(int row,int col,vector<vector<int>> nq){
    for(int i=0;i<row;i++){
        if(nq[i][col]==1){
            return false;
        }
    }
    for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
        if(nq[i][j]==1){
            return false;
        }
    }
    for(int r=row-1,c=col+1;r>=0 && c< nq.size();r--,c++){
        if(nq[r][c]==1){
            return false;
        }
    }
    return true;
}


void printNQueens(int i,int n,string asf,vector<vector<int>> nq){
    //base case
    if(i==n){
        cout << asf << ". "<<endl;
        return;
    }
    //loop for position of queen in row
    for(int col=0;col<n;col++){
        if(isQueenSafe(i,col,nq)){
            nq[i][col]=1;
            printNQueens(i+1,n,asf+to_string(i)+"-"+to_string(col)+", ",nq);
            nq[i][col]=0;
        }
    }
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> nq(n , vector<int> (n));
    
    printNQueens(0,n,"",nq);
    
}