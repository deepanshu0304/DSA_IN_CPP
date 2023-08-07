#include <bits/stdc++.h>
using namespace std;

class node

{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL; 
        this->right = NULL;
    }
};

node *buildtree(node *root)
{

    int data;
    cin >> data;
    root = new node(data);
    if (data == -1)
        return NULL;
    root->left = buildtree(root->left);
    root->right = buildtree(root->right);
    return root;
}

void levelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
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

// INORDER    LNR
// PREORDER   NLR
// POSTORDER  LRN

void inOrderTraversal(node *root)
{
    if (root == NULL)
        return;
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

void preOrderTraversal(node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(node *root)
{
    if (root == NULL)
        return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

void buildFromLevelOrderTraversal(node *&root)
{
    queue<node *> q;
    int data;
    cin >> data;
    root = new node(data);
    q.push(root);
    while (!q.empty())
    {

        node *temp = q.front();
        q.pop();
        int d;
        cin >> d;
        if (d != -1)
        {

            temp->left = new node(d);
            q.push(temp->left);
        }
        int da;
        cin >> da;
        if (da != -1)
        {

            temp->right = new node(da);
            q.push(temp->right);
        }
    }
}

int main()
{
    node *root = NULL;
    root = buildtree(root);
    levelOrderTraversal(root);
    inOrderTraversal(root);
    cout << endl;
    preOrderTraversal(root);
    cout << endl;
    postOrderTraversal(root);

    // buildFromLevelOrderTraversal(root);

    return 0;
}