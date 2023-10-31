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

int findInInorder(vector<int> &inorder, int key, int s, int e)
{
    for (int i = s; i <= e; i++)
    {
        if (inorder[i] == key)
            return i;
    }
    return -1;
}

Node *buildTreeHelper(vector<int> &preorder, vector<int> &inorder, int &index, int start, int end)
{
    if (start > end || index > preorder.size())
        return NULL;

    int root = preorder[index++];
    int posInIndex = findInInorder(inorder, root, start, end);
    Node *node = new Node(root);
    node->left = buildTreeHelper(preorder, inorder, index, start, posInIndex - 1);
    node->right = buildTreeHelper(preorder, inorder, index, posInIndex + 1, end);
    return node;
}

Node *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    int index = 0;
    int n = inorder.size();
    return buildTreeHelper(preorder, inorder, index, 0, n - 1);
}
int main(){

    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};

    Node *head = buildTree(preorder, inorder);

    //! You can check if the tree is valid or not by printing its post order traversal 

    return 0;
}
