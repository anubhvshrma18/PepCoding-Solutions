#include <bits/stdc++.h>
using namespace std;

int fib(int n,vector<int> &v){
    // write your code here
    if(n==0 || n==1){
        return n;
    }
    if(v[n]!=-1){
        return v[n]; 
    }
    int fibn=fib(n-1,v)+fib(n-2,v);
    v[n]=fibn;
    return fibn;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n+1,-1);
    int ans=fib(n,arr);
    cout << ans << endl;
    return 0;
}