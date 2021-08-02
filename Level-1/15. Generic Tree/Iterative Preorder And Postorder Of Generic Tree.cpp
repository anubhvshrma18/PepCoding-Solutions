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

void traversal(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    stack<pair<Node *, int>> st;
    vector<int> pre, post;
    st.push({root, -1});
    pre.push_back(root->data);
    while (st.size() > 0)
    {
        if (st.top().second < st.top().first->children.size() || st.top().second == -1)
        {
            st.top().second++;
            if (st.top().second < st.top().first->children.size())
            {
                pre.push_back(st.top().first->children[st.top().second]->data);
                st.push({st.top().first->children[st.top().second], -1});
            }
        }
        else
        {
            post.push_back(st.top().first->data);
            st.pop();
        }
    }

    for (auto x : pre)
    {
        cout << x << " ";
    }
    cout << endl;
    for (auto x : post)
    {
        cout << x << " ";
    }
    cout << endl;
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
    traversal(root);
    return 0;
}
