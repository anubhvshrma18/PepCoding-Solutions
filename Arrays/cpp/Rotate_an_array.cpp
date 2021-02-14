#include <bits/stdc++.h>
using namespace std;
void reverseArray(int arr[], int start,int end){ 
    while (start < end){ 
        swap(arr[start], arr[end]); 
        start++; 
        end--; 
    } 
} 

void rotatearray(int a[],int d,int n){
	reverseArray(a, 0, n-1); 
    reverseArray(a, 0, d-1); 
    reverseArray(a, d, n-1);
}

int main(){
	int n,k;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	cin >> k;
	if(k<0){
	    k=abs(k)%n;
	    k=n-abs(k);
	}
	k=k%n;
	rotatearray(a,k,n);
	for(int i=0;i<n;i++){
		cout << a[i] <<" ";
	}
	return 0;
}