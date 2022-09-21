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

// time: O(h)
// space: O(1)

node *inorderSuccessorIterative(node *root,int x)
{
    node *succ=NULL;
    while(root)
    {
        if(x>=root->key)
        root=root->right;
        else
        {
            succ=root;
            root=root->left;
        }
    }
    return succ;
}

node *inorderSuccessor(node *root,int x)
{
    static node *succ=NULL;
    if(!root)
    return NULL;
    if(x<root->key)
    {
        succ=root;
        inorderSuccessor(root->left,x);
    }
    if(x>=root->key)
        inorderSuccessor(root->right,x);
    return succ;
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
    node *succ=inorderSuccessorIterative(root,3);
    cout<<"the inorder succ is "<<succ->key<<endl;
    return 0;
}