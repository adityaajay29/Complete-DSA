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

node *iterInsert(node *root,int x)
{
    node *temp=new node(x);
    node *parent=nullptr;
    node *curr=root;
    while(curr!=NULL)
    {
        parent=curr;
        if(x<curr->key)
        {
            curr=curr->left;
        }
        else if(x>curr->key)
        {
            curr=curr->right;
        }
        else 
        return root;
    }
    if(parent==NULL)
    return temp;
    else if(x<parent->key)
    parent->left=temp;
    else 
    parent->right=temp;
    return root;
}

int main()
{
    node *root=NULL;
    root=iterInsert(root,24);
    return 0;
}