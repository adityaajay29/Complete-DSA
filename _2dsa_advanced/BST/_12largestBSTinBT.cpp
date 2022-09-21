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

void inorder(node *root,vector<int>&v)
{
    if(!root)
    return;
    inorder(root->left,v);
    v.push_back(root->key);
    inorder(root->right,v);
}

int largestBST(node *root)
{
    vector<int>v;
    inorder(root,v);
    int res=0;
    int count=1;
    for(int i=0;i<v.size()-1;i++)
    {
        if(v[i+1]>v[i])
        {
            count++;
        }
        else
        {
            count=1;
        }
        res=max(res,count);
    }
    return res;
}

int main()
{
    node *root=new node(0);
    root->left=new node(2);
    root->left->left=new node(1);
    root->left->right=new node(4);
    root->left->right->left=new node(3);
    root->right=new node(10);
    root->right->left=new node(8);
    root->right->left->left=new node(7);
    root->right->left->right=new node(9);
    root->right->right=new node(11);
    int ans=largestBST(root);
    cout<<"the largest bst is "<<ans<<endl;
    return 0;
}