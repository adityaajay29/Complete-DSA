#include <iostream>
#include <stack>
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

// approach: 
// use 2 stacks
// push the root in s1
// take the top guy form s1, mark it as curr, pop it and push to s2
// if curr->left exists, push to s1
// if curr->right exists, push to s1
// run the lopp until s1 is empty
// now, s2 contains ele in postorder from top to bottom, print them

void postorder(node *root)
{
    stack<node *>s1;
    stack<node *>s2;
    s1.push(root);
    while(!s1.empty())
    {
        node *curr=s1.top();
        s1.pop();
        s2.push(curr);
        if(curr->left)
        s1.push(curr->left);
        if(curr->right)
        s1.push(curr->right);
    }
    while(!s2.empty())
    {
        cout<<s2.top()->key<<" ";
        s2.pop();
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
    postorder(root);
    return 0;
}