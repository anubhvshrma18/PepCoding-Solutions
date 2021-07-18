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
int size(ListNode* head){
    ListNode* temp=head;
    int cnt=0;
    while(temp){
        cnt++;
        temp=temp->next;
    }
    return cnt;
}

ListNode *reverseInKGroup(ListNode *head, int k)
{
    if(k==0){
        return head;
    }
    ListNode* aH=nullptr;
	ListNode* at=nullptr;
	ListNode* curr=head;
	int nrsf = size(head);

	while(nrsf >= k){
		ListNode* prev=nullptr;
		ListNode* oc = curr;

		int temp=k;
		while(temp-- > 0){
			ListNode* nex=curr->next;
			curr->next=prev;
			prev=curr;
			curr=nex;
		}

		if(aH==nullptr){
			// this is pre
			aH=prev;
			at=oc;
		}
		else{
			at->next = prev;
			at=oc;
		}

		nrsf-=k;
	}

	if(nrsf>0){
		at->next = curr;
	}

	return aH;
    
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
    int k;
    cin >> k;
    h1 = reverseInKGroup(h1, k);
    printList(h1);

    return 0;
}