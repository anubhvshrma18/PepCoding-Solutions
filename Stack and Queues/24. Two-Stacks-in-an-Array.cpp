#include<bits/stdc++.h>
using namespace std;

class Stack {
    int sze;
    int *arr;
    int tp1;
    int tp2;
    public:
        Stack(int n){
            sze=n;
            arr=new int [sze];
            tp1=-1;
            tp2=n;
        }
        void push1(int val){
            if(tp1+1==tp2){
                cout << "Stack overflow" << endl;
                return;
            }
            else{
            tp1++;
            arr[tp1]=val;
            }
        }
        void push2(int val){
            if(tp1+1==tp2){
                cout << "Stack overflow" << endl;
                return;
            }
            tp2--;
            arr[tp2]=val;
        }
        int pop1(){
            if(tp1==-1){
                cout<<"Stack underflow"<<endl;
                return -1;
            }
            return arr[tp1--];
        }
        int pop2(){
            if(tp2==sze){
                cout<<"Stack underflow"<<endl;
                return -1;
            }
            return arr[tp2++];
        }
        int size1(){
            return tp1+1;
        }
        int size2(){
            return tp2--;
        }
        int top1(){
            if(tp1==-1){
                cout<<"Stack underflow"<<endl;
                return -1;
            }
            return arr[tp1];
        }
        int top2(){
            if(tp2==sze){
               cout<<"Stack underflow"<<endl;
                return -1; 
            }
            return arr[tp2];
        }
};

int main(){
    int n;
    cin >> n;
    Stack st(n);
    string str;
    cin >> str;
    while(str!="quit"){
        if(str=="push1" || str=="push2"){
            if(str[4]=='1'){
                int val;
                cin >> val;
                st.push1(val);
            }
            else{
                int val;
                cin >> val;
                st.push2(val);
            }
        }
        else if(str=="pop1" || str=="pop2"){
            if(str[3]=='1'){
                int ans=st.pop1();
                if(ans!=-1){
                    cout << ans << endl;
                }
            }
            else{
                int ans=st.pop2();
                if(ans!=-1){
                    cout << ans << endl;
                }
            }
            
        }
        else if(str=="top1" || str=="top2"){
            if(str[3]=='1'){
                int ans=st.top1();
                if(ans!=-1){
                    cout << ans << endl;
                }
            }
            else{
                int ans=st.top2();
                if(ans!=-1){
                    cout << ans << endl;
                }
            }
        }
        else if(str=="size1"|| str=="size2"){
            if(str[4]=='1'){
                cout << st.size1() << endl;
            }
            else{
                cout << st.size2() << endl;
            }
        }
        cin >> str;
    }
}