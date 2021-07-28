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

vector<int> TopView(TreeNode *root)
{
    vector<int> ans;
    if (!root)
    {
        return ans;
    }
    map<int, vector<int>> mp;
    queue<pair<int, TreeNode *>> q;
    q.push({0, root});
    while (q.size() > 0)
    {
        TreeNode *node = q.front().second;
        int hd = q.front().first;
        q.pop();
        mp[hd].push_back(node->val);

        if (node->left)
        {
            q.push({hd - 1, node->left});
        }
        if (node->right)
        {
            q.push({hd + 1, node->right});
        }
    }

    for (auto x : mp)
    {
        ans.push_back(x.second[0]);
    }
    return ans;
}

// input_section=================================================

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

    vector<int> ans = TopView(root);

    for (int i : ans)
    {
        cout << i << " ";
    }
}

int main()
{
    solve();
    return 0;
}