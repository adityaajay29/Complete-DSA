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

bool searchNode(node *root,int x)
{
    if(!root)
    return false;
    if(x==root->key)
    return true;
    else if(x<root->key)
    return searchNode(root->left,x);
    else
    return searchNode(root->right,x);
}

int main()
{
    node *root=new node(8);
    root->left=new node(5);
    root->left->left=new node(4);
    root->left->right=new node(7);
    root->left->right->left=new node(6);
    root->right=new node(12);
    root->right->left=new node(10);
    root->right->right=new node(14);
    root->right->right->left=new node(13);
    cout<<searchNode(root,17)<<endl;
    return 0;
}
