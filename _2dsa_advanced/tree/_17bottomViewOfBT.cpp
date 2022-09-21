#include <iostream>
#include <queue>
#include <map>
#include <vector>
using namespace std;

// approach: similar to top view
// only differ: change the mp[hd] if new node at that vertical line is found
// in this way, mp will contain the lasr elements of level order trav


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

vector<int> bottomView(node *root)
{
    vector<int>ans;
    if(!root)
    return ans;
    map<int,int>mp;
    queue<pair<node *,int> >q;
    q.push({root,0});
    while(!q.empty())
    {
        node *curr=q.front().first;
        int hd=q.front().second;
        q.pop();
        // we will replace the node for the given hd if already present
        mp[hd]=curr->key;
        if(curr->left)
        q.push({curr->left,hd-1});
        if(curr->right)
        q.push({curr->right,hd+1});
    }
    for(auto x:mp)
    ans.push_back(x.second);
    return ans;
}

int main()
{
    node *root=new node(1);
    root->left=new node(2);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->left->right->left=new node(8);
    root->left->right->right=new node(9);
    root->right=new node(3);
    root->right->left=new node(6);
    root->right->right=new node(7);
    vector<int>ans=bottomView(root);
    for(auto x:ans)
    {
        cout<<x<<" ";
    }
    return 0;
}