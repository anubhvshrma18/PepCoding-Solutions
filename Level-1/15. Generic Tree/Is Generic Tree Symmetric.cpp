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

bool areMirror(Node *root1, Node *root2)
{
    if (root1->children.size() != root2->children.size())
    {
        return false;
    }

    for (int i = 0; i < root1->children.size(); i++)
    {
        if (!areMirror(root1->children[i], root2->children[root2->children.size() - i - 1]))
        {
            return false;
        }
    }
    return true;
}

bool isSymmetric(Node *root)
{
    //    if(root->children[0]!=root->children[root->children.size()-1]){
    //        return false;
    //    }
    //
    //    for(int i=0;i<root->children.size();i++){
    //        if(!isSymmetric(root->children[i])){
    //            return false;
    //        }
    //
    //    }
    //    return true;
    return areMirror(root, root);
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
    //    Node *root2 = construct(arr2,m);
    if (isSymmetric(root))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    return 0;
}
