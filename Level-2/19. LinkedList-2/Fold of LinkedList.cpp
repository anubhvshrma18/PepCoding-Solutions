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

ListNode *midNode(ListNode *head)
{
    ListNode* slow=head , *fast=head;
    while(fast && fast->next && fast->next->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

ListNode *reverse(ListNode* head){
    ListNode* curr=head,*prev=nullptr,*nex=nullptr;
    while(curr){
        nex=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nex;
    }
    return prev;
}


void fold(ListNode *head)
{
    if(!head || !head->next){
        return;
    }
    ListNode* temp=head;
    ListNode* mid=midNode(head);
    ListNode* rev=reverse(mid);
    
    ListNode* cnext=nullptr,*rnext=nullptr;
    while(temp && rev){
        cnext=temp->next;
        rnext=rev->next;
        
        temp->next=rev;
        
        rev->next=cnext;
        
        temp=cnext;
        rev=rnext;
        
    }
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
    ListNode *dummy = new ListNode(-1);
    ListNode *prev = dummy;
    while (n-- > 0)
    {
        int val;
        cin >> val;
        prev->next = new ListNode(val);
        prev = prev->next;
    }

    ListNode *head = dummy->next;
    fold(head);
    printList(head);

    return 0;
}