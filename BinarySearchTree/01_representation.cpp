#include <bits/stdc++.h>
using namespace std;

// ! Inorder treaversal of BST is always sorted.
class Node
{

public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp != NULL)
            cout << temp->data << " ";
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
    }
}

Node *insertInBST(Node *root, int d)
{
    // base case
    if (root == NULL)
    {
        root = new Node(d);
        return root;
    }

    if (d > root->data)
    {

        root->right = insertInBST(root->right, d);
    }
    else
    {

        root->left = insertInBST(root->left, d);
    }
    return root;
}

void takeInput(Node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = insertInBST(root, data);
        cin >> data;
    }
}

int main()
{

    Node *root = NULL;
    takeInput(root);
    levelOrderTraversal(root);

    return 0;
}   
