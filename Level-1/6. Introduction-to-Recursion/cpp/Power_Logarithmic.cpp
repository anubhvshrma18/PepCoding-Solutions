#include<bits/stdc++.h>
using namespace std;

int power(int x,int n){
    if (n == 0) {
        return 1;
    }
    int ans=power(x, n / 2);
    ans=ans*ans;
    if(n%2==1){
        ans=ans*x;
    }
    return ans;
}

int main(){
    int x,n;
    cin >> x >> n;
    cout << power(x,n) << "\n";
}