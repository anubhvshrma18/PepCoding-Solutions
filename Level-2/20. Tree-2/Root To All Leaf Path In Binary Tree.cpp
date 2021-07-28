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

void path(TreeNode* root,vector<int> &v,vector<vector<int>> &ap){
    if(root==NULL){
        return;
    }
    if(root->left==NULL && root->right==NULL){
        v.push_back(root->val);
        ap.push_back(v);
        v.pop_back();
        return;
    }
    
    v.push_back(root->val);
    path(root->left,v,ap);
    path(root->right,v,ap);
    v.pop_back();
}



vector<vector<int>> rootToAllLeafPath(TreeNode* root)
{
    vector<vector<int>> ap;
    vector<int> v;
    path(root,v,ap);
    return ap;
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

  vector<vector<int>> ans = rootToAllLeafPath(root);
  if (ans.size() == 0)
    cout << endl;
  for (auto al: ans)
  {
    for (int ele : al){
        cout << ele << " ";  
    }
      
    cout << endl;
  }
}

int main()
{
  solve();
  return 0;
}