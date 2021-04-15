#include <bits/stdc++.h>
using namespace std;



vector<int> nextSmalleronleft(int *arr,int n){
	vector<int> v(n);
	stack<int> st;
	st.push(0);
	v[0]=-1;
	for(int i=1;i<n;i++){
		while(st.size()>0 && arr[st.top()]>=arr[i]){
			st.pop();
		}
		if(st.size()==0){
			v[i]=-1;
		}
		else{
			v[i]=st.top();
		}
		st.push(i);
	}

	return v;

}

vector<int> nextSmalleronright(int *arr,int n){
	vector<int> v(n);
	stack<int> st;
	st.push(n-1);
	v[n-1]=n;
	for(int i=n-2;i>=0;i--){
		while(st.size()>0 && arr[st.top()]>=arr[i]){
			st.pop();
		}
		if(st.size()==0){
			v[i]=n;
		}
		else{
			v[i]=st.top();
		}
		st.push(i);
	}

	return v;

}

void largestAreaHistogram(int *arr,int n){
	vector<int> nsl=nextSmalleronleft(arr,n);
	vector<int> nsr=nextSmalleronright(arr,n);

	int mxarea=INT_MIN;
	for(int i=0;i<n;i++){
		int width=nsr[i]-nsl[i]-1;
		int area=width*arr[i];
		mxarea=max(mxarea,area);
	}
	cout << mxarea << endl;
}



int main(){
	int n; 
	cin >> n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}

	// infixEval(s);
	largestAreaHistogram(arr,n);
	return 0;
}