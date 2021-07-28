#include <iostream>
#include <vector>
#include <queue>
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

int width(TreeNode *root)
{
    if (!root)
    {
        return 0;
    }

    queue<pair<TreeNode *, int>> q;
    q.push({root, 0});
    int ans = 0, minhd = 1e9, maxhd = -1e9;
    while (q.size() > 0)
    {
        TreeNode *node = q.front().first;
        int hd = q.front().second;
        q.pop();
        minhd = min(minhd, hd);
        maxhd = max(maxhd, hd);
        if (node->left)
        {
            q.push({node->left, hd - 1});
        }
        if (node->right)
        {
            q.push({node->right, hd + 1});
        }
    }
    ans = max(ans, maxhd - minhd + 1);
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

    cout << width(root) << endl;
}

int main()
{
    solve();
    return 0;
}