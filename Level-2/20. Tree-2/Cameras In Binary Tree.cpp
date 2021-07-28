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

int cam = 0;

int min(TreeNode *root)
{
    if (!root)
        return 1;

    int lc = min(root->left);
    int rc = min(root->right);

    if (lc == -1 || rc == -1)
    {
        cam++;
        return 0;
    }

    if (lc == 0 || rc == 0)
    {
        return 1;
    }
    return -1;
}

int MinCamerasInBT(TreeNode *root)
{
    if (!root)
    {
        return 0;
    }
    if (min(root) == -1)
    {
        cam++;
    }
    return cam;
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
    cout << MinCamerasInBT(root) << endl;
}

int main()
{
    solve();
    return 0;
}