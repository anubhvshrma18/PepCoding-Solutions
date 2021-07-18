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
ListNode* getTail(ListNode* head){
    if(!head){
        return head;
    }
    
    ListNode* curr=head;
    while(curr->next!=nullptr){
        curr=curr->next;
    }
    return curr;
}
ListNode *segregateOnLastIndex(ListNode *head)
{
    ListNode *sh=new ListNode(-1);
    ListNode *gh=new ListNode(-1);
    
    ListNode *st=sh , *gt=gh;
    ListNode* pivot=getTail(head);
    int data=pivot->val;
    ListNode* curr=head;
    while(curr){
        if(curr->val <= data){
            st->next=curr;
            st=st->next;
        }
        else{
            gt->next=curr;
            gt=gt->next;
        }
        curr=curr->next;
    }
    
    st->next=gh->next;
    gt->next=nullptr;
    return st;
    
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

ListNode *createList(int n)
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

int main()
{
    int n;
    cin >> n;
    ListNode *h1 = createList(n);
    h1 = segregateOnLastIndex(h1);
    printList(h1);

    return 0;
}