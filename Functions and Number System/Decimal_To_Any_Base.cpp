#include<bits/stdc++.h>
using namespace std;

// convertion from decimal to base b
void getBase(int n,int b){
    string s="";
    while(n>0){
        s=to_string(n%b)+s;
        n=n/b;
    }
    cout << s << endl;
}

int main(){
    int n,b;
    cin >> n >> b;
    getBase(n,b);
}