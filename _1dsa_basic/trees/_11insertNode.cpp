#include <iostream>
#include <queue>
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

// node* insert(node *root,int x)
// {
//     node *temp=new node(x);
//     if(root==NULL)
//     return temp;
//     queue<node *>q;
//     q.push(root);
//     while(q.empty()!=true)
//     {
//         node *curr=q.front();
//         q.pop();
//         if(curr->left!=NULL)
//         q.push(curr->left);
//         else
//         {
//             curr->left=temp;
//             return root;
//         }
//         if(curr->right!=NULL)
//         q.push(curr->right);
//         else
//         {
//             curr->right=temp;
//             return root;
//         }
//     }
//     return root;
// }

node *insert(node *root, int key)
{
    node *temp=new node(key);
    if(root==NULL)
    return temp;
    queue<node *>q;
    q.push(root);
    while(!q.empty())
    {
        node *curr=q.front();
        q.pop();
        // if left of curr exists, then push it in queue
        if(curr->left)
        q.push(curr->left);
        // else make temp as the left of the curr
        else
        {
            curr->left=temp;
            return root;
        }
        // if right exists push it in queue
        if(curr->right)
        q.push(curr->right);
        // else make temp as the right of curr
        else
        {
            curr->right=temp;
            return root;
        }
    }
    return root;
}

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
    node *root=new node(10);
    root->left=new node(20);
    root->right=new node(30);
    root->right->left=new node(40);
    root->right->right=new node(50);
    root=insert(root,12);
    inorder(root);
    cout<<endl;
    return 0;
}