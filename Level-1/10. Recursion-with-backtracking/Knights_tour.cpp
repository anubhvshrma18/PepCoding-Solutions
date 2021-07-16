#include<bits/stdc++.h>
using namespace std;

//function to display the 2-d array
void display(vector<vector<int>> &kt,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << kt[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void knightsTour(vector<vector<int>> &kt,int n,int row,int col,int count){
    //base case
    if(row<0 || col<0 || row>=n || col >= n || kt[row][col] != 0){
        return;
    }
    //base case
    if(count==n*n){
        kt[row][col]=count;
        display(kt,n);
        kt[row][col]=0;
        return;
    }
    kt[row][col]=count;
    knightsTour(kt,n,row-2,col+1,count+1);
    knightsTour(kt,n,row-1,col+2,count+1);
    knightsTour(kt,n,row+1,col+2,count+1);
    knightsTour(kt,n,row+2,col+1,count+1);
    knightsTour(kt,n,row+2,col-1,count+1);
    knightsTour(kt,n,row+1,col-2,count+1);
    knightsTour(kt,n,row-1,col-2,count+1);
    knightsTour(kt,n,row-2,col-1,count+1);
    kt[row][col]=0;
}

int main(){
    int n,r,c;
    cin >> n >> r >> c;
    vector<vector<int>> kt(n,vector<int> (n,0));
    knightsTour(kt,n,r,c,1);
}
