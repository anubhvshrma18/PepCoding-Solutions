#include <iostream>
using namespace std;

class ListNode
{
public:
  int val = 0;
  ListNode* next = nullptr;

  ListNode(int val)
  {
    this->val = val;
  }
};

ListNode* getNodeAt(ListNode* l,int idx){
    ListNode* temp =l;
    while(idx-- >0){
        temp=temp->next;

    }
    return temp;
}
// segregate over pivot index
ListNode* segregateOverPivot(ListNode* head,int pivot){
    ListNode* sh=new ListNode(-1);
    ListNode* gh=new ListNode(-1);
    ListNode* st=sh,*gt=gh;

    ListNode* pn = getNodeAt(head,pivot);
    int d=pn->val;

    ListNode* curr=head;
    while(curr){
        if(pn==curr){
        }
        else if(curr->val <=d){
            st->next=curr;
            st=st->next;
        }
        else{
            gt->next=curr;
            gt=gt->next;
        }
        curr=curr->next;
    }

    st->next = pn;
    pn->next = gh->next;

    gt->next=NULL;

    return sh->next;


}

void printList(ListNode* node)
{
  ListNode* curr = node;
  while (curr != nullptr)
  {
    cout << curr->val << " ";
    curr = curr->next;
  }
  cout << endl;
}

ListNode* createList(int n)
{
  ListNode* dummy = new ListNode(-1);
  ListNode* prev = dummy;
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
  int n, pivotIdx;
  cin >> n;
  ListNode* h1 = createList(n);
  cin >> pivotIdx;
  h1 = segregateOverPivot(h1, pivotIdx);
  printList(h1);

  return 0;
}