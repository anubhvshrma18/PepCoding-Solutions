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

class levelPair
{
public:
    TreeNode *par = nullptr;
    int lb = -INT_MIN;
    int rb = INT_MAX;

    levelPair()
    {
    }

    levelPair(TreeNode *par, int lb, int rb)
    {
        this->par = par;
        this->lb = lb;
        this->rb = rb;
    }
};

TreeNode *constructBSTFromLevelOrder(vector<int> &arr)
{
    int i = 0;
    queue<levelPair *> q;
    TreeNode *root = NULL;
    levelPair *m = new levelPair();
    q.push(m);
    while (q.size() > 0 && i < arr.size())
    {
        levelPair *p = q.front();
        // TreeNode* pr=p->par;
        q.pop();

        if (arr[i] < p->lb || arr[i] > p->rb)
        {
            continue;
        }
        TreeNode *node = new TreeNode(arr[i]);
        i++;
        if (p->par == nullptr)
        {
            root = node;
        }
        else
        {

            if (p->par->val > node->val)
            {
                p->par->left = node;
            }
            else if (p->par->val < node->val)
            {
                p->par->right = node;
            }
        }
        levelPair *lp = new levelPair(node, p->lb, node->val);
        levelPair *rp = new levelPair(node, node->val, p->rb);
        q.push(lp);
        q.push(rp);
    }

    return root;

    // return ;
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

    TreeNode *root = constructBSTFromLevelOrder(pre);
    display(root);
}

int main()
{
    solve();
    return 0;
}