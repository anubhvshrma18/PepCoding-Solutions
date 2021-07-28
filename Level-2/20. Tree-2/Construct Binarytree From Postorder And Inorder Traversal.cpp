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
TreeNode *bTU(vector<int> &in, vector<int> &pos, int s, int e)
{
    if (s > e)
    {
        return nullptr;
    }
    int val = pos[idx];
    TreeNode *root = new TreeNode(val);
    idx--;

    if (s == e)
    {
        return root;
    }
    root->right = bTU(in, pos, mp[val] + 1, e);
    root->left = bTU(in, pos, s, mp[val] - 1);
    return root;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    idx = postorder.size() - 1;
    for (int i = 0; i < inorder.size(); i++)
    {
        mp[inorder[i]] = i;
    }
    return bTU(inorder, postorder, 0, postorder.size() - 1);
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
    vector<int> post(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> post[i];
    }

    vector<int> in(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> in[i];
    }

    TreeNode *root = buildTree(in, post);
    display(root);
}

int main()
{
    solve();
    return 0;
}