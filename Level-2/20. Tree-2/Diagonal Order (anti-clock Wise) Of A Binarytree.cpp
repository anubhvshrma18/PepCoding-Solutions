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

vector<vector<int>> diagonalOrder(TreeNode *root)
{
    queue<TreeNode *> que;
    que.push(root);
    vector<vector<int>> ans;
    while (que.size() != 0)
    {
        int size = que.size();
        vector<int> smallAns;
        while (size-- > 0)
        {
            TreeNode *node = que.front();
            que.pop();
            while (node != nullptr)
            {
                smallAns.push_back(node->val);
                if (node->right != nullptr)
                {
                    // add in que for next diagonal process.
                    que.push(node->right);
                }
                node = node->left; // move forward in respective diagonal.
            }
        }

        ans.push_back(smallAns);
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

    vector<vector<int>> ans = diagonalOrder(root);
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