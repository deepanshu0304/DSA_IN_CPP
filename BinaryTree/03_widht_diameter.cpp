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

int width(node *root)
{
      if (root == NULL)
        return 0;
    int op1 = width(root->left);
    int op2 = width(root->right);
    int hei = height(root->left)+height(root->right)+1;
    return max(op1, max(op2, hei));
}
// TC-0(n^2)

pair<int,int> width2(node *root)
{
    if (root == NULL){

    pair<int, int> p = make_pair(0, 0);
    return p;
    }
    pair<int,int> left = width2(root->left);
    pair<int,int> right = width2(root->right);
    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;
    int hei = max(left.second, right.second) + 1;
    pair<int, int> ans = make_pair(max(op1, max(op2, op3)), hei);
    return ans;
}


int main()
{
    node *root = NULL;
    root = buildtree(root);
    int dia = width(root);
    pair<int,int> dia2 = width2(root);

    return 0;
}