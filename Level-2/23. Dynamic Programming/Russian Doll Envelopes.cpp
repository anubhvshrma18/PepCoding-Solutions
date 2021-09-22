#include<bits/stdc++.h>
using namespace std;

int findC(vector<int> &t,int val){
    int l=0,r=t.size(),c=-1;
    while(l<=r){
        int m = l+(r-l)/2;
        if(t[m]==val){
            c = m;
            break;
        }
        else if(t[m]< val){
            l=m+1;
        }
        else{
            c = m;
            r=m-1;
        }
    }
    return c;
}


int solve(vector<vector<int>> &v){
    int n = v.size();
    sort(v.begin(),v.end(),[&](const auto&a ,const auto &b){
        if(a[0]==b[0]){
            return a[1] < b[1];
        }
       return a[0] < b[0]; 
    });
    
    
    
    
    vector<int> dp(n);
    vector<int> temp;
    
    for(int i=0;i<n;i++){
        if(temp.size()==0 || temp[temp.size()-1] < v[i][1]){
            temp.push_back(v[i][1]);
        }
        else{
            int ci = findC(temp,v[i][1]);
            temp[ci]=v[i][1];
        }
    }
    
    return temp.size();
}



int main(){
    int n;
    cin >> n;
    vector<vector<int>> v(n,vector<int>(2));
    for(int i=0;i<n;i++){
        cin >> v[i][0] >> v[i][1];
    }
    
    cout << solve(v) << endl;
}
