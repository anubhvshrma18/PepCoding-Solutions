#include<bits/stdc++.h>
using namespace std;

bool duplicateBrackets(string s){
    stack<char> st;
    bool check=true;
    for(int i=0;i<s.length();i++){
        char ch=s[i];
        
        if(ch==')'){
            int pc=0;
            while(st.top()!='('){
                pc++;
                st.pop();
            }
            if(pc==0){
                check=false;
                return check;
            }
            else{
                st.pop();
            }
        }
        else{
            st.push(ch);
        }
        
    }
    return check;
}

int main(){
    string s;
    getline(cin , s);
    if(duplicateBrackets(s)){
        cout << "false" << endl;
    }
    else{
        cout << "true" << endl;
    }
}