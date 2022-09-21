#include <iostream>
using namespace std;

// approach:
// check if root->left==root->right
// and recursively call for left and right sub trees
// return whatever is returned by this function

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

bool findIfSymmetric(node *left,node *right)
{
    if(left==NULL || right==NULL)
    return left==right;
    if(left->key!=right->key)
    return false;
    return (findIfSymmetric(left->left,right->right)
        &&  findIfSymmetric(left->right,right->left));
}

bool isSymmetric(node *root)
{
    if(root==NULL)
    return false;
    else
    return findIfSymmetric(root->left,root->right);
}

int main()
{
    node *root=new node(1);
    root->left=new node(2);
    root->right=new node(2);
    root->left->left=new node(3);
    root->right->right=new node(3);
    root->left->left->right=new node(4);
    root->right->right->left=new node(4);
    cout<<isSymmetric(root)<<endl;
    return 0;
}