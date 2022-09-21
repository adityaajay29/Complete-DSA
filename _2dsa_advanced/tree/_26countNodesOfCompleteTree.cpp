#include <iostream>
#include <math.h>
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

// naive approach:
// void nodeCount(node *root,int &nodes)
// {
//     if(!root)
//     return;
//     nodes++;
//     nodeCount(root->left,nodes);
//     nodeCount(root->right,nodes);
// }

// efficient approach:
// time:O(logn)^2

// using the property of complete binary tree

// find left height
int leftHeight(node *root)
{
    if(!root)
    return 0;
    int lh=0;
    node *curr=root;
    while(curr)
    {
        curr=curr->left;
        lh++;
    }
    return lh;
}

// find right height
int rightHeight(node *root)
{
    if(!root)
    return 0;
    int rh=0;
    node *curr=root;
    while(curr)
    {
        curr=curr->right;
        rh++;
    }
    return rh;
}

int totalNodes(node *root)
{
    if(!root)
    return 0;
    int lh=leftHeight(root);
    int rh=rightHeight(root);
    // if left height is equal to right height, means its complete balanced tree
    if(lh==rh)
    return pow(2,lh)-1;
    // else recursively find left height of subtree
    // recursively find right height of subtree
    int lhRec=totalNodes(root->left);
    int rhRec=totalNodes(root->right);
    // return the total nodes as left + right + root (as 1)
    return 1+lhRec+rhRec;
} 

int main()
{
    node *root=new node(1);
    root->left=new node(2);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->left->left->left=new node(8);
    root->left->left->right=new node(9);
    root->left->right->left=new node(10);
    root->left->right->right=new node(11);
    root->right=new node(3);
    root->right->left=new node(6);
    root->right->right=new node(7);
    cout<<"total nodes of the tree are "<<totalNodes(root)<<endl;
    return 0;
}