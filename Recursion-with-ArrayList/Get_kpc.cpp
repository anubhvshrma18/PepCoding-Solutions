#include <bits/stdc++.h>
using namespace std;
string getString(char n){
    if(n=='0'){
        return ".;";
    }
    else if(n=='1'){
        return "abc";
    }
    else if(n=='2'){
        return "def";
    }
    else if(n=='3'){
        return "ghi";
    }
    else if(n=='4'){
        return "jkl";
    }
    else if(n=='5'){
        return "mno";
    }
    else if(n=='6'){
        return "pqrs";
    }
    else if(n=='7'){
        return "tu";
    }
    else if(n=='8'){
        return "vwx";
    }
    else{
        return "yz";
    }
}

vector<string> getkpc(string s){
    if(s.length()==0){
        vector<string> v;                             
        string output="";
        v.push_back(output);
        return v;
    }
    string output=getString(s[0]);
    vector<string> rec=getkpc(s.substr(1));
    vector<string> result;
    for(int i=0;i<output.length();i++){
        for(int j=0;j<rec.size();j++){
            result.push_back(output[i]+rec[j]);
        }  
    }
    return result;

}
int main() {
    string s;
    cin >> s;
    vector<string> res=getkpc(s);
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
}
