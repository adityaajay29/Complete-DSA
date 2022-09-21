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

int ceiling(node *root,int x)
{
    static int ceil=INT_MIN;
    if(!root)
    return ceil;
    if(x==root->key)
    {
        ceil=x;
        return ceil;
    }
    else if(root->key>x)
    {
        ceil=root->key;
        ceil=min(ceil,ceiling(root->left,x));
    }
    else
    {
        ceil=min(ceil,ceiling(root->right,x));
    }
    return ceil;
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
    cout<<"the ceiling is "<<ceiling(root,-8);
    return 0;
}