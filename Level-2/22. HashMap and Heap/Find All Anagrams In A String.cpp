#include<bits/stdc++.h>
using namespace std;

bool compe(unordered_map<char,int> &map1,unordered_map<char,int> &map2){
    if(map1.size()!=map2.size()){
        return false;
    }
    for(auto m:map2){
        char ch=m.first;
        if(map1.find(ch)==map1.end()){
            return false;
        }
        if(map1[ch]!=map2[ch]){
            return false;
        }
    }
    return true;
}

vector<int> findAnagram(string s,string t){
    vector<int> ans;
    unordered_map<char,int> map1;
    for(auto ch:t){
        map1[ch]++;
    }
    unordered_map<char,int> map2;
    int size = t.size(),i;
    for(i=0;i<size;i++){
        map2[s[i]]++;
    }
    int j=0;
    for(;i<s.length();i++,j++){
        if(compe(map1,map2)==true){
            ans.push_back(j);
        }
        
        map2[s[i]]++;
        
        if(map2[s[j]]==1){
            map2.erase(s[j]);
        }
        else{
            map2[s[j]]--;
        }
    }
    if(compe(map1,map2)==true){
        ans.push_back(j);
    }
    
    return ans;
}



int main(){
    string s,t;
    cin >> s  >> t;
    vector<int> ans = findAnagram(s,t);
    cout << ans.size() << endl;
    for(auto a:ans){
        cout << a << " ";
    }
    cout << endl;
}