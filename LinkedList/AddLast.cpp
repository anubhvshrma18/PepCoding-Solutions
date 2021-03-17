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
     while(temp!=NULL){
         cout<<temp->val<<endl;
         temp=temp->next;
     }
    //  cout << endl;
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
        int data;
        cin>> data;
        insert_at_tail(head ,data);
        cin >> s;
    }
    if(head==NULL){
        cout << 0 << endl;
        return 0;
    }
    print(head);
    cout << size(head) << endl;
    last(head);
    
}