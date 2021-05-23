#include <iostream>
using namespace std;

void printStairPaths(int n, string psf){
    // write your code here
    if(n==0){
        cout << psf << endl;
        return;
    }
    if(n<0){
        return;
    }
    string x=to_string(1);
    printStairPaths(n-1,psf+x);
    string y=to_string(2);
    printStairPaths(n-2,psf+y);
    string z=to_string(3);
    printStairPaths(n-3,psf+z);
}

int main(){

    int n;
    cin >> n;
    printStairPaths(n, "");
}