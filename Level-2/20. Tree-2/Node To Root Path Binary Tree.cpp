#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class TreeNode
{
public:
  int val = 0;
  TreeNode* left = nullptr;
  TreeNode* right = nullptr;

  TreeNode(int val)
  {
    this->val = val;
  }
};

vector<TreeNode*> nodeToRootPath(TreeNode* root, int data)
{
    vector<TreeNode*> v;
    if(root==NULL){
        // vector<TreeNode*> v;
        return v;
    }
    
    if(root->val == data){
        vector<TreeNode*> v;
        v.push_back(root);
        return v;
    }
    
    vector<TreeNode*> lntrp=nodeToRootPath(root->left,data);
    if(lntrp.size()>0){
        lntrp.push_back(root);
        return lntrp;
    }
    
    vector<TreeNode*> rntrp=nodeToRootPath(root->right,data);
    if(rntrp.size()>0){
        rntrp.push_back(root);
        return rntrp;
    }
    
    return v;
}

// input_section=================================================

TreeNode* createTree(vector<int>& arr, vector<int>& IDX)
{

  if (IDX[0] > arr.size() || arr[IDX[0]] == -1)
  {
    IDX[0]++;
    return nullptr;
  }

  TreeNode* node = new TreeNode(arr[IDX[0]++]);
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
  TreeNode* root = createTree(arr, IDX);

  int data;
  cin >> data;
  vector<TreeNode*> ans = nodeToRootPath(root, data);
  if (ans.size() == 0)
    cout << endl;
  for (TreeNode* node : ans)
  {
    cout << node->val << " ";
  }
}

int main()
{
  solve();
  return 0;
}