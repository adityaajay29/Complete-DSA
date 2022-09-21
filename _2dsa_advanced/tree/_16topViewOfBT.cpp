#include <iostream>
#include <queue>
#include <map>
#include <vector>
using namespace std;

// approach
// similar to vertical order trav
// here, create a map of int,int, as we have to insert only the top ele of the lvl order trav for each hd
// hd:horizontal distance
// put the ele in map only of mp[hd] doesnt exists
// this ensures that only one ele that is the top one in the tree only goes to the map
// time : O(nlogn)
// space :O(n) for map,but optimised + O(n) for queue + O(n) for vector

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

vector<int> topView(node *root)
{
    vector<int>ans;
    if(!root)
    return ans;
    map<int,int>mp;
    queue<pair<node*,int> >q;
    q.push({root,0});
    while(!q.empty())
    {
        node *curr=q.front().first;
        int hd=q.front().second;
        q.pop();
        // only put the top view ele
        // if(!mp[hd])
        if(mp.find(hd)==mp.end())
        mp[hd]=curr->key;
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
        ans.push_back(x.second);
    }
    return ans;
}

int main()
{
    node *root=new node(1);
    root->left=new node(2);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->left->right->left=new node(6);
    root->right=new node(3);
    root->right->right=new node(7);
    vector<int>ans=topView(root);
    for(auto x:ans)
    {
        cout<<x<<" ";
    }
    return 0;
}

