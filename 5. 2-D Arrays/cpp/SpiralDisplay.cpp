#include<bits/stdc++.h>
using namespace std;



void spiralDisplay(vector<vector<int>> arr,int n,int m){
    int rmin=0,rmax=n-1,cmin=0,cmax=m-1,count=0;
    while(count < (n*m)){
        for(int i=rmin;i<=rmax && count < (n*m);i++){
            cout << arr[i][cmin] << endl;
            count++;
        }
        cmin++;
        for(int i=cmin;i<=cmax && count < (n*m);i++){
            cout << arr[rmax][i]<< endl;
            count++;
        }
        rmax--;
        for(int i=rmax;i>=rmin && count < (n*m);i--){
            cout << arr[i][cmax]<< endl;
            count++;
        }
        cmax--;
        for(int i=cmax;i>=cmin && count < (n*m);i--){
            cout << arr[rmin][i]<< endl;
            count++;
        }
        rmin++;
    }
}



int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> arr(n,vector<int> (m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
        }
    }
    spiralDisplay(arr,n,m);
}