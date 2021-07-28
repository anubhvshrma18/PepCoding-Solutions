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

TreeNode *one;
TreeNode *two;
TreeNode *pre;
void isvalidbst(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    isvalidbst(root->left);
    if (pre != nullptr && pre->val >= root->val)
    {
        if (!one)
        {
            one = pre;
        }
        two = root;
    }
    pre = root;
    isvalidbst(root->right);
}

void recoverTree(TreeNode *root)
{
    one = NULL, two = NULL, pre = NULL;
    isvalidbst(root);
    swap(one->val, two->val);
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

TreeNode *createTree(vector<int> &arr, vector<int> &IDX)
{
    if (IDX[0] > arr.size() || arr[IDX[0]] == -1)
    {
        IDX[0]++;
        return nullptr;
    }

    TreeNode *node = new TreeNode(arr[IDX[0]++]);
    node->left = createTree(arr, IDX);
    node->right = createTree(arr, IDX);

    return node;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> IDX(1, 0);
    TreeNode *root = createTree(arr, IDX);
    recoverTree(root);
    display(root);
}

int main()
{
    solve();
    return 0;
}