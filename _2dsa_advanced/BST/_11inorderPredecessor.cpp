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

node *inorderPredecessor(node *root,int x)
{
    node *pre=nullptr;
    while(root!=NULL)
    {
        if(x<=root->key)
        {
            root=root->left;
        }
        else
        {
            pre=root;
            root=root->right;
        }
    }
    return pre;
}

int main()
{
    node *root=new node(5);
    root->left=new node(2);
    root->left->left=new node(1);
    root->left->right=new node(4);
    root->left->right->left=new node(3);
    root->right=new node(7);
    root->right->left=new node(6);
    root->right->right=new node(9);
    root->right->right->left=new node(8);
    root->right->right->right=new node(10);
    node *pre=inorderPredecessor(root,7);
    cout<<"the inorder predecessor is "<<pre->key<<endl;
    return 0;
}