#include <iostream>
using namespace std;

void display(int arr[], int idx, int n){
    if(idx==n){
        return;
    }
    cout << arr[idx] << endl;
    display(arr,idx+1,n);
    
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    display(arr, 0, n);
}