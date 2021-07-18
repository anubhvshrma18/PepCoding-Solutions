//
// Created by anubhav on 4/19/2021.
//
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=nullptr;
        right=nullptr;
    }
};

//Node* construct(int* arr,int lo,int hi){
//    if(lo>hi){
//        return nullptr;
//    }
//    int mid=lo+(hi-lo)/2;
//    Node* m=new Node(arr[mid]);
//    m->left= construct(arr,lo,mid-1);
//    m->right= construct(arr,mid+1,hi);
//    return m;
//
//}
Node* construct(int *arr){
    Node* root=new Node(arr[0]);
    pair<Node*,int> p={root,1};

    stack<pair<Node*,int>> st;
    st.push(p);

    int idx=1;
    while(!st.empty()){
        // pair<Node*,int> pe=st.top();
        if(st.top().second==1){
            st.top().second++;
            if(arr[idx]!=-1){
                st.top().first->left=new Node(arr[idx]);
                pair<Node*,int> lp={st.top().first->left,1};
                st.push(lp);
            }
            else{
                st.top().first->left=nullptr;
            }
            idx++;
        }
        else if (st.top().second == 2) {
            st.top().second++;
            if (arr[idx] != -1) {
                st.top().first->right = new Node(arr[idx]);
                pair<Node*,int> rp={st.top().first->right,1};
                st.push(rp);
            } else {
                st.top().first->right = nullptr;
            }
            idx++;
        }
        else {
            st.pop();
        }

    }
    return root;
}
void display(Node* node) {
    if (node == nullptr) {
        return;
    }

    string str = " <- " + to_string(node->data) + " -> ";

    string left = (node->left == nullptr) ? "." :  "" + to_string(node->left->data);
    string right = (node->right == nullptr) ? "." : "" + to_string(node->right->data);

    str = left + str + right;
    cout << str << endl;

    display(node->left);
    display(node->right);
}
int min(Node* root){
    if(root->left== nullptr){
        return root->data;
    }
    return min(root->left);
}
int max(Node* root){
    if(root->right== nullptr){
        return root->data;
    }
    return max(root->right);
}
int sum(Node* root){
    if(root== nullptr){
        return 0;
    }
    int ls=sum(root->left);
    int rs=sum(root->right);

    return ls+ rs+root->data;
}
int size(Node* root){
    if(root== nullptr){
        return 0;
    }
    int ls= size(root->left);
    int rs= size(root->right);

    return ls+rs+1;
}
bool find(Node* root,int data){
    if(root== nullptr){
        return false;
    }
    if(root->data==data) {
        return true;
    }
    else if(data<root->data){
        return find(root->left,data);
    }
    else{
        return find(root->right,data);
    }

}
// method-1
//void add (Node* &root,int data){
//    if(root->left== nullptr && data < root->data){
//        Node* temp=new Node(data);
//        root->left=temp;
//        return;
//    }
//    if(root->right== nullptr && data > root->data){
//        Node* temp=new Node(data);
//        root->right=temp;
//        return;
//    }
//    if(data==root->data){
//        return;
//    }
//
//
//    if(data<root->data){
//        add(root->left,data);
//    }
//    else{
//        add(root->right,data);
//    }
//}
Node* add(Node* root,int data){
    if(root== nullptr){
        Node* temp=new Node(data);
        return temp;
    }
    if(data<root->data){
        root->left= add(root->left,data);
    }
    if(data>root->data){
        root->right= add(root->right,data);
    }

    return root;
}
Node* remove(Node* root,int data){
    if(root== nullptr){
        return nullptr;
    }
    if(data<root->data){
        root->left= remove(root->left,data);

    }
    else if(data>root->data){
        root->right=remove(root->right,data);
    }
    else{
        if(root->left!= nullptr&& root->right!= nullptr){
            int lmx=max(root->left);
            root->data=lmx;
            root->left=remove(root->left,lmx);
        }
        else if(root->left!= nullptr){
            return root->left;
        } else if(root->right!= nullptr){
            return root->right;
        }
        else{
            return nullptr;
        }
    }

    return root;
}
int sumi=0;
void replacewithsum(Node* &root){
    if(root==nullptr){
        return;
    }
    replacewithsum(root->right);
    int x=root->data;
    root->data=sumi;
    sumi+=x;
    replacewithsum(root->left);
    // this should not be done because we only need sum of nodes larger than current so therer is no need to do operation
    // on left tree we just need to function for traversal
//    int y=root->data;
//    root->data=sumi;
//    sumi+=y;
}
//vector<Node*> nodetorootpath(Node* root,int a){
//    if(root== nullptr){
//        vector<Node*> v;
//        return v;
//    }
//    if(root->data==a){
//        vector<Node*> v;
//        v.push_back(root);
//        return v;
//    }
//    vector<Node*>
//
//}
//void function
//void lca(Node* root,int a,int b){
//    if(root== nullptr){
//        return;
//    }
//    if(root->data > a && root->data > b){
//        ans=root->left->data;
//        lca(root->left,a,b);
//    }
//    else if(root->data < a && root->data < b){
//        ans=root->right->data;
//        lca(root->right,a,b);
//    }
//    else{
//
//    }
//}

//integer function
//int lca(Node* root,int a,int b){
//    if(root== nullptr){
//        return -1;
//    }
//    if(root->data > a && root->data > b){
//        int ans=lca(root->left,a,b);
//        return (ans!=-1)?ans:root->left->data;
//    }
//    else if(root->data < a && root->data < b){
//        int ans=lca(root->right,a,b);
//        return (ans!=-1)?ans:root->right->data;
//    }
//    else{
//        return root->data;
//    }
//}

// 1st method - Not optimised
//void printinrange(Node* root,int a,int b){
//    if(root== nullptr){
//        return;
//    }
//    if(root->data > a || root->data < b){
//        printinrange(root->left,a,b);
//    }
//    if(root->data >=a && root->data <= b){
//        cout << root->data << endl;
//    }
//    if(root->data < b) {
//        printinrange(root->right, a, b);
//    }
//}

// 2nd method - optimised method
//void printinrange(Node* root,int a,int b){
//    if(root==nullptr){
//        return;
//    }
//    if(a>root->data && b>root->data){
//        printinrange(root->right,a,b);
//    }
//    else if(a<root->data && b < root->data){
//        printinrange(root->left,a,b);
//    }
//    else{
//        printinrange(root->left,a,b);
//        cout << root->data << endl;
//        printinrange(root->right, a, b);
//    }
//}

// 1st method - Time Complexity - O(nlogn)
void targetSum(Node* root,Node* root1,int tar){
    if(root== nullptr){
        return;
    }
    targetSum(root->left,root1,tar);
    int lefttar=tar-root->data;
    if(find(root1,lefttar)){
        if(lefttar>root->data){
            cout << root->data << " " << lefttar << endl;
        }
    }
    targetSum(root->right,root1,tar);
}


int main(){
    int n;
    cin >> n;
    int v[n];
    for(int i=0;i<n;i++){
        string x;
        cin >> x;
        if(x=="n"){
            v[i]=-1;

        }
        else{
            v[i]=stoi(x);
        }
    }
    int a;
    cin >> a;
    Node* root= construct(v);
    targetSum(root,root,a);
}