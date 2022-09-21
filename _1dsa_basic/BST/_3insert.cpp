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

/*
the below code is wrong because
when we will come to leaf, and fall into base case, we will only make a new node and wont link it
if we dont assign the returned value to the root->left or root->right, that creates the linking

node *insert(node *root,int x)
{
    node *temp=new node(x);
    if(root==NULL)
    return temp;
    else if(root->key==x)
    return root;
    else if(x<root->key)
    {
        insert(root->left,x);
    }
    else if(x>root->key)
    {
        insert(root->right,x);
    }
    return root;
}
*/

node *insert(node *root,int x)
{
    node *temp=new node(x);
    if(root==NULL)
    return temp;
    else if(x<root->key)
    {
        // linking of newly created node is needed
        root->left=insert(root->left,x);
    }
    else if(x>root->key)
    {
        // linking is again needed
        root->right=insert(root->right,x);
    }
    return root;
}  

bool iterSearch(node *root,int x)
{
    while(root!=NULL)
    {
        if(root->key==x)
        return true;
        else if(x<root->key)
        root=root->left;
        else if(x>root->key)
        root=root->right;
    }
    return false;
}

void inorder(node *root)
{
    if(!root)
    return;
    inorder(root->left);
    cout<<root->key<<" ";
    inorder(root->right);
}

int main()
{
    // node *root=new node(10);
    // root=insert(root,45);
    // root=insert(root,56);
    node *root=new node(4);
    root->left=new node(2);
    root->left->left=new node(1);
    root->left->right=new node(3);
    root->right=new node(7);
    root=insert(root,5);
    // cout<<iterSearch(root,56)<<endl;
    inorder(root);
    return 0;
} 