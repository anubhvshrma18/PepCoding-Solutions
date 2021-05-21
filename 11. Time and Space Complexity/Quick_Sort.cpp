#include<bits/stdc++.h>
using namespace std;

void quicksort(int *arr,int s,int e){
    int pvtidx=e;
    int pivot=arr[pvtidx];
    if(s<=e){
        cout << "pivot -> " << pivot << endl;
        int i=s,j=s;
        for(;j<=e;){
            if(arr[j]>pivot){
                j++;
            }
            else{
                swap(arr[i],arr[j]);
                cout << "Swapping " << arr[i] <<" and " << arr[j] << endl;
                i++,j++;
            }
        }
        pvtidx=i-1;
        cout << "pivot index -> " << pvtidx<< endl;
        quicksort(arr,s,pvtidx-1);
        quicksort(arr,pvtidx+1,e);
    }
}


int main(){
    int n,pivt;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    
    quicksort(arr,0,n-1);
    
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    
}