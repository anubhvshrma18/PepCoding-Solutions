#include<bits/stdc++.h>
using namespace std;

void pdi(int n){
    if (n < 1) {
        return;
    }
    cout << n << endl;
    pdi(n - 1);
    cout << n << endl;

}

int main(){
    int n;
    cin >> n;
    pdi(n);
}