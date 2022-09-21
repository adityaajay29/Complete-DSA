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

// using the fact that inorder trav of bst is sorted
// using a var to store the prev key, if curr key is larger, then true, else false
// O(n) time, O(h) aux space of rec call stack

bool isBST(node *root)
{
    static int prev=INT_MIN;
    if(!root)
    return true;
    // if left returns false, return false
    if(isBST(root->left)==false)
    return false;
    // check for prev key, if prev is smaller than curr, then update the prev as curr->key
    if(root->key<=prev)
    // else return false
    return false;
    prev=root->key;
    // if both left sub and curr root returns true, then whatever is returned by right sub will be ans
    return isBST(root->right);
}

int main()
{
    node *root=new node(50);
    root->left=new node(20);
    root->left->left=new node(10);
    root->left->right=new node(40);
    root->right=new node(100);
    root->right->left=new node(70);
    root->right->left->left=new node(60);
    root->right->left->right=new node(80);
    root->right->right=new node(120);
    cout<<isBST(root)<<endl;
    return 0;
}