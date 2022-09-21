#include <iostream>
using namespace std;

// approach:
// Use the concept of maximum height
// For every note goes left and go towards the right and find the maximum Key val
// Keep updating the maximum value by adding the key value and left key and right key
// Return key value plus maximum of left and right key value

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

int maxPathSum=0;

int height(node *root,int &maxPathSum)
{  
    if(root==NULL)
    return 0;

    // corner case, when left key or right key is negative, return 0, not -ve key
    // because that will give us lower maxSum than expected

    int leftMax=max(0,height(root->left,maxPathSum));
    int rightMax=max(0,height(root->right,maxPathSum));
    maxPathSum=max(maxPathSum,root->key+leftMax+rightMax);
    return root->key+max(leftMax,rightMax);
}

int maxSum(node *root)
{
    int ans=height(root,maxPathSum);
    return maxPathSum;
}

int main()
{
    node *root=new node(15);
    root->left=new node(10);
    root->right=new node(20);
    root->right->left=new node(-30);
    root->right->right=new node(-15);
    cout<<"the max path sum is "<<maxSum(root)<<endl;
    return 0;
}