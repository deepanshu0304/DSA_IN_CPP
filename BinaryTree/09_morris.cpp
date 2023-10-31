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

node *predecessor(node *root)
{
    node *ans = root;
    ans = ans->left;
    while (ans->right != NULL && ans->right != root)
    {
        ans = ans->right;
    }
    return ans;
}

vector<int> morrisTraversal(node *root)
{
    vector<int> inorder;
    node *curr = root;
    while (curr != NULL)
    {

        if (curr->left == NULL)
        {
            inorder.push_back(curr->data);
            curr = curr->right;
        }
        else
        {
            node *pred = predecessor(curr);
            if (pred->right == NULL)
            {
                pred->right = curr;
                curr = curr->left;
            }
            else
            {
                pred->right = NULL;
                inorder.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
    return inorder;
}

int main()
{

    node *root = NULL;
    root = buildtree(root);
    auto inorder = morrisTraversal(root);
    for(auto a:inorder){
        cout << a << endl;
    }

    return 0;
}
