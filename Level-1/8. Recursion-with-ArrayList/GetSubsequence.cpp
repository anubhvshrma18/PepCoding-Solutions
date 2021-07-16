#include <iostream>
#include <vector>
using namespace std;

vector<string> gss(string s){
    // write your code here
    vector<string> x;
    if(s.length()==0){
        x.push_back("");
        return x;
        
    }
    string small=s.substr(0,s.length()-1);
    vector<string> getsub=gss(small);
    for(int i=0;i<getsub.size();i++){
        x.push_back(getsub[i]+"");
        x.push_back(getsub[i]+s[s.length()-1]);
    }
    return x;
}

int main(){
    string s;
    cin >> s;
    vector<string> ans = gss(s);
    int cnt = 0;

    cout << '[';
    for (string str : ans){
        if (cnt != ans.size() - 1)
            cout << str << ", ";
        else
            cout << str;
        cnt++;
    }
    cout << ']';
}