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
    if (head == nullptr || head->next == nullptr)
        return head;

    ListNode *slow = head;
    ListNode *fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}
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
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode* rev1=reverse(l1);
    ListNode* rev2=reverse(l2);
    ListNode* dummy=nullptr;
    ListNode* p=dummy;
    ListNode* m=dummy;
    int carry=0;
    while(rev1 || rev2 || carry!=0){
        int x=carry;
        if(rev1){
            x+=rev1->val;
        }
        if(rev2){
            x+=rev2->val;
        }
        
        ListNode* nn=new ListNode(x%10);
        nn->next=dummy;
        dummy=nn;
        carry=x/10;
        if(rev1)
            rev1=rev1->next;
        if(rev2)
            rev2=rev2->next;
    
    }
    
    return dummy;
    
    
    
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

    ListNode *head = addTwoNumbers(head1, head2);
    printList(head);

    return 0;
}