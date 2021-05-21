#include<bits/stdc++.h>
using namespace std;

// convertion from any base b to decimal(base 10)
void getDec(int n,int b){
    int sum=0,i=0;
    while(n>0){
        sum+=pow(b,i)*(n%10);
        n=n/10;
        i++;
    }
    cout << sum << endl;
}

int main(){
    int n,b;
    cin >> n >> b;
    getDec(n,b);
}