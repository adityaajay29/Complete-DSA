#include <iostream>
#include <vector>
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

void serialise(node *root,vector<int>&info)
{
    static int empty=-1;
    if(!root)
    {
        info.push_back(empty);
        return;
    }
    info.push_back(root->key);
    serialise(root->left,info);
    serialise(root->right,info);
}

node * deserialise(vector<int>&info)
{
    static int index=0;
    if(index==info.size())
    return NULL;
    int val=info[index];
    index++;
    if(val==-1)
    return NULL;
    node *root=new node(val);
    root->left=deserialise(info);
    root->right=deserialise(info);
    return root;
}

void preorder(node *root)
{
    if(!root)
    return;
    cout<<root->key<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    node *root=new node(10);
    root->left=new node(5);
    root->right=new node(20);
    root->right->left=new node(30);
    root->right->right=new node(35);
    vector<int>info;
    serialise(root,info);
    for(auto x:info)
    cout<<x<<" ";
    cout<<endl;
    node *root1=deserialise(info);
    preorder(root1);
    return 0;
}