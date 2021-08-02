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

int c = INT_MAX;
int f = INT_MIN;
void ceilandfloor(Node *root, int data)
{
    if (root == nullptr)
    {
        return;
    }

    if (root->data > data && root->data < c)
    {
        c = root->data;
    }
    if (root->data < data && root->data > f)
    {
        f = root->data;
    }

    for (int i = 0; i < root->children.size(); i++)
    {
        ceilandfloor(root->children[i], data);
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
    ceilandfloor(root, data);
    cout << "CEIL = " << c << "\nFLOOR = " << f << endl;

    return 0;
}
