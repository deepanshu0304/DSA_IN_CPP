#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
int findIndex(vector<int> &inorder, int key, int s, int e)
{
    for (int i = s; i <= e; i++)
    {
        if (inorder[i] == key)
            return i;
    }

    return -1;
}
Node *buildTreeHelper(vector<int> &inorder, vector<int> &postorder, int &index, int start, int end)
{
    if (start > end || index < 0)
        return nullptr;
    int root = postorder[index--];
    int posInInorder = findIndex(inorder, root, start, end);

    Node *node = new Node(root);
    node->right = buildTreeHelper(inorder, postorder, index, posInInorder + 1, end);
    node->left = buildTreeHelper(inorder, postorder, index, start, posInInorder - 1);
    return node;
}

Node *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    int n = postorder.size();
    int index = n - 1;
    return buildTreeHelper(inorder, postorder, index, 0, n - 1);
}
int main(){
    vector<int> postorder = {9, 15, 7, 20, 3};
    vector<int> inorder = {9, 3, 15, 20, 7};

    Node *head = buildTree(inorder, postorder);

    //! you can check if tree is valid or not by printing it's preorder traversal

    return 0;
}