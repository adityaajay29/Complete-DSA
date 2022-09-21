#include <iostream>
using namespace std;

struct node
{
    int key;
    node *left;
    node *right;
    node(int x)
    {
        key=x;
        left=right=NULL;
    }
};

void preorder(node *root)
{
    if(root==NULL)
    return;
    cout<<root->key<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    node *root=new node(1);
    root->left=new node(2);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right=new node(3);
    root->right->left=new node(6);
    root->right->right=new node(7);
    root->right->right->right=new node(8);
    preorder(root);
    return 0;
}