#include<bits/stdc++.h>
#include <iostream>
#include <vector>
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

int calc(TreeNode* root,int *mx){
    if(!root){
        return 0;
    }
    if(!root->left && !root->right){
        return root->val;
    }
    int lc=calc(root->left,mx);
    int rc=calc(root->right,mx);
    
    if(root->left && root->right){
        if(lc+rc+root->val >= *mx){
            *mx=lc+rc+root->val;
        }
        
        return max(lc,rc)+root->val;
    }
    
    return root->left?lc+root->val:rc+root->val;
    
}
int maxPathSum(TreeNode* root)
{
    int mx=INT_MIN;
    int x=calc(root,&mx);
    if(mx==INT_MIN){
        return x;   
    }
    else{
        return mx;
    }
}

// input_Section=================================================

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
  int tar;
  cin >> tar;
  vector<int> IDX(1, 0);
  TreeNode* root = createTree(arr, IDX);
  cout << maxPathSum(root) << endl;
}

int main()
{
  solve();
  return 0;
}