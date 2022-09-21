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

// approach:
// we need three diff steps:
// 1. print the left most nodes of left subtree at each level except the leaves 
// if the left is not present, then print right
// 2. print all the leaves of left subtree and right subtree from left to right
// 3. print the right most nodes of right subtree at each level except the leaves 
// if the right is not present, then print left
// merge them in one function to ensure none of the necessary leaves are left 
// time :O(n) space O(n)

void printLeft(node *root)
{
    if(root==NULL)
    return;
    if(root->left)
    {
        cout<<root->key<<" ";
        printLeft(root->left);
    }
    else if(root->right)
    {
        cout<<root->key<<" ";
        printLeft(root->right);
    }
}

void printRight(node *root)
{
    if(root==NULL)
    return;
    if(root->right)
    {
        cout<<root->key<<" ";
        printRight(root->right);
    }
    else if(root->left)
    {
        cout<<root->key<<" ";
        printRight(root->left);
    }
}

// similar to inorder traversal

void printLeaves(node *root)
{
    if(root==NULL)
    return;
    printLeaves(root->left);
    if(!root->left && !root->right)
    cout<<root->key<<" ";
    printLeaves(root->right);
}

void printBoundaryNodes(node *root)
{
    if(root==NULL)
    return;
    cout<<root->key<<" ";
    // call printLeft for left subtree
    printLeft(root->left);
    // call printLeaves for printing leaves of left subtree
    printLeaves(root->left);
    // call printLeaves for printing leaves of right subtree
    printLeaves(root->right);
    // call printRight for right subtree
    printRight(root->right);
}

int main()
{
    node *root=new node(20);
    root->left=new node(8);
    root->left->left=new node(4);
    root->left->right=new node(12);
    root->left->right->left=new node(10);
    root->left->right->right=new node(14);
    root->right=new node(22);
    root->right->right=new node(25);
    cout<<"the bounjdary nodes are ";
    printBoundaryNodes(root);
    cout<<endl;
    return 0;
}