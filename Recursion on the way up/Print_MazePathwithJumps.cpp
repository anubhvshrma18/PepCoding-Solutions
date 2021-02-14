#include<iostream>
using namespace std;


void printMazePaths(int sr, int sc, int dr, int dc, string psf) {
    // write your code here
    if(sr==dr && sc==dc){
        cout << psf << endl;
    }
    if(sr>dr || sc>dc){
        return;
    }
    string a="h";
    for(int i=1;sc+i<=dc;i++){
        string x=to_string(i);
        printMazePaths(sr,sc+i,dr,dc,psf+a+x);   
    }
    string b="v";
    for(int j=1;sr+j<=dr;j++){
        string y=to_string(j);
        printMazePaths(sr+j,sc,dr,dc,psf+b+y);
    }
    string c="d";
    for(int k=1;sr+k<=dr && sc+k<=dc;k++){
        string z=to_string(k);
        printMazePaths(sr+k,sc+k,dr,dc,psf+c+z);
    }
}

int main() {
        int n ;
        int m ;cin>>n>>m;
        printMazePaths(0, 0, n - 1, m - 1, "");
    }