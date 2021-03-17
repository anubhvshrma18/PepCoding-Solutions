#include<bits/stdc++.h>
using namespace std;

class Stack {
    int sze;
    int *arr;
    int tp;
    public:
        Stack(int n){
            sze=n;
            arr=new int [sze];
            tp=-1;
        }
        void push(int val){
            if(tp==sze-1){
                cout << "Stack overflow" << endl;
                return;
            }
            tp++;
            arr[tp]=val;
        }
        int pop(){
            if(tp==-1){
                cout<<"Stack underflow"<<endl;
                return -1;
            }
            return arr[tp--];
        }
        int size(){
            return tp+1;
        }
        int top(){
            if(tp==-1){
                cout<<"Stack underflow"<<endl;
                return -1;
            }
            return arr[tp];
        }
        void display(){
                for(int i=tp; i>=0; i--){
                    cout<< arr[i]<<" ";
                }
                cout<<endl;
           
        }
};

int main(){
    int n;
    cin >> n;
    Stack st(n);
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
        else if(str=="display"){
            st.display();
        }
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