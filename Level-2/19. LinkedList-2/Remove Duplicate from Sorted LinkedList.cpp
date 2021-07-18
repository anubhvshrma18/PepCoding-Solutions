#include <iostream>
using namespace std;

class ListNode{
public:
  int val = 0;
  ListNode* next = nullptr;

  ListNode(int val)
  {
    this->val = val;
  }
};
void addLast(){
    
}
ListNode* removeDuplicates(ListNode* head)
{
  if(!head || !head->next){
      return head;
  }
  int v=-1;
  ListNode* dummy=new ListNode(-1);
  ListNode* c=dummy;
  ListNode* curr=head;
  while(curr){
      if(curr->val!=v){
        c->next=curr;
        c=c->next;
        v=curr->val;
      }
      curr=curr->next;
  }
  c->next=nullptr;
  return dummy->next;
  
}
// Input_code===================================================

ListNode* makeList(int n)
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

int main()
{
  int n;
  cin >> n;
  ListNode* head = makeList(n);

  head = removeDuplicates(head);
  printList(head);

  return 0;
}