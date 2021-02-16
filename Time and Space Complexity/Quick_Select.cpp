#include<bits/stdc++.h>
using namespace std;

void quickselect(int *arr,int str,int end,int k){
    if(str<=end){
        int pidx=end;
        int pivot=arr[pidx];
        cout << "pivot -> " << pivot << endl;
        int i=str,j=str;
        while(j<=end){
            if(arr[j]>pivot){
                j++;
            }
            else{
                swap(arr[i],arr[j]);
                cout << "Swapping " << arr[i] <<" and " << arr[j] << endl;
                i++;
                j++;
            }
        }
        pidx=i-1;
        cout << "pivot index -> " << pidx << endl;
        if(pidx==k-1){
            cout << arr[pidx] << endl;
            return;
        }
        else{
            if(k-1<pidx){
                quickselect(arr,str,pidx-1,k);
            }
            else{
                quickselect(arr,pidx+1,end,k);    
            }
            
        }
    }
}

int main(){
    int n,k;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    cin >> k;
    quickselect(arr,0,n-1,k);
}