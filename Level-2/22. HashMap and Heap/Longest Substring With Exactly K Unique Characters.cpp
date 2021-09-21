#include "bits/stdc++.h"
using namespace std;


int check(string &s,int k){
    int i=-1;
    int j=-1;
    int ans=0;
    int n=s.length();
    if(n==0){
        return 0;
    }
    map<char,int> mp;
    while(i < n-1){
        // acquire;
        while(i < n-1){
            i++;
            mp[s[i]]++;
            if(mp.size()<=k){
                ans+=(i-j);
            }
            else {
                break;
            }
        }
        while(j<i && mp.size()>k){
            j++;
            if(mp[s[j]]==1){
                mp.erase(s[j]);
            }
            else {
                mp[s[j]]--;
            }
            
            if(mp.size()==k){
                ans+=(i-j);
            }
        }
    }
    
    
    return ans;
}

int longestKSubstr(string s, int k) {
    return check(s,k)-check(s,k-1);
}

int main(){
    string s;cin>>s;
    int k;cin>>k;
    cout << longestKSubstr(s,k) << endl;
}