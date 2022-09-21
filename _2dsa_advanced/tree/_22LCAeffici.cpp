#include <iostream>
using namespace std;

// idea : use the recursive traversal
// there are following cases :
// case 1: if node is null, return null
// case 2: if node key is equal to either p or q, return that node
// case 3: if both the subtrees contains p and q (one each), return that root node
// case 4: if left subtree contains both p and q, return leftCheck node
// case 5: if right subtree contains both p and q or neiter of them contains p and q, return rightCheck node

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

node *LCA(node *root,int p,int q)
{
    // case 1: if node is null, return null
    if(root==NULL)
    return NULL;
    // case 2: if node key is equal to either p or q, return that node
    if(root->key==p || root->key==q)
    return root;
    // call for the left and right subtree
    node *leftCheck= LCA(root->left,p,q);
    node *rightCheck= LCA(root->right,p,q);
    // case 3: if both the subtrees contains p and q (one each), return that root node
    if(leftCheck!=NULL && rightCheck!=NULL)
    return root;
    // case 4: if left subtree contains both p and q, return leftCheck node
    if(leftCheck!=NULL)
    return leftCheck;
    // case 5: if right subtree contains both p and q
    // or neiter of them contains p and q, return rightCheck node
    else 
    return rightCheck;
}

int main()
{
    node *root=new node(10);
    root->left=new node(20);
    root->right=new node(30);
    root->right->left=new node(40);
    root->right->right=new node(50);
    node *lca=LCA(root,40,50);
    cout<<"the lca is "<<lca->key<<endl;
    return 0;
}
