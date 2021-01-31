#include <iostream>
using namespace std;

int main(int argc, char **argv){
    int n;
    cin >> n;
    while(n>0){
        cout << n%10 << endl;
        n=n/10;
    }
    //write your code here
    return 0;
    
}