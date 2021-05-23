#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<ll> nextGreateronright(ll *arr,ll n){
	vector<ll> v(n);
	stack<ll> st;
	st.push(n-1);
	v[n-1]=n;
	for(ll i=n-2;i>=0;i--){
		while(st.size()>0 && arr[st.top()]<arr[i]){
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

void swm(ll *arr, ll n,ll k){
	vector<ll> ngor=nextGreateronright(arr,n);
// 	vector<ll> vec(n-k+1);
	for(ll i=0;i<=n-k;i++){
		int idx=i;
		while(ngor[idx]<k+i){
			idx=ngor[idx];
		}
        cout << arr[idx] << endl;
		
	}
}

int main(){
	ll n,k;
	cin >> n;
	ll arr[n];
	for(ll i=0;i<n;i++){
		cin >> arr[i];
	}
	cin >> k;
	swm(arr,n,k);
	return 0;
}