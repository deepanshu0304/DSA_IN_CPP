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

int height(node *root)
{
    if (root == NULL)
        return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return max(lh, rh) + 1;
}
//TC  -0(n)
//SC -0(height) as max stack will only be occupied when we were traversing maximum detpth branch
int main()
{
    node *root = NULL;
    root = buildtree(root);
    int hei = height(root);
    return 0;
}