#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int val;
    node* next;
   

};
void insert_at_tail(node *&head,int val){
    if(head==NULL){
        node *newnode = new node;
        newnode->val=val;
        newnode->next=NULL;
        head=newnode;

    }
    else{
        node *newnode = new node;
        newnode->val=val;
        newnode->next=NULL;
        node *temp = head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next = newnode;
    }

}
void print (node* head){
    node *temp =head;
    if(head==NULL){
        return;
    }
     while(temp!=NULL){
         cout<<temp->val<<" ";
         temp=temp->next;
     }
     cout << endl;
}
void last(node* head){
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    cout << temp->val << " ";
}
int size(node* head){
    int cnt=0;
    node* temp=head;
    while(temp!=NULL){
        temp=temp->next;
        cnt++;
    }
    return cnt;
}
int main() {
    node *head=NULL;
    string s;
    cin >> s;
    while(s!="quit"){
        if(s=="addLast"){
            int data;
            cin>> data;
            insert_at_tail(head ,data);
        }
        else if(s=="display"){
            if(head!=NULL){
                print(head);
            }
            
        }
        else if(s=="size"){
            if(head!=NULL){
                 cout << size(head) << endl;
            }
        }
            
        cin >> s;
    }
    if(head==NULL){
        cout << 0 << endl;
        return 0;
    }
    
}