#include <iostream>
using namespace std;

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
    node *root=new node(1);
    root->left=new node(2);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right=new node(3);
    root->right->left=new node(6);
    root->right->right=new node(7);
    root->right->right->right=new node(8);
    inorder(root);
    return 0;
} 