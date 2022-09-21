#include <iostream>
#include <vector>
#include <unordered_map>
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

// approach :
// problem can be reduced to O(n) if we use hash map to store the index and values of inorder array
// by doing so, finding inIndex will bwcome O(1) operation istead of O(n)

node *buildTree(vector<int>pre,vector<int>in,int is,int ie,unordered_map<int,int>&mp)
{
    static int preIndex=0;
    if(is>ie)
    return NULL;
    int val=pre[preIndex];
    preIndex++;
    node *root=new node(val);
    int inIndex=mp[val];
    root->left=buildTree(pre,in,is,inIndex-1,mp);
    root->right=buildTree(pre,in,inIndex+1,ie,mp);
    return root;
}

node *buildTreeEffi(vector<int>pre,vector<int>in)
{
    int is=0;
    int ie=in.size()-1;
    unordered_map<int,int>mp;
    for(int i=is;i<=ie;i++)
    {
        mp[in[i]]=i;
    }
    node *root=buildTree(pre,in,is,ie,mp);
    return root;
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
    vector<int>pre{10,20,30,40,50};
    vector<int>in{20,10,40,30,50};
    node *root=buildTreeEffi(pre,in);
    inorder(root);
    return 0;
}