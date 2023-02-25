#include <bits/stdc++.h>
using namespace std;

string codes[] = {".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};

string getString(char n) {
    int idx = n - '0';
    if (idx < 0 || idx > 9) {
        return "";
    }
    return codes[idx];
}

vector<string> getkpc(string s){
    if(s.length() == 0){
        vector<string> v;                             
        string output="";
        v.push_back(output);
        return v;
    }
    string output = getString(s[0]);
    vector<string> rec = getkpc(s.substr(1));
    vector<string> result;
    for(int i=0; i<output.length(); i++){
        for(int j=0; j<rec.size(); j++){
            string code = output.substr(i, 1);
            result.push_back(code + rec[j]);
        }  
    }
    return result;
}

int main() {
    string s;
    cin >> s;
    vector<string> res = getkpc(s);
    int cnt = 0;
    cout << '[';
    for (string str : res){
        if (cnt != res.size() - 1)
            cout << str << ", ";
        else
            cout << str;
        cnt++;
    }
    cout << ']';
    return 0;
}
