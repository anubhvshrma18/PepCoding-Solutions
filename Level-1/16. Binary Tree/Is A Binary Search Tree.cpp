//
// Created by anubhav on 4/13/2021.
//
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

Node *construct(int *arr)
{
    Node *root = new Node(arr[0]);
    pair<Node *, int> p = {root, 1};

    stack<pair<Node *, int>> st;
    st.push(p);

    int idx = 1;
    while (!st.empty())
    {
        // pair<Node*,int> pe=st.top();
        if (st.top().second == 1)
        {
            st.top().second++;
            if (arr[idx] != -1)
            {
                st.top().first->left = new Node(arr[idx]);
                pair<Node *, int> lp = {st.top().first->left, 1};
                st.push(lp);
            }
            else
            {
                st.top().first->left = nullptr;
            }
            idx++;
        }
        else if (st.top().second == 2)
        {
            st.top().second++;
            if (arr[idx] != -1)
            {
                st.top().first->right = new Node(arr[idx]);
                pair<Node *, int> rp = {st.top().first->right, 1};
                st.push(rp);
            }
            else
            {
                st.top().first->right = nullptr;
            }
            idx++;
        }
        else
        {
            st.pop();
        }
    }
    return root;
}

void display(Node *node)
{
    if (node == nullptr)
    {
        return;
    }

    string str = " <- " + to_string(node->data) + " -> ";

    string left = (node->left == nullptr) ? "." : "" + to_string(node->left->data);
    string right = (node->right == nullptr) ? "." : "" + to_string(node->right->data);

    str = left + str + right;
    cout << str << endl;

    display(node->left);
    display(node->right);
}

void traversal(Node *root)
{
    string pre = "";
    string post = "";
    string in = "";
    stack<pair<Node *, int>> st;

    pair<Node *, int> p = {root, 0};
    st.push(p);
    while (st.size() > 0)
    {
        // pair<Node* , int> p=st.top();
        if (st.top().second == 0)
        {
            pre += to_string(st.top().first->data) + " ";
            st.top().second++;
            if (st.top().first->left != nullptr)
            {
                pair<Node *, int> x = {st.top().first->left, 0};
                st.push(x);
            }
        }
        else if (st.top().second == 1)
        {
            in += to_string(st.top().first->data) + " ";
            st.top().second++;
            if (st.top().first->right != nullptr)
            {
                pair<Node *, int> x = {st.top().first->right, 0};
                st.push(x);
            }
        }
        else
        {
            post += to_string(st.top().first->data) + " ";
            st.pop();
        }
    }

    cout << pre << "\n"
         << in << "\n"
         << post << endl;
}

int size(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    return size(root->left) + size(root->right) + 1;
}

int sum(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    int leftsum = sum(root->left);
    int rightsum = sum(root->right);

    return root->data + leftsum + rightsum;
}

int height(Node *root)
{
    if (root == nullptr)
    {
        return -1;
    }

    return max(height(root->left), height(root->right)) + 1;
}

int max(Node *root)
{
    if (root == nullptr)
    {
        return INT_MIN;
    }

    int leftmax = max(root->left);
    int rightmax = max(root->right);

    return max(root->data, max(leftmax, rightmax));
}

int min(Node *root)
{
    if (root == nullptr)
    {
        return INT_MAX;
    }
    int leftmin = min(root->left);
    int rightmin = min(root->right);

    return min(root->data, min(leftmin, rightmin));
}

void levelOrder(Node *root)
{
    queue<Node *> q;
    q.push(root);
    while (q.size() > 0)
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            cout << q.front()->data << " ";

            if (q.front()->left)
            {
                q.push(q.front()->left);
            }
            if (q.front()->right)
            {
                q.push(q.front()->right);
            }

            q.pop();
        }

        cout << endl;
    }
}

bool isPresent(Node *root, int d)
{
    if (root == nullptr)
    {
        return false;
    }
    if (root->data == d)
    {
        return true;
    }

    bool checkLeft = isPresent(root->left, d);
    bool checkRight = isPresent(root->right, d);

    if (checkLeft || checkRight)
    {
        return true;
    }
    else
    {
        return false;
    }
}

vector<Node *> nodetorootpath(Node *root, int data)
{
    if (root == nullptr)
    {
        vector<Node *> n;
        return n;
    }

    if (root->data == data)
    {
        vector<Node *> n;
        n.push_back(root);
        return n;
    }

    vector<Node *> ans = nodetorootpath(root->left, data);

    if (ans.size() > 0)
    {
        ans.push_back(root);
        return ans;
    }
    ans = nodetorootpath(root->right, data);
    if (ans.size() > 0)
    {
        ans.push_back(root);
        return ans;
    }
    return ans;
}

