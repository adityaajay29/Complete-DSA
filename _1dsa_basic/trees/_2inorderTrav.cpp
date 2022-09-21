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

void inorder(node *root)
{
    if(root==NULL)
    return; //returns control back to the parent caller
    inorder(root->left);
    cout<<root->key<<" ";
    inorder(root->right);
}

int main()
{
    node *root=new node(10);
    root->left=new node(20);
    root->left->left=new node(60);
    root->left->left->right=new node(70);
    root->left->left->right->right=new node(80);
    root->right=new node(30);
    root->right->left=new node(40);
    root->right->right=new node(50);
    root->right->right->right=new node(90);
    root->right->right->right->right=new node(140);
    root->right->right->right->left=new node(100);
    root->right->right->right->left->right=new node(120); 
    cout<<"the inorder tree traversal is ";
    inorder(root);
    cout<<endl;
    return 0;
}