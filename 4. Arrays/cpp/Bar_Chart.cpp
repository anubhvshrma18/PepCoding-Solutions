#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,max=INT_MIN;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]>max){
            max=arr[i];
        }
    }
    for(int r=0;r<max;r++){
        for(int c=0;c<n;c++){
            if(r>=max-arr[c]){
                cout <<"*	";
            }
            else{
                cout<<"	";
            }
        }
        cout<<"\n";
    }
}