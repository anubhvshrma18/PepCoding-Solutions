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

int subtreesum(Node *root, Node *&sum, Node *&y)
{
    if (root == nullptr)
    {
        return 0;
    }
    int x = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        x += subtreesum(root->children[i], sum, y);
    }
    x += root->data;
    if (sum->data < x)
    {
        y = root;
        sum->data = x;
    }
    return x;
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
    Node *root = construct(arr, n);
    Node *sum = new Node();
    Node *y = nullptr;
    sum->data = INT_MIN;
    subtreesum(root, sum, y);
    cout << y->data << "@" << sum->data << endl;
    return 0;
}
