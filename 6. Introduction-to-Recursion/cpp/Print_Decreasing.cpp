#include<bits/stdc++.h>
using namespace std;

void printDecreasing(int n){
    if (n < 1) {
        return;
    }
    cout << n << endl;
    printDecreasing(n - 1);
}

int main(){
    int n;
    cin >> n;
    printDecreasing(n);
}