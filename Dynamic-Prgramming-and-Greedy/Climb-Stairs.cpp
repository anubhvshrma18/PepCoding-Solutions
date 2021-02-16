#include <bits/stdc++.h>
using namespace std;

int cs(int n,vector<int> &v){
    // write your code here
    if(n==0){
        return 1;
    }
    if(n<0){
        return 0;
    }
    if(v[n]!=-1){
        return v[n];
    }
    int csp=cs(n-1,v)+cs(n-2,v)+cs(n-3,v);
    v[n]=csp;

    return csp;

}

int main(){
    int n;
    cin>>n;
    vector<int> v(n+1,-1);
    cout<<cs(n,v)<<endl;
}