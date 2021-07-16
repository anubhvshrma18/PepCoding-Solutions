#include<bits/stdc++.h>
using namespace std;

void sumOfTwoArrays(int arr1[],int arr2[],int n, int m){
    int len=max(n,m)+1;
    int arr[len];
    int i=n-1;
    int j=m-1;
    int k=len-1;
    int carry=0;
    while(i>=0 || j>=0 || k>=0){
        int sum=0;
        if(i>=0){
            sum+=arr1[i];
        }
        if(j>=0){
            sum+=arr2[j];
        }
        sum+=carry;
        int rem=sum%10;
        carry=sum/10;
        arr[k]=rem;
        i--;
        j--;
        k--;
    }
    if(arr[0]!=0){
        cout <<arr[0] <<endl;
    }
    for(int i=1;i<sizeof(arr)/sizeof(arr[1]);i++){
        cout << arr[i] << endl;
    }
}


int main(){
    int n1,n2,x=0,y=0;
    cin >> n1;
    int arr1[n1];
    for(int i=0;i<n1;i++){
        cin >> arr1[i];
    }
    cin >> n2;
    int arr2[n2];
    for(int i=0;i<n2;i++){
        cin >> arr2[i];
    }
    sumOfTwoArrays(arr1,arr2,n1,n2);
    return 0;
    
}