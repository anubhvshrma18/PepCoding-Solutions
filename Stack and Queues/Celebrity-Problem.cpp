#include<bits/stdc++.h>
using namespace std;

void celebPrblm(vector<string> &v,int n,stack<int> &st){
    while(st.size()>1){
        int v1=st.top();
        st.pop();
        int v2=st.top();
        st.pop();
        
        if(v[v1][v2]=='1'){
            st.push(v2);
        }
        else{
            st.push(v1);
        }
    }
    
    for(int i=0;i<n && i!=st.top();i++){
        if(v[i][st.top()]=='0'){
            cout << "none" << endl;
            return;
        }
    }
    for(int i=0;i<n;i++){
        if(v[st.top()][i]=='1'){
            cout << "none" << endl;
            return;
        }
    }
    
    cout << st.top() << endl;
    
}


int main(){
    int n;
    cin >> n;
    vector<string> s;
    stack<int> st;
    for(int i=0;i<n;i++){
        string str;
        cin >> str;
        s.push_back(str);
        st.push(i);
    }
    celebPrblm(s,n,st);
}