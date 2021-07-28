#include <iostream>
#include <vector>
#include <queue>
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

// Encodes a tree to a single string.
string serialize(TreeNode *root)
{
    if (!root)
    {
        return "n";
    }

    string ls = serialize(root->left);
    string rs = serialize(root->right);

    return to_string(root->val) + " " + ls + " " + rs;
}

int idx;
// Decodes your encoded data to tree.
TreeNode *deserialize(vector<string> &v)
{
    if (v[idx] == "n")
    {
        idx++;
        return nullptr;
    }
    else
    {
        TreeNode *node = new TreeNode(stoi(v[idx]));
        idx++;
        node->left = deserialize(v);
        node->right = deserialize(v);
        return node;
    }
}

TreeNode *deserialize(string s)
{
    vector<string> vec;
    stringstream ss(s);
    string word;
    while (ss >> word)
    {
        vec.push_back(word);
    }

    idx = 0;

    return deserialize(vec);
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

    string s = serialize(root);
    display(deserialize(s));
}

int main()
{
    solve();
    return 0;
}