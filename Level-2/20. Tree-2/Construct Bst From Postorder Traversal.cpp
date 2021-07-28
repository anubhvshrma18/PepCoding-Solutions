#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val = 0;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;

    TreeNode(int val)
    {
        this->val = val;
    }
};
int idx;
TreeNode *build(vector<int> &pre, int minval, int maxval)
{
    if (idx < 0 || pre[idx] < minval || pre[idx] > maxval)
    {
        return NULL;
    }
    // if(pre[idx] > minval && pre[idx] < maxval){

    // }
    else
    {
        TreeNode *root = new TreeNode(pre[idx]);
        idx--;
        root->right = build(pre, root->val, maxval);
        root->left = build(pre, minval, root->val);

        return root;
    }
}

TreeNode *bstFromPostorder(vector<int> &preorder)
{
    idx = preorder.size() - 1;
    return build(preorder, INT_MIN, INT_MAX);
}

// input_Section_====================================================================

void display(TreeNode *node)
{
    if (node == nullptr)
        return;

    string str = "";
    str += ((node->left != nullptr ? to_string(node->left->val) : "."));
    str += (" -> " + to_string(node->val) + " <- ");
    str += ((node->right != nullptr ? to_string(node->right->val) : "."));

    cout << str << endl;

    display(node->left);
    display(node->right);
}

void solve()
{
    int n;
    cin >> n;
    vector<int> pre(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> pre[i];
    }

    TreeNode *root = bstFromPostorder(pre);
    display(root);
}

int main()
{
    solve();
    return 0;
}