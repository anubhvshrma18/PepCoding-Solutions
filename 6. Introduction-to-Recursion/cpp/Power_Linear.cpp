#include<bits/stdc++.h>
using namespace std;
int power(int x,int n){
    if (x == 0) {
        return 1;
    }
    int xM1power = power(x - 1, n);
    int npower = n * xM1power;
    return npower;
}

int main(){
    int n,x;
    cin >> n;
    cin >> x;
    cout << power(x,n);

    return 0;
}