#include <iostream>
#include <vector>
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

TreeNode *build(vector<int> &in, int st, int en)
{
    if (st > en)
    {
        return nullptr;
    }
    int md = st + (en - st) / 2;
    TreeNode *root = new TreeNode(in[md]);

    root->left = build(in, st, md - 1);
    root->right = build(in, md + 1, en);

    return root;
}

TreeNode *constructFromInOrder(vector<int> &in)
{
    return build(in, 0, in.size() - 1);
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
    vector<int> in(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> in[i];
    }

    TreeNode *root = constructFromInOrder(in);
    display(root);
}

int main()
{
    solve();
    return 0;
}