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

int floor(Node *root, int data, int f)
{
    if (root == nullptr)
    {
        return INT_MIN;
    }
    if (root->data < data && root->data > f)
    {
        f = root->data;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        f = floor(root->children[i], data, f);
    }
    return f;
}

int KthLargest(Node *root, int k)
{
    if (root == nullptr)
    {
        return 0;
    }
    int fl = INT_MAX;
    for (int i = 0; i < k; i++)
    {
        int f = INT_MIN;
        fl = floor(root, fl, f);
    }

    return fl;
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
    cout << KthLargest(root, data);
    return 0;
}
