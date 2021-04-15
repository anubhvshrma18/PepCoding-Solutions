#include<bits/stdc++.h>
using namespace std;

class minStack {
    stack<int> s;
    stack<int> minval;
    public:
        void push(int val){
            if(minval.size()==0 || val<=minval.top()){
                
                minval.push(val);
            }
            s.push(val);
        }
        int pp(){
            if(s.size()==0){
                cout<<"Stack underflow"<<endl;
                return -1;
            }
            int x=s.top();
            s.pop();
            if(x==minval.top()){
                minval.pop();
            }
            return x;
            // if(s.size()>0){
            //     if(s.top()>minval.top()){
            //         int x=s.top();
            //         s.pop();
            //         return x;
            //     }
            //     else{
            //         int x=s.top();
            //         s.pop();
            //         minval.pop();
            //         return x;
            //     }
            // }
            // else{
            //     cout<<"Stack underflow"<<endl;
            //     return -1;
            // }
        }
        int size(){
            return s.size();
        }
        int tp(){
            if(s.size()<=0){
                cout<<"Stack underflow"<<endl;
                return -1;
            }
            return s.top();
        }
        int min(){
            if(minval.size()>0){
                return minval.top();    
            }
            else{
                cout<<"Stack underflow"<<endl;
                return -1;
            }
            
        }
        // void display(){
        //     for(int i=tp; i>=0; i--){
        //         cout<< arr[i]<<" ";
        //     }
        //     cout<<endl;
        // }
        int mn(){
            if(minval.size()>0){
                return minval.top();
            }
            else{
                return -1;
            }
        }
};

int main(){
    // int n;
    // cin >> n;
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