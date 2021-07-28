#include <bits/stdc++.h>
using namespace std;

struct Node{
	int val;
	Node* left;
	Node* right;

	Node(int val){
		this->val=val;
		left=NULL;
		right=NULL;
	}
};

static Node* pre=NULL;

void btoDLL_(Node* root,Node** head){
	if(root==NULL){
		return;
	}

	btoDLL_(root->left,head);
	if(pre==NULL){
		*head=root;
	}
	else{
		pre->right = root;
		root->left = pre;
	}

	pre=root;
	btoDLL_(root->right,head);
}

Node* btoDLL(Node* root){
	pre=NULL;
	Node* head=NULL;
	btoDLL_(root,&head);
	head->left=pre;
	pre->right = head;
	return head;
}



void display(Node* node) {
	Node* head=node;
	while (node != NULL) {
	  cout << node->val  <<  " ";
	  node = node->right;
	  if(node==head){
	  	break;
	  }
	}

}



Node* constructFromInorder(vector<int> &in, int si, int ei) {
	if (si > ei)
	  return NULL;

	int mid = (si + ei) / 2;
	Node* node = new Node(in[mid]);

	node->left = constructFromInorder(in, si, mid - 1);
	node->right = constructFromInorder(in, mid + 1, ei);

	return node;
}



void solve(){
	int n;
	cin >> n;
	vector<int> in(n);
	for(int i=0;i<n;i++){
		cin >> in[i];
	}
	Node* root=constructFromInorder(in,0,n-1);
	root = btoDLL(root);
	display(root);
}


int main(){
	solve();
}