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
map<int, int> mp;
int idx;

TreeNode *buildTreeUtil(vector<int> &pre, vector<int> &in, int s, int e)
{
    if (s > e)
    {
        return nullptr;
    }

    int val = pre[idx];
    TreeNode *root = new TreeNode(val);
    idx++;
    int midx = mp[val];
    if (s == e)
    {
        return root;
    }
    root->left = buildTreeUtil(pre, in, s, midx - 1);
    root->right = buildTreeUtil(pre, in, midx + 1, e);

    return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    idx = 0;
    for (int i = 0; i < inorder.size(); i++)
    {
        mp[inorder[i]] = i;
    }
    return buildTreeUtil(preorder, inorder, 0, preorder.size() - 1);
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

    vector<int> in(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> in[i];
    }

    TreeNode *root = buildTree(pre, in);
    display(root);
}

int main()
{
    solve();
    return 0;
}