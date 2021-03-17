#include<bits/stdc++.h>
using namespace std;

bool balBrac(string s){
    stack<char> st;
    bool check=true;
    for(int i=0;i<s.length();i++){
        if(s[i]=='{' || s[i]=='[' || s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i]=='}'){
            if(st.size()==0){
                return false;
            }
            else if(st.top()!='{'){
                return false;
            }
            else{
                st.pop();
            }
        }
        else if(s[i]==')'){
            if(st.size()==0){
                return false;
            }
            else if(st.top()!='('){
                return false;
            }
            else{
                st.pop();
            }
            
        }
        else if(s[i]==']'){
            if(st.size()==0){
                return false;
            }
            else if(st.top()!='['){
                return false;
            }
            else{
                st.pop();
            }
        }
    }
    if(st.size()==0){
        return check;    
    }
    else{
        return !check;
    }
    
}

int main(){
    string s;
    getline(cin , s);
    if(balBrac(s)){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }
}