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

node *insertNode(node *root,int x)
{
    static node *temp=new node(x);
    if(!root)
    return temp;
    else if(x<root->key)
    {
        root->left=insertNode(root->left,x);
    }
    else if(x>root->key)
    {
        root->right=insertNode(root->right,x);
    }
    return root;
}

void inorder(node *root)
{
    if(!root)
    return;
    inorder(root->left);
    cout<<root->key<<" ";
    inorder(root->right);
}

int main()
{
    node *root=new node(4);
    root->left=new node(2);
    root->left->left=new node(1);
    root->left->right=new node(3);
    root->right=new node(7);
    root=insertNode(root,-9);
    inorder(root);
    return 0;
}