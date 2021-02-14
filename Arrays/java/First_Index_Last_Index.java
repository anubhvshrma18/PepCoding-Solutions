#include<bits/stdc++.h>
using namespace std;

void firstAndLastIndex(int arr[],int d,int n){
    int flg=0;
    for(int i=0;i<n;i++){
        if(arr[i]==d){
            flg=1;
            cout << i << endl;
            break;
        }
    }
    for(int j=n-1;j>=0;j--){
        if(arr[j]==d){
            cout << j << endl;
            break;
        }
    }
    if(flg==0){
        cout << -1 << endl << -1 << endl;
    }
}

int main(){
    int n,d;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    cin >> d;
    firstAndLastIndex(arr,d,n);
    
    return 0;
}