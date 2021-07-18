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

int lengthOfLL(ListNode *node)
{
    if (node == nullptr)
        return 0;

    int len = 0;
    while (node != nullptr)
    {
        node = node->next;
        len++;
    }

    return len;
}

ListNode *IntersectionNodeInTwoLL(ListNode *headA, ListNode *headB)
{
    if (headA == nullptr || headB == nullptr)
        return nullptr;

    int l1 = lengthOfLL(headA);
    int l2 = lengthOfLL(headB);

    ListNode *biggerList = l1 > l2 ? headA : headB;
    ListNode *smallerList = l1 > l2 ? headB : headA;

    int diff = max(l1, l2) - min(l1, l2);
    while (diff-- > 0)
        biggerList = biggerList->next;

    while (biggerList != smallerList)
    {
        biggerList = biggerList->next;
        smallerList = smallerList->next;
    }

    return biggerList;
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

int main()
{
    int n,idx;
    cin >> n;
    ListNode *head1 = makeList(n);
    cin >> idx;
    
    int m;
    cin >> m;
    ListNode *head2 = makeList(m);

    if (idx >= 0)
    {
        ListNode *curr = head1;

        while (idx-- > 0)
            curr = curr->next;

        ListNode *prev = head2;
        while (prev->next != nullptr)
            prev = prev->next;

        prev->next = curr;
    }

    ListNode *ans = IntersectionNodeInTwoLL(head1, head2);
    cout << (ans != nullptr ? ans->val : -1) << endl;
    return 0;
}