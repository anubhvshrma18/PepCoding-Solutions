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
    int data;
    cin >> data;
    Node* root= construct(v);
    cout << size(root) <<"\n"<< sum(root) << "\n" << max(root) << "\n"<< min(root) <<  "\n";
    if(find(root,data)){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }
    //display(root);
}