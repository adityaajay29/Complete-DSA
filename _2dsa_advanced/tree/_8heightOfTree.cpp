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

int height(node *root)
{
    if(root==NULL)
    return 0;
    return max(height(root->left),height(root->right))+1;
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
    root->right->right->left->right->left=new node(10);
    root->right->right->left->right->left->right=new node(11);
    root->right->right->left->right->left->right->right=new node(12);
    root->right->right->left->right->left->right->right->right=new node(13);
    cout<<"the height of tree is "<<height(root)<<endl;
    return 0;
}