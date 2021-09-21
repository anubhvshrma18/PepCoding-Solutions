#include<bits/stdc++.h>
using namespace std;

bool wordPattern(string &pattern, string &s) {
    stringstream ns(pattern);
    stringstream ss(s);
    vector<string> v;
    string word;
    while(ss >> word){
        v.push_back(word);
    }
    ns >> pattern;
    if(v.size() != pattern.size()) return false;
    map<char,string> map;
    set<string> st;
    for(int i=0;i<v.size();i++){
        if(map.find(pattern[i])!=map.end()){
            if(map[pattern[i]] != v[i]) return false;
        }
        else if(st.count(v[i]) > 0){
            return false;
        }
        else{
            map[pattern[i]]=v[i];
            st.insert(v[i]);
        }
        
    }
    return true;
}
int main(){
    string s; 
    getline(cin,s);
    string t;
    getline(cin,t);
    // cout << s << endl;
    if(wordPattern(s,t)){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }
}