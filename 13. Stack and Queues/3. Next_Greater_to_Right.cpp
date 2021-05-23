#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int a[n];
    stack<int> st;
    st.push(arr[n-1]);
    a[n-1]=-1;
    for(int i=n-2;i>=0;i--){
        while(st.size()>0 && st.top()< arr[i]){
            st.pop();
        }
        if(st.size()==0){
            a[i]=-1;
            // st.push(arr[i]);
        }
        else{
            a[i]=st.top();
            
        }
        st.push(arr[i]);
    }
    
    for(int i=0;i<n;i++){
        cout << a[i] << endl;
    }
}