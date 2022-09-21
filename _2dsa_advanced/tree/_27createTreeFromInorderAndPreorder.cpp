#include <iostream>
#include <vector>
#include <map>
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

// ****** A UNIQUE TREE CAN'T BE CREATED USING JUST PREORDER AND POSTORDER ********
// can be created either using inorder and preorder
// or by using inorder and postorder

// simple recursive construction in preorder fashion
// maintain a preIndex to check for curr root for our tree
// make the preINdex ele of preorder as the root, increment preIndex
// maintian inStrat and InEnd for getting left and right subtrees for the root node fo particular preIndex
// run a loop to find the elements in leftSub ans Right sub in INorder array
// call for left and right subtrees and make link in returning
// time :O(n2)
// space :O(n) aux space 

node *treeInPreorder(vector<int>inorder,vector<int>preorder,int inStart,int inEnd)
{
    static int preIndex=0;
    if(inStart>inEnd)
    return NULL;
    node *root=new node(preorder[preIndex]);
    preIndex++;
    int InIndex;
    for(int i=inStart;i<=inEnd;i++)
    {
        if(inorder[i]==root->key)
        {
            InIndex=i;
            break;
        }
    }
    root->left=treeInPreorder(inorder,preorder,inStart,InIndex-1);
    root->right=treeInPreorder(inorder,preorder,InIndex+1,inEnd);
    return root;
}

node *createTree(vector<int>inorder,vector<int>preorder)
{
    int inStart=0;
    int inEnd=inorder.size()-1;
    node *root=treeInPreorder(inorder,preorder,inStart,inEnd);
    if(!root)
    return NULL;
    return root;
}

void preorderTrav(node *root)
{
    if(!root)
    return;
    cout<<root->key<<" ";
    preorderTrav(root->left);
    preorderTrav(root->right);
}

int main()
{
    vector<int>preorder{10,20,30,40,50};
    vector<int>inorder{20,10,40,30,50};
    node *root=createTree(inorder,preorder);
    cout<<"the preorder trav of the constructed tree is ";
    preorderTrav(root);
    return 0;
}

