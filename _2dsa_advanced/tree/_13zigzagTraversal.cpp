#include <iostream>
#include <queue>
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

// ******** WRONG CODE *********

void zigZagTrav(node *root)
{
    if(root==NULL)
    return;
    queue<node *>q;
    q.push(root);
    int i=1;
    while(!q.empty())
    {
        node *curr=q.front();
        q.pop();
        cout<<curr->key<<" ";
        // if i is odd
        if(i%2)
        {
            if(curr->left)
            q.push(curr->left);
            if(curr->right)
            q.push(curr->right);
            i++;
        }
        else
        {
            if(curr->right)
            q.push(curr->right);
            if(curr->left)
            q.push(curr->left);
            i++;
        }
    }
}

int main()
{
    node *root=new node(1);
    root->left=new node(2);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right=new node(3);
    root->right->right=new node(6);
    cout<<"the zig zag traversal of the tree is ";
    zigZagTrav(root);
    cout<<endl;
    return 0;
}