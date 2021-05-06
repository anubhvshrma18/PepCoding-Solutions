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

node* getAt(node* &head,int p){
    if(head==NULL){
        cout << "List is Empty" << endl;
        return NULL;
    }
    int cnt=0;
    node* temp=head;
    while(cnt < p){
        cnt++;
        temp=temp->next;
    }
    //cout << temp->val << endl;
    return temp;
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

void mid(node* &head){
    if(head==NULL){
        return;
    }
    else{
        node*temp1=head;
        node*temp2=head;
        while(temp2->next!=NULL && temp2->next->next!=NULL){
            temp2=temp2->next->next;
            // if(temp2==NULL){
            //     break;
            // }
            temp1=temp1->next;
        }
        
        cout << temp1->val << endl;
    }
}

int kthNodefromLast(node* &head,int k){
    node *temp1=head;
    node *temp2=head;
    for(int i=0;i<k;i++){
        temp2=temp2->next;
    }
    
    while(temp2->next!=nullptr){
        temp2=temp2->next;
        temp1=temp1->next;
    }
    
    return temp1->val;
}

void removeDuplicates(node* &head){
    node* temp1=head;
    node* temp2=head;
    map<int,int> mp;
    while(temp2!=nullptr){
        mp[temp2->val]++;
        if(mp[temp2->val]>1){
            temp1->next=temp2->next;
            temp2=temp2->next;
        }
        else{
            temp1=temp2;
            temp2=temp2->next;
        }
    }
}

int intersection(node* list1,node* list2){
    int len1=0,len2=0,diff=0;
    node *h1=list1,*h2=list2;
    while(h1!=NULL){
        h1=h1->next;
        len1++;
    }
    while(h2!=NULL){
        h2=h2->next;
        len2++;
    }
    if(len1>len2){
        h1=list1,h2=list2,diff=len1-len2;
    }
    else{
        h1=list2,h2=list1,diff=len2-len1;
    }
    
    for(int i=0;i<diff;i++){
        h1=h1->next;
    }
    
    while(h1!=NULL &&h2!=NULL){
        if(h1==h2){
            return h1->val;
        }
        h1=h1->next;
        h2=h2->next;
    }
    return -1;
}

int main(){
    node* head1=NULL,*head2=NULL;
    int n,m,ln,pos;
    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        insert_at_tail(head1 ,x);
        
    }
    cin >> m;
    for(int i=0;i<m;i++){
        int x;
        cin >> x;
        insert_at_tail(head2 ,x);
        
    }
    cin >> ln >> pos;
    if(ln==1){
        node* temp=head2;
        node* temp2=getAt(head1,pos);
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=temp2;
    }
    else{
        node* temp=head1;
        node* temp2=getAt(head2,pos);
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=temp2;
    }
    
    
    cout << intersection(head1,head2) << "\n";
    
}

