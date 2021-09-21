#include<bits/stdc++.h>
using namespace std;

bool isValidAnagram(string s,string t){
    unordered_map<char,int> map;
    for(char ch:s){
        map[ch]++;
    }
    
    for(char ch:t){
        if(map.find(ch)==map.end()){
            return false;
        }
        map[ch]--;
    }
    
    
    for(auto m:map){
        if(m.second!=0){
            return false;
        }
    }
    return true;
}

int main(){
    string s,t;
    cin >> s >> t;
    if(isValidAnagram(s,t)){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }
}