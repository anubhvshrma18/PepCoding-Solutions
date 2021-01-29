#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    for (int fact = 1; fact * fact <= n; fact++) {
        cout << fact * fact << endl;;
    }
    return 0;

}