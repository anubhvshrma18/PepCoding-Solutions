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


bool isPalindrome(ListNode *head)
{   
    ListNode* temp=head;
    ListNode* mnode=midNode(head);
    ListNode* rev=reverse(mnode);
    
    while(rev!=nullptr && temp!=nullptr){
        if(rev->val != temp->val){
            return false;
        }
        rev=rev->next;
        temp=temp->next;
    }
    return true;
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

    cout << (boolalpha) << isPalindrome(dummy->next) << endl;

    return 0;
}