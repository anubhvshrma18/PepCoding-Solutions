#include "bits/stdc++.h"
using namespace std;

int longestKSubstr(string s, int k) {
    // your code here
    int i=-1;
    int j=-1;
    int ans=-1;
    int n=s.length();
    map<char,int> mp;
    while(i < n-1){
        // cout << n << endl;
        while(i < n-1){
            i++;
            mp[s[i]]++;
            
            // cout << "ans" << endl;
            
            if(mp.size()==k){
                ans=max(ans,i-j);
            }
            else if(mp.size()>k){
                break;
            }
        }
        while(j<i){
            j++;
            if(mp[s[j]]==1){
                mp.erase(s[j]);
            }
            else {
                mp[s[j]]--;
            }
            
            if(mp.size()==k){
                break;
            }
        }
    }
    
    
    // cout << " a" << endl;
    
    return ans;
}

int main(){
    string s;cin>>s;
    int k;cin>>k;
    cout << longestKSubstr(s,k) << endl;
}