void printKLevelsDown(Node *root, int k, Node *hurdle)
{
    if (root == nullptr || root == hurdle)
    {
        return;
    }

    if (k == 0)
    {
        cout << root->data << endl;
        return;
    }

    printKLevelsDown(root->left, k - 1, hurdle);
    printKLevelsDown(root->right, k - 1, hurdle);
}

void KFar(Node *root, int x, int k)
{
    vector<Node *> ntrp = nodetorootpath(root, x);
    Node *hurdle = nullptr;

    for (int i = 0; i < ntrp.size(); i++)
    {
        Node *temp = ntrp[i];
        printKLevelsDown(temp, k - i, hurdle);
        hurdle = temp;
    }
}

void pathtoleaffromroot(Node *root, string path, int sum, int lo, int hi)
{
    if (root == nullptr)
    {
        return;
    }
    if (root->left == nullptr && root->right == nullptr)
    {
        sum += root->data;
        path += to_string(root->data) + " ";
        if (sum > lo && sum < hi)
        {
            cout << path << endl;
        }
        return;
    }

    pathtoleaffromroot(root->left, path + to_string(root->data) + " ", sum + root->data, lo, hi);
    pathtoleaffromroot(root->right, path + to_string(root->data) + " ", sum + root->data, lo, hi);
}

void printsinglenodes(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    if (root->left == nullptr)
    {
        if (root->right != nullptr)
        {
            cout << root->right->data << endl;
        }
    }
    else
    {
        if (root->right == nullptr)
        {
            cout << root->left->data << endl;
        }
    }

    printsinglenodes(root->left);
    printsinglenodes(root->right);
}

void leftclone(Node *&root)
{
    if (root == nullptr)
    {
        return;
    }
    leftclone(root->left);
    leftclone(root->right);
    Node *nn = new Node(root->data);
    Node *temp = root->left;
    root->left = nn;
    nn->left = temp;
}

void removeLeftClone(Node *&root)
{
    if (root == nullptr || root->left == nullptr)
    {
        return;
    }
    removeLeftClone(root->left);
    removeLeftClone(root->right);

    if (root->left->data == root->data)
    {
        Node *temp = root->left;
        root->left = temp->left;
        free(temp);
    }
}

int tilt(Node *root)
{
    if (root->left == nullptr && root->right == nullptr)
    {
        return 0;
    }
    if (root->left == nullptr)
    {
        return abs(root->right->data);
    }
    if (root->right == nullptr)
    {
        return abs(root->left->data);
    }

    int tiltleft = tilt(root->left);
    int tiltright = tilt(root->right);

    return tiltleft + tiltright + abs(sum(root->left) - sum(root->right));
}

int diameter(Node *root)
{
    if (root == nullptr)
    {
        return 1;
    }

    int lf = height(root->left);
    int rl = height(root->right);

    int ld = diameter(root->left);
    int rd = diameter(root->right);

    return max(lf + rl + 2, max(ld, rd));
}

bool isBalanced(Node *root)
{
    if (root == nullptr)
    {
        return true;
    }

    bool lf = isBalanced(root->left);
    bool rl = isBalanced(root->right);

    return lf && rl && (abs(height(root->left) - height(root->right)) <= 1);
}

// 1st method
//bool isBST(Node* root){
//    if(root== nullptr){
//        return true;
//    }
//    if(root->left==nullptr && root->right== nullptr){
//        return true;
//    }
//    bool isleftbst= isBST(root->left);
//    bool isrightbst= isBST(root->right);
//
//    bool check= false;
//    if(max(root->left) < root->data && min(root->right) > root->data){
//        check= true;
//    }
//
//    return isleftbst && isrightbst && check;
//}

// 2nd method
bool isBSTHelper(Node *root, int mn, int mx)
{
    if (root == nullptr)
    {
        return true;
    }

    if (root->data <= mn)
    {
        return false;
    }

    if (root->data >= mx)
    {
        return false;
    }

    return isBSTHelper(root->left, mn, root->data) && isBSTHelper(root->right, root->data, mx);
}
bool isBST(Node *root)
{

    return isBSTHelper(root, INT_MIN, INT_MAX);
}

int main()
{
    int n;
    cin >> n;
    int v[n];
    for (int i = 0; i < n; i++)
    {
        string x;
        cin >> x;
        if (x == "n")
        {
            v[i] = -1;
        }
        else
        {
            v[i] = stoi(x);
        }
    }
    Node *root = construct(v);
    if (isBST(root))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
}