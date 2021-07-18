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

bool isCyclePresentInLL(ListNode *head)
{
    ListNode* slow=head,*fast=head;
    // bool loop=false;
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
        if(slow == fast){
            return true;
        }
        
    }
    return false;
}

ListNode *takeInput()
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
    int idx;
    cin >> idx;
    if (idx >= 0)
    {
        ListNode *curr = dummy->next;
        while (idx-- > 0)
        {
            curr = curr->next;
        }
        prev->next = curr;
    }
    return dummy->next;
}

int main()
{
    ListNode *head = takeInput();
    cout << (boolalpha) << isCyclePresentInLL(head) << endl;
    return 0;
}