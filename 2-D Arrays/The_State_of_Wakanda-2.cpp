#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> arr(n,vector<int> (n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }
    
    //state of wakanda2 
    int count=0;
    while(count<n){
        int str=count;
        int i=0;
        while(str<n){
            int strval=arr[i][str];
            cout << strval << endl;
            i++,str++;
        }
        count++;
    }
}