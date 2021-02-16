#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,pivt;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    cin >> pivt;
    
    //partion
    int idx=0;
    for(int i=0;i<n;i++){
        if(pivt>=arr[i]){
            swap(arr[idx],arr[i]);
            cout << "Swapping " << arr[idx] << " and " << arr[i] << endl;
            idx++;
        }
    }
    
    //display array
    for(int i=0;i<n;i++){
        cout << arr[i] <<" ";
    }
    cout << endl;
}