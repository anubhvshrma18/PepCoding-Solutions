#include <iostream>
using namespace std;

void printMazePaths(int sr, int sc, int dr, int dc, string psf){
    // write your code here
    if(sr==dr && sc==dc){
        cout << psf << endl;
        return;
    }
    if(sr>dr || sc>dc){
        return;
    }
    string a="h";
    printMazePaths(sr,sc+1,dr,dc,psf+a);
    string b="v";
    printMazePaths(sr+1,sc,dr,dc,psf+b);
}

int main(){
    int n;
    int m;
    cin >> n >> m;
    printMazePaths(0, 0, n - 1, m - 1, "");
}