#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

// approach : 
// Keep track of the horizontal level for each nodes  
// The horizontal level for the route node is zero 
// and if we go to the left of the root we decrease the horizontal level By 1 
// and if you go to the right of the root we increase the horizontal level by one
// keep all the nodes of same horizontal lvl in same map key
// print the keys 
// using lvl order trav to get the vertical nodes in same order as they appear in tree

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

vector<vector<int> > verticalOrderTrav(node *root)
{
    vector<vector<int> >ans;
    if(root==NULL)
    return ans;
    map<int,vector<int> >mp;
    queue<pair<node *,int> >q;
    q.push({root,0});
    while(!q.empty())
    {
        node *curr=q.front().first;
        int hd=q.front().second;
        q.pop();
        mp[hd].push_back(curr->key);
        if(curr->left)
        {
            q.push({curr->left,hd-1});
        }
        if(curr->right)
        {
            q.push({curr->right,hd+1});
        }
    }
    for(auto x:mp)
    {
        vector<int>v;
        for(auto it:x.second)
        {
            v.push_back(it);
        }
        ans.push_back(v);
    }
    return ans;
}

int main()
{
    node* root = new node(1);
    root->left = new node(2);
    root->left->left = new node(4);
    root->left->right = new node(10);
    root->left->left->right = new node(5);
    root->left->left->right->right = new node(6);
    root->right = new node(3);
    root->right->left=new node(9);
    root->right->right=new node(10);
    cout<<"the vertical order trav is "<<endl;
    vector<vector<int> >ans = verticalOrderTrav(root);
    for(int i=0;i<ans.size();i++)
    {
        for(auto x:ans[i])
        cout<<x<<" ";
        cout<<endl;
        // for(auto it=ans[i].begin();it!=ans[i].end();it++)
        // cout<<*it<<" ";
        // cout<<endl;
    }
    return 0;
}