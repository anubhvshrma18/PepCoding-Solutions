#include <bits/stdc++.h>
using namespace std;

void stockSpan(int *arr,int n){
	stack<int> st;
// 	st.push(arr[0]);
	vector<int> a(n);
	for(int i=0;i<n;i++){
		while(st.size()>0 && arr[st.top()]<arr[i]){
			st.pop();
		}
		if(st.size()==0){
			a[i]=i+1;
		}
		else{
			a[i]=i-st.top();
		}
		st.push(i);
	}
    for(int i=0;i<n;i++){
        cout << a[i] << endl;
    }
    
}

int main(){
	int n,k;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	stockSpan(arr,n);
	return 0;
}