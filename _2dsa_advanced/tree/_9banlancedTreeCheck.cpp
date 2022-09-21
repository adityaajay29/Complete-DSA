#include <iostream>
using namespace std;

// if the abs diff b/w left and right height is greater than 1
// it is not balanced tree
// return tree height if diff is not greater than -1
// else return -1
// then use it to return boolean val of function 

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

int height(node *root)
{
    if(root==NULL)
    return 0;
    int lh=height(root->left);
    if(lh==-1)
    return -1;
    int rh=height(root->right);
    if(rh==-1)
    return -1;
    if(abs(lh-rh)>1)
    return -1;
    return max(lh,rh)+1;
}

bool balanceCheck(node *root)
{
    int res=height(root);
    return res != -1;
}

int main()
{
    node *root=new node(1);
    root->left=new node(2);
    root->left->left=new node(3);
    root->left->right=new node(4);
    root->right=new node(5);
    root->right->left=new node(6);
    root->right->right=new node(7);
    root->right->right->left=new node(8);
    root->right->right->left->right=new node(9);
    cout<<balanceCheck(root)<<endl;
    return 0;
}