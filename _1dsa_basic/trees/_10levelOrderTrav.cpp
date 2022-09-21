#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct node
{
    int key;
    node*left,*right;
    node(int x)
    {
        key=x;
        left=right=NULL;
    }
};

// void levelOrderTrav(node *root)
// {
//     if(root==NULL)
//     return;
//     // creating a queue to store the address of current root
//     queue<node *>q;
//     q.push(root);
//     while(q.empty()!=true)
//     {
//         node *curr=q.front();
//         cout<<curr->key<<" ";
//         q.pop();
//         if(curr->left!=NULL)
//         q.push(curr->left);
//         if(curr->right!=NULL)
//         q.push(curr->right);
//     }
// }

vector <int> levelOrderTrav(node *root)
{
    queue<node *>q;
    vector<int>v;
    q.push(root);
    while(!q.empty())
    {
        // whichever is poped is our current and is traversed 
        node *curr=q.front();
        q.pop();
        v.push_back(curr->key);
        if(curr->left)
        q.push(curr->left);
        if(curr->right)
        q.push(curr->right);
    }
    return v;
}

int main()
{
    node *root=new node(10);
    root->left=new node(20);
    root->left->left=new node(60);
    root->left->left->right=new node(70);
    root->left->left->right->right=new node(80);
    root->right=new node(30);
    root->right->left=new node(40);
    root->right->right=new node(50);
    root->right->right->right=new node(90);
    root->right->right->right->right=new node(140);
    root->right->right->right->left=new node(100);
    root->right->right->right->left->right=new node(120);
    vector<int>v=levelOrderTrav(root);
    for(auto x:v)
    cout<<x<<" ";
    cout<<endl;
    return 0;
}