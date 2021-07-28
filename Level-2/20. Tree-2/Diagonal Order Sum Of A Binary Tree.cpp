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

vector<int> DiagonalOrderSum(TreeNode *root)
{
    queue<TreeNode *> Q;
    TreeNode *p;
    Q.push(root);
    vector<int> diagonalNode;
    while (!Q.empty())
    {
        int sum = 0, size = Q.size();
        while (size-- > 0)
        {
            p = Q.front();
            Q.pop();
            while (p)
            {
                sum += p->val;
                if (p->left)
                {
                    Q.push(p->left);
                }
                p = p->right;
            }
        }
        diagonalNode.push_back(sum);
    }
    return diagonalNode;
}

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

    vector<int> ans = DiagonalOrderSum(root);
    for (int j : ans)
    {
        cout << j << " ";
    }
}

int main()
{
    solve();
    return 0;
}