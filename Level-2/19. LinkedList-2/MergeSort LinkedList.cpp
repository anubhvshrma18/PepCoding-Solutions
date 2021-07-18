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
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    if(!l1){
        return l2;
    }
    if(!l2){
        return l1;
    }
    
    if(l1->val < l2->val){
        l1->next=mergeTwoLists(l1->next,l2);
        return l1;
    }
    else{
        l2->next=mergeTwoLists(l1,l2->next);
        return l2;
    }
}

ListNode *midNode(ListNode *head)
{
    ListNode* slow=head , *fast=head;
    while(fast && fast->next && fast->next->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}



ListNode *mergeSort(ListNode *head)
{
    if(!head || !head->next){
        return head;
    }
    
    ListNode* firsthalf=head;
    ListNode* mid = midNode(head);
    ListNode* secondHalf = mid->next;
    mid->next=nullptr;
    
    return mergeTwoLists(mergeSort(firsthalf),mergeSort(secondHalf));
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

    ListNode *head = mergeSort(h1);
    printList(head);

    return 0;
}