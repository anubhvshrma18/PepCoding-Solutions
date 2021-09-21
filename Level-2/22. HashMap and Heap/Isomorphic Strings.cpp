    #include<bits/stdc++.h>
using namespace std;

bool isIsomorphic(string &s,string &t){
    unordered_map<char,char> map1;
    unordered_map<char,bool> map2;
    
    for(int i=0;i<s.length();i++){
        if(map1.find(s[i])!=map1.end()){
            if(map1[s[i]]!=t[i]){
                return false;
            }
        }
        else{
            if(map2.find(t[i])!=map2.end()){
                return false;
            }
            else{
                map1[s[i]]=t[i];
                map2[t[i]]=true;
            }
        }
    }
    return true;
}

int main(){
    string s,t;
    cin >> s >> t;
    if(isIsomorphic(s,t)){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }
}