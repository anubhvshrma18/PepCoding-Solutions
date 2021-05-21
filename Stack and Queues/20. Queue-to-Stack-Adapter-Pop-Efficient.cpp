#include<bits/stdc++.h>
using namespace std;

class Stack{
    queue<int> q1;
    queue<int> q2;
    int sz=0;
    public:
        void push(int val){
            q2.push(val);
            while(!q1.empty()){
                q2.push(q1.front());
                q1.pop();
            }
            queue<int> q=q1;
            q1=q2;
            q2=q;
            sz++;
        }
        int pop(){
            if(q1.empty()){
               cout << "Stack underflow" << endl;
               return -1; 
            }
            int vl=q1.front();
            q1.pop();
            sz--;
            return vl;
        }
        int top(){
            if(!q1.empty()){
                return q1.front();
            }
            else{
                cout << "Stack underflow" << endl;
                return -1;
            }
        }
        int size(){
            return sz;
        }
};


int main(){
    Stack st;
    string str;
    cin >> str;
    while(str!="quit"){
        if(str=="push"){
            int val;
            cin >> val;
            st.push(val);
        }
        else if(str=="pop"){
            int ans=st.pop();
            if(ans!=-1){
                cout << ans << endl;
            }
            
        }
        // else if(str=="display"){
        //     st.display();
        // }
        else if(str=="top"){
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