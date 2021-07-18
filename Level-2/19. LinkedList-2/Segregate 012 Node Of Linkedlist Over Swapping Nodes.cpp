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

ListNode *segregate012(ListNode *head)
{
    ListNode* zeroH=NULL,*zeroT=NULL,*oneH=NULL,*oneT=NULL,*twoH=NULL,*twoT=NULL;
    ListNode* curr=head;
    while(curr){
        if(curr->val==0){
            if(zeroH==NULL){
                zeroH=zeroT=curr;
            }
            else{
                zeroT->next=curr;
                zeroT=zeroT->next;
            }
        }
        else if(curr->val==1){
            if(oneH==NULL){
                oneH=oneT=curr;
            }
            else{
                oneT->next=curr;
                oneT=oneT->next;
            }
        }
        else{
            if(twoH==NULL){
                twoH=twoT=curr;
            }
            else{
                twoT->next=curr;
                twoT=twoT->next;
            }
        }
        curr=curr->next;
    }

    if(zeroH){
        if(oneH){
            zeroT->next=oneH;
            oneT->next=twoH;
        }
        else{
            zeroT->next=twoH;
        }
        
        if(twoT){
            twoT->next=NULL;
        }
        return zeroH;
    }
    else if(oneH){
        oneT->next=twoH;
        if(twoT){
            twoT->next=NULL;
        }
        return oneH;
    }
    else if(twoH){
        twoT->next=NULL;
        return twoH;
    }
    

    // return zeroH;    
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
    h1 = segregate012(h1);
    printList(h1);

    return 0;
}