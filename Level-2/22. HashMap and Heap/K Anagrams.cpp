#include<bits/stdc++.h>
using namespace std;

bool KAnagrams(string &s,string &t,int k){
    if(s.size()!=t.size()) return false;
    
    vector<int> v1(26),v2(26);
    for(auto ch:s){
        v1[ch-'a']++;
    }
    for(auto ch:t){
        v2[ch-'a']++;
    }
    int cnt=0;
    for(int i=0;i<26;i++){
        cnt+=(v1[i]-v2[i]>0?v1[i]-v2[i]:0);
    }
    // cout << cnt<< endl;
    return cnt<=k;
}


int main(){
    string s,t;
    cin >> s>>t;
    int k;
    cin >> k;
    if(KAnagrams(s,t,k)){
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}