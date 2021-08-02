#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    vector<Node *> children;
};

Node *construct(int *arr, int n)
{
    Node *root = new Node();
    root->data = arr[0];
    stack<Node *> st;
    st.push(root);

    for (int i = 1; i < n; i++)
    {
        if (arr[i] == -1)
        {
            st.pop();
        }
        else
        {
            Node *nn = new Node();
            nn->data = arr[i];
            st.top()->children.push_back(nn);
            st.push(nn);
        }
    }
    return root;
}
Node *pred = nullptr;
Node *succ = nullptr;
Node *previous = nullptr;
Node *curr = nullptr;

void predSucs(Node *root, int data)
{
    if (root == nullptr)
    {
        return;
    }
    previous = curr;
    curr = root;
    if (curr->data == data)
    {
        pred = previous;
    }
    if (previous != nullptr && previous->data == data)
    {
        succ = curr;
    }
    //int a=*pred,b=*succ,c=*prev,d=*curr;

    for (int i = 0; i < root->children.size(); i++)
    {
        predSucs(root->children[i], data);
    }
}

int main()
{
    int n, m;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int data;
    cin >> data;
    Node *root = construct(arr, n);
    predSucs(root, data);
    if (pred != nullptr)
    {
        cout << "Predecessor = " << pred->data << endl;
    }
    else
    {
        cout << "Predecessor = Not found" << endl;
    }

    if (succ != nullptr)
    {
        cout << "Successor = " << succ->data << endl;
    }
    else
    {
        cout << "Successor = Not found" << endl;
    }
    return 0;
}
