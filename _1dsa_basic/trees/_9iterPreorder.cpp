#include <iostream>
#include <stack>
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

void iterPreorder(node *root)
{
    node *curr=root;
    stack<node *>s;
    s.push(root);
    while(!s.empty())
    {
        // whichever is popped is our new head, traverse for that
        node *curr=s.top();
        cout<<curr->key<<" ";
        s.pop();
        if(curr->right)
        s.push(curr->right);
        if(curr->left)
        s.push(curr->left);
    }
}

int main()
{
    node *root=new node(10);
    root->left=new node(20);
    root->right=new node(30);
    root->right->left=new node(40);
    root->right->right=new node(50);
    cout<<"the inorder traversal is ";
    iterPreorder(root);
    cout<<endl;
    return 0;
}