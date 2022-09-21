#include <iostream>
#include <vector>
using namespace std;

// approach:
// go to left and right
// add the root key in the vector
// if node is not found in the traversal, then return back and remove that root
// create a seperate bool fun to check if that trav contains the given node
// then use this fun to return the ans vector

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

bool checkPathForNode(node *root,vector<int>&ans,int givenNode)
{
    if(root==NULL)
    return false;
    if(root->key==givenNode)
    return true;
    ans.push_back(root->key);
    if(checkPathForNode(root->left,ans,givenNode) || checkPathForNode(root->right,ans,givenNode))
    return true;
    ans.pop_back();
    return false;
}

vector<int> rootToNode(node *root,int givenNode)
{
    vector<int>ans;
    if(root==NULL)
    return ans;
    checkPathForNode(root,ans,givenNode);
    ans.push_back(givenNode);
    return ans;
}

int main()
{
    node *root=new node(1);
    root->left=new node(2);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->left->right->left=new node(6);
    root->left->right->right=new node(7);
    root->right=new node(3);
    vector<int>ans=rootToNode(root,7);
    for(auto x:ans)
    cout<<x<<" ";
    return 0;
}