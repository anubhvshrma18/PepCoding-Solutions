#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int val;
    node* next;
   

};

node* tail;
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
void insertion_at_head(node* &head,int val){
    node *newnode = new node;
    newnode->val=val;
    newnode->next=NULL;
    if(head==NULL){
        head=newnode;
    }
    else{
        newnode ->next =head;
        head = newnode;
    }

}
void print (node* &head){
    node *temp =head;
    if(head==NULL){
        cout << endl;
        return;
    }
    else{     
        while(temp!=NULL){
             cout<<temp->val<<" ";
             temp=temp->next;
         }
         cout << endl;
    }
}
void deletion_at_head(node* &head){
      if(head==NULL) return;
      node *temp=head;
      head=head->next;
      delete temp;

}
void deletion_at_tail(node*& head){
    if(head==NULL) return;
      node* previous=NULL;
      node* temp=head;
      while(temp->next!=NULL){
          previous=temp;
          temp=temp->next;
      }
      previous->next = NULL;
      delete temp;
}
void last(node* &head){
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    cout << temp->val << endl;
}
int size(node* &head){
    int cnt=0;
    node* temp=head;
    while(temp!=NULL){
        temp=temp->next;
        cnt++;
    }
    return cnt;
}
void first(node* &head){
    cout << head->val << endl;
}

void getAt(node* &head,int p){
    if(head==NULL){
        cout << "List is Empty" << endl;
        return;
    }
    int cnt=0;
    node* temp=head;
    while(cnt < p){
        cnt++;
        temp=temp->next;
    }
    cout << temp->val << endl;
}

void addAt(node* &head,int pos,int data){
    if(pos==0){
        insertion_at_head(head,data);
        return;
    }
    node* newnode=new node;
    newnode->val=data;
    int cnt=0;
    node* temp=head;
    while(cnt<pos-1){
        cnt++;
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
    // }
    
}

void removeAt(node* &head,int p){
    if(head==NULL){
        cout << "List is empty" << endl;
        return;
    }
    else if(p==0){
        deletion_at_head(head);
    }
    else{
        node* temp=head;
        int cnt=0;
        while(cnt<p-1){
            temp=temp->next;
            cnt++;
        }
        node* t=temp->next;
        temp->next=t->next;
        free(t);
        return;
    }
}
// function to get the node at i index
node* getNodeAt(node* &head,int i){
    node* temp=head;
    int cnt=0;
    while(cnt<i){
        temp=temp->next;
        cnt++;
    }
    
    return temp;
}
// reverse data interatively
void reverseDI(node* &head){
    int l=0;
    int r=size(head)-1;
    while(l<r){
        node* left=getNodeAt(head,l);
        node* right=getNodeAt(head,r);
        swap(right->val,left->val);
        l++;
        r--;
    }
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
        else if(s=="addFirst"){
            int data;
            cin>> data;
            insertion_at_head(head ,data);
        }
        else if(s=="getFirst"){
            if(head!=NULL){
                first(head);
            }else{
                cout << "List is empty" << endl;
            }
        }
        else if(s=="getLast"){
            if(head!=NULL){
                last(head);
            } 
            
        }
        else if(s=="removeFirst"){
            if(head!=NULL){
                deletion_at_head(head);
            }
            else{
                cout << "List is empty" << endl; 
            }
            
        }
        else if(s=="removeLast"){
            if(head!=NULL){
                deletion_at_tail(head);
            }
            else{
                cout << "List is empty" << endl; 
            }
            
        }
        else if(s=="removeAt"){
            int i;
            cin >> i;
            if(i>=size(head)){
                cout << "Invalid arguments" << endl;
            }
            else{
                removeAt(head,i); 
            }
        }
        else if(s=="getAt"){
            if(head!=NULL){
                int i;
                cin >> i;
                if(i>=size(head)){
                    cout << "Invalid arguments" << endl;
                }
                else{
                    getAt(head,i);
                }
                
            }
            
        }
        else if(s=="reverseDI"){
            reverseDI(head);
        }
        else if(s=="display"){
            if(head!=NULL){
                print(head);
            }
            else{
                cout << endl;
            }
        }
        else if(s=="size"){
            // if(head!=NULL){
                 cout << size(head) << endl;
            // }
        }
        else if(s=="addAt"){
            int val,i;
            cin >> i >> val;
            if(i>size(head)){
                cout << "Invalid arguments" << endl;
            }
            else{
                addAt(head,i,val);
            }
        }
        cin >> s;
    }
    
}