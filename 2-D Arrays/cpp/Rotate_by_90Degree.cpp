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
    
    //rotation by 90 degree
    
    //swapping of elements
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            swap(arr[i][j],arr[j][i]);
        }
    }
    //reversing the rows;
    for(int i=0;i<n;i++){
        int str=0,end=n-1;
        while(str<end){
            swap(arr[i][str],arr[i][end]);
            str++;
            end--;
        }
    }
    
    // printing the array
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    
    
}