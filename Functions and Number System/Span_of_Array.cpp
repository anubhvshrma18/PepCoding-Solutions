#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int mn=INT_MAX;
    int mx=INT_MIN;
    for(int i=0;i<n;i++){
        mn=min(mn,a[i]);
        mx=max(mx,a[i]);
    }
    cout << mx-mn << endl;
}