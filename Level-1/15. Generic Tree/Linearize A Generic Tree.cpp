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
void display(Node *root)
{
    cout << root->data << " -> ";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << ", ";
    }
    cout << "." << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        display(root->children[i]);
    }
}

Node *getTail(Node *r)
{
    while (r->children.size() > 0)
    {
        for (int i = 0; i < r->children.size(); i++)
        {
            r = r->children[i];
        }
    }
    return r;
}

void linearize(Node *&root)
{
    for (int i = 0; i < root->children.size(); i++)
    {
        linearize(root->children[i]);
    }
    for (int i = root->children.size() - 1; i >= 1; i--)
    {
        Node *temp = root->children[i];
        Node *slt = getTail(root->children[i - 1]);
        slt->children.push_back(temp);
        root->children.pop_back();
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    Node *root = construct(arr, n);
    linearize(root);
    display(root);
    return 0;
}