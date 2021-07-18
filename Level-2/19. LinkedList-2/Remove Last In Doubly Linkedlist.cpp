#include <bits/stdc++.h>
using namespace std;

class DoublyLinkedList
{
  class Node
  {
  public:
    int data = 0;
    Node* prev = nullptr;
    Node* next = nullptr;

    Node(int data)
    {
      this->data = data;
    }
  };

  Node* head = nullptr;
  Node* tail = nullptr;
  int size = 0;

public:
  void display()
  {
    string str = "";
    Node* curr = this->head;
    str += "[";
    while (curr != nullptr)
    {
      str += to_string(curr->data);
      if (curr->next != nullptr)
        str += ", ";
      curr = curr->next;
    }
    str += "]";

    cout << str<<endl;
  }

private:
  void addFirstNode(Node* node)
  {
    if (this->size == 0)
      this->head = this->tail = node;
    else
    {
      node->next = this->head;
      this->head->prev = node;
      this->head = node;
    }
    this->size++;
  }
  
  bool ListisEmpty(){
      if(this->size == 0){
          cout << "ListIsEmpty: ";
          return true;
      }
      return false;
  }

public:
  void addFirst(int data)
  {
    Node* node = new Node(data);
    addFirstNode(node);
  }

  void addLast(int data)
  {
    // complete this function.
    Node* nn=new Node(data);
    if(tail==NULL){
        head=tail=nn;
    }
    else{
        tail->next=nn;
        nn->prev=tail;
        tail=nn;
    }
    size++;
  }
  
  int removeF(){
      if(ListisEmpty()){
          return -1;
      }
      int d=head->data; 
      if(size==1){
        head = tail=NULL;
        size=0;
      }
      else{
        //   cout << head->data << endl;
          Node* temp=head;
          head=head->next;
          temp->next=NULL;
          head->prev=NULL;
          size--;
          
      }
      return d;
  }
};

int main()
{
  DoublyLinkedList dll;
  string word;
  cin >> word;
  while (word!="stop")
  {
    if (word == "addFirst")
    {
      int data;
      cin >> data;
      dll.addFirst(data);
    }
    else if (word == "addLast")
    {
      int data;
      cin >> data;
      dll.addLast(data);
    }
    else if(word == "removeFirst"){
        int ans=dll.removeF();
        cout << ans << endl;
    }
    cin >> word;
  }

  dll.display();

  return 0;
}