#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct Node
{
    int data;
    vector<Node *> children;
};

Node *construct(int *arr, int n)
{
    Node *root;

    stack<Node *> st;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == -1)
        {
            st.pop();
        }

        else
        {
            Node *newnode = new Node();
            newnode->data = arr[i];

            if (st.size() > 0)
            {
                Node *top = st.top();
                (top->children).push_back(newnode);
            }

            else
            {
                root = newnode;
            }

            st.push(newnode);
        }
    }

    return root;
}

void traversals(Node *node)
{

    // pre node
    cout << "Node Pre " << node->data << endl;

    for (int i = 0; i < node->children.size(); i++)
    {
        Node *child = (node->children)[i];

        // pre edge
        cout << "Edge Pre " << node->data << "--" << child->data << endl;

        traversals(child);

        // post edge
        cout << "Edge Post " << node->data << "--" << child->data << endl;
    }

    // post node
    cout << "Node Post " << node->data << endl;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Node *root = construct(arr, n);
    traversals(root);

    return 0;
}