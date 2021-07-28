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
TreeNode *build(vector<int> &pre, int pres, int pree, vector<int> &post, int poss, int pose)
{
    if (pres > pree || poss > pose)
    {
        return nullptr;
    }
    if (pres == pree || poss == pose)
    {
        return new TreeNode(pre[pres]);
    }

    TreeNode *root = new TreeNode(pre[pres]);
    int idx = poss;
    while (post[idx] != pre[pres + 1])
    {
        idx++;
    }

    int colse = idx - poss + 1;

    root->left = build(pre, pres + 1, pres + colse, post, poss, idx);
    root->right = build(pre, pres + colse + 1, pree, post, idx + 1, pose - 1);

    return root;
}

TreeNode *constructFromPrePost(vector<int> &pre, vector<int> &post)
{
    int n = pre.size();
    return build(pre, 0, n - 1, post, 0, n - 1);
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

    vector<int> pre(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> pre[i];
    }

    TreeNode *root = constructFromPrePost(pre, post);
    display(root);
}

int main()
{
    solve();
    return 0;
}