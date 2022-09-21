#include <iostream>
#include <queue>
using namespace std;

// use queue as it is fifo
// whatever is in the top, assign the top as curr print it and pop
// go to its left if exists, and add to queue
// go to its right if exists, and add to queue

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

void levelOrder(node *root)
{
    if(root==NULL)
    return;
    queue<node *>q;
    q.push(root);
    while(!q.empty())
    {
        node *curr=q.front();
        q.pop();
        cout<<curr->key<<" ";
        if(curr->left)
        q.push(curr->left);
        if(curr->right)
        q.push(curr->right);
    }
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
    levelOrder(root);
    return 0;
}