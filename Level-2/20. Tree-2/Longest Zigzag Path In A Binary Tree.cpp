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

class Pair
{
public:
    int lzp;
    int rzp;
    int mzp;

    Pair()
    {
    }

    Pair(int lzp, int rzp, int mzp)
    {
        this->lzp = lzp;
        this->rzp = rzp;
        this->mzp = mzp;
    }
};

Pair lp(TreeNode *root)
{
    if (!root)
    {
        return Pair(-1, -1, 0);
    }

    Pair lcp = lp(root->left);
    Pair rcp = lp(root->right);

    Pair P;

    P.lzp = lcp.rzp + 1;
    P.rzp = rcp.lzp + 1;
    P.mzp = max(P.lzp, max(P.rzp, max(lcp.mzp, rcp.mzp)));
    return P;
}

int longestZigZagPath(TreeNode *root)

{
    Pair ans = lp(root);

    return ans.mzp;
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

    cout << longestZigZagPath(root) << endl;
}

int main()
{
    solve();
    return 0;
}