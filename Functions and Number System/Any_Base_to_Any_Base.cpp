#include<bits/stdc++.h>
using namespace std;

//to convert from given number in base b to decimal base
int getDec(int n,int b){
    int sum = 0, i = 0;
    while(n > 0){
        sum += pow(b,i) * (n%10);
        n = n/10;
        i++;
    }
    return sum;
}
// to convert given number to number in base b
int getBase(int n,int b){
    int sum = 0,i = 0;
    while(n > 0){
        sum += (n%b) * pow(10,i);
        n = n/b;
        i++;
    }
    return sum;
}

int main(){
    int n,b1,b2;
    cin >> n >> b1 >> b2;
    int val=getDec(n,b1);//covert to decimal val
    cout << getBase(val,b2) << endl;// convert decimal to base b
}