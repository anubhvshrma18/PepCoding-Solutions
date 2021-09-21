#include<bits/stdc++.h>
using namespace std;


string fracToDec(int num, int deno){
    if(!num)return "0";
    string ans;
    if(num > 0 ^ deno > 0){
        ans+="-";
    }
    long n=labs(num),d=labs(deno),r=n%d;
    ans+=to_string(n/d);
    if(!r)return ans;
    ans+=".";
    unordered_map<long,long>mp;
    while(r){
        if(mp.find(r)!= mp.end()){
            ans.insert(mp[r],"(");
            ans+=")";
            break;
        }
        mp[r]=ans.size();
        r*=10;
        ans+=to_string(r/d);
        r=r%d;
        
    }
    return ans;
}


int main(){
    int n,d;
    cin >> n >> d;
    cout << fracToDec(n,d) << endl;
}