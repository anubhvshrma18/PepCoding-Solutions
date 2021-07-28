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
int cnt;
void addSingleChildParents(TreeNode *root)
{
    if (!root)
    {
        return;
    }

    if ((!root->left && root->right) || (root->left && !root->right))
    {
        cnt++;
    }
    addSingleChildParents(root->left);
    addSingleChildParents(root->right);
}

int countExactlyOneChild(TreeNode *node)
{
    cnt = 0;
    addSingleChildParents(node);
    return cnt;
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

    int data;
    cin >> data;
    int ans = countExactlyOneChild(root);
    cout << ans << endl;
}

int main()
{
    solve();
    return 0;
}