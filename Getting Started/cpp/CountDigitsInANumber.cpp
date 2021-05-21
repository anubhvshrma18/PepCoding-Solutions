#include <iostream>
using namespace std;

int main(int argc, char **argv){
    int n,count=0;
    cin >> n;
    while(n>0){
        count++;
        n=n/10;
    }
    cout << count << endl;
    //write your code here
    
}