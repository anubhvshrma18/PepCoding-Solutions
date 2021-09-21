#include<bits/stdc++.h>
using namespace std;


int lengthOfLongestSubstringKDistinct(string &s, int k) {
        // write your code here
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



int main(){
    string s;
    cin >> s;
    int k;cin>>k;
    cout << lengthOfLongestSubstringKDistinct(s,k) << endl;
}