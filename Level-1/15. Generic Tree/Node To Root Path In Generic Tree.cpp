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

vector<Node *> nodetorootpath(Node *root, int data)
{
    if (root == nullptr)
    {
        vector<Node *> n;
        return n;
    }

    if (root->data == data)
    {
        vector<Node *> nn;
        nn.push_back(root);
        return nn;
    }

    for (int i = 0; i < root->children.size(); i++)
    {
        vector<Node *> res = nodetorootpath(root->children[i], data);
        if (res.size() > 0)
        {
            res.push_back(root);
            return res;
        }
    }
    vector<Node *> s;
    return s;
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
    int data;
    cin >> data;
    Node *root = construct(arr, n);
    vector<Node *> ans = nodetorootpath(root, data);
    int cnt = 0;
    cout << "[";
    for (auto x : ans)
    {
        if (cnt == ans.size() - 1)
        {
            cout << x->data;
            break;
        }
        cout << x->data << ", ";
        cnt++;
    }
    cout << "]" << endl;
    return 0;
}