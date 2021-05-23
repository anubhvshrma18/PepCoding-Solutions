#include<bits/stdc++.h>
using namespace std;

class minStack {
    stack<int> s;
    int min=INT_MAX;
    public:
        void push(int val){
            if(s.size()==0){
                s.push(val);
                min=val;
            }
            else if(val<=min){
                s.push((2*val)-min);
                min=val;
            }
            else{
                s.push(val);
            }
        }
        int pp(){
            if(s.size()==0){
                cout<<"Stack underflow"<<endl;
                return -1;
            }
            int x=s.top();
            if(x<=min){
                x=min;
                min=2*x-s.top();
            }
            s.pop();
            return x;
        }
        int size(){
            return s.size();
        }
        int tp(){
            if(s.size()<=0){
                cout<<"Stack underflow"<<endl;
                return -1;
            }
            int x=s.top();
            if(x<=min){
                x=min;
            }
            return x;
        }
        int mn(){
            if(min!=INT_MAX){
                return min;    
            }
            else{
                cout<<"Stack underflow"<<endl;
                return -1;
            }
            
        }
    
};

int main(){
    minStack st;
    string str;
    cin >> str;
    while(str!="quit"){
        if(str=="push"){
            int val;
            cin >> val;
            st.push(val);
        }
        else if(str=="pop"){
            int ans=st.pp();
            if(ans!=-1){
                cout << ans << endl;
            }
            
        }
        else if(str=="top"){
            int ans=st.tp();
            if(ans!=-1){
                cout << ans << endl;
            }
        }
        else if(str=="size"){
            cout << st.size() << endl;
        }
        else if(str=="min"){
            cout << st.mn() << endl;
        }
        cin >> str;
    }
}