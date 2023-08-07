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

//! balanced tree is if the difference between left and right height is less than 1;
bool isBalanced(node *root)
{
    if (root == NULL)
        return true;

    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);
    bool diff = abs(height(root->left) - height(root->right)) <= 1;

    return (left && right && diff);
}
// TC-0(n^2);


pair<bool,int> isBalanced2(node *root)
{
    if (root == NULL){

        // return true;
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }

    pair<bool, int> left = isBalanced2(root->left);
    auto right = isBalanced2(root->right);
    auto diff = abs(left.second- right.second) <= 1;
    pair<bool, int> ans = make_pair(left.first && right.first && diff, max(left.second, right.second) + 1);

    return ans;
}
//TC-0(n)

int main()
{
    node *root = NULL;
    root = buildtree(root);
    return 0;
}