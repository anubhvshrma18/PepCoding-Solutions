#include<bits/stdc++.h>
using namespace std;

class Queue{
  stack<int> s1;
  stack<int> s2;
  int sz=0;
  public:
    void push(int val){
        s1.push(val);
        sz++;
    }
    int pop(){
        if(s1.empty() && s2.empty()){
            cout << "Queue underflow" << endl;
            return -1;
        }
        else if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int x=s2.top();
        s2.pop();
        sz--;
        return x;
    }
    int top(){
        if(s1.empty() && s2.empty()){
            cout << "Queue underflow" << endl;
            return -1;
        }
        else if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int x=s2.top();
        return x;
    }
    int size(){
        return sz;
    }
};

int main(){
    Queue st;
    string str;
    cin >> str;
    while(str!="quit"){
        if(str=="add"){
            int val;
            cin >> val;
            st.push(val);
        }
        else if(str=="remove"){
            int ans=st.pop();
            if(ans!=-1){
                cout << ans << endl;
            }
            
        }
        else if(str=="peek"){
            int ans=st.top();
            if(ans!=-1){
                cout << ans << endl;
            }
        }
        else if(str=="size"){
            cout << st.size() << endl;
        }
        cin >> str;
    }
}