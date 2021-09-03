#include "bits/stdc++.h"
using namespace std;


int main(){
    int n;cin>> n;
    unordered_map<string,string> map;
    for(int i=0;i<n;i++){
        string s1,s2;cin>>s1>>s2;
        map[s1]=s2;
    }

    unordered_map<string,bool> path;

    for(auto m:map){
        string s1 = m.first,s2=m.second;

        if(path.find(s1)==path.end()){
            path[s1]=true;
        }
        path[s2]=false;
    }
    string src="";
    for(auto m:path){
        if(m.second==true){
            src=m.first;
            break;
        }
    }
    string pa=src;
    while(map.find(src)!=map.end()){
        string ndes = map[src];
        pa += " -> "+ ndes;
        src = ndes;
    }

    cout << pa << "." << endl;

}