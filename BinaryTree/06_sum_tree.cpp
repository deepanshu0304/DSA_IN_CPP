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

pair<bool, int> isSumTree(node *root)
{
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
    if (root->left == NULL && root->right == NULL)
    {
        pair<bool, int> p = make_pair(true, root->data);
        return p;
    }
    auto left = isSumTree(root->left);
    auto right = isSumTree(root->right);

    pair<bool, int> ans = make_pair((left.first && right.first && root->data == left.second + right.second), root->data + left.second + right.second);

    return ans;
}
int main()
{
    node *root = NULL;
    root = buildtree(root);
    return 0;
}