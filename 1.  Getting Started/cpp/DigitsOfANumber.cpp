#include <iostream>
using namespace std;
typedef long long int ll;

int pow(int n,int b){
    int sum=1;
    for(int i=0;i<b;i++){
        sum*=n;
    }
    return sum;
}

int main(){
    ll n,x,count=0,sum=0;
    cin >> n;
    ll y=n;
    while (y != 0) {
        x = y % 10;
        sum = sum * 10 + x;
        y /= 10;
        count++;
    }
    while(count>0){
        cout << sum%10 << endl;
        sum=sum/10;
        count--;
    }
}