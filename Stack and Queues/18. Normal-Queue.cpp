#include<bits/stdc++.h>
using namespace std;

class Queue{
    int sze;
    int *arr;
    int front;
    int rear;
    public:
        Queue(int size){
            sze=size;
            arr= new int [sze];
            front=-1;
            rear=-1;
        }
        void add(int data){
            if(front==-1 && rear==-1){
                front=0;
                ++rear;
                arr[rear%sze]=data;
            }
            else if(front%sze==(rear+1)%sze){
                cout << "Queue overflow" << endl;
                return;
            }
            else{
               ++rear;
                arr[(rear)%sze]=data;
            }
        }
        int remove(){
            if(front==-1){
                cout << "Queue underflow" << endl;
                return -1;
            }
            else{
            	if(front%sze==rear%sze){
            		int val=arr[front%sze];
            		front=rear=-1;
            		return val;
            	}
	            else{
                    //front=(front)%sze;
	                int val=arr[front%sze];
                   front++;
                    // front=front%sze;
	                return val;
	            }
            }
        }
        int peek(){
            if(front==-1){
                cout << "Queue underflow" << endl;
                return -1;
            }
            else{
                int x=front%sze;
                return arr[x];
            }
        }
        int size(){
            return rear%sze-(front%sze)+1;
        }
        void display(){
            if(front==-1 || rear == -1){
                cout << endl;
                return;
            }
            for(int i=front;i<=rear;i++){
                if(front%sze==rear%sze){
                    cout << arr[i%sze] << " ";
                    break;
                }
                cout << arr[i%sze] << " ";
            }
            cout << endl;
        }

};


int main(){
    int n;
    cin >> n;
    Queue st(n);
    string str;
    cin >> str;
    while(str!="quit"){
        if(str=="add"){
            int val;
            cin >> val;
            st.add(val);
        }
        else if(str=="remove"){
            int ans=st.remove();
            if(ans!=-1){
                cout << ans << endl;
            }

        }
        else if(str=="display"){
            st.display();
        }
        else if(str=="peek"){
            int ans=st.peek();
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