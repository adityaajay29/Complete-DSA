#include <iostream>
#include <vector>
using namespace std;

// naive approach:
// find path for both the nodes from root to that node seperately
// find the last common node in the both path arrays

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

bool findPath(node *root, vector<node*>arr,int p)
{
    if(root==NULL)
    return false;
    arr.push_back(root);
    if(root->key==p)
    return true;
    if(findPath(root->left,arr,p) || findPath(root->right,arr,p))
    return true;
    arr.pop_back();
    return false;
}

node *LCA(node *root,int p,int q)
{
    if(root==NULL)
    return NULL;
    vector<node *>path1;
    vector<node *>path2;
    if(!findPath(root,path1,p) || !findPath(root,path2,q))
    return NULL;
    for(auto i=path1.begin();i!=path1.end() && i!=path2.end();i++)
    if(path1[i+1]->key!=path2[i+1]->key)
    return path1[i];
}

int main()
{
    node *root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->right->left=new node(4);
    root->right->right=new node(5);
    root->right->left->left=new node(8);
    root->right->right->left=new node(6);
    root->right->right->right=new node(7);
    int node1=8;
    int node2=7;
    cout<<"the lowest common ansistor of "<<node1<<" and  "<<node2<<" is ";
    node *ans=LCA(root,node1,node2);
    cout<<ans->key;
    return 0;
}
     