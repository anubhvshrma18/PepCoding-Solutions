#include<bits/stdc++.h>
using namespace std;

int getMin(string str){
    stack<char> st;
    for(int i=0;i<str.length();i++){
        char ch = str[i];
        if(ch == '('){
            st.push(ch);
        }
        else{
            if(st.size()==0 || st.top()==')'){
                st.push(ch);
            }
            else if(st.top()=='('){
                st.pop();
            }
        }
    }
    return st.size();
}

void solution(string str,int mn,unordered_set<string> &ans,unordered_set<string> &tt){
    if(mn == 0){
        if(getMin(str)==0 && ans.count(str)==0){
            cout << str << endl;
            ans.insert(str);
        }
        return;
    }
    for(int i=0;i<str.length();i++){
        string temp = str.substr(0,i)+str.substr(i+1);
        if(tt.count(temp)==0){
          tt.insert(temp);
          solution(temp,mn-1,ans,tt);

        }
    }
}

int main(){
    string s;
    cin >> s;
    // int mn = ;
    unordered_set<string> st,tt;
    solution(s,getMin(s),st,tt);
}