#include <iostream>
using namespace std;

struct node
{
    int key;
    node *left,*right;
    node(int x)
    {
        key=x;
        left=right=NULL;
    }
};
// finding the closest greater value
// we can also find closest smaller value instead of closest greater value
node *successor(node *root)
{
    if(!root)
    return NULL;
    node *curr=root->right;
    while(curr!=NULL && curr->left!=NULL)
    {
        curr=curr->left;
    }
    return curr;
}

node *del(node *root, int x)
{
    node *temp=NULL;
    if(root==NULL)
    return root;
    else if(x<root->key)
    // to make link, storing the returned value 
    root->left=del(root->left,x);
    else if(x>root->key)
    root->right=del(root->right,x);

    // checking if only left leef present of node to be deleted
    else
    {
        if(root->right==NULL)
        {
            temp=root->left;
            delete root;
            // left child will replace the deleted node
            return temp;
        }
        // if only right leaf child present
        else if(root->left==NULL)
        {
            temp=root->right;
            delete root;
            // right child will replace the given node
            return temp;
        }
    // if both left and right child are present, we will look for immediate successor, 
    // which in deleting case is left most child of the right child 
        else
        {
            node *succ=successor(root);
            // copying the succeessor to the root to be deleted, and deleting the successor
            root->key=succ->key;
            // now delete the successor node as same as deleting the left child, and returned value is assigned
            // the right child
            root->right=del(root->right,succ->key);
        }
    }
    return root;
} 

void inorder(node *root)
{
    if(root==NULL)
    return;
    inorder(root->left);
    cout<<root->key<<" ";
    inorder(root->right);
}

int main()
{
    node *root=new node(50);
    root->left=new node(30);
    root->left->left=new node(20);
    root->left->right=new node(40);
    root->right=new node(70);
    root->right->left=new node(60);
    root->right->right=new node(80);
    inorder(root);
    cout<<endl;
    root=del(root,30);
    inorder(root);
    cout<<endl;
    return 0;
}