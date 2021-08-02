#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    vector<Node *> children;
};
struct Pair
{
    int sum;
    Node *node;
    Pair(int x, Node *n)
    {
        sum = x;
        node = n;
    }
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

int dia = 0;
int diameter(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int mxd = -1, smxd = -1;
    for (int i = 0; i < root->children.size(); i++)
    {
        int x = diameter(root->children[i]);
        if (mxd < x)
        {
            smxd = mxd;
            mxd = x;
        }
        else if (x > smxd)
        {
            smxd = x;
        }
    }
    if (mxd + smxd + 2 > dia)
    {
        dia = mxd + smxd + 2;
    }
    return mxd + 1;
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
    diameter(root);
    cout << dia << endl;
    return 0;
}