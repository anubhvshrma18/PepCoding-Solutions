#include<bits/stdc++.h>
using namespace std;

string mx;

void findMax(string s,int k){
    mx = max(mx,s);
    if(k==0){
        return;
    }
    
    
    for(int i=0;i<s.length()-1;i++){
        for(int j=i+1;j<s.length();j++){
            if(s[j] > s[i]){
                swap(s[i],s[j]);
                findMax(s,k-1);
                swap(s[i],s[j]);
            }
        }
    }
}


int main(){
    string s;
    cin >> s;
    int k;
    cin >> k;
    mx=s;
    findMax(s,k);
    cout << mx << endl;
}