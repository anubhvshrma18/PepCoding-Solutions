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

vector<int> hr(TreeNode *root)
{
    if (!root)
    {
        vector<int> v(2);
        return v;
    }

    vector<int> lhr = hr(root->left);
    vector<int> rhr = hr(root->right);

    vector<int> ans(2);
    ans[0] = lhr[1] + rhr[1] + root->val;
    ans[1] = max(lhr[0], lhr[1]) + max(rhr[0], rhr[1]);

    return ans;
}

int HouseRobber(TreeNode *root)
{
    vector<int> ans = hr(root);
    return max(ans[0], ans[1]);
}

// input_Section_====================================================================

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
    cout << HouseRobber(root) << endl;
}

int main()
{
    solve();
    return 0;
}