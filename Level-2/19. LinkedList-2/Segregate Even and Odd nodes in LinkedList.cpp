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
        next=nullptr;
    }
};

ListNode *segregateEvenOdd(ListNode *head)
{
    ListNode* even=new ListNode(-1);
    ListNode* odd=new ListNode(-1);
    ListNode* d1=even,*d2=odd;
    
    ListNode* temp=head;
    while(temp){
        if(temp->val%2==0){
            d1->next=temp;
            d1=d1->next;
            temp=temp->next;
        }
        else{
            d2->next=temp;
            d2=d2->next;
            temp=temp->next;
        }
        
    }
    d1->next=odd->next;
    d2->next=nullptr;
    return even->next;
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

    ListNode *head = segregateEvenOdd(dummy->next);
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
    return 0;
}