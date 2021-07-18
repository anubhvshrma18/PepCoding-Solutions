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
void unfold(ListNode *head)
{
    if(!head || !head->next){
        return;
    }
    ListNode* l1=head;
    ListNode* l2=head->next;
    ListNode* p1=l1,*p2=l2;
    
    while(p1->next && p2->next){
        ListNode* n1=p1->next;
        ListNode* n2=p2->next;
        
        p1->next=n2;
        p2->next=n2->next;
        
        p1=p1->next;
        p2=p2->next;
    }
    
    l2=reverse(l2);
    p1->next=l2;
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
    unfold(head);
    printList(head);

    return 0;
}