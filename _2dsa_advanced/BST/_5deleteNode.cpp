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

node *successor(node *root)
{
    if(!root)
    return NULL;
    node *curr=root->right;
    while(curr && curr->left)
    {
        curr=curr->left;
    }
    return curr;
}

node *deleteNode(node *root, int x)
{
    if(!root)
    return NULL;
    else if(x<root->key)
    root->left=deleteNode(root->left,x);
    else if(x>root->key)
    root->right=deleteNode(root->right,x);
    else
    {
        if(!root->right)
        {
            node *temp=root->left;
            delete root;
            return temp;
        }
        else if(!root->left)
        {
            node *temp=root->right;
            delete root;
            return temp;
        }
        else
        {
            node *succ=successor(root);
            root->key=succ->key;
            root->right=deleteNode(root->right,succ->key);
        }
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
    inorder(root);
    cout<<endl;
    root=deleteNode(root,7);
    inorder(root);
    return 0;
}
