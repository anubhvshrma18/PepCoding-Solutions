#include <bits/stdc++.h>
using namespace std;
struct node{
    //public:
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
int first(node* &head){
    if(head==NULL){
        return -1;
    }
    return head->val;
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

void displayReverse(node* &head){
    if(!head){
        return;
    }
    displayReverse(head->next);
    cout << head->val << " ";
}

void oddEven(node* &head){
    node* odd=NULL,*even=NULL;
    node* temp=head;
    while(temp!=NULL){
        if(temp->val%2==0){
            if(even==NULL){
                node* nn=new node();
                nn->val= temp->val;
                nn->next=NULL;
                even=nn;
            }
            else{
                node* nn=new node();
                nn->val= temp->val;
                nn->next=NULL;
                node*te=even;
                while(te->next!=NULL){
                    te=te->next;
                }
                te->next=nn;
            }
        }
        else{
            if(odd==NULL){
               node* nn=new node();
                nn->val= temp->val;
                nn->next=NULL;
                odd=nn; 
            }
            else{
                node* nn=new node();
                nn->val= temp->val;
                nn->next=NULL;
                node*te=odd;
                while(te->next!=NULL){
                    te=te->next;
                }
                te->next=nn;
            }
        }
        deletion_at_head(temp);
        
    }
    
    
    if(odd!=NULL){
        head=odd;
        node* tt=odd;
        while(tt->next!=NULL){
            tt=tt->next;
        }
        tt->next=even;
    }
    else{
        head=even;
    }
    
    print(head);
}

node* kreverse(node* &head,int k){
    node* curr=head,*prev=NULL,*nex=NULL;
    node* tem=head;
    int len=0;
    while(tem!=NULL){
        tem=tem->next;
        len++;
    }
    if(k>=len){
        return head;
    }
    int count=0;
    while(curr!=NULL & count<k){
        nex=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nex;
        count++;
    }
    if(nex!=NULL){
        head->next=kreverse(nex,k);
    }
    return prev;
}
node* reverse(node* head){
        node* curr=head;
        node* prev=NULL,*nex=NULL;
        while(curr){
            nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }
        return prev;
    }
node* addTwoLists(node* first,node* second)
    {
        // code here
        first=reverse(first);
        second=reverse(second);
        node *head3=NULL;
        int carry=0;
        while(first || second || carry!=0){
            int x=carry;
            if(first){
                x+=first->val;
            }
            if(second){
                x+=second->val;
            }
            
            carry=x/10;
            x=x%10;
            node* neNode=new node;
            neNode->val=x;
            neNode->next=head3;
            head3=neNode;
            
            if(first){
                first=first->next;
                
            }
            if(second){
                second=second->next;
                
            }
            
        }
        return head3;
    }

int main(){
    node* head1=NULL,*head2=NULL;
    int n,m;
    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        insert_at_tail(head1,x);
    }
    cin >> m;
    for(int i=0;i<m;i++){
        int x;
        cin >> x;
        insert_at_tail(head2,x);
    }
    int a,b;
    cin >> a >> b;
    if(head1!=NULL){
        print(head1);
    }
    if(head2!=NULL){
        print(head2);
    }
    node* point=addTwoLists(head1,head2);
    print(point);
    insert_at_tail(point,b);
    insertion_at_head(point,a);
    print(point);
    
    
}