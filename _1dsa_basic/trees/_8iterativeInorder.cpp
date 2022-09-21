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
        left=right=nullptr;
    }
};

void iterInorder(node *root)
{
    stack<node *>s;
    node *curr=root;
    while(curr!=NULL || !s.empty())
    {
        while(curr!=NULL)
        {
            s.push(curr);
            curr=curr->left;
        }
        // whichever is poped is our current, we traverse for that node
        curr=s.top();
        s.pop();
        cout<<curr->key<<" ";
        curr=curr->right;
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
    iterInorder(root);
    cout<<endl;
    return 0;
}