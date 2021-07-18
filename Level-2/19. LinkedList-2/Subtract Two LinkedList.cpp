#include <iostream>
using namespace std;

class ListNode
{
public:
    int val = 0;
    ListNode *next = nullptr;

    ListNode(int val)
    {
        this->val = val;
    }
};

// ListNode *midNode(ListNode *head)
// {
//     if (head == nullptr || head->next == nullptr)
//         return head;

//     ListNode *slow = head;
//     ListNode *fast = head;
//     while (fast->next != nullptr && fast->next->next != nullptr)
//     {
//         slow = slow->next;
//         fast = fast->next->next;
//     }

//     return slow;
// }
ListNode * reverse(ListNode* head){
    ListNode* curr=head,*prev=nullptr,*nex=nullptr;
    while(curr){
        nex=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nex;
    }
    return prev;
}
int size(ListNode* head){
    int cnt=0;
    while(head){
        head=head->next;cnt++;
    }
    return cnt;
}
ListNode* gr(ListNode* l1,ListNode* l2){
    int s1=size(l1);
    int s2=size(l2);
    
    if(s1>s2){return l1;}
    else if(s2>s1){return l2;}
    
    ListNode* c1=l1;
    ListNode* c2=l2;
    
    while(c1 && c2){
        if(c1->val > c2->val){
            return l1;
        }
        else if(c1->val < c2->val){
            return l2;
        }
        else{
            c1=c1->next;c2=c2->next;
        }
    }
    if(!c1 && !c2){
        return nullptr;
    }
    else if(!c1){
        return l2;
    }
    else{
        return l1;
    }
}
ListNode *subtractTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *dm=new ListNode(-1);
    ListNode *m=dm;
    
    ListNode* c1=nullptr,*c2=nullptr;
    ListNode* check=gr(l1,l2);
    if(check==l1){
        c1=reverse(l1);
        c2=reverse(l2);
    }
    else if(check==l2){
        c1=reverse(l2);
        c2=reverse(l1);
    }
    else{
        ListNode* nn=new ListNode(0);
        return nn;
    }
    
    int borrow=0;
    while(c1){
        int val = c1->val+borrow;
        
        if(c2){
            val -= c2->val;
            c2=c2->next;
        }
        if(val<0){
            val+=10;
            borrow=-1;
        }
        else{
            borrow=0;
        }
        
        ListNode* nn=new ListNode(val);
        m->next=nn;
        m=m->next;
        c1=c1->next;
    }
    
    ListNode* ptr=reverse(dm->next);
    ListNode* temp=ptr;
    while(ptr && ptr->val == 0){
        ptr=ptr->next;
    }
    
    return temp;
}

// Input_code===================================================

ListNode *makeList(int n)
{
    ListNode *dummy = new ListNode(-1);
    ListNode *prev = dummy;
    while (n-- > 0)
    {
        int val;
        cin >> val;
        prev->next = new ListNode(val);
        prev = prev->next;
    }
    return dummy->next;
}

void printList(ListNode *node)
{
    ListNode *curr = node;
    while (curr != nullptr)
    {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    ListNode *head1 = makeList(n);

    int m;
    cin >> m;
    ListNode *head2 = makeList(m);

    ListNode *head = subtractTwoNumbers(head1, head2);
    printList(head);

    return 0;
}