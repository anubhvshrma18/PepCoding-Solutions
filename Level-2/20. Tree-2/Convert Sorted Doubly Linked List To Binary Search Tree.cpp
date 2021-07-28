#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int val = 0;
    Node *left = nullptr;
    Node *right = nullptr;

    Node(int val)
    {
        this->val = val;
    }
};

Node *midNode(Node *head, Node *tail)
{
    Node *slow = head, *fast = head;
    while (fast->right != tail && fast->right->right != tail)
    {
        slow = slow->right;
        fast = fast->right->right;
    }

    return slow;
}
Node *buildTemp(Node *head, Node *tail)
{
    if (head == tail)
    {
        return NULL;
    }

    if (head->right == tail)
    {
        Node *root = new Node(head->val);
        return root;
    }

    Node *mid = midNode(head, tail);
    Node *root = new Node(mid->val);
    Node *temp = mid->right;
    mid->right = NULL;
    root->left = buildTemp(head, mid);
    root->right = buildTemp(temp, tail);

    return root;
}
Node *SortedDLLToBST(Node *head)
{
    return buildTemp(head, NULL);
}

// input_Section_====================================================================

void display(Node *node)
{
    if (node == nullptr)
        return;

    string str = "";
    str += ((node->left != nullptr ? to_string(node->left->val) : "."));
    str += (" -> " + to_string(node->val) + " <- ");
    str += ((node->right != nullptr ? to_string(node->right->val) : "."));

    cout << str << endl;

    display(node->left);
    display(node->right);
}

Node *makeList(int n)
{
    Node *dummy = new Node(-1);
    Node *prev = dummy;
    while (n-- > 0)
    {
        int val;
        cin >> val;
        Node *node = new Node(val);
        prev->right = node;
        node->left = prev;
        prev = prev->right;
    }

    Node *head = dummy->right;
    head->left = dummy->right = nullptr;

    return head;
}

void solve()
{
    int n;
    cin >> n;
    Node *head = makeList(n);

    head = SortedDLLToBST(head);
    display(head);
}

int main()
{
    solve();
    return 0;
}