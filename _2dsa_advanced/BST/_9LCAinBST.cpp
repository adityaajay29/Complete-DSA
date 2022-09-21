#include <iostream>
using namespace std;

struct node
{
    int key;
    node *left;
    node *right;
    node(int x)
    {
        left=right=NULL;
        key=x;
    }
};

// time : O(h)

node *LCAinBST(node *root,int p,int q)
{
    if(!root)
    return NULL;
    // case 1: when p is smaller and q is largeer or vice versa
    if(p<root->key && q>root->key || p>root->key && q<root->key)
    return root;
    // case 2: if root is one of p or q return root
    else if(p==root->key || q==root->key)
    return root;
    // case 3: if both are smaller go to left and return whatever returned by left sub
    else if(p<root->key && q<root->key)
    {
        return LCAinBST(root->left,p,q);
    }
    // case 4: else goto right and return whatever returned by right sub
    else 
    return LCAinBST(root->right,p,q);
}

int main()
{
    node *root=new node(6);
    root->left=new node(2);
    root->left->left=new node(0);
    root->left->right=new node(4);    
    root->left->right->left=new node(3);
    root->left->right->right=new node(5);
    root->right=new node(8);
    root->right->left=new node(7);
    root->right->right=new node(9);
    node *lca=LCAinBST(root,9,7);
    cout<<"the lca is "<<lca->key<<endl;
    return 0;
}