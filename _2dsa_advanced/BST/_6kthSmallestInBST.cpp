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

// time: O(h+k)

void kthSmallest(node* root,int k)
{
    static int count=0;
    if(root)
    {
        kthSmallest(root->left,k);
        count++;
        if(count==k)
        {
            cout<<root->key;
            return;
        }
        kthSmallest(root->right,k);
    }
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
    node *root=new node(5);
    root->left=new node(3);
    root->left->left=new node(1);
    root->left->left->right=new node(2);
    root->left->right=new node(4);
    root->right=new node(7);
    root->right->left=new node(6);
    root->right->right=new node(8);
    int k=7;
    cout<<"the kth smallest node is ";
    kthSmallest(root,k);
    cout<<endl;
    return 0;
}