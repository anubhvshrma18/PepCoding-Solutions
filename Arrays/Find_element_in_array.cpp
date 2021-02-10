#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,ele,position=-1;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    cin >> ele;
    for(int i=0;i<n;i++){
        if(a[i]==ele){
            position=i;
        }
    }
    cout << position << endl;
    
}