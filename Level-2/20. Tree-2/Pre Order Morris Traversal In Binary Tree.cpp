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
TreeNode *rightMostNode(TreeNode *left, TreeNode *root)
{
    while (left->right != NULL && left->right != root)
    {
        left = left->right;
    }
    return left;
}
vector<int> morrisPreTraversal(TreeNode *root)
{
    vector<int> v;
    if (!root)
        return v;
    TreeNode *left, *rmn;
    TreeNode *curr = root;
    while (curr)
    {
        left = curr->left;
        if (left == NULL)
        {
            v.push_back(curr->val);
            curr = curr->right;
        }
        else
        {
            rmn = rightMostNode(left, curr);
            if (rmn->right == NULL)
            {
                v.push_back(curr->val);
                rmn->right = curr;
                curr = curr->left;
            }
            else
            {
                rmn->right = NULL;
                curr = curr->right;
            }
        }
    }
    return v;
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

    vector<int> ans = morrisPreTraversal(root);

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