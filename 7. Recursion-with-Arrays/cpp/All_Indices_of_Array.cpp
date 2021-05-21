#include<bits/stdc++.h>
using namespace std;

vector<int> allIdx(int arr[],int n,int x,int idx){
    if(idx==n){
        vector<int> v;
        return v;
    }
    vector<int> c=allIdx(arr,n,x,idx+1);
    if(arr[idx]==x){
        c.push_back(idx);
    }
    return c;
}

int main(){
    int n,x;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    cin >> x;
    vector<int> vec=allIdx(arr,n,x,0);
    if(vec.size()==0){
        cout << endl;
    }
    else{
        for(int i=vec.size()-1;i>=0;i--){
            cout << vec[i] << endl;
        }   
    }
    
    
}