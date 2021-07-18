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
ListNode* reverse(ListNode* l1){
    if(!l1){
        return l1;
    }
        ListNode *curr=l1, *prev=nullptr,*nex=nullptr;
        while(curr){
            nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }
        return prev;
    }
ListNode *reverseInRange(ListNode *head, int left,int right)
{
    if(left==right ||head==nullptr ||head->next==nullptr){
        return head;
    }
    
    ListNode* tm=nullptr;
    if(left-1!=0){
        tm=head;
        left=left-1;
        while(--left && tm){
            tm=tm->next;
        }
    }
    ListNode* tm2=head;
    right=right-1;
    while(right-- && tm2){
        tm2=tm2->next;
    }
    ListNode* str=nullptr,*end=tm2;
    if(tm==nullptr){
        str=head;
    }
    else{
        str=tm->next;
    }
    tm2=tm2->next;
    // tm->next=nullptr;
    end->next=nullptr;
    
    ListNode* rev=reverse(str);
    // tm->next=rev;
    if(tm!=nullptr){
        tm->next=rev;
    }
    else{
        head=rev;
    }
    while(rev->next){
        rev=rev->next;
    }
    rev->next=tm2;
    
    return head;
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
    int str,end;
    cin>>str>>end;
    h1 = reverseInRange(h1, str,end);
    printList(h1);

    return 0;
}