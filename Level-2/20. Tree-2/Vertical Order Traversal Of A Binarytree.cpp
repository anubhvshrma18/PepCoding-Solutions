#include <iostream>
#include <vector>
#include <queue>
#include <map>
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

vector<vector<int>> verticalOrderTraversal(TreeNode *root)
{
    vector<vector<int>> ans;
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
        vector<int> v;
        for (int i : x.second)
        {
            v.push_back(i);
        }
        ans.push_back(v);
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

    vector<vector<int>> ans = verticalOrderTraversal(root);
    int idx = 0;
    for (vector<int> &i : ans)
    {
        cout << idx++ << " -> ";
        for (int j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

int main()
{
    solve();
    return 0;
}