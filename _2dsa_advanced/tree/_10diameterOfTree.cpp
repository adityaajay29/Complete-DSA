#include <iostream>
using namespace std;

// the max distance btw any two nodes of the tree is called diameter
// approach : 
// find the height for all the nodes and subtrees
// return the max height at any node
// that will be diameter
// diameter need not include main root

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

int maxDiameter=0;

int height(node *root, int &maxDiameter)
{
    if(root==NULL)
    return 0;
    int lh=height(root->left ,maxDiameter);
    int rh=height(root->right, maxDiameter);
    maxDiameter=max(maxDiameter, (lh+rh));
    return 1 + max(lh,rh);
}

int maxDia(node *root, int &maxDiameter)
{
    int h=height(root, maxDiameter);
    return maxDiameter;
}

int main()
{
    node *root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->right->left=new node(4);
    root->right->left->left=new node(5);
    root->right->left->left->left=new node(9);
    root->right->right=new node(6);
    root->right->right->right=new node(7);
    root->right->right->right->right=new node(8);
    cout<<"the diameter of tree is "<<maxDia(root,maxDiameter)<<endl;
    return 0;
}