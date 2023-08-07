#include<bits/stdc++.h>
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

bool isIndentical(node* root1,node* root2){
    if(root1==NULL && root2==NULL){
        return true;
    }
    if(root1==NULL || root2==NULL){
        return false;
    }

    if(root1->data != root2->data){
        return false;
    }
    else{
        bool left = isIndentical(root1->left, root2->left);
        bool right = isIndentical(root1->right, root2->right);
        return (left && right);
    }
}

int main(){
    node *root1 = NULL;
    root1 = buildtree(root1);
    node *root2 = NULL;
    root2 = buildtree(root2);
    return 0;
}