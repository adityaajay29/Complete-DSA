#include <iostream>
#include <vector>
using namespace std;

// approach:
// use inorder trav
// create a prev node, as NULL
// goto left left left...and assign the left most node as head of LL
// if no left then check if prev is NULL, if so, make root as head
// if prev is not NULL
// then make root left as prev
// and make prev right as root 
// assign root to prev
// then go to root->right

// time :O(n)
// space :O(n) aux space for recursion call stack 

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

node *LL(node *root)
{
    if(!root)
    return root;
    // creating static prev so that it can be used again and again in all recursion calls
    static node *prev=NULL;
    // returning whatever is on the left most as head
    node *head=LL(root->left);
    if(prev==NULL)
    // even if left didnt exist and retrurned null, then all the root will be head, as prev==NULL
    head=root;
    else
    {
        root->left=prev;
        prev->right=root;
    }
    prev=root;
    LL(root->right);
    return head;
}

void printList(node *head)
{
    if(!head)
    return;
    node *curr=head;
    while(curr)
    {
        cout<<curr->key<<" ";
        curr=curr->right;
    }
}

int main()
{
    node *root=new node(10);
    root->left=new node(5);
    root->right=new node(20);
    root->right->left=new node(30);
    root->right->right=new node(35);
    node *head=LL(root);
    printList(head);
    return 0;
}