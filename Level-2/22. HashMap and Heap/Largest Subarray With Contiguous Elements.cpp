#include<bits/stdc++.h>
using namespace std;

int solution(int arr[],int n){
    int ans=0;
    for(int i=0;i<n;i++){
        int mn=INT_MAX;
        int mx=INT_MIN;
        
        unordered_set<int> st;
        
        for(int j=i;j<n;j++){
            mn=min(arr[j],mn);
            mx=max(mx,arr[j]);
            
            
            if(st.find(arr[j])!=st.end()){
                break;
            }
            
            st.insert(arr[j]);
            int ec=j-i+1;
            int dc=mx-mn+1;
            
            if(ec==dc){
                ans=max(ans,ec);
            }
        }
    }
    
    return ans;
}


int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    
    cout << solution(arr,n) << endl;
}