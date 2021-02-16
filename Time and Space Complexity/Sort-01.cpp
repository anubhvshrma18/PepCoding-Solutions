#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    
    int i=0,j=0;
    for(int k=0;k<n;k++){
        if(arr[j]==1){
            j++;
        }
        else{
            swap(arr[i],arr[j]);
            cout << "Swapping index " << j <<" and index " << i << endl;
            i++,j++;
        }
    }
    for(int k=0;k<n;k++){
        cout << arr[k] << endl;
    }
}