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

void levelOrderLinewise(Node *&node)
{
    stack<Node *> main;
    stack<Node *> child;

    int level = 1;
    main.push(node);

    while (!main.empty())
    {
        Node *rem = main.top();
        main.pop();

        cout << rem->data << " ";

        if (level % 2 == 1)
        {
            for (int i = 0; i < rem->children.size(); i++)
            {
                child.push(rem->children[i]);
            }
        }

        else
        {
            for (int i = rem->children.size() - 1; i >= 0; i--)
            {
                child.push(rem->children[i]);
            }
        }

        if (main.size() == 0)
        {
            main = child;
            stack<Node *> x;
            child = x;
            level++;
            cout << endl;
        }
    }
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
    levelOrderLinewise(root);

    return 0;
}