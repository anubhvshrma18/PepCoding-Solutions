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

void addSingleChildParents(TreeNode *root, vector<int> &v)
{
    if (!root)
    {
        return;
    }

    if ((!root->left && root->right) || (root->left && !root->right))
    {
        v.push_back(root->val);
    }
    addSingleChildParents(root->left, v);
    addSingleChildParents(root->right, v);
}

vector<int> exactlyOneChild(TreeNode *root)
{
    vector<int> ans;
    addSingleChildParents(root, ans);
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

    vector<int> ans = exactlyOneChild(root);
    if (ans.size() == 0)
        cout << endl;
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