#include <iostream>
using namespace std;

struct node
{
    int key;
    node *left, *right;
    node(int x)
    {
        key=x;
        left=right=NULL;
    }
};

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

int main()
{
    node *root=new node(15);
    root->left=new node(5);
    root->left->left=new node(3);
    root->right=new node(20);
    root->right->left=new node(18);
    root->right->left->left=new node(16);
    root->right->right=new node(80);
    cout<<iterSearch(root,80)<<endl;
    return 0;
}